/**
 * @file	CPhi__dData.h
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief	Struct definition to hold the different phi__d values.
 */
#ifndef CPHI__DDATA_H
#define CPHI__DDATA_H
#include "Global.h"

struct CPhidData
{
	Float32 mTime;
	Float32 mEstimationValue;
	Float32 mKalmanValue;
};

#endif
