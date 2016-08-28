/*
 * Cservocontrol.h
 *
 *  Created on: 08.05.2016
 *      Author: Alexander Schleicher
 */

#ifndef CSERVO_CONTROL_H_
#define CSERVO_CONTROL_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
#include "global.h"
#include "Cpwm.h"


class Cservo_control {
public:
	Cservo_control();
	~Cservo_control();
	void set_brake_close();
	void set_brake_open();

private:
	UInt32 set_degree(UInt16 degree);
	Cpwm mPwm;
};

#endif /* CSERVO_CONTROL_H_ */
