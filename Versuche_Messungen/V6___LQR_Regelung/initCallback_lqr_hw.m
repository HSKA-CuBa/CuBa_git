%Michael Meindl, 8.8.2016
%Skript zur Initialisierung des Modell "model_1D.slx", setzt die Werte von
%konstanten Systemgrößen und Anfangswerte der Zustandsgrößen

%Konstante Parameter
C_phi       = 6.2e-3;
C_psi       = 3.1176e-5;
l_AB        = 0.084;
l_AC        = 0.087;
m_K         = 0.221;
m_R         = 0.09;
O_A_K       = 2.8e-3;
O_B_R       = 1.1683e-4;
O_A_G       = O_A_K + m_R * l_AB^2;
g           = 9.81;
T_M_e       = 5.5e-4;
T_M_m       = 12.4e-3;

%Anfangswerte der Zustandsgrößen
phi_0       = degtorad(3);
phi__d_0    = 0;
phi__dd_0   = 0;
psi_0       = 0;
psi__d_0    = 0;
psi__dd_0   = 0;

%Reglerberechnung
alpha1 = (g*(m_K * l_AC + m_R * l_AB)) / (O_A_G);
alpha2 = -C_phi / (O_A_G);
alpha3 = C_psi / (O_A_G);
alpha4 = -alpha1;
alpha5 = -alpha2;
alpha6 = (-C_psi*(O_B_R + O_A_G)) / (O_B_R * O_A_G);
beta1  = -1/(O_A_G);
beta2  = (O_A_G + O_B_R) / (O_A_G * O_B_R);

A = [0 1 0;
    alpha1 alpha2 alpha3;
    alpha4 alpha5 alpha6];
B = [0;beta1;beta2];

Tmax = 0.07;
phiKmax = degtorad(5);
phiK_dmax = degtorad(20);
phiR_dmax = degtorad(2000*6);
R = 1/(Tmax^2);
Q = [1/(phiKmax^2) 0 0;0 1/(phiK_dmax^2) 0; 0 0 1/(phiR_dmax^2)];


K = lqr(A,B,Q,R);
Kd = lqrd(A,B,Q,R,0.02);