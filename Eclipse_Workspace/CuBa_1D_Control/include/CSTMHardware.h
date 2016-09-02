//27.8.2016, Michael Meindl
//Class to control the hardware on the STM-Board
#ifndef CSTMHARDWARE_H
#define CSTMHARDWARE_H
#include "IHardware.h"
#include "Cmotor_control.h"
#include "Cservo_control.h"
#include "CSensor.h"

class CSTMHardware : public IHardware
{
public:
	Int16 getX1__dd_raw() override;
	Int16 getX2__dd_raw() override;
	Int16 getY1__dd_raw() override;
	Int16 getY2__dd_raw() override;
	Int16 getPhi1__d_raw() override;
	Int16 getPhi2__d_raw() override;
	UInt16 getPsi__d_raw() override;
	void openBrake() override;
	void closeBrake() override;
	void enableMotor() override;
	void disableMotor() override;
	void setTorque(const float toruqe) override;
public:
	CSTMHardware() = default;
	CSTMHardware(const CSTMHardware&) = delete;
	CSTMHardware& operator=(const CSTMHardware&) = delete;
	~CSTMHardware() = default;
private:
	CSensor mSensor;
	Cmotor_control mMotor;
	Cservo_control mServo;
};

#endif
