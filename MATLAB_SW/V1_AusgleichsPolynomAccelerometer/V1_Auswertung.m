%13.9.16, Michael Meindl

load('datafiles/sensordata___phi_0');
load('datafiles/sensordata___phi_15');
load('datafiles/sensordata___phi_30');
load('datafiles/sensordata___phi_45');
load('datafiles/sensordata___phi_-15');
load('datafiles/sensordata___phi_-30');
load('datafiles/sensordata___phi_-45');

phiArr          = [-45 -30 -15 0 15 30 45];
sensorDataArr   = [sensordata___phi_m45; sensordata___phi_m30;...
                   sensordata___phi_m15; sensordata___phi_0;...
                   sensordata___phi_15; sensordata___phi_30;
                   sensordata___phi_45];

%Plot the raw sensor values
for n = 1:7
    phistr = num2str(phiArr(n));
    %X1_raw__dd
    title = strcat('X-Beschleunigung Sensor 1 bei $\varphi = ', phistr,...
                   '^\circ$');
    savefile = strcat('plots/X1__dd___phi_', phistr);
    sensorDataArr(n).plotX1_raw__dd(title, savefile);
    %X2_raw__dd
    title = strcat('X-Beschleunigung Sensor 2 bei $\varphi = ', phistr,...
                   '^\circ$');
    savefile = strcat('plots/X2__dd___phi_', phistr);
    sensorDataArr(n).plotX2_raw__dd(title, savefile);
    %Y1_raw__dd
    title = strcat('Y-Beschleunigung Sensor 1 bei $\varphi = ', phistr,...
                   '^\circ$');
    savefile = strcat('plots/Y1__dd___phi_', phistr);
    sensorDataArr(n).plotY1_raw__dd(title, savefile);
    %Y2_raw__dd
    title = strcat('Y-Beschleunigung Sensor 2 bei $\varphi = ', phistr,...
                   '^\circ$');
    savefile = strcat('plots/Y2__dd___phi_', phistr);
    sensorDataArr(n).plotY2_raw__dd(title, savefile);
end

%Calculate the polynomials
x1_mean = [mean(sensordata___phi_m45.mX1_raw__dd), mean(sensordata___phi_m30.mX1_raw__dd),...
           mean(sensordata___phi_m15.mX1_raw__dd), mean(sensordata___phi_0.mX1_raw__dd),...
           mean(sensordata___phi_15.mX1_raw__dd), mean(sensordata___phi_30.mX1_raw__dd),...
           mean(sensordata___phi_45.mX1_raw__dd)];
x2_mean = [mean(sensordata___phi_m45.mX2_raw__dd), mean(sensordata___phi_m30.mX2_raw__dd),...
           mean(sensordata___phi_m15.mX2_raw__dd), mean(sensordata___phi_0.mX2_raw__dd),...
           mean(sensordata___phi_15.mX2_raw__dd), mean(sensordata___phi_30.mX2_raw__dd),...
           mean(sensordata___phi_45.mX2_raw__dd)];
y1_mean = [mean(sensordata___phi_m45.mY1_raw__dd), mean(sensordata___phi_m30.mY1_raw__dd),...
           mean(sensordata___phi_m15.mY1_raw__dd), mean(sensordata___phi_0.mY1_raw__dd),...
           mean(sensordata___phi_15.mY1_raw__dd), mean(sensordata___phi_30.mY1_raw__dd),...
           mean(sensordata___phi_45.mY1_raw__dd)];
y2_mean = [mean(sensordata___phi_m45.mY2_raw__dd), mean(sensordata___phi_m30.mY2_raw__dd),...
           mean(sensordata___phi_m15.mY2_raw__dd), mean(sensordata___phi_0.mY2_raw__dd),...
           mean(sensordata___phi_15.mY2_raw__dd), mean(sensordata___phi_30.mY2_raw__dd),...
           mean(sensordata___phi_45.mY2_raw__dd)];

g = 9.81;
x_targetArr__dd = g*sind(phiArr);
y_targetArr__dd = -g*cosd(phiArr);

