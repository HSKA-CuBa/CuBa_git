/**
 * @file EEvent.h
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief Enum definition to represent events.
 */
#ifndef EEVENT_H
#define EEVENT_H
#include "Global.h"

enum class EEvent : UInt8
{
	/**
	 * Default event which is used in standard constructors.
	 */
	EV_DEFAULT_IGNORE = 0,
    /**
     * Event to request the transmission of a data packet to the MATLAB-Application.
     */
    EV_TRANSMIT_DATA = 1,
	/**
	 * Event to represent a CMD received from MATLAB.
	 */
	EV_CMD = 2,
	/**
	 * Event to signal a timer tick, leading to a sampling intervall
	 */
	EV_TIMER_TICK = 3,
	/**
	 * Event to signal that the MATLAB-Client disconnected
	 */
	EV_CLIENT_DISCONNECT = 4
};
#endif
