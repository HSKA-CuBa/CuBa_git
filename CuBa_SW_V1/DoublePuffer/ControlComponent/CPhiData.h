/**
 * @file	CPhiData.h
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief	Struct to hold the different values for phi.
 */
#ifndef CPHIDATA_H
#define CPHIDATA_H
#include "Global.h"

struct CPhiData
{
	Float32 mTime;
	Float32 mEstimationValue;
	Float32 mCompValue;
	Float32 mKalmanValue;
	UInt8 mPadding[4];
};

#endif
