/************************************************
 * Author: Michael Meindl
 * Datum : 17.04.2016
 ***********************************************/
#ifndef ECONTROLEVENT_H
#define ECONTROLEVENT_H

enum class EControlEvent
{
	EV_DEFAULT_INITIAL = 0,
	EV_START = 1,
	EV_STOP = 2,
	EV_SET_JUMP_FLAG = 3,
	EV_SET_BALANCE_FLAG = 4,
	EV_SET_TRANSMIT_FLAG = 5,
	EV_SET_JUMP_VELOCITY = 6,
	EV_SET_PID_VALUES = 7,
	EV_JUMP = 8,
	EV_BRAKE = 9,
	EV_PHIK_IN_BALANCEAREA = 10,
	EV_PHIK_NOT_IN_BALANCEAREA = 11,
	EV_TIMER = 12,
	EV_INIT = 13,
	EV_EXIT = 14,
	EV_RESTING = 15,
	EV_NOT_RESTING = 16,
	EV_JUMP_VELOCITY_REACHED = 17,
	EV_GET_LOG_DATA = 18,
	EV_USART_SYNCHRO_CHECK = 19
};

#endif
