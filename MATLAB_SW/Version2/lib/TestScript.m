cuba = CClient();
cuba.mPhi.livePlot();
fopen(cuba.mClient);
cuba.sendCommand(ECommand.CMD_RUN_EXPERIMENT4);

cuba.setPhiOffset(23);
cuba.selectFilter(EFilter.PHI_COMP);
cuba.setPhi__dOffset(21);
cuba.setPsi__dOffset(93);
cuba.setTorque(0.000);

