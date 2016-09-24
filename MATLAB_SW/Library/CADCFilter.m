classdef CADCFilter < handle
    properties 
        mTime
        mPsiRaw
        mPsiMean4
        mPsiMean8
        mPsiMean16
    end
    
    methods
        function this = CADCFilter(time, raw)
            this.mTime          = time;
            this.mPsiRaw        = raw;
            %Calculate the FloatingMean-Filter
            this.mPsiMean4    = raw;
            for n = 1:3
                this.mPsiMean4(n) = sum(this.mPsiRaw(1:n)) / n;
            end
            for n = 4:length(this.mPsiRaw)
                this.mPsiMean4(n) = sum(this.mPsiRaw(n-3:n)) / 4;
            end
            this.mPsiMean8    = raw;
            for n = 1:7
                this.mPsiMean8(n) = sum(this.mPsiRaw(1:n)) / n;
            end
            for n = 8:length(this.mPsiRaw)
                this.mPsiMean8(n) = sum(this.mPsiRaw(n-7:n)) / 8;
            end
            this.mPsiMean16   = raw;
            for n = 1:15
                this.mPsiMean16(n) = sum(this.mPsiRaw(1:n)) / n;
            end
            for n = 16:length(this.mPsiRaw)
                this.mPsiMean16(n) =sum(this.mPsiRaw(n-15:n)) / 16; 
            end
        end
        function plotFilter(this)
           figure;
           plot(this.mTime(601:1000), radtodeg(this.mPsiRaw(601:1000)),...
                this.mTime(601:1000), radtodeg(this.mPsiMean4(601:1000)),...
                this.mTime(601:1000), radtodeg(this.mPsiMean8(601:1000)),...
                this.mTime(601:1000), radtodeg(this.mPsiMean16(601:1000))); grid;
            xlabel('\boldmath$t \big[s \big]$', 'interpreter', 'latex', 'fontsize', 13);
            ylabel('\boldmath$\dot{\psi} \Big[ \frac{^\circ}{s} \Big]$', 'interpreter', 'latex', 'fontsize', 13);
            legend('Nicht gefiltert', 'Mittelwert (N=4)', 'Mittelwert (N=8)', 'Mittelwert (N=16)', 'Location', 'nw');
            title('Filtervergleich \boldmath$\dot{\psi}$', 'interpreter', 'latex', 'fontsize', 14);
            print('plots/filtervergleich_psi__d', '-depsc');
        end
    end
end