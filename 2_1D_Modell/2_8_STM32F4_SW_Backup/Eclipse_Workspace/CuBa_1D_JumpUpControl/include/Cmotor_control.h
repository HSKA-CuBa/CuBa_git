/*
 * Cmotor_control.h
 *
 *  Created on: 07.05.2016
 *      Author: Alexander Schleicher
 */

#ifndef CMOTOR_CONTROL_H_
#define CMOTOR_CONTROL_H_
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
#include "global.h"
#include "Cpwm.h"
#include "CAdc.h"

class Cmotor_control {
public:
	Cmotor_control();
	~Cmotor_control() = default;
	void set_turn_on();
	void set_turn_off();
	bool set_torque(float torque);  //MikroNm
	UInt16 getVelocity();
private:
	void set_pwm(float duty_percent);
	void set_release_on();			//PD12 green led
	void set_release_off();
	void set_trend_positiv();		//PD13 orange led
	void set_trend_negativ();
	void GPIO_Init(GPIO_TypeDef* GPIOx, UInt16 GPIO_PIN_x);
	GPIO_InitTypeDef mGPIO_InitSt;
	Cpwm mPwm;
	CAdc mADC;
	bool mRelease;
	bool mTrend;
};

#endif /* CMOTOR_CONTROL_H_ */
