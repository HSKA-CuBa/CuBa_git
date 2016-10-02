/**
 * @file	CCommFSM.cpp
 * @author	Michael Meindl
 * @date	29.9.2016
 * @brief	Method definitions for CCommFSM.
 */
#include "CCommFSM.h"

CMessage CCommFSM::sInternalQueue;
Int32 CCommFSM::sQueueSize = 0;
CCommFSM::CCommFSM(CProxy& proxy) : mProxy(proxy),
									mAction(proxy),
									mState(STANDBY)
{
	mAction.onEntryStandby();
}
bool CCommFSM::dispatch(CMessage& msg)
{
	bool consumed = false;
	switch(mState)
	{
	case STANDBY:
		consumed = this->onStandby(msg);
		break;
	case RUNNING:
		consumed = this->onRunning(msg);
		break;
	}
	while(sQueueSize != 0)
	{
		sQueueSize = 0;
		switch(mState)
		{
		case STANDBY:
			consumed = this->onStandby(sInternalQueue);
			break;
		case RUNNING:
			consumed = this->onRunning(sInternalQueue);
			break;
		}
	}
	return consumed;
}
bool CCommFSM::onRunning(CMessage& msg)
{
	bool consumed = false;
	EEvent event  = msg.getEvent();
	if(EEvent::EV_TRANSMIT_DATA == event)
	{
		if(mAction.transmitMessage(msg) == false)
		{
			sInternalQueue = CMessage(EEvent::EV_CLIENT_DISCONNECT);
			sQueueSize = 1;
		}
		consumed = true;
	}
	else if(EEvent::EV_CLIENT_DISCONNECT == event)
	{
		mAction.onExitRunning();
		mState = STANDBY;
		mAction.onEntryStandby();
		consumed = true;
	}
	return consumed;
}
bool CCommFSM::onStandby(CMessage& msg)
{
	bool consumed = false;
	EEvent event  = msg.getEvent();
	if(EEvent::EV_CLIENT_CONNECT == event)
	{
		mAction.onExitStandby();
		mState = RUNNING;
		mAction.onEntryRunning();
		consumed = true;
	}
	return consumed;
}
