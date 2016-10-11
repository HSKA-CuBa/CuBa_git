/**
 * @file	CControlAction.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef CCONTROLACTION_H
#define CCONTROLACTION_H
#include "Global.h"
#include "CTimerTask.h"
#include "CThread.h"
#include "CSensorEvaluation.h"
#include "CFilterSystem.h"

class CControlAction
{
public:
	void entryStandby();
	void exitStandby();
	void entrySensorMeasurement();
	void exitSensorMeasurement();
	void entryADCMeasurement();
	void exitADCMeasurement();
	void entryCPsiIdentification();
	void exitCPsiIdentification();
	void entryCPhiIdentification();
	void exitCPhiIdentification();
	void entryControlTest();
	void exitControlTest();
	void entryJumpTest();
	void exitJumpTest();
	void entryIdle();
	void exitIdle();
	void entryBalancing();
	void exitBalancing();
	void entryWaiting();
	void exitWaiting();
	void entryAccelerating();
	void exitAccelerating();
	void entryBraking();
	void exitBraking();

	void sampleSensors();
	void sampleADC();
	void sampleCPsiIdentification();
	void sampleCPhiIdentification();
	void setTorque(Float32 torque);
	void controlIteration();

	bool breakingFinished();
	bool isResting();
	bool jumpVelocityReached();
	bool inBalanceArea();
public:
	CControlAction();
	CControlAction(const CControlAction&) = delete;
	CControlAction& operator=(const CControlAction&) = delete;
	~CControlAction() = default;
private:
	CProxy& mProxy;
	CTimerTask mTimerTask;
	CThread mTimerThread;
	CSensorEvaluation mSensorEval;
	CFilterSystem mFilter;
};


#endif
