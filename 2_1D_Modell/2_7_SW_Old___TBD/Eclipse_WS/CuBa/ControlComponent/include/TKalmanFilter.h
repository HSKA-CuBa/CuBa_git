//26.8.2016, Michael Meindl
#ifndef TKALMANFILTER_H
#define TKALMANFILTER_H
#include "Global.h"
#include "ControlConfig.h"

/// Template-Class to filter a data set using the Kalman-Filter.
template<const UInt32 n>
class TKalmanFilter
{
public:
	Float32 calculatePhi(const Float32 phi, const Float32 phi__d);
public:
	TKalmanFilter<n>();
	TKalmanFilter<n>(const TKalmanFilter<n>&) = delete;
	TKalmanFilter<n>& operator=(const TKalmanFilter<n>&) = delete;
	~TKalmanFilter<n>() = default;
private:
	Float32 calculateVariancePhi();
	Float32 calculateVariancePhi__d();
private:
	Float32 mRecentPhiValues[n];
	Float32 mRecentPhi__dValues[n];
	Float32 mP;
	Float32 mK;
	UInt32 mValueIndex;
	bool mInitialRun;
	UInt8 mPadding[3];
};

template<const UInt32 n>
TKalmanFilter<n>::TKalmanFilter() : mRecentPhiValues{0.0F},
									mRecentPhi__dValues{0.0F},
									mP(0.0F),
									mK(0.0F),
									mValueIndex(0U),
									mInitialRun(true),
									mPadding{0U}
{

}
template<const UInt32 n>
Float32 TKalmanFilter<n>::calculatePhi(const Float32 phi, const Float32 phi__d)
{
	if(true == mInitialRun)
	{
		mInitialRun		= false;
		for(UInt32 index = 0U; index < n; index++)
		{
			mRecentPhiValues[index] 	= phi;
			mRecentPhi__dValues[index] 	= phi__d;
		}
	}
	Float32 recentPhi 				= mRecentPhiValues[mValueIndex];
	Float32 recentPhi__d 			= mRecentPhi__dValues[mValueIndex];
	mValueIndex 					= mValueIndex == n ? 0U : mValueIndex + 1U;
	mRecentPhiValues[mValueIndex] 	= recentPhi + recentPhi__d * ControlConfig::T_a;
	mP = mP + this->calculateVariancePhi__d();
	mK = mP / ( mP + this->calculateVariancePhi());
	mRecentPhiValues[mValueIndex] = mRecentPhiValues[mValueIndex] +
									mK * ( phi - mRecentPhiValues[mValueIndex]);
	mP = (1.0F - mK) * mP;
	return mRecentPhiValues[mValueIndex];
}
template<const UInt32 n>
Float32 TKalmanFilter<n>::calculateVariancePhi()
{
	Float32 phiMean = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phiMean += mRecentPhiValues[index];
	}
	phiMean /= static_cast<Float32>(n);

	Float32 phiVariance = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phiVariance += (mRecentPhiValues[index] - phiMean) *
					   (mRecentPhiValues[index] - phiMean);
	}
	return phiVariance / static_cast<Float32>(n - 1U);
}
template<const UInt32 n>
Float32 TKalmanFilter<n>::calculateVariancePhi__d()
{
	Float32 phi__dMean = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phi__dMean += mRecentPhi__dValues[index];
	}
	phi__dMean = phi__dMean / static_cast<Float32>(n);

	Float32 phi__dVariance = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phi__dVariance += (mRecentPhiValues[index] - phi__dMean) *
					      (mRecentPhiValues[index] - phi__dMean) *
						  ControlConfig::T_a * ControlConfig::T_a;
	}
	return phi__dVariance / static_cast<Float32>(n - 1U);
}
#endif