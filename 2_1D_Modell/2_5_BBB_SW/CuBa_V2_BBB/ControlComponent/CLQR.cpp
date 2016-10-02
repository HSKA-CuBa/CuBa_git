//28.8.9, Michael Meindl
#include "ControlConfig.h"
#include "CLQR.h"

CLQR::CLQR() : mPhiOffset(ControlConfig::PhiBalanceOffset),
			   mPhi__dOffset(ControlConfig::Phi__dOffset),
			   mPsi__dOffset(ControlConfig::Psi__dOffset)
{

}
float CLQR::controlIteration(const float phi, const float phi__d, const float psi__d)
{
	return (ControlConfig::K_phi    * (phi - mPhiOffset)) +
		   (ControlConfig::K_phi__d * (phi__d - mPhi__dOffset)) +
		   (ControlConfig::K_psi__d * (psi__d - mPsi__dOffset));
}
void CLQR::setPhiOffset(Float32& offset)
{
	mPhiOffset = offset;
}
void CLQR::setPhi__dOffset(Float32& offset)
{
	mPhi__dOffset = offset;
}
void CLQR::setPsi__dOffset(Float32& offset)
{
	mPsi__dOffset = offset;
}
