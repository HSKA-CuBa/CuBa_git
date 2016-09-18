%18.9.16, Michael Meindl

n = 3000;

client = CClient();
client.run_V6_BestimmungC_phi(n);
savefile = 'datafiles/V6_data';
sensordata = client.mSensorData;
compdata   = client.mCompData;
unfiltereddata = client.mUnfilteredData;
kalmandata     = client.mKalmanData;
save(savefile, 'sensordata', 'compdata', 'unfiltereddata', 'kalmandata');