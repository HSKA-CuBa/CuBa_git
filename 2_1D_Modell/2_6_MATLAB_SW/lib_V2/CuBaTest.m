cuba = CCuBa();
cuba.connect();
cuba.mProxy.runSensorMeasurement();
cuba.disconnect();

cuba.connect();
cuba.mProxy.runADCMeasurement();
cuba.mProxy.setTorque(5);
cuba.disconnect();

cuba.connect();
cuba.mProxy.runCPsiIdentification();
cuba.mProxy.setTorque(23);
cuba.disconnect();

cuba.connect();
cuba.mProxy.runCPhiIdentification();
cuba.disconnect();

cuba.connect();
cuba.mProxy.runControlTest();
cuba.disconnect();

cuba.connect();
cuba.mProxy.runJumpTest();
cuba.disconnect();