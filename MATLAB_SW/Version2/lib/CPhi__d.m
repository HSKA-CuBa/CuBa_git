classdef CPhi__d < handle
    properties
        mTime
        mEstimation
        mKalman
        mPlot
        mFigure
    end
    
    methods
        function this = CPhi__d()
            this.mTime       = [];
            this.mEstimation = [];
            this.mKalman     = [];
            this.mPlot       = [];
            this.mFigure     = [];
        end
        function addDat(this, time, estimate, kalman)
            this.mTime       = [this.mTime, time];
            this.mEstimation = [this.Estimation, radtodeg(estimate)];
            this.mKalman     = [this.mKalman, radtodeg(kalman)];
            if(isempty(this.mPlot) == 0)
                refreshdata(this.mPlot, 'caller');
                drawnow;
            end
        end
        function livePlot(this)
            this.mFigure = figure;
            this.mPlot   = plot(0,0,0,0);
            grid; legend('Gyroscope', 'Kalman-Filter');
            xlabel('$\bodlmath t [s]$', 'interpreter', 'latex', 'fontsize', 13);
            ylabel('$\boldmath \dot{varphi} [\frac{^\circ}{s}]$', 'interpreter', 'latex', 'fontsize', 13);
            title('Verlauf von $\bodlmath \dot{\varphi}$', 'interpreter', 'latex', 'fontsize', 14);
            this.mPlot(1).XDataSource = 'this.mTime';
            this.mPlot(1).YDataSource = 'this.mEstimation';
            this.mPlot(2).XDataSource = 'this.mTime';
            this.mPlot(2).YDataSource = 'this.mKalman';
        end
    end
    
end

