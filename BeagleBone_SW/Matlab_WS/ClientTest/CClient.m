classdef CClient < handle
    properties
        mClient
        mSensorData;
    end
    
    methods
        function ctor = CClient()
            ctor.mClient = tcpclient('192.168.9.1', 40000);
            ctor.mSensorData = CSensorData();
        end
        function run(this)
            while(1)
                while(this.mClient.BytesAvailable < 20)
                    ;   %Wait for a Message to arrrive
                end
                %Parse the header information
                header = read(this.mClient, 4, 'uint8');

                event = EEvent(header(1));
                dataType = EDataType(header(2));
                switch(event)
                    case EEvent.EV_REQUEST_TX_DATA
                        this.parseDataMessage(dataType);
                    otherwise
                        read(this.mClient, 16, 'uin8');
                end
            end
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
            end
            
        end
    end
    
end

