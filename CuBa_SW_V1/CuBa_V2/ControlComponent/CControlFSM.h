/**
 * @file	CControlFSM.h
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Class defintion for the control FSM.
 */
#ifndef CCONTROLFSM_H
#define CCONTROLFSM_H
#include "CMessage.h"
#include "CProxy.h"
#include "CControlAction.h"

class CControlFSM
{
public:
	enum EState { STANDBY, EXPERIMENT1, EXPERIMENT2, EXPERIMENT3, EXPERIMENT4, EXPERIMENT5, EXPERIMENT6 };
public:
	/**
	 * Method to handle messages/events.
	 * param[in] msg	Message to handle.
	 * return			Specifies whether the event was consumed.
	 */
	bool dispatch(CMessage& msg);
private:
	bool onStandby(CMessage& msg);
	bool onExperiment1(CMessage& msg);
	bool onExperiment2(CMessage& msg);
	bool onExperiment3(CMessage& msg);
	bool onExperiment4(CMessage& msg);
	bool onExperiment5(CMessage& msg);
	bool onExperiment6(CMessage& msg);
public:
	CControlFSM(CProxy& proxy);
	CControlFSM(const CControlFSM&) = delete;
	CControlFSM& operator=(const CControlFSM&) = delete;
	~CControlFSM() = default;
private:
	CControlAction mAction;
	EState mState;
};

#endif
