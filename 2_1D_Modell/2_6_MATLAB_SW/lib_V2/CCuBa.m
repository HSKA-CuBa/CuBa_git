classdef CCuBa < handle
    properties
        mClient
        mProxy
        mSensorData
        mPhi
        mPhi__d
        mPsi__d
    end
    
    methods
        function this = CCuBa()
            this.mClient = tcpip('localhost', 40000,...
                                 'NetworkRole', 'Client',...
                                 'Terminator', '');
            this.mClient.ByteOrder              = 'littleEndian';
            this.mClient.BytesAvailableFcnCount = 24;
            this.mClient.BytesAvailableFcn      = @rxCallback;
            this.mClient.BytesAvailableFcnMode  = 'byte';
            this.mClient.UserData               = this;
            this.mProxy  = CProxy(this.mClient);
            this.mSensorData = CSensorData();
            this.mPhi        = CPhi();
            this.mPhi__d     = CPhi__d();
            this.mPsi__d     = CPsi__d();
        end
        function receiveCallback(this)
            event = EEvent(fread(this.mClient, 1, 'uint32'));
            this.parseMessage(event);
        end
        function parseMessage(this, event)
            switch event
                case EEvent.TX_SENSOR_DATA
                    time    = double(fread(this.mClient, 1, 'float32'));
                    x1      = double(fread(this.mClient, 1, 'int16'));
                    x2      = double(fread(this.mClient, 1, 'int16'));
                    y1      = double(fread(this.mClient, 1, 'int16'));
                    y2      = double(fread(this.mClient, 1, 'int16'));
                    phi1    = double(fread(this.mClient, 1, 'int16'));
                    phi2    = double(fread(this.mClient, 1, 'int16'));
                    psi     = double(fread(this.mClient, 1, 'int16'));
                    fread(this.mClient, 1, 'int16');
                    this.mSensorData.addData(time, x1, x2, y1, y2, phi1, phi2, psi);
                case EEvent.TX_PHI_DATA
                    time     = double(fread(this.mClient, 1, 'float32'));
                    estimate = double(fread(this.mClient, 1, 'float32'));
                    comp     = double(fread(this.mClient, 1, 'float32'));
                    kalman   = double(fread(this.mClient, 1, 'float32'));
                    fread(this.mClient, 1, 'float32');
                    this.mPhi.addData(time, estimate, comp, kalman);
                case EEvent.TX_PHI__D_DATA
                    time     = double(fread(this.mClient, 1, 'float32'));
                    estimate = double(fread(this.mClient, 1, 'float32'));
                    kalman   = double(fread(this.mClient, 1, 'float32'));
                    fread(this.mClient, 2, 'float32');
                    this.mPhi__d.addData(time, estimate, kalman);
                case EEvent.TX_PSI__D_DATA
                    time     = double(fread(this.mClient, 1, 'float32'));
                    estimate = double(fread(this.mClient, 1, 'float32'));
                    mean4    = double(fread(this.mClient, 1, 'float32'));
                    mean8    = double(fread(this.mClient, 1, 'float32'));
                    mean16   = double(fread(this.mClient, 1, 'float32'));
                    this.mPsi__d.addData(time, estimate, mean4, mean8, mean16);
            end
        end
        function connect(this)
            fopen(this.mClient); 
        end
        function disconnect(this)
             fclose(this.mClient);
        end
        function resetData(this)
            this.mPhi    = CPhi();
            this.mPhi__d = CPhi__d();
            this.mPsi__d = CPsi__d();
        end
    end
    
end

