%Michael Meindl, 8.8.2016
%Wird nach Beenden des Modells 'BeschleunigungsAuswertung.slx' ausgeführt.
%Berechnet die Mittelwerte und plottet diese im Vergleich zu den Rohwerten
%der x und y Beschleunigung der beiden Sensoren. Speichert anschließend die
%Plots und Messwerte.

phi = 45;

t      = double(x1__dd.time(2:end));
x1__dd = double(x1__dd.signals(1).values(2:end));
y1__dd = double(y1__dd.signals(1).values(2:end));
x2__dd = double(x2__dd.signals(1).values(2:end));
y2__dd = double(y2__dd.signals(1).values(2:end));

x1__dd_mean = ones(size(t,1)) * mean(x1__dd);
y1__dd_mean = ones(size(t,1)) * mean(y1__dd);
x2__dd_mean = ones(size(t,1)) * mean(x2__dd);
y2__dd_mean = ones(size(t,1)) * mean(y2__dd);

figure;
plot(t, x1__dd,t, x1__dd_mean, 'r'); grid; 
xlabel('Zeit [s]'); ylabel('X-Beschleunigung []');
title(strcat('X-Beschleunigung Sensor1 bei \phi = ', num2str(phi), '°'));
legend('Rohwert', 'Mittelwert');
print(strcat('Plots/X1__dd___phi_', num2str(phi)), '-depsc');
figure;
plot(t, y1__dd, t, y1__dd_mean, 'r'); grid; 
xlabel('Zeit [s]'); ylabel('Y-Beschleunigung []');
title(strcat('Y-Beschleunigung Sensor1 bei \phi = ', num2str(phi), '°'));
legend('Rohwert', 'Mittelwert');
print(strcat('Plots/Y1__dd___phi_', num2str(phi)), '-depsc');
figure;
plot(t, x2__dd, t, x2__dd_mean, 'r'); grid; 
xlabel('Zeit [s]'); ylabel('X-Beschleunigung []');
title(strcat('X-Beschleunigung Sensor1 be2 \phi = ', num2str(phi), '°'));
legend('Rohwert', 'Mittelwert');
print(strcat('Plots/X2__dd___phi_', num2str(phi)), '-depsc');
figure;
plot(t, y2__dd, t, y2__dd_mean, 'r'); grid; 
xlabel('Zeit [s]'); ylabel('Y-Beschleunigung []');
title(strcat('Y-Beschleunigung Sensor2 bei \phi = ', num2str(phi), '°'));
legend('Rohwert', 'Mittelwert');
print(strcat('Plots/Y2__dd___phi_', num2str(phi)), '-depsc');

saveFilename = strcat('Messwerte\Sensoren_xy_dd___phi_', num2str(phi));
save(saveFilename, 't', 'x1__dd', 'y1__dd', 'x2__dd', 'y2__dd',...
     'x1__dd_mean', 'x2__dd_mean', 'y1__dd_mean', 'y2__dd_mean');