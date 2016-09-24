classdef CMotorData < handle
    properties
        mTime
        mTorque
        mPsi__d
        mPsi_raw__d
    end
    
    methods
        function ctor = CMotorData()
            ctor.mTime       = [];
            ctor.mTorque     = [];
            ctor.mPsi__d     = [];
            ctor.mPsi_raw__d = [];
        end
        function addData(this, time, torque, psi__d, psi_raw__d)
            this.mTime       = [this.mTime, double(time)];
            this.mTorque     = [this.mTorque, double(torque)];
            this.mPsi__d     = [this.mPsi__d, double(psi__d)];
            this.mPsi_raw__d = [this.mPsi_raw__d, double(psi_raw__d)];
        end
        function plotPsi_raw__d(this, titleStr, savePath)
            figure;
            plot(this.mTime, this.mPsi_raw__d);
            grid; xlabel('$\boldmath t \big[s \big]$', 'interpreter', 'latex', 'fontsize', 13);
            ylabel('$\boldmath \dot{\psi} \big[\ \big]$', 'interpreter', 'latex', 'fontsize', 13);
            title(titleStr, 'interpreter', 'latex', 'fontsize', 14);
            print(savePath, '-depsc'); 
        end
    end
    
end

