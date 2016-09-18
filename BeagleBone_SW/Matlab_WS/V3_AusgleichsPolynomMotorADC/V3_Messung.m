%12.9.16, Michael Meindl
%Motor is configured as speed controller, the torque pwm now signals the
%target motor velocity

%rpmvalues = [-2500 -1500 -500 500 1500 2500];
rpm     = 2500;

n = 1000;

savepath = strcat(pwd, '/datafiles');
client = CClient();
client.run_V3_AusgleichsPolynomMotorADC(n, savepath, rpm);