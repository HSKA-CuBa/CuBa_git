%3.10.2016, Michael Meindl, Problem Set 2.2
beta  = sym('beta', [3 1], 'real');
alpha = sym('alpha', [3 1], 'real');
q     = sym('q', [3 1], 'real');

A_R_B = [cos(q(2))*cos(q(3)), cos(q(2))*cos(q(3)), -sin(q(2));
         sin(q(1))*sin(q(2))*cos(q(3))-sin(q(3))*cos(q(1)),...
         sin(q(1))*sin(q(2))*sin(q(3))+cos(q(3))*cos(q(1)), sin(q(1))*cos(q(2));
         cos(q(1))*sin(q(2))*cos(q(3)), cos(q(1))*sin(q(2))*sin(q(3))-cos(q(3))*sin(q(1)),...
         cos(q(1))*cos(q(2))];

A_v = [0;alpha(1);0];
B_v = A_R_B*A_v;