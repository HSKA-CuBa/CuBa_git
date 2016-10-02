classdef CClient < handle
    properties
        mClient
        mSensorData;
        mUnfilteredData;
        mCompData;
        mKalmanData;
        mMotorData;
        mPhiPlot;
        mPhi__dPlot;
        mPsi__dPlot;
    end
    
    methods
        function ctor = CClient()
            ctor.mClient;
            ctor.mSensorData        = CSensorData();
            ctor.mUnfilteredData    = CFilterData();
            ctor.mCompData          = CFilterData();
            ctor.mKalmanData        = CFilterData();
            ctor.mMotorData         = CMotorData();
            ctor.mPhiPlot           = CPlot();
            ctor.mPhi__dPlot        = CPlot();
            ctor.mPsi__dPlot        = CPlot();
        end
        function run_V1_AusgleichsPolynomAccelerometer(this, nbrOfDatapoints,...
                                                       savepath, phi)
            %Reset the sensordata
            this.mSensorData = CSensorData();
            %Connect to the BBB-Server
            this.mClient = tcpclient('192.168.9.1', 40000);
            n = 0;
            while(n < nbrOfDatapoints)
                n = n + 1;
                while(this.mClient.BytesAvailable < 20)
                    ;    %Wait for a message
                end
                %Parse the header
                header   = read(this.mClient, 4, 'uint8');
                event    = EEvent(header(1));
                dataType = EDataType(header(2));
                
                switch(event)
                    case EEvent.EV_REQUEST_TX_DATA
                        this.parseDataMessage(dataType);
                    otherwise
                        read(this.mClient, 16, 'uint8');   
                end
            end
            %Shutdown the connection
            this.mClient = [];
            %Save the data
            saveFilename = strcat(savepath, '/sensordata___phi_', num2str(phi));
            if (phi < 0)
                varName = sprintf('sensordata___phi_m%d', abs(phi));
            else
                varName = sprintf('sensordata___phi_%d', abs(phi));
            end
            eval(strcat(varName, '= this.mSensorData;'));
            save(saveFilename, varName);
        end
        function run_V2_OffsetGyroscope(this, nbrOfDatapoints, savepath)
            %Reset the sensordata
            this.mSensorData        = CSensorData();
            this.mUnfilteredData    = CFilterData();
            this.mCompData          = CFilterData();
            this.mKalmanData        = CFilterData();
            %Connect to the BBB
            this.mClient = tcpclient('192.168.9.1', 40000);
            n = 0;
            while(n < nbrOfDatapoints)
                n = n + 1;
                while(this.mClient.BytesAvailable < 20)
                    ;    %Wait for a message
                end
                %Parse the header
                header   = read(this.mClient, 4, 'uint8');
                event    = EEvent(header(1));
                dataType = EDataType(header(2));
                
                switch(event)
                    case EEvent.EV_REQUEST_TX_DATA
                        this.parseDataMessage(dataType);
                    otherwise
                        read(this.mClient, 16, 'uint8');   
                end
            end
            %Shutdown the connection
            this.mClient = [];
            %Save the data
            saveFilename = strcat(savepath, '/sensordata');
            sensordata = this.mSensorData;
            save(saveFilename, 'sensordata');
        end
        function run_V3_AusgleichsPolynomMotorADC(this, nbrOfDatapoints,savepath, rpm)
            %Reset the data classes
            this.mSensorData        = CSensorData();
            this.mUnfilteredData    = CFilterData();
            this.mCompData          = CFilterData();
            this.mKalmanData        = CFilterData();
            this.mMotorData         = CMotorData();
            %Connect to the BBB
            this.mClient = tcpclient('192.168.9.1', 40000);
            %Transmit the torque/rpm
            rpm_factor = 140000;
            this.setTorque(rpm/rpm_factor);
            n = 0;
            while(n < nbrOfDatapoints)
                n = n + 1;
                while(this.mClient.BytesAvailable < 20)
                    ;    %Wait for a message
                end
                %Parse the header
                header   = read(this.mClient, 4, 'uint8');
                event    = EEvent(header(1));
                dataType = EDataType(header(2));
                
                switch(event)
                    case EEvent.EV_REQUEST_TX_DATA
                        this.parseDataMessage(dataType);
                    otherwise
                        read(this.mClient, 16, 'uint8');   
                end
            end
            %Shutdown the connection
            this.mClient = [];            
            %Save the data
            saveFilename = strcat(savepath, '/motordata___rpm_', num2str(rpm));
            if (rpm < 0)
                varName = sprintf('motordata___phi_m%d', abs(rpm));
            else
                varName = sprintf('motordata___phi_%d', abs(rpm));
            end
            eval(strcat(varName, '= this.mMotorData;'));
            save(saveFilename, varName);
        end
        function run_V4_FilterTest(this, nbrOfDatapoints)
            %Reset the sensordata
            this.mSensorData        = CSensorData();
            this.mUnfilteredData    = CFilterData();
            this.mCompData          = CFilterData();
            this.mKalmanData        = CFilterData();
            %Connect to the BBB
            this.mClient = tcpclient('192.168.9.1', 40000);
            n = 0;
            %Create the updateable plots
            plotTick = 0;
            this.mPhiPlot.createPlots('Ungefiltert', 'Komplementär', 'Kalman',...
                                      '$\varphi [^\circ]$', 'Ausfallwinkel $\varphi$');
            this.mPhi__dPlot.createPlots('Ungefiltert', 'Komplementär', 'Kalman',...
                                         '$\dot{\varphi} [\frac{^\circ}{s}]$', 'Winkelgeschwindigkeit $\dot{\varphi}$');
            while(n < nbrOfDatapoints)
                n = n + 1;
                while(this.mClient.BytesAvailable < 20)
                    ;    %Wait for a message
                end
                %Parse the header
                header   = read(this.mClient, 4, 'uint8');
                event    = EEvent(header(1));
                dataType = EDataType(header(2));
                
                switch(event)
                    case EEvent.EV_REQUEST_TX_DATA
                        this.parseDataMessage(dataType);
                    otherwise
                        read(this.mClient, 16, 'uint8');   
                end
                %Update the plots once in a while
                plotTick = plotTick + 1;
                if(plotTick > 31)
                    plotTick = 0;
                    this.mPhiPlot.updateData(this.mUnfilteredData.mTime,...
                                             radtodeg(this.mUnfilteredData.mPhi),...
                                             this.mCompData.mTime,...
                                             radtodeg(this.mCompData.mPhi),...
                                             this.mKalmanData.mTime,...
                                             radtodeg(this.mKalmanData.mPhi));
                    this.mPhi__dPlot.updateData(this.mUnfilteredData.mTime,...
                                                radtodeg(this.mUnfilteredData.mPhi__d),...
                                                this.mCompData.mTime,...
                                                radtodeg(this.mCompData.mPhi__d),...
                                                this.mKalmanData.mTime,...
                                                radtodeg(this.mKalmanData.mPhi__d));
                end
            end
            %Shutdown the connection
            this.mClient = [];            
            
        end
        function run_V5_BestimmungC_psi(this, nbrOfDatapoints, savepath, torque)
            %Reste the data containers
            this.mSensorData        = CSensorData();
            this.mUnfilteredData    = CFilterData();
            this.mCompData          = CFilterData();
            this.mKalmanData        = CFilterData();
            this.mMotorData         = CMotorData();
            %Connect to the BBB
            this.mClient = tcpclient('192.168.9.1', 40000);
            %Transmit the torque/rpm
            this.setTorque(torque);
            n = 0;
            while(n < nbrOfDatapoints)
                n = n + 1;
                while(this.mClient.BytesAvailable < 20)
                    ;    %Wait for a message
                end
                %Parse the header
                header   = read(this.mClient, 4, 'uint8');
                event    = EEvent(header(1));
                dataType = EDataType(header(2));
                
                switch(event)
                    case EEvent.EV_REQUEST_TX_DATA
                        this.parseDataMessage(dataType);
                    otherwise
                        read(this.mClient, 16, 'uint8');   
                end
            end
            %Shutdown the connection
            this.mClient = [];            
            %Save the data
            saveFilename = strcat(savepath, '/motordata');
            motordata    = this.mMotorData;
            save(saveFilename, 'motordata');     
        end
        function run_V6_BestimmungC_phi(this, nbrOfDatapoints)
            this.run_V4_FilterTest(nbrOfDatapoints); 
        end
        function parseDataMessage(this, dataType)
            switch(dataType)
                case EDataType.SENSOR_DATA
                    time = read(this.mClient,1, 'single');
                    x1   = read(this.mClient,1, 'int16');
                    y1   = read(this.mClient,1, 'int16');
                    phi1 = read(this.mClient,1, 'int16');
                    x2   = read(this.mClient,1, 'int16');
                    y2   = read(this.mClient,1, 'int16');
                    phi2 = read(this.mClient,1, 'int16');
                    this.mSensorData.addData(time, x1, y1, phi1,...
                                             x2, y2, phi2); 
                case EDataType.UNFILTERED_DATA
                    time    = read(this.mClient,1, 'single');
                    phi     = read(this.mClient,1, 'single');
                    phi__d  = read(this.mClient,1, 'single');
                    phi__dd = read(this.mClient,1, 'single');
                    this.mUnfilteredData.addData(time, phi, phi__d, phi__dd);
                case EDataType.COMPLEMENTARY_DATA
                    time    = read(this.mClient,1, 'single');
                    phi     = read(this.mClient,1, 'single');
                    phi__d  = read(this.mClient,1, 'single');
                    phi__dd = read(this.mClient,1, 'single');
                    this.mCompData.addData(time, phi, phi__d, phi__dd);  
                case EDataType.KALMAN_DATA
                    time    = read(this.mClient,1, 'single');
                    phi     = read(this.mClient,1, 'single');
                    phi__d  = read(this.mClient,1, 'single');
                    phi__dd = read(this.mClient,1, 'single');
                    this.mKalmanData.addData(time, phi, phi__d, phi__dd);
                case EDataType.MOTOR_DATA
                    time        = read(this.mClient,1, 'single');
                    torque      = read(this.mClient,1, 'single');
                    psi__d      = read(this.mClient,1, 'single');
                    psi_raw__d  = read(this.mClient,1, 'single');
                    this.mMotorData.addData(time, torque, psi__d, psi_raw__d);
            end
            
        end
        function setTorque(this, torque)
            header = [EEvent.EV_SET_TORQUE, 0, 0, 0];
            data   = typecast([single(torque), 0, 0, 0], 'uint8');
            msg    = [uint8(header), data];
            write(this.mClient, msg);
        end
    end
    
end

