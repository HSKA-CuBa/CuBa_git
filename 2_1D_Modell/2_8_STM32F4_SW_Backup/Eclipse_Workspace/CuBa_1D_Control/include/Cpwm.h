/*
 * cpwm.h
 *
 *  Created on: 06.05.2016
 *  Author: Flo & Alex
 */

#ifndef CPWM_H_
#define CPWM_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
#include "global.h"

class Cpwm
{
public:
	~Cpwm() = default;
	Cpwm(TIM_TypeDef* TIMx, UInt32 TIM_CHANNEL_x, GPIO_TypeDef* GPIOx, UInt16 GPIO_PIN_x, UInt8 GPIO_AFx_TIMx);
	void set_pwm_p_direct(UInt32 duty_on);

private:
	void GPIO_Init(GPIO_TypeDef* GPIOx, UInt16 GPIO_PIN_x, UInt8 GPIO_AFx_TIMx);
	void Timer_PWM_Init(TIM_TypeDef* TIMx, UInt32 Tim_OCMODE_PWMx);

	const UInt32 mPrescaler;
	const UInt16 mPeriod;
	UInt32 mTIM_CHANNEL_x;
	TIM_HandleTypeDef mPWM_Struct;
	TIM_OC_InitTypeDef mStrOutputChannel;
	GPIO_InitTypeDef mGPIO_InitSt;
};

#endif /* CPWM_H_ */
