classdef CComplementaryFilter < handle
    properties
        mFilteredPhi
        mRawPhi
        mRawPhi__d
        mAlpha
        mTime
    end
    
    methods
        function this = CComplementaryFilter(phi, phi__d, time, alpha)
            this.mRawPhi        = phi;
            this.mRawPhi__d     = phi__d;
            this.mFilteredPhi   = ones(size(time))*phi(1);
            this.mAlpha         = alpha;
            this.mTime          = time;
            
            T_a = time(2)-time(1);
            for n = 2:length(this.mTime)
                firstSummand  = alpha*(this.mFilteredPhi(n-1)+T_a*this.mRawPhi__d(n));
                secondSummand = (1-alpha)*(this.mRawPhi(n));
                this.mFilteredPhi(n) = firstSummand + secondSummand;
            end
        end

    end
    
end

