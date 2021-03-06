//12.9.16, Michael Meindl
#ifndef CFILTERDATA_H
#define CFILTERDATA_H
#include "Global.h"

/// Container-Class to hold filtered values
class CFilterData
{
public:
	Float32 getTime() const;
	Float32 getPhi() const;
	Float32 getPhi__d() const;
	Float32 getPhi__dd() const;
public:
	CFilterData(Float32 time,
				Float32 phi,
				Float32 phi__d,
				Float32 phi__dd);
	CFilterData(const CFilterData&) = default;
	CFilterData& operator=(const CFilterData&) = default;
	~CFilterData() = default;
private:
	Float32 mTime;		///< Current time.
	Float32 mPhi;		///< Current phi value in SI-Units.
	Float32 mPhi__d;	///< Current phi__d value in SI-Units.
	Float32 mPhi__dd;	///< Current phi__dd value in SI-Units.
};

#endif
