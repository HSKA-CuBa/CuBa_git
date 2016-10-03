q    = sym('q', [2 1], 'real');
q__d = sym('q__d',[2 1], 'real');
r    = sym('r', 'real');

L_R_C = [0,0,1;cos(q(1)), sin(q(1)), 0; -sin(q(1)), cos(q(1)), 0];

L_c2         = L_R_C'*[0;1;0];
L_c2__d_q1   = diff(L_c2, q(1));
C_L_c2__d_q1 = L_R_C*L_c2__d_q1;
simplify(C_L_c2__d_q1);

L_c3         = L_R_C'*[0;0;1];
L_c3__d_q1   = diff(L_c3, q(1));
C_L_c3__d_q1 = L_R_C*L_c3__d_q1;
simplify(C_L_c3__d_q1);

C_p = [-3*r*cos(q(2)); 3*r*sin(q(2)) + r; 0];
L_p = L_R_C'*C_p;

L_p__d = diff(L_p, q(1))*q__d(1) + diff(L_p, q(2))*q__d(2) + diff(L_p, 't');
C_L_p__d = L_R_C*L_p__d;