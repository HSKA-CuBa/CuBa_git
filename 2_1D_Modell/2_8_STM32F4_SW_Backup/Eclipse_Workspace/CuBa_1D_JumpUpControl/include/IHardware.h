//27.8.2016, Michael Meindl
//Interface to seperate the Hardware
#ifndef IHARDWARE_H
#define IHARDWARE_H
#include "Global.h"

class IHardware
{
public:
	virtual UInt16 getX1__dd_raw() = 0;
	virtual UInt16 getX2__dd_raw() = 0;
	virtual UInt16 getY1__dd_raw() = 0;
	virtual UInt16 getY2__dd_raw() = 0;
	virtual UInt16 getPhi1__d_raw() = 0;
	virtual UInt16 getPhi2__d_raw() = 0;
	virtual Int16 getPsi__d_raw() = 0;
	virtual void openBrake() = 0;
	virtual void closeBrake() = 0;
	virtual void enableMotor() = 0;
	virtual void disableMotor() = 0;
	virtual void setTorque(const float torque) = 0;
public:
	IHardware() = default;
	IHardware(const IHardware&) = delete;
	IHardware& operator=(const IHardware&) = delete;
	virtual ~IHardware() = default;
};

#endif
