//7.9.2016, Michael Meindl
//Class-Decalaration to interface a MPU6050-Device
#ifndef CMPU6050_H
#define CMPU6050_H
#include "Global.h"

class CMPU6050
{
public:
	Int16 getX__dd_raw();
	Int16 getY__dd_raw();
	Int16 getZ__dd_raw();
	Int16 getX_angular__d_raw();
	Int16 getY_angular__d_raw();
	Int16 getZ_angular__d_raw();
public:
	CMPU6050(bool AD0PinLevel);
	CMPU6050() = delete;
	CMPU6050(const CMPU6050&) = delete;
	CMPU6050& operator=(const CMPU6050&) = delete;
	~CMPU6050();
private:
	void writeRegister(const UInt8 registerAddr, const UInt8 registerValue);
	UInt8 readRegister(const UInt8 registerAddr);
private:
	Int32 mFile;
	bool mAD0Level;
	UInt8 mPadding[3];
};

#endif
