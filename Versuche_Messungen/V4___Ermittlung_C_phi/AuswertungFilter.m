%Michael Meindl, Prof. Dr. mult. Florian Roth, 18.08.2016
%Berechnet Kalman-Filter und Komplementärfilter für die Sensorwerte aus V4

mu = 0.140/0.061;
r1 = 0.14;


load('Messwerte\V4_SensorValues');
t       = SensorValues.time;
ta      = t(2)-t(1);
x1__dd  = double(SensorValues.signals(1).values(20:end));
y1__dd  = double(SensorValues.signals(2).values(20:end));
phi1__d = double(SensorValues.signals(3).values(20:end));
x2__dd  = double(SensorValues.signals(4).values(20:end));
y2__dd  = double(SensorValues.signals(5).values(20:end));
phi2__d = double(SensorValues.signals(6).values(20:end));
t       = 0:ta:(size(x1__dd,1)-1)*ta;

x1__dd  = x1__dd * (-5.852e-5) + 0.03477;
x2__dd  = x2__dd * (-4.713e-4) + 0.168;
y1__dd  = y1__dd * (-6.188e-4) + 0.1636;
y2__dd  = y2__dd * (-6.185e-4) + 0.05969;
phi1__d = degtorad((phi1__d - 79) * -0.0076);
phi2__d = degtorad((phi2__d - 161) * -0.0076);

%Komplementärfilter
a           = 0.98;
phi_inc     = zeros(size(phi1__d,1),1);
phi_gyr     = zeros(size(phi1__d,1),1);
%Winkelschätzung
phi         = -atan2(x1__dd - mu*x2__dd, y1__dd - mu*y2__dd);
for n = 1:size(phi,1)
    if(phi(n) < 0)
        phi(n) = degtorad(360)+phi(n);
    end
    phi(n) = phi(n) - degtorad(180);
end

komp_angle  = phi(1)*ones(size(phi1__d,1),1);

for n=2:length(phi1__d)
    phi_inc(n,1) = ta/2*((phi1__d(n,1) + phi1__d(n-1,1))); 
    phi_gyr(n,1) = komp_angle(n-1,1) + phi_inc(n,1);
    komp_angle(n,1) = (a*phi_gyr(n,1) + (1-a) * phi(n));
end

%Kalman für phi
phi_n   = ones(size(phi,1),1) * phi(1);
P       = zeros(size(phi,1),1);
P(1,1)  = 0.001;
K       = zeros(size(phi,1),1);

for n=7:length(phi)-1
    phi_n(n+1,1) = phi_n(n,1) + phi1__d(n,1)*ta;
    P(n+1,1)     = P(n,1) + var(phi1__d(n-6:n)*ta);
    K(n+1,1)     = P(n+1,1) / (P(n+1,1)+var(phi(n-6:n)));
    phi_n(n+1,1) = phi_n(n+1,1) + K(n+1,1)*((phi(n+1,1) - phi_n(n+1,1)));
    P(n+1,1)     = (1-K(n+1,1))*P(n+1,1);
end


plot(t, radtodeg(phi), t, radtodeg(komp_angle), t, radtodeg(phi_n)); grid;
legend('Winkelschätzung', 'Komplementärfilter', 'Kalman-Filter');
xlabel('Zeit [s]'); ylabel('$\varphi$ [$\circ$]', 'interpreter', 'latex');
title('Vergleich der Filter');

%Kalman für phi_d
phi__dd     = x1__dd / r1;
phi__d_t     = (x1__dd / r1)*ta;

phi__d_n    = ones(size(phi)) * phi1__d(1);
P           = zeros(size(phi));
P(1,1)      = 0.001;
K           = zeros(size(phi));

phi1__dd_dif = 1/ta * diff(phi1__d);
phi1__dd_dif = [phi1__dd_dif; phi1__dd_dif(end)];

for n=7:length(phi)-1
    phi__d_n(n+1)   = phi__d_n(n,1) + phi__dd(n,1)*ta;
    P(n+1)          = P(n) + var(phi__dd(n-6:n)*ta);
    K(n+1)          = P(n+1) / (P(n+1) + var(phi1__d(n-6:n)));
    phi__d_n(n+1)   = phi__d_n(n+1) + K(n+1)*(phi1__d(n+1) - phi__d_n(n+1));
    P(n+1)          = (1-K(n+1))*P(n+1);
end

%Save Filtervalues
phi     = phi_n;
phi__d  = phi1__d;


saveFile = 'Messwerte\Filterwerte';
save(saveFile, 'phi', 'phi__d', 'phi__dd', 't');