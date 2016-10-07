/**
 * @file	CAction.h
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#ifndef CACTION_H
#define CACTION_H
#include "Global.h"

class CAction
{
public:
	void onEntryStandby();
	void onExitStandby();
	void onEntryExperiment1();
	void onExitExperiment1();
	void onEntryExperiment2();
	void onExitExperiment2();
	void onEntryExperiment3();
	void onExitExperiment3();
	void onEntryExperiment4();
	void onExitExperiment4();
	void onEntryExperiment5();
	void onExitExperiment5();
	void onEntryExperiment6();
	void onExitExperiment6();
	void onEntryExperiment7();
	void onExitExperiment7();
	void onEntryCuBa();
	void onExitCuBa();
	void onEntryIdle();
	void onExitIdle();
	void onEntryBalancing();
	void onExitBalancing();
	void onEntryJumpUp();
	void onExitJumpUp();
	void onEntryWaiting();
	void onExitWaiting();
	void onEntryAccelerating();
	void onExitAccelerating();
	void onEntryBraking();
	void onExitBraking();

	bool isResting();
	bool jumpVelocityReached();
	bool brakingFinished();
	bool inBalanceArea();	void sampleE1();
	void sampleE2();
	void sampleE3();
	void sampleE4();
	void sampleE5();
	void controlIteration();
	void setTorque(Float32 torque);
	void setBalanceFlag(bool flag);
public:
	CAction();
	CAction(const CAction&) = delete;
	CAction& operator=(const CAction&) = delete;
	~CAction() = default;
private:
	bool mBalanceFlag;
};

#endif
