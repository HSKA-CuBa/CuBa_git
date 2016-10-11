%12.9.16, Michael Meindl
%Motor is configured as speed controller, the torque pwm now signals the
%target motor velocity

%rpmvalues = [-2500 -1500 -500 500 1500 2500];
rpm        = 500;
rpm_factor = 140000;
torque     = rpm/rpm_factor;

savepath = strcat(pwd, '/datafiles');
n        = 500;

cuba = CCuBa();
cuba.connect();
cuba.mProxy.runADCMeasurement();
cuba.mProxy.setTorque(torque);

while(length(cuba.mSensorData.mTime) < n)
    ;
end

cuba.disconnect();
saveFile = strcat('sensordata___rpm_', num2str(rpm));

if(rpm < 0)
    saveName = strcat('sensordata___rpm_m', num2str(-1*rpm));
else
    saveName = strcat('sensordata___rpm_', num2str(rpm));
end
eval(strcat(saveName, ' = cuba.mSensorData;'));
save(strcat('datafiles/', saveFile), saveName);