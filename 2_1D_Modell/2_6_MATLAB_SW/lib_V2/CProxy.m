classdef CProxy < handle    
    properties
        mClient
    end
    
    methods
        function this = CProxy(client)
            this.mClient = client; 
        end
        function runSensorMeasurement(this)
            header = uint32(EEvent.RUN_SENSOR_MEASUREMENT);
            data   = uint32(zeros(1,5));
            msg    = [header, data];
            fwrite(this.mClient, msg, 'uint32');
        end
        function runADCMeasurement(this)
            header = uint32(EEvent.RUN_ADC_MEASUREMENT);
            data   = uint32(zeros(1,5));
            msg    = [header, data];
            fwrite(this.mClient, msg, 'uint32');
        end
        function runCPsiIdentification(this)
            header = uint32(EEvent.RUN_CPSI_IDENTIFICATION);
            data   = uint32(zeros(1,5));
            msg    = [header, data];
            fwrite(this.mClient, msg, 'uint32');
        end
        function runCPhiIdentification(this)
            header = uint32(EEvent.RUN_CPHI_IDENTIFICATION);
            data   = uint32(zeros(1,5));
            msg    = [header, data];
            fwrite(this.mClient, msg, 'uint32');
        end
        function runControlTest(this)
            header = uint32(EEvent.RUN_CONTROL_TEST);
            data   = uint32(zeros(1,5));
            msg    = [header, data];
            fwrite(this.mClient, msg, 'uint32');
        end
        function runJumpTest(this)
            header = uint32(EEvent.RUN_JUMP_TEST);
            data   = uint32(zeros(1,5));
            msg    = [header, data];
            fwrite(this.mClient, msg, 'uint32');
        end
        function setTorque(this, torque)
            header = uint32(EEvent.SET_TORQUE);
            data   = [single(torque), 0, 0, 0, 0];
            fwrite(this.mClient, header, 'uint32');
            fwrite(this.mClient, data, 'float32');
        end
        function setPhiOffset(this, offset)
            header = uint32(EEvent.SET_PHI_OFFSET);
            data   = [single(offset), 0, 0, 0, 0];
            fwrite(this.mClient, header, 'uint32');
            fwrite(this.mClient, data, 'float32');
        end
        function setPhi__dOffset(this, offset)
            header = uint32(EEvent.SET_PHI__D_OFFSET);
            data   = [single(offset), 0,0,0,0];
            fwrite(this.mClient, header, 'uint32');
            fwrite(this.mClient, data, 'float32');
        end
        function setPsi__dOffset(this, offset)
            header = uint32(EEvent.SET_PSI__D_OFFSET);
            data   = [single(offset), 0,0,0,0];
            fwrite(this.mClient, header, 'uint32');
            fwrite(this.mClient, data, 'float32');
        end
    end
    
end

