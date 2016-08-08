%Michael Meindl, 8.8.2016
%Skript zur Initialisierung des Modell "model_1D.slx", setzt die Werte von
%konstanten Systemgrößen und Anfangswerte der Zustandsgrößen

%Konstante Parameter
C_phi       = 1;
C_psi       = 2;
l_AB        = 3;
l_AC        = 4;
m_K         = 5;
m_R         = 1;
O_A_K       = 2;
O_B_R       = 3;
g           = 9.81;
T_M_e       = 5.5e-4;
T_M_m       = 12.4e-3;

%Anfangswerte der Zustandsgrößen
phi_0       = 0;
phi__d_0    = 0;
phi__dd_0   = 0;
psi_0       = 0;
psi__d_0    = 0;
psi__dd_0   = 0;