/**
 * @file	CCommFSM.h
 * @author	Michael Meindl
 * @date	29.9.2016
 * @brief	Class defintion for the comm FSM.
 */
#ifndef CCOMMFSM_H
#define CCOMMFSM_H
#include "CMessage.h"
#include "CCommAction.h"

class CCommFSM
{
public:
	enum EState { STANDBY, RUNNING};
public:
	bool dispatch(CMessage& msg);
private:
	bool onStandby(CMessage& msg);
	bool onRunning(CMessage& msg);
public:
	CCommFSM(CProxy& proxy);
	CCommFSM(const CCommFSM&) = delete;
	CCommFSM& operator=(const CCommFSM&) = delete;
	~CCommFSM() = default;
private:
	static CMessage sInternalQueue;
	static Int32 sQueueSize;
	CProxy& mProxy;
	CCommAction mAction;
	EState mState;
};

#endif
