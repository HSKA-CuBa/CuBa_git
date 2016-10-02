classdef CClient < handle
    properties
        mSensorData
        mPhi
        mPhi__d
        mPsi__d
        mClient
    end
    
    methods
        function this = CClient()
            this.mClient = tcpip('192.168.9.1', 40000,...
                                 'NetworkRole', 'Client',...
                                 'Terminator', '');
            this.mClient.ByteOrder              = 'littleEndian';
            this.mClient.BytesAvailableFcnCount = 24;
            this.mClient.BytesAvailableFcn      = @rxCallback;
            this.mClient.BytesAvailableFcnMode  = 'byte';
            this.mClient.UserData               = this;
            this.mSensorData = CSensorData();
            this.mPhi        = CPhi();
            this.mPhi__d     = CPhi__d();
            this.mPsi__d     = CPsi__d();
        end
        function resetData(this)
            close all;
            this.mSensorData = CSensorData();
            this.mPhi        = CPhi();
            this.mPhi__d     = CPhi__d();
            this.mPsi__d     = CPsi__d();
        end
        function setTorque(this, torque)
            header = [uint8(EEvent.EV_CMD), uint8(EDataType.DEFAULT_IGNORE),...
                      uint8(ECommand.CMD_SET_TORQUE), uint8(0)];
            data   = [single(torque), single(0), single(0), single(0), single(0)];
            fwrite(this.mClient, header, 'uint8');
            fwrite(this.mClient, data, 'float32');
        end
        function selectFilter(this, filter)
            header = [uint8(EEvent.EV_CMD), uint8(EDataType.DEFAULT_IGNORE),...
                      uint8(ECommand.CMD_SET_FILTER), uint8(0)];
            data   = [uint32(filter), uint32(0), uint32(0), uint32(0), uint32(0)];
            fwrite(this.mClient, header, 'uint8');
            fwrite(this.mClient, data, 'uint32');
        end
        function setPhiOffset(this, offset)
            header = [uint8(EEvent.EV_CMD), uint8(EDataType.DEFAULT_IGNORE),...
                      uint8(ECommand.CMD_SET_PHI_OFFSET), uint8(0)];
            data   = [single(offset), single(0), single(0), single(0), single(0)];
            fwrite(this.mClient, header, 'uint8');
            fwrite(this.mClient, data, 'float32');
        end
        function setPhi__dOffset(this, offset)
            header = [uint8(EEvent.EV_CMD), uint8(EDataType.DEFAULT_IGNORE),...
                      uint8(ECommand.CMD_SET_PHI__D_OFFSET), uint8(0)];
            data   = [single(offset), single(0), single(0), single(0), single(0)];
            fwrite(this.mClient, header, 'uint8');
            fwrite(this.mClient, data, 'float32');
        end
        function setPsi__dOffset(this, offset)
            header = [uint8(EEvent.EV_CMD), uint8(EDataType.DEFAULT_IGNORE),...
                      uint8(ECommand.CMD_SET_PSI__D_OFFSET), uint8(0)];
            data   = [single(offset), single(0), single(0), single(0), single(0)];
            fwrite(this.mClient, header, 'uint8');
            fwrite(this.mClient, data, 'float32');
        end
        function sendCommand(this, cmd)
            header = [uint8(EEvent.EV_CMD), uint8(EDataType.DEFAULT_IGNORE), uint8(cmd), 0];
            data   = uint8(zeros(1,20));
            msg    = [header, data];
            fwrite(this.mClient, msg, 'uint8');
        end
        function receiveCallback(this)
            event    = EEvent(fread(this.mClient, 1, 'uint8'));
            datatype = EDataType(fread(this.mClient, 1, 'uint8'));
            cmd      = ECommand(fread(this.mClient, 1, 'uint8'));
            fread(this.mClient, 1, 'uint8');
            this.parseMessage(event, datatype, cmd);
        end
        function parseMessage(this, event, datatype, cmd)
            if(EEvent.EV_TRANSMIT_DATA == event)
                switch datatype
                    case EDataType.SENSORDATA
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
                    case EDataType.PHI
                        time     = double(fread(this.mClient, 1, 'float32'));
                        estimate = double(fread(this.mClient, 1, 'float32'));
                        comp     = double(fread(this.mClient, 1, 'float32'));
                        kalman   = double(fread(this.mClient, 1, 'float32'));
                        fread(this.mClient, 1, 'float32');
                        this.mPhi.addData(time, estimate, comp, kalman);
                    case EDataType.PHI__D
                        time     = double(fread(this.mClient, 1, 'float32'));
                        estimate = double(fread(this.mClient, 1, 'float32'));
                        kalman   = double(fread(this.mClient, 1, 'float32'));
                        fread(this.mClient, 2, 'float32');
                        this.mPhi__d.addData(time, estimate, kalman);
                    case EDataType.PSI__D
                        time     = double(fread(this.mClient, 1, 'float32'));
                        estimate = double(fread(this.mClient, 1, 'float32'));
                        mean4    = double(fread(this.mClient, 1, 'float32'));
                        mean8    = double(fread(this.mClient, 1, 'float32'));
                        mean16   = double(fread(this.mClient, 1, 'float32'));
                        this.mPsi__d.addData(time, estimate, mean4, mean8, mean16);
                end
            end
        end
    end
   
end