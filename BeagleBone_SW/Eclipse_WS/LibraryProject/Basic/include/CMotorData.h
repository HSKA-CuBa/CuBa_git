//12.9.16, Michael Meindl
#ifndef CMOTORDATA_H
#define CMOTORDATA_H
#include "Global.h"

/// Container-Class to hold motor values.
class CMotorData
{
public:
public:
	/// Constructor to create an instance with valid data.
	CMotorData(Float32 time,
			   Float32 torque,
			   Float32 psi__d,
			   Float32 psi_raw__dd);
	CMotorData(const CMotorData&) = delete;
	CMotorData& operator=(const CMotorData&) = default;		///< Necessary to copy messages into the queue.
	~CMotorData() = default;
private:
	Float32 mTime;			///< Current time.
	Float32 mTorque;		///< Current motor torque.
	Float32 mPsi__dd;		///< Current motor velocity in SI-Units.
	Float32 mPsi_raw__dd;	///< Raw ADC-Values which represent the motor velocity.
};

#endif
