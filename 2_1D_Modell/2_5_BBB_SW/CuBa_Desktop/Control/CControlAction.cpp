/**
 * @file	CControlAction.cpp
 * @author	Michael Meindl
 * @date 	5.10.2016
 */
#include "CControlAction.h"
#include <iostream>
using namespace std;

CControlAction::CControlAction() : mProxy(CProxy::getInstance()),
								   mTimerTask(),
								   mTimerThread(&mTimerTask)
{
	mTimerThread.start();
}
bool CControlAction::inBalanceArea()
{
	static bool dummy = true;
	dummy = !dummy;
	return dummy;
}
bool CControlAction::breakingFinished()
{
	static bool dummy = false;
	static int counter = 0;
	counter++;
	if(counter > 3)
	{
		counter = 0;
		dummy = !dummy;
	}
	return dummy;
}
bool CControlAction::isResting()
{
	static bool dummy = false;
	static int counter = 0;
	counter++;
	if(counter > 3)
	{
		counter = 0;
		dummy = !dummy;
	}
	return true;
}
bool CControlAction::jumpVelocityReached()
{
	static bool dummy = false;
	static int counter = 0;
	counter++;
	if(counter > 3)
	{
		counter = 0;
		dummy = !dummy;
	}
	return dummy;
}
void CControlAction::controlIteration()
{
	cout << "[*] Control-FSM: Control-Iteration" << endl;
}
void CControlAction::sampleSensors()
{
	cout << "[*] Control-FSM: Sampling Sensors" << endl;
	const CSensorData& data = mSensorEval.getSensorData();
	mProxy.transmitSensorData(data, false);
}
void CControlAction::sampleADC()
{
	cout << "[*] Control-FSM: Sampling ADC" << endl;
	const CSensorData& data = mSensorEval.getSensorData();
	mProxy.transmitSensorData(data, false);
}
void CControlAction::sampleCPsiIdentification()
{
	cout << "[*] Control-FSM: Sampling CPsi-Identification" << endl;
	mFilter.calculateValues(mSensorEval.getPhi(),
							mSensorEval.getPhi__d(),
							mSensorEval.getPhi__dd(),
							mSensorEval.getPsi__d());
	mProxy.transmitPhi(mFilter.getPhiValues(), false);
	mProxy.transmitPhi__d(mFilter.getPhi__dValues(), false);
	mProxy.transmitPsi__d(mFilter.getPsi__dValues(), false);
}
void CControlAction::sampleCPhiIdentification()
{
	cout << "[*] Control-FSM: Sampling CPhi-Identification" << endl;
	mFilter.calculateValues(mSensorEval.getPhi(),
							mSensorEval.getPhi__d(),
							mSensorEval.getPhi__dd(),
							mSensorEval.getPsi__d());
	mProxy.transmitPhi(mFilter.getPhiValues(), false);
	mProxy.transmitPhi__d(mFilter.getPhi__dValues(), false);
	mProxy.transmitPsi__d(mFilter.getPsi__dValues(), false);
}
void CControlAction::setTorque(Float32 torque)
{
	cout << "[*] Control-FSM: Setting Torque " << torque << endl;
}
void CControlAction::entryWaiting()
{
	cout << "[*] Control-FSM: Entering Waiting" << endl;
}
void CControlAction::exitWaiting()
{
	cout << "[*] Control-FSM: Exiting Waiting" << endl;
}
void CControlAction::entryAccelerating()
{
	cout << "[*] Control-FSM: Entering Accelerating" << endl;
}
void CControlAction::exitAccelerating()
{
	cout << "[*] Control-FSM: Exiting Accelerating" << endl;
}
void CControlAction::entryBraking()
{
	cout << "[*] Control-FSM: Entering Braking" << endl;
}
void CControlAction::exitBraking()
{
	cout << "[*] Control-FSM: Exiting Braking" << endl;
}
void CControlAction::entryIdle()
{
	cout << "[*] Control-FSM: Entering Idle" << endl;
}
void CControlAction::exitIdle()
{
	cout << "[*] Control-FSM: Exiting Idle" << endl;
}
void CControlAction::entryBalancing()
{
	cout << "[*] Control-FSM: Entering Balancing" << endl;
}
void CControlAction::exitBalancing()
{
	cout << "[*] Control-FSM: Exiting Balancing" << endl;
}
void CControlAction::entryStandby()
{
	cout << "[*] Control-FSM: Entering Standby" << endl;
}
void CControlAction::exitStandby()
{
	cout << "[*] Control-FSM: Exiting Standby" << endl;
}
void CControlAction::entrySensorMeasurement()
{
	cout << "[*] Control-FSM: Entering Sensor-Measurement" << endl;
	mTimerTask.resume(true);
}
void CControlAction::exitSensorMeasurement()
{
	cout << "[*] Control-FSM: Exiting Sensor-Measurement" << endl;
	mTimerTask.pause(true);
}
void CControlAction::entryADCMeasurement()
{
	cout << "[*] Control-FSM: Entering ADC-Measurement" << endl;
	mTimerTask.resume(true);
}
void CControlAction::exitADCMeasurement()
{
	cout << "[*] Control-FSM: Exiting ADC-Measurement" << endl;
	mTimerTask.pause(true);
}
void CControlAction::entryCPsiIdentification()
{
	cout << "[*] Control-FSM: Entering CPsi-Identification" << endl;
	mTimerTask.resume(true);
}
void CControlAction::exitCPsiIdentification()
{
	cout << "[*] Control-FSM: Exiting CPsi-Identification" << endl;
	mTimerTask.pause(true);
}
void CControlAction::entryCPhiIdentification()
{
	cout << "[*] Control-FSM: Entering CPhi-Identification" << endl;
	mTimerTask.resume(true);
}
void CControlAction::exitCPhiIdentification()
{
	cout << "[*] Control-FSM: Exiting CPhi-Identification" << endl;
	mTimerTask.pause(true);
}
void CControlAction::entryControlTest()
{
	cout << "[*] Control-FSM: Entering Control-Test" << endl;
	mTimerTask.resume(true);
}
void CControlAction::exitControlTest()
{
	cout << "[*] Control-FSM: Exiting Control-Test" << endl;
	mTimerTask.pause(true);
}
void CControlAction::entryJumpTest()
{
	cout << "[*] Control-FSM: Entering Jump-Test" << endl;
	mTimerTask.resume(true);
}
void CControlAction::exitJumpTest()
{
	cout << "[*] Control-FSM: Exiting Jump-Test" << endl;
	mTimerTask.pause(true);
}
