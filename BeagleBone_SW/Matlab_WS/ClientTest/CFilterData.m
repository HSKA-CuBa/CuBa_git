classdef CFilterData < handle
    properties
        mTime
        mPhi
        mPhi__d
        mPhi__dd
    end
    
    methods
        function ctor = CFilterData()
            ctor.mTime    = [];
            ctor.mPhi     = [];
            ctor.mPhi__d  = [];
            ctor.mPhi__dd = [];
        end
        function addData(this, time, phi, phi__d, phi__dd)
            this.mTime      = [this.mTime, double(time)];
            this.mPhi       = [this.mPhi, double(phi)];
            this.mPhi__d    = [this.mPhi__d, double(phi__d)];
            this.mPhi__dd   = [this.mPhi__dd, double(phi__dd)];
        end
    end
    
end

