/************************************************
 * Author: Michael Meindl
 * Datum : 17.04.2016
 ***********************************************/
#ifndef ECOMMEVENT_H
#define ECOMMEVENT_H

enum class ECommEvent
{
	EV_DEFAULT_INITIAL = 0,
	EV_COMM_MSG_RECEIVED = 1,
	EV_TRANSMIT_TORQUE = 2,
	EV_TRANSMIT_PHI_K = 3,
	EV_TRANSMIT_PHI_K_D = 4,
	EV_TRANSMIT_PHI_K_DD = 5,
	EV_TRANSMIT_PHI_R_D = 6,
	EV_TRANSMIT_BRAKE_STATE = 7,
	EV_TRANSMIT_ENTRY_STATE = 8,
	EV_TRANSMIT_UNHANDELD_EV = 9,
	EV_TRANSMIT_VELOCITY = 10,
	EV_TRANSMIT_ANGLE = 11,
	EV_TRANSMIT_USART_SYNCHRO_CHECK = 12
};

#endif
