// Michael Meindl, 8.8.2016
#include "MotorControl.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"
#include "ADC.h"

static void initMotorGPIO();
static void initMotorPWM();
static void setTorque(float *torque);

void motorIteration(bool motorState, float* torque)
{
	static bool initDone = false;
	if(false == initDone)
	{
		initMotorGPIO();
		initMotorPWM();
		initDone = true;
	}
	if(true == motorState)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_12);
		setTorque(torque);
	}
	else
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
        float t = 0.0F;
		setTorque(&t);
	}
}
UInt16 getMotorADCValue()
{
    static bool adcInit = false;
    if(false == adcInit)
    {
        adcInit = true;
        initADC();
    }
	return getADCValue();
}
void setTorque(float *torque)
{
	if(*torque > 0.071F)
	{
		*torque = 0.071F;
	}
	else if(*torque < -0.071F)
	{
		*torque = -0.071F;
	}
	if(*torque > 0.0F)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
	}
	else
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_13);
	}
	*torque = *torque > 0.0F ? *torque : -(*torque);
	TIM_SetCompare1(TIM3, (UInt32)((0.1F + (*torque)/0.08875F) * 10000.0F));
}
void initMotorGPIO()
{
	//PWM Pin-B4
	GPIO_InitTypeDef init;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3);
	init.GPIO_Pin		= GPIO_Pin_4;
	init.GPIO_Mode		= GPIO_Mode_AF;
	init.GPIO_OType		= GPIO_OType_PP;
	init.GPIO_PuPd		= GPIO_PuPd_UP;
	init.GPIO_Speed		= GPIO_Speed_100MHz;
	GPIO_Init(GPIOB, &init);
	//GPIO Pin-D12/13
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	init.GPIO_Pin		= GPIO_Pin_12 | GPIO_Pin_13;
	init.GPIO_Mode		= GPIO_Mode_OUT;
	init.GPIO_OType		= GPIO_OType_PP;
	init.GPIO_PuPd		= GPIO_PuPd_NOPULL;
	init.GPIO_Speed		= GPIO_Speed_100MHz;
	GPIO_Init(GPIOD, &init);
}
void initMotorPWM()
{
	TIM_TimeBaseInitTypeDef init;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	init.TIM_CounterMode		= TIM_CounterMode_Up;
	init.TIM_ClockDivision		= TIM_CKD_DIV1;
	init.TIM_RepetitionCounter	= 0;
	init.TIM_Period				= 9999U;
	init.TIM_Prescaler			= 167U;
	TIM_TimeBaseInit(TIM3, &init);

	TIM_OCInitTypeDef ocInit;
	ocInit.TIM_OCMode			= TIM_OCMode_PWM1;
	ocInit.TIM_OutputState		= TIM_OutputState_Enable;
	ocInit.TIM_Pulse			= 1000U;
	ocInit.TIM_OCPolarity		= TIM_OCPolarity_High;
	TIM_OC1Init(TIM3, &ocInit);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
}
