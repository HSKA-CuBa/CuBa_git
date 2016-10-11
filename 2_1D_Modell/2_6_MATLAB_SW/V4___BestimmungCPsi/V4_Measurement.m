%17.9.2016, Michael Meindl
torque     = 0.002;

savepath = strcat(pwd, '/datafiles');
n        = 1000;

cuba = CCuBa();
cuba.connect();
cuba.mProxy.runCPsiIdentification();
cuba.mProxy.setTorque(torque);

while(length(cuba.mPsi__d.mTime) < n)
    ;
end

cuba.disconnect();
saveFile = 'psi__d';
psi__d   = cuba.mPsi__d;
save(strcat('datafiles/', saveFile), 'psi__d');
