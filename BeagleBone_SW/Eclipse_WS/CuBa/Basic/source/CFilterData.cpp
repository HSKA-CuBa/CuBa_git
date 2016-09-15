#include "CFilterData.h"

CFilterData::CFilterData(Float32 time,
						 Float32 phi,
						 Float32 phi__d,
						 Float32 phi__dd) : mTime(time),
						 	 	 	 	    mPhi(phi),
											mPhi__d(phi__d),
											mPhi__dd(phi__dd)
{

}
Float32 CFilterData::getTime() const
{
	return mTime;
}
Float32 CFilterData::getPhi() const
{
	return mPhi;
}
Float32 CFilterData::getPhi__d() const
{
	return mPhi__d;
}
Float32 CFilterData::getPhi__dd() const
{
	return mPhi__dd;
}
