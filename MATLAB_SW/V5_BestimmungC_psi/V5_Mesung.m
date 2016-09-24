%17.9.2016, Michael Meindl

torque = 0.002;
n = 1000;
savepath = strcat(pwd, '/datafiles');

client = CClient();
client.run_V5_BestimmungC_psi(n, savepath, torque);
