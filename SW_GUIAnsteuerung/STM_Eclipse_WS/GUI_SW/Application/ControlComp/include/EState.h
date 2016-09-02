/************************************************
 * Author: Michael Meindl
 * Datum : 21.04.2016
 ***********************************************/
#ifndef ESTATE_H
#define ESTATE_H

enum class EState
{
	STATE_CONFIFURATION = 0,
	STATE_RUNNING = 1,
	STATE_IDLE = 2,
	STATE_BALANCE = 3,
	STATE_JUMP = 4,
	STATE_WAITING = 5,
	STATE_ACCELERATE = 6,
	STATE_BRAKE = 7
};

#endif
