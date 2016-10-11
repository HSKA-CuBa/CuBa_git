/**
 * @file	CFilterSystem.cpp
 * @author	Michael Meindl
 * @date	10.10.2016
 */
#include "CFilterSystem.h"

CFilterSystem::CFilterSystem() : mPhi{0U},
								 mPhi__d{0U},
								 mPsi__d{0U}
{

}
void CFilterSystem::calculateValues(Float32 phi, Float32 phi__d,
					 	 	 	 	Float32 phi__dd, Float32 psi__d)
{
	mPhi.mEstimation 	= phi;
	mPhi.mComplementary = mPhiComp.calculateValues(phi, phi__d);
	mPhi.mKalman		= mPhiKalman.calculateValue(phi, phi__d);

	mPhi__d.mEstimation = phi__d;
	mPhi__d.mKalman		= mPhi__dKalman.calculateValue(phi__d, phi__dd);

	mPsi__d.mEstimation = psi__d;
	mPsi__d.mMean4		= mPsi__dMean4.calculateValue(psi__d);
	mPsi__d.mMean8		= mPsi__dMean8.calculateValue(psi__d);
	mPsi__d.mMean16		= mPsi__dMean16.calculateValue(psi__d);
}
const CPhi& CFilterSystem::getPhiValues() const
{
	return mPhi;
}
const CPhi__d& CFilterSystem::getPhi__dValues() const
{
	return mPhi__d;
}
const CPsi__d& CFilterSystem::getPsi__dValues() const
{
	return mPsi__d;
}
