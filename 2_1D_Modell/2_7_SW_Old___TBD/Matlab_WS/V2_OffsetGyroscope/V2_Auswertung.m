%13.9.16, Michael Meindl

load('datafiles/sensordata');

%Plot the raw values
title    = 'Z-Winkelgeschwindigkeit Sensor 1';
savepath = 'plots/phi1__d';
sensordata.plotPhi1_raw__d(title, savepath);
title    = 'Z-Winkelgeschwindigkeit Sensor 2';
savepath = 'plots/phi2__d';
sensordata.plotPhi2_raw__d(title, savepath);

phi1_polynom_p1 = -0.0076 * degtorad(1);    %Manufacturer factor
phi2_polynom_p1 = -0.0076 * degtorad(1);
phi1_polynom_p2 = -mean(sensordata.mPhi1_raw__d);
phi2_polynom_p2 = -mean(sensordata.mPhi2_raw__d);
