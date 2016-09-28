classdef CPsi__d < handle
    properties
        mTime
        mEstimation
        mMean4
        mMean8
        mMean16
        mPlot
        mFigure
    end
    
    methods
        function this = CPsi__d()
            this.mTime       = [];
            this.mEstimation = [];
            this.mMean4      = [];
            this.mMean8      = [];
            this.mMean16     = [];
            this.mPlot       = [];
            this.mFigure     = [];
        end
        function addData(this, time, estimate, mean4, mean8, mean16)
            this.mTime       = [this.mTime, time];
            this.mEstimation = [this.mEstimation, radtodeg(estimate)];
            this.mMean4      = [this.mMean4, radtodeg(mean4)];
            this.mMean8      = [this.mMean8, radtodeg(mean8)];
            this.mMean16     = [this.mMean16, radtodeg(mean16)];
            if(isempty(this.mPlot) == 0)
                refreshdata(this.mPlot, 'caller');
                drawnow;
            end
        end
        function livePlot(this)
            this.mFigure = figure;
            this.mPlot   = plot(0,0, 0,0, 0,0, 0,0);
            grid; legend('Hall-Sensoren', 'Mittelwert(N=4)', 'Mittelwert(N=8)', 'Mittelwert(N=16)');
            xlabel('$\bodlmath t [s]$', 'interpreter', 'latex', 'fontsize', 13);
            ylabel('$\boldmath \dot{\psi} [\frac{^\circ}{s}]$', 'interpreter', 'latex', 'fontsize', 13);
            title('Verlauf von $\bodlmath \dot{\psi}$', 'interpreter', 'latex', 'fontsize', 14);
            this.mPlot(1).XDataSource = 'this.mTime';
            this.mPlot(1).YDataSource = 'this.mEstimation';
            this.mPlot(2).XDataSource = 'this.mTime';
            this.mPlot(2).YDataSource = 'this.mMean4';
            this.mPlot(3).XDataSource = 'this.mTime';
            this.mPlot(3).YDataSource = 'this.mMean8';
            this.mPlot(4).XDataSource = 'this.mTime';
            this.mPlot(4).YDataSource = 'this.mMean16';
        end
    end
    
end

