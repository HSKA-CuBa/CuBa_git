//12.9.16, Michael Meindl
#ifndef CFILTERDATA_H
#define CFILTERDATA_H
#include "Global.h"

/// Container-Class to hold filtered values
class CFilterData
{
public:


private:
	Float32 mTime;		///< Current time.
	Float32 mPhi;		///< Current phi value in SI-Units.
	Float32 mPhi__d;	///< Current phi__d value in SI-Units.
	Float32 mPhi__dd;	///< Current phi__dd value in SI-Units.
};

#endif
