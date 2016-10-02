/*
 * Cmotor_control.cpp
 *
 *  Created on: 07.05.2016
 *      Author: Alexander Schleicher.
 *
 * PWM PB4 1KHz
 * Freigabe PD12 (grüne LED)
 * Richtung PD13 (orange LED)
 *
 */

#include "Cpwm.h"
#include "Cmotor_control.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

Cmotor_control::Cmotor_control(): mPwm(TIM3, TIM_CHANNEL_1, GPIOB, GPIO_PIN_4, GPIO_AF2_TIM3),
								  mADC(1U),
								  mRelease(false),
								  mTrend(false)
{
	GPIO_Init(GPIOD, UInt16 GPIO_PIN_12);
	GPIO_Init(GPIOD, UInt16 GPIO_PIN_13);
	this->set_torque(0.0F);
}
UInt16 Cmotor_control::getVelocity()
{
	return mADC.getVelocity();
}
void Cmotor_control::set_pwm(float duty_percent)
{
	UInt32 Temp_duty_percent;
	Temp_duty_percent =(duty_percent*1000);
	mPwm.set_pwm_p_direct(Temp_duty_percent);
}
void Cmotor_control::set_turn_on()
{
	set_release_on();
}
void Cmotor_control::set_turn_off()
{
	set_release_off();
	set_pwm(0);
}
void Cmotor_control::set_release_on()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
	mRelease = true;
}
void Cmotor_control::set_release_off()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	mRelease = false;
}
void Cmotor_control::set_trend_positiv()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	mTrend = true;
}
void Cmotor_control::set_trend_negativ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	mTrend = false;
}
bool Cmotor_control::set_torque(float torque)
{
	if ((torque <= 71000) && (torque >= -71000))
	{
		if (torque >= 0)
		{
			set_trend_positiv();
		}else{
			set_trend_negativ();
			torque = torque *(-1);
		}
		mPwm.set_pwm_p_direct((UInt32)(((float)(torque/8875)+1)*10000));
	}else{ //error - Value too big/small
		if (torque >= 71001)
		{
			set_trend_positiv();
			mPwm.set_pwm_p_direct(90000);
			return false; //error - Value too big
		}
		if (torque <= -71001)
		{
			set_trend_negativ();
			mPwm.set_pwm_p_direct(90000);
			return false; //error - Value too small
		}
	}
	return true;

}

void Cmotor_control::GPIO_Init(GPIO_TypeDef* GPIOx, UInt16 GPIO_PIN_x)
{

	//Only Init for release & trend
	__GPIOD_CLK_ENABLE();
	/*define gpios*/
	 mGPIO_InitSt.Pin = GPIO_PIN_x;
	 mGPIO_InitSt.Mode = GPIO_MODE_OUTPUT_PP;
	 mGPIO_InitSt.Pull = GPIO_NOPULL;
	 mGPIO_InitSt.Speed = GPIO_SPEED_HIGH;
	 mGPIO_InitSt.Alternate = 0;



	 HAL_GPIO_Init(GPIOx,&mGPIO_InitSt);
}

