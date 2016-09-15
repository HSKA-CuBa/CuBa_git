classdef CClient < handle
    properties
        mClient
        mSensorData;
        mUnfilteredData;
        mCompData;
        mKalmanData;
    end
    
    methods
        function ctor = CClient()
            ctor.mClient;
            ctor.mSensorData        = CSensorData();
            ctor.mUnfilteredData    = CFilterData();
            ctor.mCompData          = CFilterData();
            ctor.mKalmanData        = CFilterData();
        end
        function run_V1_AusgleichsPolynomAccelerometer(this, nbrOfDatapoints, phi)
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
            %Plot the data, requires latex interpreter...cd 
            this.mSensorData.plotX1_raw__dd(phi);
            this.mSensorData.plotX2_raw__dd(phi);
            this.mSensorData.plotY1_raw__dd(phi);
            this.mSensorData.plotY2_raw__dd(phi);
            %Save the data
            saveFilename = strcat('datafiles/sensoren_xy_raw__dd___phi_', num2str(phi)');
            sensorData = this.mSensorData;      %Dummy for the savefile
            save(saveFilename, 'sensorData');
        end
        function run_V2_OffsetGyroscope(this, nbrOfDatapoints)
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
            %Plot the data, requires latex interpreter...cd 
            this.mSensorData.plotPhi1_raw__d();
            this.mSensorData.plotPhi2_raw__d();
            %Save the data
            saveFilename = strcat('datafiles/sensoren_z_raw__d');
            sensorData = this.mSensorData;      %Dummy for the savefile
            save(saveFilename, 'sensorData');
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
            end
            
        end
    end
    
end

