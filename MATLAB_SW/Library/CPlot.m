classdef CPlot < handle
    %Class to create updateable figures and maintain them, draws three
    %lines per figure/plot
    properties
        mFigure;
        mPlot;
        mX1;
        mX2;
        mX3;
        mY1;
        mY2;
        mY3;
    end
    
    methods
        function this = CPlot()
            this.mX1     = [];
            this.mX2     = [];
            this.mX3     = [];
            this.mY1     = [];
            this.mY2     = [];
            this.mY3     = [];
            this.mPlot   = [];
            this.mFigure = [];
        end
        function createPlots(this, line1Name, line2Name, line3Name, ylabelstr, titlestr)
            this.mFigure = figure;
            this.mPlot   = plot(0,0,0,0,0,0);
            grid; legend(line1Name, line2Name, line3Name);
            xlabel('$\bodlmath t [s]$', 'interpreter', 'latex', 'fontsize', 13);
            ylabel(ylabelstr, 'interpreter', 'latex', 'fontsize', 13);
            title(titlestr, 'interpreter', 'latex', 'fontsize', 14);
            this.mPlot(1).XDataSource = 'this.mX1';
            this.mPlot(1).YDataSource = 'this.mY1';
            this.mPlot(2).XDataSource = 'this.mX2';
            this.mPlot(2).YDataSource = 'this.mY2';
            this.mPlot(3).XDataSource = 'this.mX3';
            this.mPlot(3).YDataSource = 'this.mY3'; 
        end
        function updateData(this,x1,y1,x2,y2,x3,y3)
            this.mX1 = x1;
            this.mY1 = y1;
            this.mX2 = x2;
            this.mY2 = y2;
            this.mX3 = x3;
            this.mY3 = y3;
            refreshdata(this.mPlot, 'caller');
            drawnow;
        end
    end
    
end

