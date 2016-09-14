classdef CSensorData < handle
    properties
        mTime
        mX1_raw__dd;
        mY1_raw__dd;
        mPhi1_raw__d;
        mX2_raw__dd;
        mY2_raw__dd;
        mPhi2_raw__d;
    end
    methods
        function ctor = CSensorData()
            ctor.mTime          = [];
            ctor.mX1_raw__dd    = [];
            ctor.mY1_raw__dd    = [];
            ctor.mPhi1_raw__d   = [];
            ctor.mX2_raw__dd    = [];
            ctor.mY2_raw__dd    = [];
            ctor.mPhi2_raw__d   = [];
        end
        function addData(this, time, x1, y1, phi1, x2, y2, phi2)
            this.mTime = [this.mTime, double(time)];
            this.mX1_raw__dd  = [this.mX1_raw__dd, double(x1)];
            this.mY1_raw__dd  = [this.mY1_raw__dd, double(y1)];
            this.mPhi1_raw__d = [this.mPhi1_raw__d, double(phi1)];
            this.mX2_raw__dd  = [this.mX2_raw__dd, double(x2)];
            this.mY2_raw__dd  = [this.mY2_raw__dd, double(y2)];
            this.mPhi2_raw__d = [this.mPhi2_raw__d, double(phi2)];
        end
    end    
end