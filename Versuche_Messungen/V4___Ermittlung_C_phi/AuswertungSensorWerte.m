%Michael Meindl, 18.8.2016
%Machen wir jetzt eigentlich erstmal Filter und damit dann die Reibwerte?
%eigentlich schon oder?

load('Messwerte\Filterwerte');
phi     = phi(1:700);
phi__d  = phi__d(1:700);
phi__dd = phi__dd(1:700);
t       = t(1:700);

figure;
plot(t, radtodeg(phi)); grid; xlabel('Zeit [s]'); ylabel('$\varphi$ [$\circ$]', 'interpreter', 'latex');
title('Versuch 4: Verlauf von $\varphi$', 'interpreter', 'latex');
print('Plots/V4_phi', '-depsc');


l_AB    = 0.084;
l_AC    = 0.087;
m_K     = 0.221;
m_R     = 0.09;
O_A_K   = 2.8e-3;
O_B_R   = 1.163e-4;

A = phi__d;
B = ((m_K * l_AC + m_R * l_AB)*9.81 .* sin(phi)) - (O_A_K + O_B_R + m_R * l_AB^2) .* phi__dd;
C = A\B