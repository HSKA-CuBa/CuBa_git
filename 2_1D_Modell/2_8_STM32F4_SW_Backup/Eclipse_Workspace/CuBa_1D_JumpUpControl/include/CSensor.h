#ifndef CSENSOR_H
#define CSENSOR_H
#include "CMPU6050.h"
#include "ELowPass.h"

class CSensor
{
public:
	Int16 getAccX1Raw();
	Int16 getAccY1Raw();
	Int16 getAccX2Raw();
	Int16 getAccY2Raw();
	Int16 getGyrZ1Raw();
	Int16 getGyrZ2Raw();
	Int16 getTemperature();
public:
	CSensor();
	CSensor(const CSensor&) = delete;
	CSensor& operator=(const CSensor&) = delete;
	~CSensor() = default;
private:
	I2C_HandleTypeDef mHandle;
	CMPU6050 mMPU1;
	CMPU6050 mMPU2;
};


#endif
