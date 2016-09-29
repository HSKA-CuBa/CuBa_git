/**
 * @file	CControlAction.h
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Class definition for a control action handler.
 */
#ifndef CCONTROLACTION_H
#define CCONTROLACTION_H
#include "Global.h"
#include "CMessage.h"
#include "CProxy.h"
#include "CThread.h"
#include "CTimerTask.h"

/**
 * Dummy class for the action handler.
 * This action handler simulates the BBB-Hardware by creating
 * random values for the data fields. This can be used for testing
 * the communication concept in a desktop environment.
 */
class CControlAction
{
public:
	void onEntryStandby();
	void onExitStandby();
	/**
	 * Method to set a fixed motor torque.
	 */
	void setFixTorque(const Float32& torque);
	/**
	 * Method to select a filter,which will is for the LQR-Calculation.
	 */
	void selectFilter(EFilter& filter);
	/**
	 * Method to select the current phi-offset, which is used for the LQR-Calculation.
	 */
	void setPhiOffset(Float32& offset);
	/**
	 * Method to select the current phi__d-offset, which is used for the LQR-Calculation.
	 */
	void setPhi__dOffset(Float32& offset);
	/**
	 * Method to select the current psi__d-offset, which is used for the LQR-Calculation.
	 */
	void setPsi__dOffset(Float32& offset);
	/**
	 * Method to be run each on sample step in experiment 1.
	 */
	void sampleE1();
	/**
	 * Method to be run each on sample step in experiment 2.
	 */
	void sampleE2();
	/**
	 * Method to be run each on sample step in experiment 3.
	 */
	void sampleE3();
	/**
	 * Method to be run each on sample step in experiment 4.
	 */
	void sampleE4();
	/**
	 * Method to be run each on sample step in experiment 5.
	 */
	void sampleE5();
	/**
	 * Method to be run each on sample step in experiment 6.
	 */
	void sampleE6();
public:
	CControlAction(CProxy& proxy);
	CControlAction(const CControlAction&) = delete;
	CControlAction& operator=(const CControlAction&) = delete;
	~CControlAction() = default;
private:
	CTimerTask mTimerTask;
	CThread mTimerThread;
	CProxy& mProxy;
	CSensorData mSensorData;
	CPhi mPhi;
	CPhi__d mPhi__d;
	CPsi__d mPsi__d;

};

#endif
