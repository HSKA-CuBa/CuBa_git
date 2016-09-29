// ==========================================================================
//  Copyright © 2016  Christian Steiger  -  All rights reserved
// ==========================================================================

#ifndef BBBHARDWARE_H
#define BBBHARDWARE_H

#include "Global.h"
#include "IHardware.h"
#include "CMpu6050.h"

class CBBBHardware : IHardware
{
public:
	CBBBHardware();
	~CBBBHardware();

	Int16 getX1__dd_raw();
	Int16 getX2__dd_raw();
	Int16 getY1__dd_raw();
	Int16 getY2__dd_raw();
	Int16 getPhi1__d_raw();
	Int16 getPhi2__d_raw();
	UInt16 getPsi__d_raw();

	int initializeHardware();
	int fetchValues();
	void openBrake();
	void closeBrake();
	void enableMotor();
	void disableMotor();
	void setTorque(float torque);

private:
	int sysfsEcho(const char* file, const char* string);
	int initializeGpioPin(UInt8 gpio, UInt8 dir = 1, UInt8 alow = 0);

	UInt16   mPsi;
	 int     mAdcFd;
	CMpu6050 mpu6050[2];
};

#endif
