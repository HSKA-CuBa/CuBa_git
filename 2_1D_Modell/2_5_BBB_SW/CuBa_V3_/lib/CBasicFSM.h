/**
 * @file	CBasicFSM.h
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#ifndef CBASICFSM_H
#define CBASICFSM_H
#include "Global.h"

class CMessage;
class CAction;

class CBasicFSM
{
public:
	bool dispatch(CMessage& msg);
	using StatePtr = bool (CBasicFSM::*)(CMessage& msg);
	void entry();
	void exit();
protected:
	virtual bool onInitial(CMessage& msg) = 0;
public:
	CBasicFSM();
	CBasicFSM(const CBasicFSM&) = delete;
	CBasicFSM& operator=(const CBasicFSM&) = delete;
	virtual ~CBasicFSM() = default;
protected:
	static CMessage sInternalQueue;
	static Int32 sQueueSize;
	static CAction sAction;
	StatePtr mState;
};

#endif
