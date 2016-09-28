classdef CSensorData < handle
    properties
        mTime
        mX1__dd
        mX2__dd
        mY1__dd
        mY2__dd
        mPhi1__d
        mPhi2__d
        mPsi__d
    end
    
    methods
        function this = CSensorData()
            this.mTime       = [];
            this.mX1__dd     = [];
            this.mX2__dd     = [];
            this.mY1__dd     = [];
            this.mY2__dd     = [];
            this.mPhi1__d    = [];
            this.mPhi2__d    = [];
            this.mPsi__d     = [];
        end
        function addData(this, time, x1, x2, y1, y2, phi1, phi2, psi)
            this.mTime    = [this.mTime, time];
            this.mX1__dd  = [this.mX1__dd, x1];
            this.mX2__dd  = [this.mX2__dd, x2];
            this.mY1__dd  = [this.mY1__dd, y1];
            this.mY2__dd  = [this.mY2__dd, y2];
            this.mPhi1__d = [this.mPhi1__d, phi1];
            this.mPhi2__d = [this.mPhi2__d, phi2];
            this.mPsi__d  = [this.mPsi__d, psi];
        end
    end
    
end

