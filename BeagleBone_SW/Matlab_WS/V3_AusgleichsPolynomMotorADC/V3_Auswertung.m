%17.9.16, Michael Meindl

load('datafiles/motordata___rpm_0');
load('datafiles/motordata___rpm_1000');
load('datafiles/motordata___rpm_2000');
load('datafiles/motordata___rpm_3000');
load('datafiles/motordata___rpm_-1000');
load('datafiles/motordata___rpm_-2000');
load('datafiles/motordata___rpm_-3000');

title    = 'ADC-Werte bei Sollgeschwindigkeit = -3000 RPM';
savefile = 'plots/psi1__d___rpm_-3000';
motordata___phi_m3000.plotPsi_raw__d(title, savefile);
title    = 'ADC-Werte bei Sollgeschwindigkeit =  -2000 RPM';
savefile = 'plots/psi1__d___rpm_-2000';
motordata___phi_m2000.plotPsi_raw__d(title, savefile);
title    = 'ADC-Werte bei Sollgeschwindigkeit = -1000 RPM';
savefile = 'plots/psi1__d___rpm_-1000';
motordata___phi_m1000.plotPsi_raw__d(title, savefile);
title    = 'ADC-Werte bei Sollgeschwindigkeit = 0 RPM';
savefile = 'plots/psi1__d___rpm_0';
motordata___phi_0.plotPsi_raw__d(title, savefile);
title    = 'ADC-Werte bei Sollgeschwindigkeit = 1000 RPM';
savefile = 'plots/psi1__d___rpm_1000';
motordata___phi_1000.plotPsi_raw__d(title, savefile);
title    = 'ADC-Werte bei Sollgeschwindigkeit = 2000 RPM';
savefile = 'plots/psi1__d___rpm_2000';
motordata___phi_2000.plotPsi_raw__d(title, savefile);
title    = 'ADC-Werte bei Sollgeschwindigkeit = 3000 RPM';
savefile = 'plots/psi1__d___rpm_3000';
motordata___phi_3000.plotPsi_raw__d(title, savefile);

psi_mean__d = [mean(motordata___phi_m3000.mPsi_raw__d(500:end)),...
               mean(motordata___phi_m2000.mPsi_raw__d(500:end)),...
               mean(motordata___phi_m1000.mPsi_raw__d(500:end)),...
               mean(motordata___phi_0.mPsi_raw__d(500:end)),...
               mean(motordata___phi_1000.mPsi_raw__d(500:end)),...
               mean(motordata___phi_2000.mPsi_raw__d(500:end)),...
               mean(motordata___phi_3000.mPsi_raw__d(500:end))];
psi_target__d = degtorad(6*[-3000 -2000 -1000 0 1000 2000 3000]);

psi_polynom__d = fit(psi_mean__d', psi_target__d', 'poly1');