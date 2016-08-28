%28.8.2016, Michael Meindl
%Skript um die Messwerte aus der Regelung zu plotten

t           = phi_scope.time(1:750) - phi_scope.time(1);
phi_acc     = phi_scope.signals(1).values(1:750);
phi_komp    = phi_scope.signals(2).values(1:750);
phi_kalman  = phi_scope.signals(3).values(1:750);

figure;
plot(t, phi_acc, t, phi_komp, t, phi_kalman); grid;
xlabel('Zeit [s]'); ylabel('$\varphi$ [$^\circ$]', 'interpreter', 'latex');
title('Verlauf des Winkels $\varphi$', 'interpreter', 'latex');
legend('Winkelschätzung', 'Komplementärfilter', 'Kalman-Filter');
print('Plots/phi_regelung', '-depsc');

t           = phi__d_scope.time(1:750) - phi__d_scope.time(1);
phi__d      = phi__d_scope.signals(1).values(1:750);

figure;
plot(t, radtodeg(phi__d)); grid; xlabel('Zeit [s]');
ylabel('$\dot{\varphi}$ [$\frac{^\circ}{s}$]', 'interpreter', 'latex');
title('Verlauf der Winkelgeschwindigkeit $\dot{\varphi}$', 'interpreter', 'latex');
print('Plots/phi__d_regelung', '-depsc');

t           = psi__d_scope.time(1:750) - psi__d_scope.time(1);
psi__d      = psi__d_scope.signals(1).values(1:750);

figure;
plot(t, radtodeg(psi__d)); grid; xlabel('Zeit [s]');
ylabel('$\dot{\psi}$ [$\frac{^\circ}{s}$]', 'interpreter', 'latex');
title('Verlauf der Winkelgeschwindigkeit $\dot{\psi}$', 'interpreter', 'latex');
print('Plots/psi__d_regelung', '-depsc');