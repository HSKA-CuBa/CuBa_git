// Autor: Michael Meindl
// Datum: 28.07
// Einfache Funktionen fuer eine LED zum testen von Custom Simulink Bloecken
#include "LED.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

void initLED()
{
	  GPIO_InitTypeDef  GPIO_InitStructure;
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	  // Config PD12 als Digital-Ausgang
	  GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin_12;
	  GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_UP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(GPIOD, &GPIO_InitStructure);
}
void setLED(bool ledState)
{
	ledState ? GPIO_SetBits(GPIOD, GPIO_Pin_12) : GPIO_ResetBits(GPIOD, GPIO_Pin_12);
}
