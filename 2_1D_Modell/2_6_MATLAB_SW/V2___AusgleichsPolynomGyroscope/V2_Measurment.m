%13.9.2016, Michael Meindl

savepath = strcat(pwd, '/datafiles');
n        = 500;

cuba = CCuBa();
cuba.connect();
cuba.mProxy.runSensorMeasurement();

while(length(cuba.mSensorData.mTime) < n)
    ;
end

cuba.disconnect();
saveFile = strcat('sensordata', num2str(phi));
eval(strcat(saveName, ' = cuba.mSensorData;'));
save(strcat('datafiles/', saveFile), saveName);