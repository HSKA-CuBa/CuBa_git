%13.9.2016, Michael Meindl

phi      = -45;
savepath = strcat(pwd, '/datafiles');
n        = 500;

cuba = CCuBa();
cuba.connect();
cuba.mProxy.runSensorMeasurement();

while(length(cuba.mSensorData.mTime) < n)
    ;
end

cuba.disconnect();
saveFile = strcat('sensordata___phi_', num2str(phi));

if(phi < 0)
    saveName = strcat('sensordata___phi_m', num2str(-1*phi));
else
    saveName = strcat('sensordata___phi_', num2str(phi));
end
eval(strcat(saveName, ' = cuba.mSensorData;'));
save(strcat('datafiles/', saveFile), saveName);
