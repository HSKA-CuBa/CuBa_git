ProblemSet_1__1_9;
D_b1 = C_R_D*(B_R_C*[1;0;0]);
D_b2 = C_R_D*(B_R_C*[0;1;0]);
D_b3 = C_R_D*(B_R_C*[0;0;1]);

D_b1__d = diff(D_b1, q(1))*q__d(1) +...
          diff(D_b1, q(2))*q__d(2) +...
          diff(D_b1, q(3))*q__d(3) + diff(D_b1, 't');
D_b2__d = diff(D_b2, q(1))*q__d(1) +...
          diff(D_b2, q(2))*q__d(2) +...
          diff(D_b2, q(3))*q__d(3) + diff(D_b2, 't');
D_b3__d = diff(D_b3, q(1))*q__d(1) +...
          diff(D_b3, q(2))*q__d(2) +...
          diff(D_b3, q(3))*q__d(3) + diff(D_b3, 't');
B_b1__d = B_R_C'*(C_R_D'*D_b1__d);
B_b2__d = B_R_C'*(C_R_D'*D_b2__d);
B_b3__d = B_R_C'*(C_R_D'*D_b3__d);

D_w_B = [B_b2__d(3);B_b3__d(1); B_b1__d(2)];

D_c1  = C_R_D*[1;0;0];
D_c2  = C_R_D*[0;1;0];
D_c3  = C_R_D*[0;0;1];

D_c1__d = diff(D_c1, q(1))*q__d(1) + ...
          diff(D_c1, q(2))*q__d(2) + ...
          diff(D_c1, q(3))*q__d(3);
D_c2__d = diff(D_c2, q(1))*q__d(1) + ...
          diff(D_c2, q(2))*q__d(2) + ...
          diff(D_c2, q(3))*q__d(3);
D_c3__d = diff(D_c3, q(1))*q__d(1) + ...
          diff(D_c3, q(2))*q__d(2) + ...
          diff(D_c3, q(3))*q__d(3);
C_c1__d = C_R_D'*D_c1__d;
C_c2__d = C_R_D'*D_c2__d;
C_c3__d = C_R_D'*D_c3__d;

D_w_C   = [C_c2__d(3); C_c3__d(1); C_c1__d(2)];

C_b1    = B_R_C*[1;0;0];
C_b2    = B_R_C*[0;1;0];
C_b3    = B_R_C*[0;0;1];

C_b1__d = diff(C_b1, q(1))*q__d(1) + ...
          diff(C_b1, q(2))*q__d(2) + ...
          diff(C_b1, q(3))*q__d(3);
C_b2__d = diff(C_b2, q(1))*q__d(1) + ...
          diff(C_b2, q(2))*q__d(2) + ...
          diff(C_b2, q(3))*q__d(3);
C_b3__d = diff(C_b3, q(1))*q__d(1) + ...
          diff(C_b3, q(2))*q__d(2) + ...
          diff(C_b3, q(3))*q__d(3);
B_b1__d = B_R_C'*C_b1__d;
B_b2__d = B_R_C'*C_b2__d;
B_b3__d = B_R_C'*C_b3__d;

C_w_B    = [B_b2__d(3); B_b3__d(1); B_b1__d(2)];
B__D_w_C = B_R_C'*D_w_C;

simplify(C_w_B + B__D_w_C)