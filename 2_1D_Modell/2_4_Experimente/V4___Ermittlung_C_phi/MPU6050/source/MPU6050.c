// Autor: Michael Meindl
// Datum: 28.07.2016
// Funktionen zur Initialisierung und Auslesen der Sensoren
#include "MPU6050.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_i2c.h"

#define MPU_BASE_ADDR ((UInt8)(0x68U << 1U))

static void initI2CPins();
static void initI2C();
static void startTransmission(UInt8 address, UInt8 direction);
void writeByte(bool AD0pinLevel, UInt8 registerAddr, UInt8 byte);
UInt8 readByte(bool AD0pinLevel, UInt8 registerAddr);

bool initMPU6050(bool AD0pinLevel, ELowPass lowPassConfig)
{
	initI2C();
	writeByte(AD0pinLevel, PWR_MGMT_1, 0U);
	writeByte(AD0pinLevel, CONFIG, lowPassConfig);
	return readByte(AD0pinLevel, WHO_AM_I) == 0x68U;
}
Int16 readMPU6050_XAcceleration(bool AD0pinLevel)
{
	union SensorData
	{
		Int16 xAcceleration;
		UInt8 bytes[2];
	} xAcc;
	xAcc.xAcceleration = 0;
	xAcc.bytes[0] = readByte(AD0pinLevel, ACCEL_XOUT_L);
	xAcc.bytes[1] = readByte(AD0pinLevel, ACCEL_XOUT_H);
	return xAcc.xAcceleration;
}
Int16 readMPU6050_YAcceleration(bool AD0pinLevel)
{
	union SensorData
	{
		Int16 yAcceleration;
		UInt8 bytes[2];
	} yAcc;
	yAcc.yAcceleration = 0;
	yAcc.bytes[0] = readByte(AD0pinLevel, ACCEL_YOUT_L);
	yAcc.bytes[1] = readByte(AD0pinLevel, ACCEL_YOUT_H);
	return yAcc.yAcceleration;
}
Int16 readMPU6050_ZAcceleration(bool AD0pinLevel)
{
	union SensorData
	{
		Int16 zAcceleration;
		UInt8 bytes[2];
	} zAcc;
	zAcc.zAcceleration = 0;
	zAcc.bytes[0] = readByte(AD0pinLevel, ACCEL_ZOUT_L);
	zAcc.bytes[1] = readByte(AD0pinLevel, ACCEL_ZOUT_H);
	return zAcc.zAcceleration;
}
Int16 readMPU6050_XGyroscope(bool AD0pinLevel)
{
	union SensorData
	{
		Int16 xGyro;
		UInt8 bytes[2];
	} xGyr;
	xGyr.xGyro = 0;
	xGyr.bytes[0] = readByte(AD0pinLevel, GYRO_XOUT_L);
	xGyr.bytes[1] = readByte(AD0pinLevel, GYRO_XOUT_H);
	return xGyr.xGyro;
}
Int16 readMPU6050_YGyroscope(bool AD0pinLevel)
{
	union SensorData
	{
		Int16 yGyro;
		UInt8 bytes[2];
	} yGyr;
	yGyr.yGyro = 0;
	yGyr.bytes[0] = readByte(AD0pinLevel, GYRO_YOUT_L);
	yGyr.bytes[1] = readByte(AD0pinLevel, GYRO_YOUT_H);
	return yGyr.yGyro;
}
Int16 readMPU6050_ZGyroscope(bool AD0pinLevel)
{
	union SensorData
	{
		Int16 zGyro;
		UInt8 bytes[2];
	} zGyr;
	zGyr.zGyro = 0;
	zGyr.bytes[0] = readByte(AD0pinLevel, GYRO_ZOUT_L);
	zGyr.bytes[1] = readByte(AD0pinLevel, GYRO_ZOUT_H);
	return zGyr.zGyro;
}
UInt8 readByte(bool AD0pinLevel, UInt8 registerAddr)
{
	while((I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY)))
	{
		;
	}
	UInt8 deviceAddr = AD0pinLevel ? MPU_BASE_ADDR + 2U : MPU_BASE_ADDR;
	startTransmission(deviceAddr, I2C_Direction_Transmitter);
	I2C_SendData(I2C1, registerAddr);

	startTransmission(deviceAddr+1U, I2C_Direction_Receiver);
	I2C_AcknowledgeConfig(I2C1, DISABLE);
	I2C_GenerateSTOP(I2C1, ENABLE);
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED))
	{
		;
	}
	return I2C_ReceiveData(I2C1);
}
void writeByte(bool AD0pinLevel, UInt8 registerAddr, UInt8 byteValue)
{
	while((I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY)))
	{
		;
	}
	UInt8 deviceAddr = AD0pinLevel ? MPU_BASE_ADDR + 2U : MPU_BASE_ADDR;
	startTransmission(deviceAddr, I2C_Direction_Transmitter);
	I2C_SendData(I2C1, registerAddr);
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
	{
		;
	}
	I2C_SendData(I2C1, byteValue);
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
	{
		;
	}
	I2C_GenerateSTOP(I2C1, ENABLE);
}
void startTransmission(UInt8 address, UInt8 direction)
{
	I2C_GenerateSTART(I2C1, ENABLE);
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
	{
		;
	}
	I2C_Send7bitAddress(I2C1, address, direction);
	if(I2C_Direction_Transmitter == direction)
	{
		while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		{
			;
		}
	}
	else if(I2C_Direction_Receiver == direction)
	{
		while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
		{
			;
		}
	}
}
void initI2CPins()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//CLK fuer Pins aktivieren
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	//Pin-Initialisierung: PB6&PB7, Mode:Alternate Function, Speed:50MHz, OpenDrain/PullUp
	GPIO_InitStruct.GPIO_Pin 	= GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_OD;
	GPIO_InitStruct.GPIO_PuPd 	= GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	//AlternateFunction fuer I2C1 konfigurieren
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_I2C1);
}
void initI2C()
{
	static bool initDone = false;
	if(false == initDone)
	{
		initI2CPins();
		I2C_InitTypeDef I2C_InitStruct;
		//CLK fuer I2C1 aktivieren
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
		//I2C-Initialisierung
		I2C_InitStruct.I2C_ClockSpeed 			= 100000;
		I2C_InitStruct.I2C_Mode 				= I2C_Mode_I2C;
		I2C_InitStruct.I2C_DutyCycle 			= I2C_DutyCycle_2;
		I2C_InitStruct.I2C_OwnAddress1 			= 0x00;
		I2C_InitStruct.I2C_Ack 					= I2C_Ack_Disable;
		I2C_InitStruct.I2C_AcknowledgedAddress 	= I2C_AcknowledgedAddress_7bit;
		I2C_Cmd(I2C1, ENABLE);
		I2C_Init(I2C1, &I2C_InitStruct);
		initDone = true;
	}
}
