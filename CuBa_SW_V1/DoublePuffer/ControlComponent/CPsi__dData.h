/**
 * @file	CPsi__dData.h
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief	Struct definition to hold the different values of psi__d.
 */
#ifndef CPSI__DDATA_H
#define CPSI__DDATA_H
#include "Global.h"

struct CPsi__dData
{
	Float32 mTime;
	Float32 mEstimation;
	Float32 mMean4;
	Float32 mMean8;
	Float32 mMean16;
};

#endif