x1_polynom = fit(x1_mean', x_targetArr__dd', 'poly1');
x2_polynom = fit(x2_mean', x_targetArr__dd', 'poly1');
y1_polynom = fit(y1_mean', y_targetArr__dd', 'poly1');
y2_polynom = fit(y2_mean', y_targetArr__dd', 'poly1');

x1_corrected__dd = x1_polynom.p1*x1_mean + x1_polynom.p2;
x2_corrected__dd = x2_polynom.p1*x2_mean + x2_polynom.p2;
y1_corrected__dd = y1_polynom.p1*y1_mean + y1_polynom.p2;
y2_corrected__dd = y2_polynom.p1*y2_mean + y2_polynom.p2;

x1_error = x_targetArr__dd - x1_corrected__dd;
x2_error = x_targetArr__dd - x2_corrected__dd;
y1_error = y_targetArr__dd - y1_corrected__dd;
y2_error = y_targetArr__dd - y2_corrected__dd;

%Plot the results
figure;
plot(phiArr, x1_corrected__dd, phiArr, x_targetArr__dd, phiArr, x1_error);
grid; xlabel('$\boldmath \varphi \big[^\circ \big]$', 'interpreter', 'latex', 'fontsize', 13);
ylabel('$\boldmath \ddot{x} \Big[\frac{m}{s^2}\Big]$', 'interpreter', 'latex', 'fontsize', 13);
legend('Ausgleichspolynom', 'Sollwert', 'Abweichung', 'Location', 'west');
clear title;    %Workaround mathworks
title('Ausgleichspolynom X-Beschleunigung Sensor 1', 'interpreter', 'latex', 'fontsize', 14);
print('plots/X1__dd___fitted', '-depsc');
figure;
plot(phiArr, x2_corrected__dd, phiArr, x_targetArr__dd, phiArr, x2_error);
grid; xlabel('$\boldmath \varphi \big[^\circ \big]$', 'interpreter', 'latex', 'fontsize', 13);
ylabel('$\boldmath \ddot{x} \Big[\frac{m}{s^2}\Big]$', 'interpreter', 'latex', 'fontsize', 13);
legend('Ausgleichspolynom', 'Sollwert', 'Abweichung', 'Location', 'west');
clear title;    %Workaround mathworks
title('Ausgleichspolynom X-Beschleunigung Sensor 2', 'interpreter', 'latex', 'fontsize', 14);
print('plots/X2__dd___fitted', '-depsc');
figure;
plot(phiArr, y1_corrected__dd, phiArr, y_targetArr__dd, phiArr, y1_error);
grid; xlabel('$\boldmath \varphi \big[^\circ \big]$', 'interpreter', 'latex', 'fontsize', 13);
ylabel('$\boldmath \ddot{y} \Big[\frac{m}{s^2}\Big]$', 'interpreter', 'latex', 'fontsize', 13);
legend('Ausgleichspolynom', 'Sollwert', 'Abweichung', 'Location', 'west');
clear title;    %Workaround mathworks
title('Ausgleichspolynom Y-Beschleunigung Sensor 1','interpreter', 'latex', 'fontsize', 14);
print('plots/Y1__dd___fitted', '-depsc');
figure;
plot(phiArr, y2_corrected__dd, phiArr, y_targetArr__dd, phiArr, y2_error);
grid; xlabel('$\boldmath \varphi \big[^\circ \big]$', 'interpreter', 'latex', 'fontsize', 13);
ylabel('$\boldmath \ddot{y} \Big[\frac{m}{s^2}\Big]$', 'interpreter', 'latex', 'fontsize', 13);
legend('Ausgleichspolynom', 'Sollwert', 'Abweichung', 'Location', 'west');
clear title;    %Workaround mathworks
title('Ausgleichspolynom Y-Beschleunigung Sensor 2', 'interpreter', 'latex', 'fontsize', 13);
print('plots/Y2__dd__fitted', '-depsc');
