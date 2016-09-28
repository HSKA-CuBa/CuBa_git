classdef CPhi < handle
    properties
        mTime
        mEstimation
        mComp
        mKalman
        mPlot
        mFigure
    end
    
    methods
        function this = CPhi()
            this.mTime       = [];
            this.mEstimation = [];
            this.mComp       = [];
            this.mKalman     = [];
            this.mPlot       = [];
            this.mFigure     = [];
        end
        function addData(this, time, estimate, comp, kalman)
            this.mTime       = [this.mTime, time];
            this.mEstimation = [this.mEstimation, radtodeg(estimate)];
            this.mComp       = [this.mComp, radtodeg(comp)];
            this.mKalman     = [this.mKalman, radtodeg(kalman)];
            if(isempty(this.mPlot) == 0)
                refreshdata(this.mPlot, 'caller');
                drawnow;
            end
        end
        function livePlot(this)
            this.mFigure = figure;
            this.mPlot   = plot(0,0,0,0,0,0);
            grid; legend('Winkelschätzung', 'Komplementär-Filter', 'Kalman-Filter');
            xlabel('$\bodlmath t [s]$', 'interpreter', 'latex', 'fontsize', 13);
            ylabel('$\boldmath \varphi [^\circ]$', 'interpreter', 'latex', 'fontsize', 13);
            title('Verlauf von $\bodlmath \varphi$', 'interpreter', 'latex', 'fontsize', 14);
            this.mPlot(1).XDataSource = 'this.mTime';
            this.mPlot(1).YDataSource = 'this.mEstimation';
            this.mPlot(2).XDataSource = 'this.mTime';
            this.mPlot(2).YDataSource = 'this.mComp';
            this.mPlot(3).XDataSource = 'this.mTime';
            this.mPlot(3).YDataSource = 'this.mKalman'; 
        end
    end
end