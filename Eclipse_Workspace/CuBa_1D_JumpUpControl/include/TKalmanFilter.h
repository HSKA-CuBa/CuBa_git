//26.8.2016, Michael Meindl
//Template-Class to calculate the kalman-filtered phi value
#ifndef TKALMANFILTER_H
#define TKALMANFILTER_H
#include "Global.h"
#include "Config.h"

template<const UInt32 n>
class TKalmanFilter
{
public:
	float calculatePhi(const float phi, const float phi__d);
public:
	TKalmanFilter<n>();
	TKalmanFilter<n>(const TKalmanFilter<n>&) = delete;
	TKalmanFilter<n>& operator=(const TKalmanFilter<n>&) = delete;
	~TKalmanFilter<n>() = default;
private:
	float calculateVariancePhi();
	float calculateVariancePhi__d();
private:
	float mRecentPhiValues[n];
	float mRecentPhi__dValues[n];
	float mP;
	float mK;
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
float TKalmanFilter<n>::calculatePhi(const float phi, const float phi__d)
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
	float recentPhi 	= mRecentPhiValues[mValueIndex];
	float recentPhi__d 	= mRecentPhi__dValues[mValueIndex];
	mValueIndex 		= mValueIndex == n ? 0U : mValueIndex + 1U;
	mRecentPhiValues[mValueIndex] = recentPhi + recentPhi__d * Config::T_a;
	mP = mP + this->calculateVariancePhi__d();
	mK = mP / ( mP + this->calculateVariancePhi());
	mRecentPhiValues[mValueIndex] = mRecentPhiValues[mValueIndex] +
									mK * ( phi - mRecentPhiValues[mValueIndex]);
	mP = (1.0F - mK) * mP;
	return mRecentPhiValues[mValueIndex];
}
template<const UInt32 n>
float TKalmanFilter<n>::calculateVariancePhi()
{
	float phiMean = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phiMean += mRecentPhiValues[index];
	}
	phiMean /= static_cast<float>(n);

	float phiVariance = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phiVariance += (mRecentPhiValues[index] - phiMean) *
					   (mRecentPhiValues[index] - phiMean);
	}
	return phiVariance / static_cast<float>(n - 1U);
}
template<const UInt32 n>
float TKalmanFilter<n>::calculateVariancePhi__d()
{
	float phi__dMean = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phi__dMean += mRecentPhi__dValues[index];
	}
	phi__dMean = phi__dMean / static_cast<float>(n);

	float phi__dVariance = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		phi__dVariance += (mRecentPhiValues[index] - phi__dMean) *
					      (mRecentPhiValues[index] - phi__dMean) *
						  Config::T_a * Config::T_a;
	}
	return phi__dVariance / static_cast<float>(n - 1U);
}
#endif
