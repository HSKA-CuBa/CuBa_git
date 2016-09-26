/**
 * @file 	CSensorData.h
 * @author	Michael Meindl
 * @date	26.9.2016
 * @brief	Struct definition to hold the raw data from the sensors.
 */
#ifndef CSENSORDATA_H
#define CSENSORDATA_H
#include "Global.h"

struct CSensorData
{
	Float32 mTime;
	Int16	mX1_raw__dd;
	Int16	mX2_raw__dd;
	Int16	mY1_raw__dd;
	Int16	mY2_raw__dd;
	Int16 	mPhi1_raw__d;
	Int16	mPhi2_raw__d;
	Int16	mPsi_raw__d;
	UInt16 mPadding[1];
};

#endif
