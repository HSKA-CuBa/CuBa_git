%13.9.2016, Michael Meindl

phi      = -45;
savepath = strcat(pwd, '/datafiles');
n        = 500;

client = CClient();
client.run_V1_AusgleichsPolynomAccelerometer(n, savepath, phi);