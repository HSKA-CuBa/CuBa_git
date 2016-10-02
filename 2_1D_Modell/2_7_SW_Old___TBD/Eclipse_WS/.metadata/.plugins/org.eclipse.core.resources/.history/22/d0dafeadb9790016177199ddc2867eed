//7.9.16, Michael Meindl
//Method-Definitions to read out the sensor values
#include "CMPU6050.h"
#include "MPU6050Register.h"
#include <stddef.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <unistd.h>
#include <stdlib.h> //exit
#include "ELowPass.h"

CMPU6050::CMPU6050(bool AD0PinLevel) : mFile(-1),
									   mAD0Level(AD0PinLevel),
									   mPadding{0U}
{
	Int32 retVal = -1;
	mFile = open("/dev/i2c-1", O_RDWR);
	sAssertion(mFile < 0, "(CMPU6050::CMPU6050()): Failed to open device.");

	retVal = ioctl(mFile, I2C_SLAVE, mAD0Level ? (MPU6050Register::MPU6050_DEVICE_ADDR + 1U) :
												  MPU6050Register::MPU6050_DEVICE_ADDR);
	sAssertion(retVal < 0, "(CMPU6050::CMPU6050()): Failed to set Slave-Address.");

	this->writeRegister(MPU6050Register::PWR_MGMT_1, 0U);
	this->writeRegister(MPU6050Register::CONFIG, static_cast<UInt8>(ELowPass::BANDWIDTH_44));
}
CMPU6050::~CMPU6050()
{
	Int32 retVal = close(mFile);
	sAssertion(retVal, "(CMPU6050::~CMPU6050()): Failed to close device.");
}
Int16 CMPU6050::getX__dd_raw()
{
	union
	{
		Int16 x__dd_raw;
		UInt8 rawData[2];
	};
	rawData[0] = this->readRegister(MPU6050Register::ACCEL_XOUT_L);
	rawData[1] = this->readRegister(MPU6050Register::ACCEL_XOUT_H);
	return x__dd_raw;
}
Int16 CMPU6050::getY__dd_raw()
{
	union
	{
		Int16 y__dd_raw;
		UInt8 rawData[2];
	};
	rawData[0] = this->readRegister(MPU6050Register::ACCEL_YOUT_L);
	rawData[1] = this->readRegister(MPU6050Register::ACCEL_YOUT_H);
	return y__dd_raw;
}
Int16 CMPU6050::getZ__dd_raw()
{
	union
	{
		Int16 z__dd_raw;
		UInt8 rawData[2];
	};
	rawData[0] = this->readRegister(MPU6050Register::ACCEL_ZOUT_L);
	rawData[0] = this->readRegister(MPU6050Register::ACCEL_ZOUT_H);
	return z__dd_raw;
}
Int16 CMPU6050::getX_angular__d_raw()
{
	union
	{
		Int16 x_angular__d_raw;
		UInt8 rawData[2];
	};
	rawData[0] = this->readRegister(MPU6050Register::GYRO_XOUT_L);
	rawData[1] = this->readRegister(MPU6050Register::GYRO_XOUT_H);
	return x_angular__d_raw;
}
Int16 CMPU6050::getY_angular__d_raw()
{
	union
	{
		Int16 y_angular__d_raw;
		UInt8 rawData[2];
	};
	rawData[0] = this->readRegister(MPU6050Register::GYRO_YOUT_L);
	rawData[1] = this->readRegister(MPU6050Register::GYRO_YOUT_H);
	return y_angular__d_raw;
}
Int16 CMPU6050::getZ_angular__d_raw()
{
	union
	{
		Int16 z_angular__d_raw;
		UInt8 rawData[2];
	};
	rawData[0] = this->readRegister(MPU6050Register::GYRO_ZOUT_L);
	rawData[1] = this->readRegister(MPU6050Register::GYRO_ZOUT_H);
	return z_angular__d_raw;
}
void CMPU6050::writeRegister(const UInt8 registerAddr, const UInt8 value)
{
	Int32 retVal = i2c_smbus_write_byte_data(mFile, registerAddr, 0U);
	sAssertion(retVal < 0, "(CMPU6050::writeRegister()): Failed to write Register.");
}
UInt8 CMPU6050::readRegister(const UInt8 registerAddr)
{
	Int32 retVal = i2c_smbus_write_byte(mFile, registerAddr);
	sAssertion(retVal < 0, "(CMPU6050::readRegister()): Failed to write register address.");

	retVal = i2c_smbus_read_byte(mFile);
	sAssertion(retVal < 0, "(CMPU6050::readRegister()): Failed to read register value.");

	return static_cast<UInt8>(retVal);
}
