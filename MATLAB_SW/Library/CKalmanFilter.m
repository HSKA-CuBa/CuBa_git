classdef CKalmanFilter < handle
    properties
        mTime
        mPhi
        mPhi__d
        mRawPhi
        mRawPhi__d
        mRawPhi__dd
    end
    
    methods
        function this = CKalmanFilter(time, rawphi, rawphi__d, rawphi__dd)
            this.mTime       = time;
            this.mRawPhi     = rawphi;
            this.mRawPhi__d  = rawphi__d;
            this.mRawPhi__dd = rawphi__dd;   
            this.mPhi        = ones(size(rawphi))*rawphi(1);
            this.mPhi__d     = ones(size(rawphi__d))*rawphi__d(1);
            
            %Filter the phi values
            P    = zeros(size(rawphi));
            P(1) = 0.001;
            K    = zeros(size(rawphi));
            T_a  = this.mTime(2) - this.mTime(1);
            
            for n = 7:(length(this.mRawPhi)-1)
                this.mPhi(n+1) = this.mPhi(n) + this.mRawPhi__d(n)*T_a;
                P(n+1)         = P(n) + var(this.mRawPhi__d(n-6:n)*T_a);
                K(n+1)         = P(n+1) / (P(n+1)+var(this.mRawPhi(n-6:n)));
                this.mPhi(n+1) = this.mPhi(n+1) + K(n+1) * (this.mRawPhi(n+1) - this.mPhi(n+1));
                P(n+1)         = (1-K(n+1))*P(n+1);
            end
            
            %Filter the phi__d values
            P   = zeros(size(rawphi__d));
            P(1)= 0.001;
            K   = zeros(size(rawphi__d));
            
            this.mRawPhi__dd = -1*this.mRawPhi__dd;
            
            for n=7:length(this.mRawPhi__d)-1
                this.mPhi__d(n+1)   = this.mPhi__d(n) + this.mRawPhi__dd(n)*T_a;
                P(n+1)              = P(n) + var(this.mRawPhi__dd(n-6:n)*T_a);
                K(n+1)              = P(n+1) / (P(n+1)+var(this.mRawPhi__d(n-6:n)));
                this.mPhi__d(n+1)   = this.mPhi__d(n+1) + K(n+1) * (this.mRawPhi__d(n+1) - this.mPhi__d(n+1));
                P(n+1)              = (1-K(n+1))*P(n+1);
            end
            
        end
    end    
end

