%Michael Meindl, 8.8.2016
%Skript zur Initialisierung des Modell "model_1D.slx", setzt die Werte von
%konstanten Systemgrößen und Anfangswerte der Zustandsgrößen

%Konstante Parameter
T_M         = 5;
C_phi       = 6.2e-3;
C_psi       = 3.1176e-5;
l_AB        = 0.084;
l_AC        = 0.087;
m_K         = 0.221;
m_R         = 0.09;
O_A_K       = 2.8e-3;
O_B_R       = 1.1683e-4;
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