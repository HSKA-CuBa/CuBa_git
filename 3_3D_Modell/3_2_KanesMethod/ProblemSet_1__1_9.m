%3.10.16, Michael Meindl, Problem Set 1.1-1.3
q     = sym('q', [3 1], 'real');
q__d  = sym('q__d', [3 1], 'real');
A_R_B = [1, 0, 0; 0, cos(q(1)), sin(q(1));0, -sin(q(1)), cos(q(1))];
B_R_C = [cos(q(2)), 0, -sin(q(2)); 0, 1, 0; sin(q(2)), 0, cos(q(2))];
C_R_D = [cos(q(3)), sin(q(3)), 0; -sin(q(3)), cos(q(3)), 0; 0, 0, 1];

A_u   = [1;2;3];
B_u   = A_R_B*A_u;
C_u   = B_R_C*B_u;
D_u   = C_R_D*C_u;

C_v   = (B_R_C * [1;0;0] + [0;1;0] + C_R_D'*[0;0;1]);
D_v   = C_R_D * C_v;
B_v   = B_R_C' * C_v;
A_v   = A_R_B' * B_v;

D_w   = [1;2;q(3)];
C_w   = C_R_D' * D_w;
B_w   = B_R_C' * C_w;
A_w   = A_R_B' * B_w;

%Problem 1.5
A_v__d_q1 = diff(A_v, q(1));
B_v__d_q1 = diff(B_v, q(1));
C_v__d_q2 = diff(C_v, q(2));
C_v__d_q3 = diff(C_v, q(3));
D_v__d_q2 = diff(D_v, q(2));
D_v__d_q1 = diff(D_v, q(1));

simplify(sqrt(sum(A_v__d_q1.^2)));
simplify(sqrt(sum(B_v__d_q1.^2)));
simplify(sqrt(sum(C_v__d_q2.^2)));
simplify(sqrt(sum(C_v__d_q3.^2)));
simplify(sqrt(sum(D_v__d_q2.^2)));
simplify(sqrt(sum(D_v__d_q1.^2)));

%Problem 1.6
a = A_R_B'*diff(B_u, q(1));
b = diff(B_u, q(1));
c = diff(A_u, q(1));

%Problem 1.7
alpha = q(1)+q(2)+q(3);
beta  = q(1)^2 + q(2)^2 + q(3)^2;
gamma = q(1)^3 + q(2)^3 + q(3)^3;
B_r_PQ = A_R_B*[alpha;0;0] + [0;beta;0] + B_R_C'*[0;0;gamma];
D_r_PQ__d_q3 = diff(C_R_D*(B_R_C*B_r_PQ), q(3));
subbed       = subs(D_r_PQ__d_q3, {q(1), q(2), q(3)}, {pi/2, 0, 0});
simplify(sqrt(sum(subbed.^2)));
