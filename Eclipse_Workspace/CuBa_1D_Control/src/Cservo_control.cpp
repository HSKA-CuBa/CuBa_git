/*
 * Cservocontrol.cpp
 *
 * Created on: 08.05.2016
 * Author: Alexander Schleicher
 */

#include "Cservo_control.h"

Cservo_control::Cservo_control() : mPwm(TIM3, TIM_CHANNEL_2, GPIOB, GPIO_PIN_5, GPIO_AF2_TIM3)
{
    set_brake_open();
}

Cservo_control::~Cservo_control() {}

void Cservo_control::set_brake_close()
{
    //nearly close
    //90 complete close
    mPwm.set_pwm_p_direct(set_degree(90));
}

void Cservo_control::set_brake_open()
{
    //10 far open
    //40 good
    //50 too much
    //45 very scarce - sufficient (almost touching)
    mPwm.set_pwm_p_direct(set_degree(40));
}

UInt32 Cservo_control::set_degree(UInt16 degree)
{
    if ((degree >= 0U) && (degree <= 160U))
    {
        return (11470 - (47*degree));
    }else{
        return 0;
    }
}
