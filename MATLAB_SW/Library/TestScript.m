clear all;
client = CClient();
%client.run_V1_AusgleichsPolynomAccelerometer(1000)
%client.run_V2_OffsetGyroscope(1000);
client.run_V3_AusgleichsPolynomMotorADC(1000, 0.005);
%client.run_V4_FilterTest(1000);