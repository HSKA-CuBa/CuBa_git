classdef CPhi < handle
    properties
        mTime
        mEstimation
        mComp
        mKalman
        mPlot
        mFigure
        mUpdateCounter
    end
    
    methods
        function this = CPhi()
            this.mTime       = [];
            this.mEstimation = [];
            this.mComp       = [];
            this.mKalman     = [];
            this.mPlot       = [];
            this.mFigure     = [];
            this.mUpdateCounter = 0;
        end
        function addData(this, time, estimate, comp, kalman)
            this.mTime       = [this.mTime, time];
            this.mEstimation = [this.mEstimation, radtodeg(estimate)];
            this.mComp       = [this.mComp, radtodeg(comp)];
            this.mKalman     = [this.mKalman, radtodeg(kalman)];
            this.mUpdateCounter = this.mUpdateCounter + 1;
            if((isempty(this.mPlot) == 0) && (this.mUpdateCounter > 15))
                this.mUpdateCounter = 0;
                set(this.mPlot(1), 'XData', this.mTime);
                set(this.mPlot(1), 'YData', this.mEstimation);
                set(this.mPlot(2), 'XData', this.mTime);
                set(this.mPlot(2), 'YData', this.mComp);
                set(this.mPlot(3), 'XData', this.mTime);
                set(this.mPlot(3), 'YData', this.mKalman);
                %refreshdata(this.mPlot, 'caller');
                drawnow;
            end
        end
        function livePlot(this)
            this.mFigure = figure;
            this.mPlot   = plot(0,0,0,0,0,0);
            grid; legend('Winkelschätzung', 'Komplementär-Filter', 'Kalman-Filter');
            xlabel('$\boldmath t [s]$', 'interpreter', 'latex', 'fontsize', 13);
            ylabel('$\boldmath \varphi [^\circ]$', 'interpreter', 'latex', 'fontsize', 13);
            title('Verlauf von $\boldmath \varphi$', 'interpreter', 'latex', 'fontsize', 14);
            this.mPlot(1).XDataSource = 'this.mTime';
            this.mPlot(1).YDataSource = 'this.mEstimation';
            this.mPlot(2).XDataSource = 'this.mTime';
            this.mPlot(2).YDataSource = 'this.mComp';
            this.mPlot(3).XDataSource = 'this.mTime';
            this.mPlot(3).YDataSource = 'this.mKalman'; 
        end
    end
end