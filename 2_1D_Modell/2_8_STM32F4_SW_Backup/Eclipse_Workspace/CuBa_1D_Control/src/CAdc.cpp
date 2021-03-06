#include "CAdc.h"

constexpr float ADC_P1 = 0.1039F;
constexpr float ADC_P2 = -206.2F;

CAdc::CAdc(uint32_t ADC_x) : mVelocity(0.0)
{
	ADC_ChannelConfTypeDef sConfig;

	if(ADC_x == 1)
	{
		__HAL_RCC_ADC1_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.Pin = GPIO_PIN_0;
		GPIO_InitStructure.Mode =  GPIO_MODE_ANALOG;
		GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
		GPIO_InitStructure.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

		mAdcHandle.Instance = ADC1;
		sConfig.Channel = ADC_CHANNEL_0;
	}
	else if(ADC_x == 2)
	{
		__HAL_RCC_ADC2_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.Pin = GPIO_PIN_1;
		GPIO_InitStructure.Mode =  GPIO_MODE_ANALOG;
		GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
		GPIO_InitStructure.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

		mAdcHandle.Instance = ADC2;
		sConfig.Channel = ADC_CHANNEL_1;

	}
	else if(ADC_x == 3)
	{
		__HAL_RCC_ADC3_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.Pin = GPIO_PIN_2;
		GPIO_InitStructure.Mode =  GPIO_MODE_ANALOG;
		GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
		GPIO_InitStructure.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

		mAdcHandle.Instance = ADC3;
		sConfig.Channel = ADC_CHANNEL_2;
	}

	mAdcHandle.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
	mAdcHandle.Init.Resolution = ADC_RESOLUTION_12B;
	mAdcHandle.Init.ScanConvMode = DISABLE;
	mAdcHandle.Init.ContinuousConvMode = DISABLE;
	mAdcHandle.Init.DiscontinuousConvMode = ENABLE;
	mAdcHandle.Init.NbrOfDiscConversion = 1;
	mAdcHandle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	mAdcHandle.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
	mAdcHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	mAdcHandle.Init.NbrOfConversion = 1;
	mAdcHandle.Init.DMAContinuousRequests = ENABLE;
	mAdcHandle.Init.EOCSelection = DISABLE;

	if(HAL_ADC_Init(&mAdcHandle) != HAL_OK)
	{
		//Proxy-Call ADC-Error
	}

	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_84CYCLES;
	sConfig.Offset = 0;

	if(HAL_ADC_ConfigChannel(&mAdcHandle, &sConfig) != HAL_OK)
	{
		//Proxy-Call ADC-Error
	}

}
UInt16 CAdc::getVelocity()
{
	if(HAL_ADC_Start(&mAdcHandle) == HAL_OK)
	{
		if(HAL_ADC_PollForConversion(&mAdcHandle, 2U) == HAL_OK )
		{
			return HAL_ADC_GetValue(&mAdcHandle);
		}
	}
	return 0U;
}
