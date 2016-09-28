/**
 * @file	CControlAction.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Class definition for the control action handler.
 */
#include "CControlAction.h"

CControlAction::CControlAction(CProxy& proxy) :
								   mTimerTask(proxy),
								   mTimerThread(&mTimerTask),
								   mProxy(proxy),
								   mSensorData{0.0F},
								   mPhi{0.0F},
								   mPhi__d{0.0F},
								   mPsi__d{0.0F}
{
	mTimerThread.start();
}
void CControlAction::onEntryStandby()
{
	mTimerTask.pause(true);
	mSensorData.mTime 		= 0.0F;
	mSensorData.mX1__dd 	= 0;
	mSensorData.mX2__dd		= 0;
	mSensorData.mY1__dd		= 0;
	mSensorData.mY2__dd		= 0;
	mSensorData.mPhi1__d	= 0;
	mSensorData.mPhi2__d	= 0;
	mSensorData.mPsi__d		= 0;

	mPhi.mTime			= 0.0F;
	mPhi.mEstimation	= 0.0F;
	mPhi.mComplementary = 0.0F;
	mPhi.mKalman		= 0.0F;

	mPhi__d.mTime		= 0.0F;
	mPhi__d.mEstimation	= 0.0F;
	mPhi__d.mKalman		= 0.0F;

	mPsi__d.mTime		= 0.0F;
	mPsi__d.mEstimation = 0.0F;
	mPsi__d.mMean4		= 0.0F;
	mPsi__d.mMean8		= 0.0F;
	mPsi__d.mMean16		= 0.0F;
}
void CControlAction::onExitStandby()
{
	mTimerTask.resume(true);
}
void CControlAction::sampleE1()
{
	mSensorData.mTime 		+= 1.0F;
	mSensorData.mX1__dd 	+= 1;
	mSensorData.mX2__dd		+= 2;
	mSensorData.mY1__dd		+= 3;
	mSensorData.mY2__dd		+= 4;
	mSensorData.mPhi1__d	+= 5;
	mSensorData.mPhi2__d	+= 6;
	mSensorData.mPsi__d		+= 7;
	mProxy.transmitSensorData(mSensorData, false);
}
void CControlAction::sampleE2()
{
	mSensorData.mTime 		+= 1.0F;
	mSensorData.mX1__dd 	+= 1;
	mSensorData.mX2__dd		+= 2;
	mSensorData.mY1__dd		+= 3;
	mSensorData.mY2__dd		+= 4;
	mSensorData.mPhi1__d	+= 5;
	mSensorData.mPhi2__d	+= 6;
	mSensorData.mPsi__d		+= 7;
	mProxy.transmitSensorData(mSensorData, false);
}
void CControlAction::sampleE3()
{
	mSensorData.mTime 		+= 1.0F;
	mSensorData.mX1__dd 	+= 1;
	mSensorData.mX2__dd		+= 2;
	mSensorData.mY1__dd		+= 3;
	mSensorData.mY2__dd		+= 4;
	mSensorData.mPhi1__d	+= 5;
	mSensorData.mPhi2__d	+= 6;
	mSensorData.mPsi__d		+= 7;
	mProxy.transmitSensorData(mSensorData, false);
}
void CControlAction::sampleE4()
{
	mPhi.mTime			+= 1.0F;
	mPhi.mEstimation	+= 2.0F;
	mPhi.mComplementary += 0.5F;
	mPhi.mKalman		+= 3.0F;
	mProxy.transmitPhi(mPhi, false);

	mPhi__d.mTime		+= 1.0F;
	mPhi__d.mEstimation	+= 0.4F;
	mPhi__d.mKalman		+= 0.8F;
	mProxy.transmitPhi__d(mPhi__d, false);

	mPsi__d.mTime		+= 1.0F;
	mPsi__d.mEstimation += 0.3F;
	mPsi__d.mMean4		+= 0.6F;
	mPsi__d.mMean8		+= 0.9F;
	mPsi__d.mMean16		+= 1.2F;
	mProxy.transmitPsi__d(mPsi__d, false);
}
void CControlAction::sampleE5()
{
	mPhi.mTime			+= 1.0F;
	mPhi.mEstimation	+= 2.0F;
	mPhi.mComplementary += 0.5F;
	mPhi.mKalman		+= 3.0F;
	mProxy.transmitPhi(mPhi, false);

	mPhi__d.mTime		+= 1.0F;
	mPhi__d.mEstimation	+= 0.4F;
	mPhi__d.mKalman		+= 0.8F;
	mProxy.transmitPhi__d(mPhi__d, false);

	mPsi__d.mTime		+= 1.0F;
	mPsi__d.mEstimation += 0.3F;
	mPsi__d.mMean4		+= 0.6F;
	mPsi__d.mMean8		+= 0.9F;
	mPsi__d.mMean16		+= 1.2F;
	mProxy.transmitPsi__d(mPsi__d, false);
}
void CControlAction::sampleE6()
{
	//TODO Implement CControlActioN::sampleE6()
}
