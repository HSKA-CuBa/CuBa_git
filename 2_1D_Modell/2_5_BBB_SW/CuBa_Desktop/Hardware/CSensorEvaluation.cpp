//13.9.16, Michael Meindl
#include "CSensorEvaluation.h"
#include "ControlConfig.h"
#include <cmath>

CSensorEvaluation::CSensorEvaluation() : mPhi(0.0F),
										 mPhi__d(0.0F),
										 mPhi__dd(0.0F),
										 mPsi__d(0.0F)
{

}
void CSensorEvaluation::calculateValues()
{
	mSensorData.mX1__dd 	= mHW.getX1_raw__dd();
	mSensorData.mX2__dd 	= mHW.getX2_raw__dd();
	mSensorData.mY1__dd 	= mHW.getY1_raw__dd();
	mSensorData.mY2__dd 	= mHW.getY2_raw__dd();
	mSensorData.mPhi1__d 	= mHW.getPhi1_raw__d();
	mSensorData.mPhi2__d	= mHW.getPhi2_raw__d();
	mSensorData.mPsi__d 	= mHW.getPsi_raw__d();
	Float32 x1__dd = static_cast<Float32>(mSensorData.mX1__dd) * ControlConfig::X1__dd_P1 +
					 ControlConfig::X1__dd_P2;
	Float32 x2__dd = static_cast<Float32>(mSensorData.mX2__dd) * ControlConfig::X2__dd_P1 +
					 ControlConfig::X2__dd_P2;
	Float32 y1__dd = static_cast<Float32>(mSensorData.mY1__dd) * ControlConfig::Y1__dd_P1 +
					 ControlConfig::Y1__dd_P2;
	Float32 y2__dd = static_cast<Float32>(mSensorData.mY2__dd) * ControlConfig::Y2__dd_P1 +
					 ControlConfig::Y2__dd_P2;
	Float32 phi1__d	= (static_cast<Float32>(mSensorData.mPhi1__d) + ControlConfig::Phi1__d_P2) *
					   ControlConfig::Phi1__d_P1;
	Float32 phi2__d = (static_cast<Float32>(mSensorData.mPhi2__d) + ControlConfig::Phi2__d_P2) *
					   ControlConfig::Phi2__d_P1;
	mPsi__d     = static_cast<Float32>(mSensorData.mPsi__d) * ControlConfig::Psi__d_P1 +
					ControlConfig::Psi__d_P2;

	mPhi		= -atan2f(x1__dd - (ControlConfig::SensorAlpha * x2__dd),
						  y1__dd - (ControlConfig::SensorAlpha * y2__dd));
	mPhi__d		= (phi1__d + phi2__d) / 2.0F;
	mPhi__dd 	= (x1__dd - x2__dd) / (ControlConfig::R_S1 - ControlConfig::R_S2);
}
Float32 CSensorEvaluation::getPhi() const
{
	return mPhi;
}
Float32 CSensorEvaluation::getPhi__d() const
{
	return mPhi__d;
}
Float32 CSensorEvaluation::getPhi__dd() const
{
	return mPhi__dd;
}
Float32 CSensorEvaluation::getPsi__d() const
{
	return mPsi__d;
}
const CSensorData& CSensorEvaluation::getSensorData() const
{
	return mSensorData;
}
