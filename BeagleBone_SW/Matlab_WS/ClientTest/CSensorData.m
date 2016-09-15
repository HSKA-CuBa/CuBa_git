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
        function plotX1_raw__dd(this, phi)
            figure;
            plot(this.mTime, this.mX1_raw__dd,...
                 this.mTime, mean(this.mX1_raw__dd)*ones(size(this.mTime)));
            grid; xlabel('Zeit [s]'); ylabel('x dd');
            titleStr = strcat('Sensor 1: X-Beschleunigung bei phi=', num2str(phi), '°');
            title(titleStr);
            legend('Rohwert', 'Mittelwert');
            print(strcat('plots/X1__dd___phi_', num2str(phi)), '-depsc');
        end
        function plotX2_raw__dd(this, phi)
            figure;
            plot(this.mTime, this.mX2_raw__dd,...
                 this.mTime, mean(this.mX2_raw__dd)*ones(size(this.mTime)));
            grid; xlabel('Zeit [s]'); ylabel('x dd');
            titleStr = strcat('Sensor 2: X-Beschleunigung phi=', num2str(phi), '°');
            title(titleStr);
            legend('Rohwert', 'Mittelwert');
            print(strcat('plots/X2__dd___phi_', num2str(phi)), '-depsc');
        end
        function plotY1_raw__dd(this, phi)
            figure;
            plot(this.mTime, this.mY1_raw__dd,...
                 this.mTime, mean(this.mY1_raw__dd)*ones(size(this.mTime)));
            grid; xlabel('Zeit [s]'); ylabel('y dd');
            titleStr = strcat('Sensor 1: Y-Beschleunigung bei phi=', num2str(phi), '°');
            title(titleStr);
            legend('Rohwert', 'Mittelwert');
            print(strcat('plots/Y1__dd___phi_', num2str(phi)), '-depsc');
        end
        function plotY2_raw__dd(this, phi)
            figure;
            plot(this.mTime, this.mY2_raw__dd,...
                 this.mTime, mean(this.mY2_raw__dd)*ones(size(this.mTime)));
            grid; xlabel('Zeit [s]'); ylabel('y dd');
            titleStr = strcat('Sensor 2: Y-Beschleunigung bei phi=', num2str(phi), '°');
            title(titleStr);
            legend('Rohwert', 'Mittelwert');
            print(strcat('plots/Y2__dd___phi_', num2str(phi)), '-depsc');
        end
        function plotPhi1_raw__d(this)
            figure;
            plot(this.mTime, this.mPhi1_raw__d,...
                 this.mTime, mean(this.mPhi1_raw__d)*ones(size(this.mTime)));
            grid; xlabel('Zeit [s]'); ylabel('phi  d');
            titleStr = strcat('Sensor 2: Z-Winkelgeschwindigkeit');
            title(titleStr);
            legend('Rohwert', 'Mittelwert');
            print('plots/Phi1_d', '-depsc');
        end
        function plotPhi2_raw__d(this)
            figure;
            plot(this.mTime, this.mPhi2_raw__d,...
                 this.mTime, mean(this.mPhi2_raw__d)*ones(size(this.mTime)));
            grid; xlabel('Zeit [s]'); ylabel('phi  d');
            titleStr = strcat('Sensor 1: Z-Winkelgeschwindigkeit');
            title(titleStr);
            legend('Rohwert', 'Mittelwert');
            print('plots/Phi1__d', '-depsc');
        end
        
    end    
end