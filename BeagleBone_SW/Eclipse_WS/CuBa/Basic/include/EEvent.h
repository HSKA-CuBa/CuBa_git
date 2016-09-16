//12.9.16, Michael Meindl
#ifndef EEVENT_H
#define EEVENT_H

enum class EEvent : UInt8
{
	EV_DEFAULT_IGNORE = 0,		///< Default event for the standard constructor of the messages.
	EV_REQUEST_RUN = 1,
	EV_REQUEST_STANDBY = 2,
	EV_REQUEST_TX_DATA = 3,
	EV_SET_TORQUE = 4 			///< Event to set the torque/velocity for V3
};

#endif
