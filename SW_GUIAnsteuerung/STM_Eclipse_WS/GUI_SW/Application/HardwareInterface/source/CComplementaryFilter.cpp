//26.8.2016, Michael Meindl
//Defintions in order to filter the phi value
#include "CComplementaryFilter.h"
#include "Config.h"
#include "math.h"

CComplementaryFilter::CComplementaryFilter() : mRecentPhi(0.0F),
											   mRecentPhi__d(0.0F),
											   mFirstRun(true),
											   mPadding{0U}
{

}
float CComplementaryFilter::calculatePhi(const float phi, const float phi__d)
{
	if(true == mFirstRun)
	{
		mFirstRun 		= false;
		mRecentPhi 		= phi;
		mRecentPhi__d	= phi__d;
	}
	float phi_int 	= mRecentPhi + ((Config::T_a / 2.0F) * (mRecentPhi__d + phi__d));
	mRecentPhi		= (Config::ComplementaryAlpha * phi_int) +
					  ((1.0F - Config::ComplementaryAlpha) *  phi);
	mRecentPhi__d 	= phi__d;
	return mRecentPhi;
}
