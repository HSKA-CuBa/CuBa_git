//27.8.2016, Michael Meindl
//Enumeration to represents the FSM-Events
#ifndef EEVENT_H
#define EEVENT_H

enum class EEvent
{
	EV_DEFAULT_IGNORE,
	EV_PHI_IN_BALANCE_AREA,
	EV_PHI_NOT_IN_BALANCE_AREA,
	EV_CUBE_RESTING,
	EV_BRAKING_FINISHED
};

#endif
