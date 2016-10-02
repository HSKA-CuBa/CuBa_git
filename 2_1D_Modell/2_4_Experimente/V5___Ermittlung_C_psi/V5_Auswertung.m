%22.8.2016, Michael Meindl
%Wertet die Daten aus Versuch 5 aus und berechnet C_psi Wert

O_R_B       = 1.1683e-4;
T_M         = 0.01;
[time, rpm] = importfile('Messwerte\V5_C_psi__d.csv');
time        = (time - time(1))/1000;
T_M         = T_M * ones(size(time));
c_psi__d    = degtorad(-1*rpm*6);
c_psi__dd   = 1./diff(time) .* diff(c_psi__d);
c_psi__dd   = [c_psi__dd;c_psi__dd(end)];

A = c_psi__d;
B = T_M - (O_R_B*c_psi__dd);
C = A\B;

figure;
plot(time, radtodeg(c_psi__d)); grid; xlabel('Zeit [s]');
ylabel('$\dot{\psi}$ [$\frac{\circ}{s}$]', 'interpreter', 'latex');
title('Versuch 5: Radgeschwindigkeit bei $T_M = 10mNm$', 'interpreter', 'latex');
print('Plots/V5_c_psi_d', '-depsc');

