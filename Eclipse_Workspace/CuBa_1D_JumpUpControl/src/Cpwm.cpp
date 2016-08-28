/*
 * Cpwm.cpp
 *
 *  Created on: 06.05.2016
 *      Author: Flo & Alex
 */

#include "Cpwm.h"
#include "global.h"

Cpwm::Cpwm(TIM_TypeDef* TIMx, UInt32 TIM_CHANNEL_x, GPIO_TypeDef* GPIOx, UInt16 GPIO_PIN_x, UInt8 GPIO_AFx_TIMx):mPrescaler(205), mPeriod(8191), mTIM_CHANNEL_x(0) //mFrequenz(0)
{
	mTIM_CHANNEL_x = TIM_CHANNEL_x;

	switch (reinterpret_cast<UInt32>(TIMx))
	{
	case reinterpret_cast<UInt32>(TIM1):
		__TIM1_CLK_ENABLE();
	break;
	case reinterpret_cast<UInt32>(TIM2):
			__TIM2_CLK_ENABLE();
	break;
	case reinterpret_cast<UInt32>(TIM3):
			__TIM3_CLK_ENABLE();
	break;
	default:
		break;
	}

	switch(reinterpret_cast<UInt32>(GPIOx))
	{
	case reinterpret_cast<UInt32>(GPIOA):
			__GPIOA_CLK_ENABLE();
	break;
	case reinterpret_cast<UInt32>(GPIOB):
			__GPIOB_CLK_ENABLE();
	break;
	case reinterpret_cast<UInt32>(GPIOC):
			__GPIOC_CLK_ENABLE();
	break;
	case reinterpret_cast<UInt32>(GPIOD):
			__GPIOD_CLK_ENABLE();
	break;
	default:
		break;
	}
	Timer_PWM_Init(TIMx, TIM_OCMODE_PWM1);
	GPIO_Init(GPIOx, GPIO_PIN_x, GPIO_AFx_TIMx);
}
void Cpwm::Timer_PWM_Init(TIM_TypeDef* TIMx, UInt32 Tim_OCMODE_PWMx)
{
	 /*define and init TIMx!*/
	 mPWM_Struct.Instance=TIMx;
	 mPWM_Struct.Init.Prescaler=mPrescaler;
	 mPWM_Struct.Init.CounterMode=TIM_COUNTERMODE_UP;
	 mPWM_Struct.Init.Period=mPeriod;
	 mPWM_Struct.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	 mPWM_Struct.Init.RepetitionCounter=0;

	 HAL_TIM_Base_Init(&mPWM_Struct);
	 HAL_TIM_PWM_Init(&mPWM_Struct);

	 /*define PWM output!*/
	 mStrOutputChannel.OCMode=Tim_OCMODE_PWMx;
	 mStrOutputChannel.OCIdleState=TIM_OCIDLESTATE_SET;
	 mStrOutputChannel.OCNIdleState=TIM_OCNIDLESTATE_RESET;
	 mStrOutputChannel.OCPolarity=TIM_OCPOLARITY_HIGH;
	 mStrOutputChannel.OCNPolarity=TIM_OCPOLARITY_HIGH;
	 mStrOutputChannel.OCFastMode=TIM_OCFAST_DISABLE;
	 mStrOutputChannel.Pulse = 0;

	 HAL_TIM_PWM_ConfigChannel(&mPWM_Struct,&mStrOutputChannel,mTIM_CHANNEL_x);

	 /*start pwm*/
	 HAL_TIM_PWM_Start(&mPWM_Struct,mTIM_CHANNEL_x);
}

void Cpwm::GPIO_Init(GPIO_TypeDef* GPIOx, UInt16 GPIO_PIN_x, UInt8 GPIO_AFx_TIMx)
{
	/*define gpios*/
	 mGPIO_InitSt.Pin = GPIO_PIN_x;
	 mGPIO_InitSt.Mode = GPIO_MODE_AF_PP;  					/*alternade mode for PWM*/
	 mGPIO_InitSt.Pull = GPIO_PULLUP; 						/*no pull up nor pull down!*/
	 mGPIO_InitSt.Speed = GPIO_SPEED_HIGH;
	 mGPIO_InitSt.Alternate = GPIO_AFx_TIMx;

	 HAL_GPIO_Init(GPIOx,&mGPIO_InitSt);
}

void Cpwm::set_pwm_p_direct(UInt32 duty_on)
{
	UInt32 bTemp_duty_on;
	bTemp_duty_on = (UInt32)(((float)(duty_on)/(100000-1))*mPeriod);
	mStrOutputChannel.Pulse = bTemp_duty_on;
	HAL_TIM_PWM_ConfigChannel(&mPWM_Struct,&mStrOutputChannel,mTIM_CHANNEL_x);
	HAL_TIM_PWM_Start(&mPWM_Struct,mTIM_CHANNEL_x);
}
