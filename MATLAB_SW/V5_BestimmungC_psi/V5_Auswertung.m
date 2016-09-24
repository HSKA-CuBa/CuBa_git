%21.9.16, Michael Meindl

load('datafiles/motordata');

adcFilter = CADCFilter(motordata.mTime, motordata.mPsi__d);
adcFilter.plotFilter();


O_B_R       = 1.1683e-4;
T_M         = 0.002;
t           = adcFilter.mTime;
psi__d      = adcFilter.mPsiMean8;
psi__dd     = 1./diff(t) .* diff(psi__d);
psi__dd     = [psi__dd, psi__dd(end)];

A = psi__d;
B = T_M - (O_B_R * psi__dd);
C_psi = A'\B'

figure;
plot(t, radtodeg(psi__d)); grid;
xlabel('$\boldmath t \big[s \big]$', 'interpreter', 'latex', 'fontsize', 13);
ylabel('$\boldmath \dot{\psi} \Big[\frac{^\circ}{s} \Big]$', 'interpreter', 'latex', 'fontsize', 13);
title('Bestimmung von $\boldmath C_{\psi}$', 'interpreter', 'latex', 'fontsize', 14);
print('plots/C_psi', '-depsc');