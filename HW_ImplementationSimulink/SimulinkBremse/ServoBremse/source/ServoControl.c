//Autor : Michael Meindl
//Datum : 4.8.2016
//Implementierung der Funktionen zur Steuerung der Bremse mit Simulink
#include "ServoControl.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"

static void initPWM_GPIO();
static void initPWM_Timer();

void setBrakeState(bool state)
{
	static bool initDone = false;
	if(false == initDone)
	{
		initPWM_GPIO();
		initPWM_Timer();
		initDone = true;
	}

	TIM_SetCompare2(TIM3, state ? 400U : 820U);
}


void initPWM_GPIO()
{
	GPIO_InitTypeDef init;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);
	init.GPIO_Pin		= GPIO_Pin_5;
	init.GPIO_Mode		= GPIO_Mode_AF;
	init.GPIO_OType		= GPIO_OType_PP;
	init.GPIO_PuPd		= GPIO_PuPd_UP;
	init.GPIO_Speed		= GPIO_Speed_100MHz;
	GPIO_Init(GPIOB, &init);
}
void initPWM_Timer()
{
	TIM_TimeBaseInitTypeDef init;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	init.TIM_CounterMode		= TIM_CounterMode_Up;
	init.TIM_ClockDivision		= TIM_CKD_DIV1;
	init.TIM_RepetitionCounter	= 0;
	init.TIM_Period				= 8191U;
	init.TIM_Prescaler			= 205U;
	TIM_TimeBaseInit(TIM3, &init);

	TIM_OCInitTypeDef ocInit;
	ocInit.TIM_OCMode			= TIM_OCMode_PWM1;
	ocInit.TIM_OutputState		= TIM_OutputState_Enable;
	ocInit.TIM_Pulse			= 785U;
	ocInit.TIM_OCPolarity		= TIM_OCPolarity_High;
	TIM_OC2Init(TIM3, &ocInit);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
}
