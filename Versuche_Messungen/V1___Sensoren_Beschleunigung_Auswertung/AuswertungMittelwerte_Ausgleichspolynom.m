%Michael Meindl, 12.8.2016
%Auswertung des Mittelwertverlaufs der Beschleunigungssensoren, über die
%Mittel- und Sollwerte wird ein Ausgleichspolynom ersten Grades
%approximiert um die Rohwerte der Sensoren in Beschleunigungen umzurechnen

%Messwerte laden
load('Messwerte\Sensoren_xy_dd___phi_-15');
dd_mean_m15 = [mean(x1__dd) mean(x2__dd) mean(y1__dd) mean(y2__dd)];
load('Messwerte\Sensoren_xy_dd___phi_-30');
dd_mean_m30 = [mean(x1__dd) mean(x2__dd) mean(y1__dd) mean(y2__dd)];
load('Messwerte\Sensoren_xy_dd___phi_-45');
dd_mean_m45 = [mean(x1__dd) mean(x2__dd) mean(y1__dd) mean(y2__dd)];
load('Messwerte\Sensoren_xy_dd___phi_0');
dd_mean_0 = [mean(x1__dd) mean(x2__dd) mean(y1__dd) mean(y2__dd)];
load('Messwerte\Sensoren_xy_dd___phi_15');
dd_mean_15 = [mean(x1__dd) mean(x2__dd) mean(y1__dd) mean(y2__dd)];
load('Messwerte\Sensoren_xy_dd___phi_30');
dd_mean_30 = [mean(x1__dd) mean(x2__dd) mean(y1__dd) mean(y2__dd)];
load('Messwerte\Sensoren_xy_dd___phi_45');
dd_mean_45 = [mean(x1__dd) mean(x2__dd) mean(y1__dd) mean(y2__dd)];

x1__dd_mean = [dd_mean_m45(1) dd_mean_m30(1) dd_mean_m15(1) dd_mean_0(1) ...
               dd_mean_15(1) dd_mean_30(1) dd_mean_45(1)];
x2__dd_mean = [dd_mean_m45(2) dd_mean_m30(2) dd_mean_m15(2) dd_mean_0(2) ...
               dd_mean_15(2) dd_mean_30(2) dd_mean_45(2)];
y1__dd_mean = [dd_mean_m45(3) dd_mean_m30(3) dd_mean_m15(3) dd_mean_0(3) ...
               dd_mean_15(3) dd_mean_30(3) dd_mean_45(3)];
y2__dd_mean = [dd_mean_m45(4) dd_mean_m30(4) dd_mean_m15(4) dd_mean_0(4) ...
               dd_mean_15(4) dd_mean_30(4) dd_mean_45(4)];
           
%Define the target values
phi          = [-45 -30 -15 0 15 30 45];
x__dd_target = 9.81*sind(phi);
y__dd_target = 9.81*(-cosd(phi));

%Fit the polynoms
x1__dd_polynom = fit(x1__dd_mean', x__dd_target', 'poly1');
x2__dd_polynom = fit(x2__dd_mean', x__dd_target', 'poly1');
y1__dd_polynom = fit(y1__dd_mean', y__dd_target', 'poly1');
y2__dd_polynom = fit(y2__dd_mean', y__dd_target', 'poly1');

%Calculated the fitted mean values
x1__dd_fitted = x1__dd_polynom.p1*x1__dd_mean + x1__dd_polynom.p2;
x2__dd_fitted = x2__dd_polynom.p1*x2__dd_mean + x2__dd_polynom.p2;
y1__dd_fitted = y1__dd_polynom.p1*y1__dd_mean + y1__dd_polynom.p2;
y2__dd_fitted = y2__dd_polynom.p1*y2__dd_mean + y2__dd_polynom.p2;

%Calcualte the error vectors
x1__dd_error  = x__dd_target - x1__dd_fitted;
x2__dd_error  = x__dd_target - x2__dd_fitted;
y1__dd_error  = y__dd_target - y1__dd_fitted;
y2__dd_error  = y__dd_target - y2__dd_fitted;

%Plot the results
figure;
plot(phi, x1__dd_fitted, phi, x__dd_target, phi, x1__dd_error); grid; 
xlabel('\phi [°]'); ylabel('Beschleunigung [m/s^2]');
title('Ausgleichspolynom X-Beschleunigung Sensor 1');
legend('Ausgleichspolynom', 'Sollwert', 'Abweichung', 'Location', 'northwest');
print('Plots/X1__dd___fitted', '-depsc');
figure;
plot(phi, x2__dd_fitted, phi, x__dd_target, phi, x2__dd_error); grid;
xlabel('\phi [°]'); ylabel('Beschleunigung [m/s^2]');
title('Ausgleichpolynom X-Beschleunigung Sensor 2');
legend('Ausgleichspolynom', 'Sollwert', 'Abweichung', 'Location', 'northwest');
print('Plots/X2__dd___fitted', '-depsc');
figure;
plot(phi, y1__dd_fitted, phi, y__dd_target, phi, y1__dd_error); grid;
xlabel('\phi [°]'); ylabel('Beschleunigung [m/s^2]');
title('Ausgleichpolynom Y-Beschleunigung Sensor 1');
legend('Ausgleichspolynom', 'Sollwert', 'Abweichung', 'Location', 'west');
print('Plots/Y1__dd___fitted', '-depsc');
figure;
plot(phi, y2__dd_fitted, phi, y__dd_target, phi, y2__dd_error); grid;
xlabel('\phi [°]'); ylabel('Beschleunigung [m/s^2]');
title('Ausgleichpolynom Y-Beschleunigung Sensor 2');
legend('Ausgleichspolynom', 'Sollwert', 'Abweichung', 'Location', 'west');
print('Plots/Y2__dd___fitted', '-depsc');

%Save the polynom approximations
saveFilename = 'Messwerte\AusgleichsPolynome';
save(saveFilename, 'x1__dd_polynom', 'x2__dd_polynom',...
                   'y1__dd_polynom', 'y2__dd_polynom');