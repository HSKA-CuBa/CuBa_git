//Michael Meindl, 10.8.2016
#include "ADC.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_adc.h"

static void initADCGPIO();

UInt16 getADCValue()
{
	 ADC_SoftwareStartConv(ADC1);

	 /* wait for end of conversion */
	 while((ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET));

	 return ADC_GetConversionValue(ADC1);
}
void initADC()
{
	initADCGPIO();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	ADC_InitTypeDef init;
	init.ADC_Resolution			= ADC_Resolution_12b;
	init.ADC_ScanConvMode		= DISABLE;
	init.ADC_ContinuousConvMode = DISABLE;
	init.ADC_ExternalTrigConv	= ADC_ExternalTrigConvEdge_None;
	init.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	init.ADC_DataAlign			= ADC_DataAlign_Right;
	init.ADC_NbrOfConversion	= 0;
	ADC_Init(ADC1, &init);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_15Cycles);
	ADC_EOCOnEachRegularChannelCmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE);
	ADC_SoftwareStartConv(ADC1);
}
void initADCGPIO()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef init;
	init.GPIO_Pin 		= GPIO_Pin_0;
	init.GPIO_Mode		= GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &init);
}
