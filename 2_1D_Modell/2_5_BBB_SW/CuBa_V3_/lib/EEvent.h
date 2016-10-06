/**
 * @file	EEvent.h
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#ifndef EEVENT_H
#define EEVENT_H
#include "Global.h"

enum class EEvent
{
	INGORE 					= 0,
    INIT 					= 1,
	EXIT 					= 2,
	TIMER_TICK 				= 3,
	RUN_EXP1				= 4,
	RUN_EXP2				= 5,
	RUN_EXP3				= 6,
	RUN_EXP4				= 7,
	RUN_EXP5				= 8,
	RUN_EXP6				= 9,
	RUN_EXP7				= 10,
	RUN_CUBA				= 11,
	SET_TORQUE				= 12,
	SET_BALANCE_FLAG		= 13,
	SET_FILTER				= 14,
	SET_PHI_OFFSET			= 15,
	SET_PHI__D_OFFSET		= 16,
	SET_PSI__D_OFFSET		= 17,
	JUMP					= 18,
	IN_BALANCE_AREA			= 19,
	IN_IDLE_AREA			= 20,
	RESTING					= 21,
	MOVING					= 22,
	BRAKING_FINISHED		= 23,
	TX_SENSOR_DATA			= 24,
	TX_PHI_DATA				= 25,
	TX_PHI__D_DATA			= 26,
	TX_PSI__D_DATA			= 27,
	CLIENT_CONNECT			= 28,
	CLIENT_DISCONNECT		= 29,
	JUMP_VELOCITY_REACHED	= 30
};

#endif
