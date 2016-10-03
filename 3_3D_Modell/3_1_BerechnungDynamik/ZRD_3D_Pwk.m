w_K     = sym('w_K', [3 1], 'real');
w_R     = sym('w_R', [3 1], 'real');

O_K     = sym('O_K', [3 3], 'real');
O_R     = [sym('O_R1', 'real'), 0, 0;
           0, sym('O_R2', 'real'), 0;
           0, 0, sym('O_R3', 'real')];

T = 1/2 * (w_K'*O_K*w_K + (w_K+w_R)'*O_R*(w_K+w_R));

p_wk1 = diff(T, w_K(1));
p_wk2 = diff(T, w_K(2));
p_wk3 = diff(T, w_K(3));

p_wr1 = diff(T, w_R(1));
p_wr2 = diff(T, w_R(2));
p_wr3 = diff(T, w_R(3));
