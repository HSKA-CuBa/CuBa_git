#ifndef CADC_H
#define CADC_H
#include "Global.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_adc.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_pwr.h"
#include "stm32f4xx_hal_flash.h"


class CAdc
{
public:
	CAdc(uint32_t ADC_x);
	UInt16 getVelocity();

private:
	float mVelocity;
	ADC_HandleTypeDef mAdcHandle;
};

#endif
