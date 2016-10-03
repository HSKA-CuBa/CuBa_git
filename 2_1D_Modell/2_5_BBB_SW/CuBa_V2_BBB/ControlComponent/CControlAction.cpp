/**
 * @file	CControlAction.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Class definition for the control action handler.
 */
#include "CControlAction.h"
#include <iostream>
#include <new>

CControlAction::CControlAction(CProxy& proxy) :
								   mTimerTask(proxy),
								   mTimerThread(&mTimerTask),
								   mProxy(proxy),
								   mTime(0.0),
								   mFilterPhi(EFilter::PHI_NONE),
								   mFilterPhi__d(EFilter::PHI__D_NONE),
								   mFilterPsi__d(EFilter::PSI__D_NONE)
{
	mTimerThread.start();
	mHW.initializeHardware();
}
void CControlAction::setFixTorque(const Float32& torque)
{
	mHW.setTorque(torque);
	std::cout << "[Control-Comp] Setting torque: " << torque << std::endl;
}
void CControlAction::selectFilter(EFilter& filter)
{
	std::cout << "[Control-Comp] Selecting filter: " << static_cast<UInt32>(filter) << std::endl;
	switch(filter)
	{
	case EFilter::PHI_COMP:
	case EFilter::PHI_KALMAN:
	case EFilter::PHI_NONE:
		mFilterPhi = filter;
		break;
	case EFilter::PHI__D_KALMAN:
	case EFilter::PHI__D_NONE:
		mFilterPhi__d = filter;
		break;
	case EFilter::PSI__D_MEAN16:
	case EFilter::PSI__D_MEAN4:
	case EFilter::PSI__D_MEAN8:
	case EFilter::PSI__D_NONE:
		mFilterPsi__d = filter;
		break;
	}
}
void CControlAction::setPhiOffset(Float32& offset)
{
	std::cout << "[Control-Comp] Setting phi-offset: " << offset << std::endl;
	mLQR.setPhiOffset(offset);
}
void CControlAction::setPhi__dOffset(Float32& offset)
{
	std::cout << "[Control-Comp] Setting phi__d-offset: " << offset << std::endl;
	mLQR.setPhi__dOffset(offset);
}
void CControlAction::setPsi__dOffset(Float32& offset)
{
	std::cout << "[Control-Comp] Setting psi__d-offset: " << offset << std::endl;
	mLQR.setPsi__dOffset(offset);
}
void CControlAction::onEntryStandby()
{
	std::cout << "[Control-Comp] Entering STANDBY" << std::endl;
	mTimerTask.pause(true);
	mTime = 0.0F;
	new(&mKalmanPhi)TKalmanFilter<ControlConfig::KalmanVarianceSize>;
	new(&mKalmanPhi__d)TKalmanFilter<ControlConfig::KalmanVarianceSize>;
	new(&mCompFilter)CComplementaryFilter;
	new(&mMean4)TFloatingMean<4>;
	new(&mMean8)TFloatingMean<8>;
	new(&mMean16)TFloatingMean<16>;
	new(&mLQR)CLQR;

	mHW.setTorque(0.0F);
	mHW.disableMotor();
}
void CControlAction::onExitStandby()
{
	std::cout << "[Control-Comp] Exiting STANDBY" << std::endl;
	mTimerTask.resume(true);
	mHW.setTorque(0.0F);
	mHW.disableMotor();
}
void CControlAction::sampleE1()
{
	mHW.fetchValues();
	mTime += ControlConfig::T_a;
	CSensorData sensorData;
	sensorData.mTime		= mTime;
	sensorData.mX1__dd		= mHW.getX1__dd_raw();
	sensorData.mX2__dd		= mHW.getX2__dd_raw();
	sensorData.mY1__dd 		= mHW.getY1__dd_raw();
	sensorData.mY2__dd 		= mHW.getY2__dd_raw();
	sensorData.mPhi1__d		= mHW.getPhi1__d_raw();
	sensorData.mPhi2__d		= mHW.getPhi2__d_raw();
	sensorData.mPsi__d 		= static_cast<Int16>(mHW.getPsi__d_raw());

	mProxy.transmitSensorData(sensorData, false);
}
void CControlAction::sampleE2()
{
	this->sampleE1();
}
void CControlAction::sampleE3()
{
	mHW.enableMotor();
	this->sampleE2();
}
void CControlAction::sampleE4()
{
	mHW.fetchValues();
	mTime += ControlConfig::T_a;

	mSensorEval.calculateValues(mHW.getX1__dd_raw(), mHW.getX2__dd_raw(),
								mHW.getY1__dd_raw(), mHW.getY2__dd_raw(),
								mHW.getPhi1__d_raw(), mHW.getPhi2__d_raw(),
								mHW.getPsi__d_raw());
	CPhi phi;
	phi.mTime 		= mTime;
	phi.mEstimation	= mSensorEval.getPhi();

	CPhi__d phi__d;
	phi__d.mTime		= mTime;
	phi__d.mEstimation  = mSensorEval.getPhi__d();

	CPsi__d psi__d;
	psi__d.mTime 		= mTime;
	psi__d.mEstimation  = mSensorEval.getPsi__d();
	//Calculate the filters
	phi.mKalman		   = mKalmanPhi.calculateValue(phi.mEstimation, phi__d.mEstimation);
	phi.mComplementary = mCompFilter.calculateValues(phi.mEstimation, phi__d.mEstimation);

	phi__d.mKalman     = mKalmanPhi__d.calculateValue(phi__d.mEstimation, mSensorEval.getPsi__d());

	psi__d.mMean4 	   = mMean4.calculateValue(psi__d.mEstimation);
	psi__d.mMean8  	   = mMean8.calculateValue(psi__d.mEstimation);
	psi__d.mMean16 	   = mMean16.calculateValue(psi__d.mEstimation);

	mProxy.transmitPhi(phi, false);
	mProxy.transmitPhi__d(phi__d, false);
	mProxy.transmitPsi__d(psi__d, false);
}
void CControlAction::sampleE5()
{
	this->sampleE4();
}
void CControlAction::sampleE6()
{
	mHW.fetchValues();
	mTime += ControlConfig::T_a;

	mSensorEval.calculateValues(mHW.getX1__dd_raw(), mHW.getX2__dd_raw(),
								mHW.getY1__dd_raw(), mHW.getY2__dd_raw(),
								mHW.getPhi1__d_raw(), mHW.getPhi2__d_raw(),
								mHW.getPsi__d_raw());
	CPhi phi;
	phi.mTime 		= mTime;
	phi.mEstimation	= mSensorEval.getPhi();

	CPhi__d phi__d;
	phi__d.mTime		= mTime;
	phi__d.mEstimation  = mSensorEval.getPhi__d();

	CPsi__d psi__d;
	psi__d.mTime 		= mTime;
	psi__d.mEstimation  = mSensorEval.getPsi__d();
	//Calculate the filters
	phi.mKalman		   = mKalmanPhi.calculateValue(phi.mEstimation, phi__d.mEstimation);
	phi.mComplementary = mCompFilter.calculateValues(phi.mEstimation, phi__d.mEstimation);

	phi__d.mKalman     = mKalmanPhi__d.calculateValue(phi__d.mEstimation, mSensorEval.getPsi__d());

	psi__d.mMean4 	   = mMean4.calculateValue(psi__d.mEstimation);
	psi__d.mMean8  	   = mMean8.calculateValue(psi__d.mEstimation);
	psi__d.mMean16 	   = mMean16.calculateValue(psi__d.mEstimation);

	mProxy.transmitPhi(phi, false);
	mProxy.transmitPhi__d(phi__d, false);
	mProxy.transmitPsi__d(psi__d, false);

	Float32 phiControl = 0.0F;
	switch(mFilterPhi)
	{
	case EFilter::PHI_COMP:
		phiControl = phi.mComplementary;
		break;
	case EFilter::PHI_KALMAN:
		phiControl = phi.mKalman;
		break;
	default:
		phiControl = phi.mEstimation;
		break;
	}
	Float32 phi__dControl = 0.0F;
	switch(mFilterPhi__d)
	{
	case EFilter::PHI__D_KALMAN:
		phi__dControl = phi__d.mKalman;
		break;
	default:
		phi__dControl = phi__d.mEstimation;
		break;
	}
	Float32 psi__dControl = 0.0F;
	switch(mFilterPsi__d)
	{
	case EFilter::PSI__D_MEAN4:
		psi__dControl = psi__d.mMean4;
		break;
	case EFilter::PSI__D_MEAN8:
		psi__dControl = psi__d.mMean8;
		break;
	case EFilter::PSI__D_MEAN16:
		psi__dControl = psi__d.mMean16;
		break;
	default:
		psi__dControl = psi__d.mEstimation;
		break;
	}
	Float32 torque = mLQR.controlIteration(phiControl,
										   phi__dControl,
										   psi__dControl);
	Float32 absPhi = phiControl > 0.0F ? phiControl : -1.0F * phiControl;
	if(absPhi < ControlConfig::PhiBalanceMax)
	{
		mHW.enableMotor();
		mHW.setTorque(torque);
	}
	else
	{
		mHW.disableMotor();
	}
}