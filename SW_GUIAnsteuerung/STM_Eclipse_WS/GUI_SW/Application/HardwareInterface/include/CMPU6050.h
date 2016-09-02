#ifndef CMPU6050_H
#define CMPU6050_H
#include "MPU6050.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"

class CMPU6050
{
public:
	CMPU6050(bool AD0pinLevel, I2C_HandleTypeDef& handle);
	bool writeRegister(UInt8 registerAddr, UInt8 value);
	bool readRegister(UInt8 registerAddr, UInt8& value);
	bool init();
public:
	CMPU6050() = delete;
	CMPU6050(const CMPU6050&) = delete;
	CMPU6050& operator=(const CMPU6050) = delete;
	~CMPU6050() = default;
private:
	UInt8 mDeviceAddress;
	UInt8 mPadding[3];
	I2C_HandleTypeDef& mHandle;
};


#endif
