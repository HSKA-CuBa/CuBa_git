%17.9.2016, Michael Meindl
savepath = strcat(pwd, '/datafiles');
n        = 2000;

cuba = CCuBa();
cuba.connect();
cuba.mProxy.runCPhiIdentification();

while(length(cuba.mPhi__d.mTime) < n)
    ;
end

cuba.disconnect();
saveFile = 'phi_data';
phi      = cuba.mPhi;
phi__d   = cuba.mPhi__d;
save(strcat('datafiles/', saveFile), 'phi', 'phi__d');
