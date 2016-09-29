/**
 * @file	CControlFSM.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Method definitions for CControlFSM.
 */
#include "CControlFSM.h"

CControlFSM::CControlFSM(CProxy& proxy) : mAction(proxy),
										  mState(STANDBY)
{

}
bool CControlFSM::dispatch(CMessage& msg)
{
	bool consumed = false;
	switch(mState)
	{
	case STANDBY:
		consumed = this->onStandby(msg);
		break;
	case EXPERIMENT1:
		consumed = this->onExperiment1(msg);
		break;
	case EXPERIMENT2:
		consumed = this->onExperiment2(msg);
		break;
	case EXPERIMENT3:
		consumed = this->onExperiment3(msg);
		break;
	case EXPERIMENT4:
		consumed = this->onExperiment4(msg);
		break;
	case EXPERIMENT5:
		consumed = this->onExperiment5(msg);
		break;
	case EXPERIMENT6:
		consumed = this->onExperiment6(msg);
		break;
	}
	if(false == consumed)
	{
		this->handleUnconsumedEvent(msg);
	}
	return consumed;
}
bool CControlFSM::handleUnconsumedEvent(CMessage& msg)
{
	bool consumed = false;
	EEvent event  = msg.getEvent();
	if(EEvent::EV_CMD == event)
	{
		ECommand cmd = msg.getCommand();
		if(ECommand::CMD_SET_FILTER == cmd)
		{
			EFilter filter = msg.getFilter();
			mAction.selectFilter(filter);
			consumed = true;
		}
		else if(ECommand::CMD_SET_PHI_OFFSET == cmd)
		{
			Float32 offset = msg.getOffset();
			mAction.setPhiOffset(offset);
			consumed = true;
		}
		else if(ECommand::CMD_SET_PHI__D_OFFSET == cmd)
		{
			Float32 offset = msg.getOffset();
			mAction.setPhi__dOffset(offset);
			consumed = true;
		}
		else if(ECommand::CMD_SET_PSI__D_OFFSET == cmd)
		{
			Float32 offset = msg.getOffset();
			mAction.setPsi__dOffset(offset);
			consumed = true;
		}
	}
	return consumed;
}
bool CControlFSM::onStandby(CMessage& msg)
{
	bool consumed = false;
	EEvent event  = msg.getEvent();
	if(EEvent::EV_CMD == event)
	{
		ECommand cmd = msg.getCommand();
		if(ECommand::CMD_RUN_EXPERIMENT1 == cmd)
		{
			consumed = true;
			mAction.onExitStandby();
			mState = EXPERIMENT1;
		}
		else if(ECommand::CMD_RUN_EXPERIMENT2 == cmd)
		{
			consumed 	= true;
			mAction.onExitStandby();
			mState 		= EXPERIMENT2;
		}
		else if(ECommand::CMD_RUN_EXPERIMENT3 == cmd)
		{
			consumed 	= true;
			mAction.onExitStandby();
			mState		= EXPERIMENT3;
		}
		else if(ECommand::CMD_RUN_EXPERIMENT4 == cmd)
		{
			consumed 	= true;
			mAction.onExitStandby();
			mState		= EXPERIMENT4;
		}
		else if(ECommand::CMD_RUN_EXPERIMENT5 == cmd)
		{
			consumed	= true;
			mAction.onExitStandby();
			mState		= EXPERIMENT5;
		}
		else if(ECommand::CMD_RUN_EXPERIMENT6 == cmd)
		{
			consumed	= true;
			mAction.onExitStandby();
			mState		= EXPERIMENT6;
		}
	}
	return consumed;
}
bool CControlFSM::onExperiment1(CMessage& msg)
{
	bool consumed = false;
	EEvent event  = msg.getEvent();
	if(EEvent::EV_CLIENT_DISCONNECT == event)
	{
		consumed	= true;
		mState 		= STANDBY;
		mAction.onEntryStandby();
	}
	else if(EEvent::EV_TIMER_TICK == event)
	{
		consumed	= true;
		mAction.sampleE1();
	}
	return consumed;
}
bool CControlFSM::onExperiment2(CMessage& msg)
{
	bool consumed = false;
	EEvent event  = msg.getEvent();
	if(EEvent::EV_CLIENT_DISCONNECT == event)
	{
		consumed 	= true;
		mState		= STANDBY;
		mAction.onEntryStandby();
	}
	else if(EEvent::EV_TIMER_TICK == event)
	{
		consumed 	= true;
		mAction.sampleE2();
	}
	return consumed;
}
bool CControlFSM::onExperiment3(CMessage& msg)
{
	bool consumed = false;
	EEvent event  = msg.getEvent();
	if(EEvent::EV_CLIENT_DISCONNECT == event)
	{
		consumed	= true;
		mState 		= STANDBY;
		mAction.onEntryStandby();
	}
	else if(EEvent::EV_TIMER_TICK == event)
	{
		consumed	= true;
		mAction.sampleE3();
	}
	return consumed;
}
bool CControlFSM::onExperiment4(CMessage& msg)
{
	bool consumed = false;
	EEvent event  = msg.getEvent();
	if(EEvent::EV_CLIENT_DISCONNECT == event)
	{
		consumed	= true;
		mState 		= STANDBY;
		mAction.onEntryStandby();
	}
	else if(EEvent::EV_TIMER_TICK == event)
	{
		consumed	= true;
		mAction.sampleE4();
	}
	return consumed;
}
bool CControlFSM::onExperiment5(CMessage& msg)
{
	bool consumed = false;
	EEvent event  = msg.getEvent();
	if(EEvent::EV_CLIENT_DISCONNECT == event)
	{
		consumed	= true;
		mState 		= STANDBY;
		mAction.onEntryStandby();
	}
	else if(EEvent::EV_TIMER_TICK == event)
	{
		consumed	= true;
		mAction.sampleE5();
	}
	return consumed;
}
bool CControlFSM::onExperiment6(CMessage& msg)
{
	bool consumed = false;
	EEvent event  = msg.getEvent();
	if(EEvent::EV_CLIENT_DISCONNECT == event)
	{
		consumed	= true;
		mState 		= STANDBY;
		mAction.onEntryStandby();
	}
	else if(EEvent::EV_TIMER_TICK == event)
	{
		consumed	= true;
		mAction.sampleE6();
	}
	return consumed;
}
