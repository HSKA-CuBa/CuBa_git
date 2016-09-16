//12.9.16, Michael Meindl
#ifndef CMOTORDATA_H
#define CMOTORDATA_H
#include "Global.h"

/// Container-Class to hold motor values.
class CMotorData
{
public:
	Float32 getTime() const;
	Float32 getTorque() const;
	Float32 getPsi__d() const;
	Float32 getPsi_raw__d() const;
public:
	/// Constructor to create an instance with valid data.
	CMotorData(Float32 time,
			   Float32 torque,
			   Float32 psi__d,
			   Float32 psi_raw__d);
	CMotorData(const CMotorData&) = default;
	CMotorData& operator=(const CMotorData&) = default;
	~CMotorData() = default;
private:
	Float32 mTime;			///< Current time.
	Float32 mTorque;		///< Current motor torque.
	Float32 mPsi__d;		///< Current motor velocity in SI-Units.
	Float32 mPsi_raw__d;	///< Raw ADC-Values which represent the motor velocity.
};

#endif
