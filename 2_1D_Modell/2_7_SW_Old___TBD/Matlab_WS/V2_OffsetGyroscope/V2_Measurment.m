%13.9.16, Michael Meindl

n = 500;
savepath = strcat(pwd, '/datafiles');

client = CClient();
client.run_V2_OffsetGyroscope(n, savepath);