//26.8.16, Michael Meindl
#include "CComplementaryFilter.h"
#include "ControlConfig.h"
#include <cmath>

CComplementaryFilter::CComplementaryFilter() : mFilteredPhi(0.0F),
											   mFilteredPhi__d(0.0F),
											   mRecentPhi_C(0.0F),
											   mRecentPhi_G__d(0.0F),
											   mRecentPhi_A__d(0.0F),
											   mRecentPhi_C__d(0.0F),
											   mFirstRun(true),
											   mPadding{0U}
{

}
void CComplementaryFilter::calculateValues(const Float32 phi,
										   const Float32 phi__d,
										   const Float32 phi__dd)
{
	if(true == mFirstRun)
	{
		///Initial run, use the unfiltered values
		mFirstRun 			= false;
		mRecentPhi_C  		= phi;
		mRecentPhi_G__d  	= phi__d;
		mRecentPhi_A__d		= phi__d;
		mRecentPhi_C__d		= phi__d;
	}
	//Calculate the filtered Phi value
	Float32 firstSummand = mRecentPhi_C  + (ControlConfig::T_a * phi__d);
	mFilteredPhi = ControlConfig::CompAlpha * firstSummand +
					( (1 - ControlConfig::CompAlpha) * phi );
	//Calculate the filtered Phi__d value
	firstSummand 			= mRecentPhi_C__d + phi__d + mRecentPhi_G__d;
	Float32 secondSummand 	= mRecentPhi_A__d + ControlConfig::T_a * phi__dd;
	mFilteredPhi__d			= ControlConfig::CompAlpha * firstSummand +
							  (1 - ControlConfig::CompAlpha) * secondSummand;
	//Save the recent values
	mRecentPhi_C 	= mFilteredPhi;
	mRecentPhi_A__d = secondSummand;
	mRecentPhi_G__d = phi__d;
	mRecentPhi_C__d	= mFilteredPhi__d;
}
Float32 CComplementaryFilter::getFilteredPhi() const
{
	return mFilteredPhi;
}
Float32 CComplementaryFilter::getFilteredPhi__d() const
{
	return mFilteredPhi__d;
}
