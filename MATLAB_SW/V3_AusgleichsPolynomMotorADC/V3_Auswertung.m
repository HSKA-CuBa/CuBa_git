%17.9.16, Michael Meindl

load('datafiles/motordata___rpm_500');
load('datafiles/motordata___rpm_1500');
load('datafiles/motordata___rpm_2500');
load('datafiles/motordata___rpm_-500');
load('datafiles/motordata___rpm_-1500');
load('datafiles/motordata___rpm_-2500');

titlestr    = 'ADC-Werte bei Sollgeschwindigkeit = -2500 RPM';
savefile    = 'plots/psi1__d___rpm_-2500';
motordata___phi_m2500.plotPsi_raw__d(titlestr, savefile);
titlestr    = 'ADC-Werte bei Sollgeschwindigkeit =  -1500 RPM';
savefile    = 'plots/psi1__d___rpm_-1500';
motordata___phi_m1500.plotPsi_raw__d(titlestr, savefile);
titlestr    = 'ADC-Werte bei Sollgeschwindigkeit = -500 RPM';
savefile    = 'plots/psi1__d___rpm_-500';
motordata___phi_m500.plotPsi_raw__d(titlestr, savefile);
titlestr    = 'ADC-Werte bei Sollgeschwindigkeit = 500 RPM';
savefile    = 'plots/psi1__d___rpm_500';
motordata___phi_500.plotPsi_raw__d(titlestr, savefile);
titlestr    = 'ADC-Werte bei Sollgeschwindigkeit = 1500 RPM';
savefile    = 'plots/psi1__d___rpm_1500';
motordata___phi_1500.plotPsi_raw__d(titlestr, savefile);
titlestr    = 'ADC-Werte bei Sollgeschwindigkeit = 1500 RPM';
savefile    = 'plots/psi1__d___rpm_2500';
motordata___phi_2500.plotPsi_raw__d(titlestr, savefile);

t = motordata___phi_m2500.mTime(500:end);
psi_mean__d = [mean(motordata___phi_m2500.mPsi_raw__d(500:end)),...
               mean(motordata___phi_m1500.mPsi_raw__d(500:end)),...
               mean(motordata___phi_m500.mPsi_raw__d(500:end)),...
               mean(motordata___phi_500.mPsi_raw__d(500:end)),...
               mean(motordata___phi_1500.mPsi_raw__d(500:end)),...
               mean(motordata___phi_2500.mPsi_raw__d(500:end))];
psi_target__d = degtorad(6*[-2500 -1500 -500 500 1500 2500]);

psi_polynom__d = fit(psi_mean__d', psi_target__d', 'poly1');

psi_corrected__d = psi_mean__d * psi_polynom__d.p1 + psi_polynom__d.p2;

figure;
plot(psi_target__d, psi_corrected__d, psi_target__d, psi_target__d,...
    psi_target__d, psi_target__d - psi_corrected__d); grid;
xlabel('$\boldmath \dot{\psi} \Big[\frac{rad}{s}\Big]$', 'interpreter', 'latex', 'fontsize', 13);
ylabel('$\boldmath \dot{\psi} \Big[\frac{rad}{s}\Big]$', 'interpreter', 'latex', 'fontsize', 13);
legend('Polynom-Werte', 'Sollwert', 'Abweichung', 'Location', 'nw');
clear title;
title('Ausgleichspolynom $\dot{\psi}$', 'interpreter', 'latex', 'fontsize', 14);
print('plots/ADC_mittelwert_polynom', '-depsc');