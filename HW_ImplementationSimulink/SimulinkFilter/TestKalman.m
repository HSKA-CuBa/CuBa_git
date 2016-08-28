%27.8.2016, Michael Meindl
%Testen der Berechnungsvorschrift für Kalmanfilter

%Kalman für phi_d
t_a     = 0.02;
phi_filter = ones(size(phi)) * phi(1);
P       = zeros(size(phi));
P(1)    = 0.001;
K       = zeros(size(phi));

for n=7:length(phi)-1
    phi_filter(n+1) = phi_filter(n) + phi__d(n)*t_a;
    P(n+1) = P(n) + var(phi__d(n-6:n)*t_a);
    K(n+1) = P(n+1)  / (P(n+1) + var(phi(n-6:n)));
    phi_filter(n+1) = phi_filter(n+1) + K(n+1)*(phi(n+1)- phi_filter(n+1));
    P(n+1,1) = (1-K(n+1,1))*P(n+1,1);  
end

figure;
plot(t, phi_filter, t, phi, t, phi_kalman, t, phi_comp); grid;

