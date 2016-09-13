//8.9.2016, Michael Meindl
//Class-Declaration to control the motor
#ifndef CMOTORCONTROL_H
#define CMOTORCONTROL_H
#include "CDOUT.h"
#include "CPWM.h"

class CMotorControl
{
public:
	void enableMotor();
	void disableMotor();
	void setTorque(float torque);
public:
	CMotorControl();
	CMotorControl(const CMotorControl&) = delete;
	CMotorControl& operator=(const CMotorControl&) = delete;
	~CMotorControl() = default;
private:
	CDOUT mEnablePin;
	CDOUT mDirectionPin;
	CPWM mTorquePWM;
	static constexpr float sMaxTorque 		= 0.071;
	static constexpr float sMaxDutyCycle 	= 80.0F;
	static constexpr float sDutyCycleOffset = 10.0F;
};

#endif


