#include "CMotorData.h"

CMotorData::CMotorData(Float32 time,
					   Float32 torque,
					   Float32 psi__d,
					   Float32 psi_raw__d) : mTime(time),
					   	   	   	   	   	     mTorque(torque),
											 mPsi__d(psi__d),
											 mPsi_raw__d(psi_raw__d)
{

}
Float32 CMotorData::getTime() const
{
	return mTime;
}
Float32 CMotorData::getTorque() const
{
	return mTorque;
}
Float32 CMotorData::getPsi__d() const
{
	return mPsi__d;
}
Float32 CMotorData::getPsi_raw__d() const
{
	return mPsi_raw__d;
}
