#include "CMPU6050.h"
#include "EBit.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"

bool CMPU6050::readRegister(UInt8 registerAddress, UInt8& value)
{
	bool readSuccess = false;
	if(HAL_OK == HAL_I2C_Master_Transmit(&mHandle, mDeviceAddress, &registerAddress, 1U, 1U))
	{
		if(HAL_OK == HAL_I2C_Master_Receive(&mHandle,  EBit::BIT0 | mDeviceAddress, &value, 1U, 1U))
		{
			readSuccess = true;
		}
	}
	return readSuccess;
}
bool CMPU6050::writeRegister(UInt8 registerAddress, UInt8 value)
{
	UInt8 txBuffer[] = {registerAddress, value};
	return HAL_OK == HAL_I2C_Master_Transmit(&mHandle, mDeviceAddress, txBuffer, 2U, 1U);
}
CMPU6050::CMPU6050(bool AD0pinLevel, I2C_HandleTypeDef& handle) : mDeviceAddress(0x68U << 1U),
														  	  	  mHandle(handle)
{
	if(AD0pinLevel == true)
	{
		mDeviceAddress = mDeviceAddress + static_cast<UInt8>(2U);
	}
}
bool CMPU6050::init()
{
	return this->writeRegister(MPU6050::PWR_MGMT_1, 0U);
}
