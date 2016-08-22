%14.8.2016, Michael Meindl
%Simuliert den Lernprozess, berechnet die Ausgangsgeschwindigkeit der
%Schwungmasse zum Aufspringen, über die Simulation wird die Abweichung zum
%Sollwert bestimmt und über ein iteratives Lernverfahren die
%Radgeschwindigkeit schrittweise angepasst.


%Faktor um den Impulsverlust des nicht perfekten Stoßes zu beschreiben
a_impulse = 0.9;

%Systemgrößen (Werte vom alten Model)
deltaT  = 1e-3;
g       = 9.81;
T_M_m   = 12.4e-3;
T_M_e   = 5.5e-4;
l_AB    = 0.0751442;
l_AC    = 0.08455;
m_K     = 0.294;
m_R     = 0.1298;
O_A_K   = 3.3e-3;
O_B_R   = 0.088e-3;
C_phi   = 2.1e-3;
C_psi   = 2.1268e-5;
%Anfangswerte der Zustandsgrößen
phi_0       = degtorad(45);
phi__dd_0   = 0;

%Anfangswert der Rad/Würfelgeschwindigkeit
psi__d_0 = sqrt((2-sqrt(2))*(m_R + m_K)*g*l_AC*(O_A_K + O_B_R + m_R*l_AB^2)/(O_B_R^2));
phi__d_0 = -a_impulse * psi__d_0  * O_B_R /(O_B_R + O_A_K+ m_R*l_AB^2);

stop        = 0;
iteration   = 0;
phi_zero    = [];
phi__d_zero = [];
while(stop == 0)
    iteration = iteration + 1;
    sim('model_1D_jumpup');
    t       = phi.time;
    phi     = phi.signals(1).values;
    phi__d  = phi__d.signals(1).values;

    phi_min         = min(phi);
    t_phi_min       = find(phi == phi_min) * deltaT;
    if(phi_min >= 0)    %Nulldurchgang vor Sollwert
        deltaE = (1-cos(phi_min))*(m_K+m_R)*g*l_AC;
        deltaPsi__d_0 = sqrt(2*(O_A_K+O_B_R+m_R*l_AB^2)/(O_B_R^2)*deltaE);
        psi__d_0 = psi__d_0+ 0.02*deltaPsi__d_0;
        phi__d_0 = -a_impulse * psi__d_0  * O_B_R /(O_B_R + O_A_K+ m_R*l_AB^2);
        phi_zero(iteration)    = phi_min;
        phi__d_zero(iteration) = phi__d(find(phi==phi_min));
    else
        phi__d_min      = phi__d(find(abs(phi) == min(abs(phi))));
        t_phi__d_min    = find(abs(phi__d) == phi__d_min) * deltaT;  
        deltaE          = 0.5*(O_B_R + O_A_K+ m_R*l_AB^2)*phi__d_min^2;
        deltaPsi__d_0   = -sqrt(2*(O_A_K+O_B_R+m_R*l_AB^2)/(O_B_R^2)*deltaE);
        psi__d_0 = psi__d_0+ 0.02*deltaPsi__d_0;
        phi__d_0 = -a_impulse * psi__d_0  * O_B_R /(O_B_R + O_A_K+ m_R*l_AB^2);
        phi__d_zero(iteration) = phi__d_min;
        phi_zero(iteration)    = phi(find(abs(phi) == min(abs(phi))));
    end
    if(iteration == 100)
        stop = 1;
    end
    if(abs(phi_zero(iteration)) < degtorad(1) && abs(phi__d_zero(iteration)) < degtorad(5))
        stop = 1;
    end
end

index = 1:1:iteration;
subplot(2,1,1);
plot(index, radtodeg(phi_zero), 'o'); grid;
subplot(2,1,2);
plot(index, radtodeg(phi__d_zero), 'o'); grid;
