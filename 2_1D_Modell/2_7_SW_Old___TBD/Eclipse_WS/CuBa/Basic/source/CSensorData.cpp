//12.9.16, Michael Meindl
#include "CSensorData.h"

CSensorData::CSensorData(Float32 time, Int16 x1_raw__dd,
						 Int16 y1_raw__dd, Int16 phi1_raw__dd,
						 Int16 x2_raw__dd, Int16 y2_raw__dd,
						 Int16 phi2_raw__dd) : mTime(time),
						 	 	 	 	 	 	 mX1_raw__dd(x1_raw__dd),
												 mY1_raw__dd(y1_raw__dd),
												 mPhi1_raw__d(phi1_raw__dd),
												 mX2_raw__dd(x2_raw__dd),
												 mY2_raw__dd(y2_raw__dd),
												 mPhi2_raw__d(phi2_raw__dd)
{

}
Float32 CSensorData::getTime() const
{
	return mTime;
}
Int16 CSensorData::getX1_raw__dd() const
{
	return mX1_raw__dd;
}
Int16 CSensorData::getX2_raw__dd() const
{
	return mX2_raw__dd;
}
Int16 CSensorData::getY1_raw__dd() const
{
	return mY1_raw__dd;
}
Int16 CSensorData::getY2_raw__dd() const
{
	return mY2_raw__dd;
}
Int16 CSensorData::getPhi1_raw__d() const
{
	return mPhi1_raw__d;
}
Int16 CSensorData::getPhi2_raw__d() const
{
	return mPhi2_raw__d;
}
