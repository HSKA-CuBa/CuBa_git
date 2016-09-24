classdef CSensorData < handle
    properties
        mTime
        mX1_raw__dd;
        mY1_raw__dd;
        mPhi1_raw__d;
        mX2_raw__dd;
        mY2_raw__dd;
        mPhi2_raw__d;
    end
    methods
        function ctor = CSensorData()
            ctor.mTime          = [];
            ctor.mX1_raw__dd    = [];
            ctor.mY1_raw__dd    = [];
            ctor.mPhi1_raw__d   = [];
            ctor.mX2_raw__dd    = [];
            ctor.mY2_raw__dd    = [];
            ctor.mPhi2_raw__d   = [];
        end
        function addData(this, time, x1, y1, phi1, x2, y2, phi2)
            this.mTime = [this.mTime, double(time)];
            this.mX1_raw__dd  = [this.mX1_raw__dd, double(x1)];
            this.mY1_raw__dd  = [this.mY1_raw__dd, double(y1)];
            this.mPhi1_raw__d = [this.mPhi1_raw__d, double(phi1)];
            this.mX2_raw__dd  = [this.mX2_raw__dd, double(x2)];
            this.mY2_raw__dd  = [this.mY2_raw__dd, double(y2)];
            this.mPhi2_raw__d = [this.mPhi2_raw__d, double(phi2)];
        end
        function plotX1_raw__dd(this, titleStr, savePath)
            figure;
            plot(this.mTime, this.mX1_raw__dd,...
                 this.mTime, mean(this.mX1_raw__dd)*ones(size(this.mTime)));
            grid; xlabel('$\boldmath t \big[s \big]$', 'interpreter', 'latex', 'fontsize', 13); 
            ylabel('$\boldmath \ddot{x} \big[\ \big]$', 'interpreter', 'latex', 'fontsize', 13);
            title(titleStr, 'interpreter', 'latex', 'fontsize', 14);
            legend('Rohwert', 'Mittelwert');
            print(savePath, '-depsc');
        end
        function plotX2_raw__dd(this, titleStr, savePath)
            figure;
            plot(this.mTime, this.mX2_raw__dd,...
                 this.mTime, mean(this.mX2_raw__dd)*ones(size(this.mTime)));
            grid; xlabel('$\boldmath t \big[s \big]$', 'interpreter', 'latex', 'fontsize', 13); 
            ylabel('$\boldmath \ddot{x} \big[\ \big]$', 'interpreter', 'latex', 'fontsize', 13);
            title(titleStr, 'interpreter', 'latex', 'fontsize', 14);
            legend('Rohwert', 'Mittelwert');
            print(savePath, '-depsc');
        end
        function plotY1_raw__dd(this, titleStr, savePath)
            figure;
            plot(this.mTime, this.mY1_raw__dd,...
                 this.mTime, mean(this.mY1_raw__dd)*ones(size(this.mTime)));
            grid; xlabel('$\boldmath t \big[s \big]$', 'interpreter', 'latex', 'fontsize', 13); 
            ylabel('$\boldmath \ddot{y} \big[\ \big]$', 'interpreter', 'latex', 'fontsize', 13);
            title(titleStr, 'interpreter', 'latex', 'fontsize', 14);
            legend('Rohwert', 'Mittelwert');
            print(savePath, '-depsc');
        end
        function plotY2_raw__dd(this, titleStr, savePath)
            figure;
            plot(this.mTime, this.mY2_raw__dd,...
                 this.mTime, mean(this.mY2_raw__dd)*ones(size(this.mTime)));
            grid; xlabel('$\boldmath t \big[s \big]$', 'interpreter', 'latex', 'fontsize', 13);
            ylabel('$\boldmath \ddot{y} \big[\ \big]$', 'interpreter', 'latex', 'fontsize', 13);
            title(titleStr, 'interpreter', 'latex', 'fontsize', 14);
            legend('Rohwert', 'Mittelwert');
            print(savePath, '-depsc');
        end
        function plotPhi1_raw__d(this, titleStr, savePath)
            figure;
            plot(this.mTime, this.mPhi1_raw__d,...
                this.mTime, mean(this.mPhi1_raw__d)*ones(size(this.mTime)));
            grid; xlabel('$\boldmath t \big[s \big]$', 'interpreter', 'latex', 'fontsize', 13);
            ylabel('$\boldmath \dot{\varphi} \big[\ \big]$', 'interpreter', 'latex', 'fontsize', 13);
            title(titleStr, 'interpreter', 'latex', 'fontsize', 14);
            legend('Rohwert', 'Mittelwert');
            print(savePath, '-depsc');
        end
        function plotPhi2_raw__d(this, titleStr, savePath)
            figure;
            plot(this.mTime, this.mPhi2_raw__d,...
                this.mTime, mean(this.mPhi2_raw__d)*ones(size(this.mTime)));
            grid; xlabel('$\boldmath t \big[s \big]$', 'interpreter', 'latex', 'fontsize', 13);
            ylabel('$\boldmath \dot{\varphi} \big[\ \big]$', 'interpreter', 'latex', 'fontsize', 13);
            title(titleStr, 'interpreter', 'latex', 'fontsize', 14);
            legend('Rohwert', 'Mittelwert');
            print(savePath, '-depsc');
        end
    end    
end