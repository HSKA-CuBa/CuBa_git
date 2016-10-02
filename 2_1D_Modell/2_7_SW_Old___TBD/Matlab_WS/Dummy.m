classdef Dummy < handle
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        mTestPlot
        mFigure
        mX1
        mX2
        mY1
        mY2
    end
    
    methods
        function ctor = Dummy()
            ctor.mX1 = [];
            ctor.mX2 = [];
            ctor.mY1 = [];
            ctor.mY2 = [];
            ctor.mFigure = figure;
            ctor.mTestPlot = plot(0,0,0,0); grid;
            %This workaround only works if the calling instance of the
            %class is called 'this' as an argument
            ctor.mTestPlot(1).XDataSource = 'this.mX1';
            ctor.mTestPlot(1).YDataSource = 'this.mY1';
            ctor.mTestPlot(2).XDataSource = 'this.mX2';
            ctor.mTestPlot(2).YDataSource = 'this.mY2';
        end
        function updateData(this)
            this.mX1 = 1:10;
            this.mY1 = 3*this.mX1;
            this.mX2 = 1:20;
            this.mY2 = 0.2*this.mX2;
            refreshdata(this.mTestPlot, 'caller');
        end
    end
    
end

