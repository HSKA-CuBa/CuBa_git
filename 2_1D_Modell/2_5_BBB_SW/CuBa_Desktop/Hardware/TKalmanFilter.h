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
	Float32 calculateValue(const Float32 x, const Float32 x__d);
public:
	TKalmanFilter<n>();
	TKalmanFilter<n>(const TKalmanFilter<n>&) = delete;
	TKalmanFilter<n>& operator=(const TKalmanFilter<n>&) = delete;
	~TKalmanFilter<n>() = default;
private:
	Float32 calculateVarianceX();
	Float32 calculateVarianceX__d();
private:
	Float32 mRecentXValues[n];
	Float32 mRecentX__dValues[n];
	Float32 mP;
	Float32 mK;
	UInt32 mValueIndex;
	bool mInitialRun;
	UInt8 mPadding[3];
};

template<const UInt32 n>
TKalmanFilter<n>::TKalmanFilter() : mRecentXValues{0.0F},
									mRecentX__dValues{0.0F},
									mP(0.0F),
									mK(0.0F),
									mValueIndex(0U),
									mInitialRun(true),
									mPadding{0U}
{

}
template<const UInt32 n>
Float32 TKalmanFilter<n>::calculateValue(const Float32 phi, const Float32 phi__d)
{
	if(true == mInitialRun)
	{
		mInitialRun		= false;
		for(UInt32 index = 0U; index < n; index++)
		{
			mRecentXValues[index] 	= phi;
			mRecentX__dValues[index] 	= phi__d;
		}
	}
	Float32 recentX 			= mRecentXValues[mValueIndex];
	Float32 recentX__d 			= mRecentX__dValues[mValueIndex];
	mValueIndex 				= mValueIndex == n ? 0U : mValueIndex + 1U;
	mRecentXValues[mValueIndex] = recentX + recentX__d * ControlConfig::T_a;
	mP 							= mP + this->calculateVarianceX__d();
	mK 							= mP / ( mP + this->calculateVarianceX());
	mRecentXValues[mValueIndex] = mRecentXValues[mValueIndex] +
									mK * ( phi - mRecentXValues[mValueIndex]);
	mP = (1.0F - mK) * mP;
	return mRecentXValues[mValueIndex];
}
template<const UInt32 n>
Float32 TKalmanFilter<n>::calculateVarianceX()
{
	Float32 phiMean = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phiMean += mRecentXValues[index];
	}
	phiMean /= static_cast<Float32>(n);

	Float32 phiVariance = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phiVariance += (mRecentXValues[index] - phiMean) *
					   (mRecentXValues[index] - phiMean);
	}
	return phiVariance / static_cast<Float32>(n - 1U);
}
template<const UInt32 n>
Float32 TKalmanFilter<n>::calculateVarianceX__d()
{
	Float32 phi__dMean = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phi__dMean += mRecentX__dValues[index];
	}
	phi__dMean = phi__dMean / static_cast<Float32>(n);

	Float32 phi__dVariance = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phi__dVariance += (mRecentXValues[index] - phi__dMean) *
					      (mRecentXValues[index] - phi__dMean) *
						  ControlConfig::T_a * ControlConfig::T_a;
	}
	return phi__dVariance / static_cast<Float32>(n - 1U);
}
#endif
