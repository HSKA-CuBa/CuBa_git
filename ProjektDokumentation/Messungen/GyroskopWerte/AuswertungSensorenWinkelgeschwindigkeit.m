%Michael Meindl, 8.8.2016
%Wird nach Beenden des Modells 'GyroskopAuswertung.slx' ausgeführt.
%Berechnet den durschnittlichen Offset der Gyroskopwerte von dem
%Sollwert=0.

t       = double(phi1__d.time(2:end));
phi1__d = double(phi1__d.signals(1).values(2:end));
phi2__d = double(phi2__d.signals(1).values(2:end));

phi1__d_mean = mean(phi1__d);
phi2__d_mean = mean(phi2__d);

phi1__d_offset = round(phi1__d_mean);
phi2__d_offset = round(phi2__d_mean);

saveFilename = strcat('Messwerte\Sensoren_phi_d');
save(saveFilename, 't', 'phi1__d', 'phi2__d',...
        'phi1__d_offset', 'phi2__d_offset');