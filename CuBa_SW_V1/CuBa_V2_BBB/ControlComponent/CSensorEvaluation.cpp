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
void CSensorEvaluation::calculateValues(const Int16 x1_raw__dd,
										const Int16 x2_raw__dd,
										const Int16 y1_raw__dd,
										const Int16 y2_raw__dd,
										const Int16 phi1_raw__d,
										const Int16 phi2_raw__d,
										const UInt16 psi_raw__d)
{
	Float32 x1__dd = static_cast<Float32>(x1_raw__dd) * ControlConfig::X1__dd_P1 +
					 ControlConfig::X1__dd_P2;
	Float32 x2__dd = static_cast<Float32>(x2_raw__dd) * ControlConfig::X2__dd_P1 +
					 ControlConfig::X2__dd_P2;
	Float32 y1__dd = static_cast<Float32>(y1_raw__dd) * ControlConfig::Y1__dd_P1 +
					 ControlConfig::Y1__dd_P2;
	Float32 y2__dd = static_cast<Float32>(y2_raw__dd) * ControlConfig::Y2__dd_P1 +
					 ControlConfig::Y2__dd_P2;
	Float32 phi1__d	= (static_cast<Float32>(phi1_raw__d) + ControlConfig::Phi1__d_P2) *
					   ControlConfig::Phi1__d_P1;
	Float32 phi2__d = (static_cast<Float32>(phi2_raw__d) + ControlConfig::Phi2__d_P2) *
					   ControlConfig::Phi2__d_P1;
	mPsi__d     = static_cast<Float32>(psi_raw__d) * ControlConfig::Psi__d_P1 +
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
