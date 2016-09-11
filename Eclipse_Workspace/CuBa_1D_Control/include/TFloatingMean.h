//Michael Meindl, 5.9.2016
//Template-Class to calculate floatin mean values
#ifndef TFLOATINGMEAN_H
#define TFLOATINGMEAN_H
#include "Global.h"

template<const UInt32 n>
class TFloatingMean
{
public:
	float calculateValue(float newValue);
public:
	TFloatingMean<n>();
	TFloatingMean<n>(const TFloatingMean<n>&) = delete;
	TFloatingMean<n>& operator=(const TFloatingMean<n>&) = delete;
	~TFloatingMean<n>() = default;
private:
	float mValues[n];
	UInt32 mLastIndex;
};

template<const UInt32 n>
float TFloatingMean<n>::calculateValue(float newValue)
{
	static bool firstRun = true;
	if(true == firstRun)
	{
		for(UInt32 index = 0U; index < n; index++)
		{
			mValues[index] = newValue;
		}
		firstRun = false;
		return newValue;
	}
	mValues[mLastIndex] = newValue;
	mLastIndex = mLastIndex == (n-1U) ? 0U : mLastIndex + 1U;
	float mean = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		mean += mValues[mLastIndex];
	}
	return mean/n;
}
template<const UInt32 n>
TFloatingMean<n>::TFloatingMean() : mValues{0.0F},
									   mLastIndex(0U)
{

}

#endif
