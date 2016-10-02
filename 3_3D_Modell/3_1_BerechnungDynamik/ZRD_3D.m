phi     = sym('phi_', [3 1], 'real');
phi__d  = sym('phi__d_', [3 1], 'real');
psi     = sym('psi_', [3 1], 'real');
psi__d  = sym('psi__d_', [3 1], 'real');

D_phi1  = [cos(phi(1)), sin(phi(1)), 0; 
           -sin(phi(1)), cos(phi(1)) , 0;
           0          , 0           , 1];
D_phi2  = [cos(phi(2)), 0           ,-sin(phi(2));
           0          , 1           , 0;
           sin(phi(2)), 0           , cos(phi(2))];
D_phi3  = [1          , 0           , 0;
           0          , cos(phi(3)) , sin(phi(3));
           0          , -sin(phi(3)), cos(phi(3))];
       
w_phi_3__d = [phi__d(3);0;0];
w_phi_2__d = D_phi3 * [0; phi__d(2); 0];
w_phi_1__d = D_phi3 * (D_phi2 * [0;0;phi__d(1)]);

w_K        = w_phi_3__d + w_phi_2__d + w_phi_1__d;
w_R        = psi__d;

O_K        = sym('O_K_', [3 3], 'real');
O_R        = [sym('O_R1', 'real'), 0, 0;...
              0, sym('O_R2', 'real'), 0;...
              0, 0, sym('O_R3', 'real')];

T          = 0.5*w_K'*O_K*w_K + 0.5*(w_K+w_R)'*O_R*(w_K+w_R);

p_phi1     = diff(T, phi__d(1));
p_phi2     = diff(T, phi__d(2));
p_phi3     = diff(T, phi__d(3));
p_psi1     = diff(T, psi__d(1));
p_psi2     = diff(T, psi__d(2));
p_psi3     = diff(T, psi__d(3));

p_phi1__d  = diff(T, phi(1));
p_phi2__d  = diff(T, phi(2));
p_phi3__d  = diff(T, phi(3));
p_psi1__d  = diff(T, psi(1));
p_psi2__d  = diff(T, psi(2));
p_psi3__d  = diff(T, psi(3));