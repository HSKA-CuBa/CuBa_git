%19.9.16, Michael Meindl
%The unfiltered data has to be adjusted because the model now is a normal
%pendulum, thus there is a sudden switch from 180° to -180°

load('datafiles/V6_data');
close all

t               = unfiltereddata.mTime;
phi_raw         = unfiltereddata.mPhi;
phi_raw__d      = unfiltereddata.mPhi__d;
phi_raw__dd     = unfiltereddata.mPhi__dd;

%Values have to be adjusted because of normal pendulum setup
for n = 1:length(phi_raw)
    if(phi_raw(n) < 0)
        phi_raw(n) = degtorad(360)+phi_raw(n);
    end
    phi_raw(n) = phi_raw(n) - degtorad(180);
end

%Filter the values
compFilter      = CComplementaryFilter(phi_raw, phi_raw__d, t, 0.98);
kalmanFilter    = CKalmanFilter(t, phi_raw, phi_raw__d, phi_raw__dd);

figure;
plot(t, radtodeg(phi_raw),...
     compFilter.mTime, radtodeg(compFilter.mFilteredPhi),...
     kalmanFilter.mTime, radtodeg(kalmanFilter.mPhi)); grid;
 legend('Winkelschätzung','Komplementärfilter', 'Kalman-Filter');
 xlabel('t [s]', 'interpreter', 'latex');
 ylabel('$\varphi [^\circ]$', 'interpreter', 'latex');
 title('Vergleich der Filter $\varphi$', 'interpreter', 'latex');
 
figure;
plot(t, radtodeg(phi_raw__d),...
     kalmanFilter.mTime, radtodeg(kalmanFilter.mPhi__d)); grid;
legend('Gyroscope', 'Kalman-Filter');
xlabel('t [s]', 'interpreter', 'latex');
ylabel('$\dot{\varphi} [\frac{^\circ}{s}]$', 'interpreter', 'latex');
title('Vergleich der Filter $\dot{\varphi}$', 'interpreter', 'latex');

%Calcualte C_phi
phi     = kalmanFilter.mPhi(4:end);
phi__d  = kalmanFilter.mPhi__d(4:end);
phi__dd = phi_raw__dd(4:end);
l_AB    = 0.084;
l_AC    = 0.087;
m_K     = 0.221;
m_R     = 0.09;
O_A_K   = 2.8e-3;
O_B_R   = 1.163e-4;

A = phi__d;
B = ((m_K * l_AC + m_R * l_AB)*9.81 .* sin(phi)) - (O_A_K + O_B_R + m_R * l_AB^2) .* phi__dd;
C = A'\B';

