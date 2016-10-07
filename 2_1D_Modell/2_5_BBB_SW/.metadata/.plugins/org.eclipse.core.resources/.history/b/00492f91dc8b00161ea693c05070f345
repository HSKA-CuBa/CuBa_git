/**
 * @file	CControlFSM.cpp
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#include "CControlFSM.h"
#include "CMessage.h"
#include "CAction.h"

CControlFSM::CControlFSM()
{

}
bool CControlFSM::dispatch(CMessage& msg)
{
	bool consumed = CBasicFSM::dispatch(msg);

	while(sQueueSize != 0)
	{
		CMessage internalEvent = sInternalQueue;
		sQueueSize 			   = 0;
		CBasicFSM::dispatch(internalEvent);
	}
	return consumed;
}
bool CControlFSM::onInitial(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sStandby;
		sAction.onEntryStandby();
		return true;
	}
	else return false;
}
bool CControlFSM::onStandby(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitStandby();
		mState = sInitial;
		return true;
	}
	if(EEvent::RUN_EXP1 == event)
	{
		sAction.onExitStandby();
		mState = sExperiment1;
		sAction.onEntryExperiment1();
		return true;
	}
	if(EEvent::RUN_EXP2 == event)
	{
		sAction.onExitStandby();
		mState = sExperiment2;
		sAction.onEntryExperiment2();
		return true;
	}
	if(EEvent::RUN_EXP3 == event)
	{
		sAction.onExitStandby();
		mState = sExperiment3;
		sAction.onEntryExperiment3();
		return true;
	}
	if(EEvent::RUN_EXP4 == event)
	{
		sAction.onExitStandby();
		mState = sExperiment4;
		sAction.onEntryExperiment4();
		return true;
	}
	if(EEvent::RUN_EXP5 == event)
	{
		sAction.onExitStandby();
		mState = sExperiment5;
		sAction.onEntryExperiment5();
		return true;
	}
	if(EEvent::RUN_EXP6 == event)
	{
		sAction.onExitStandby();
		mState = sCuBa;
		sAction.onEntryCuBa();
		mSuperStateCuBa.entry();
		return true;
	}
	return false;
}
bool CControlFSM::onExperiment1(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitExperiment1();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		sAction.sampleE1();
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.onExitExperiment1();
		mState = sStandby;
		sAction.onEntryStandby();
		return true;
	}
	return false;
}
bool CControlFSM::onExperiment2(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitExperiment2();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		sAction.sampleE2();
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.onExitExperiment2();
		mState = sStandby;
		sAction.onEntryStandby();
		return true;
	}
	return false;
}
bool CControlFSM::onExperiment3(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitExperiment3();
		mState = sStandby;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		sAction.sampleE3();
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.onExitExperiment3();
		mState = sStandby;
		sAction.onEntryStandby();
		return true;
	}
	if(EEvent::SET_TORQUE == event)
	{
		sAction.setTorque(msg.getTorque());
		return true;
	}
	return false;
}
bool CControlFSM::onExperiment4(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitExperiment4();
		mState = sStandby;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		sAction.sampleE4();
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.onExitExperiment5();
		mState = sStandby;
		sAction.onEntryStandby();
		return true;
	}
	if(EEvent::SET_TORQUE == event)
	{
		sAction.setTorque(msg.getTorque());
		return true;
	}
	return false;
}
bool CControlFSM::onExperiment5(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitExperiment5();
		mState = sStandby;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		sAction.sampleE5();
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.onExitExperiment5();
		mState = sStandby;
		return true;
	}
	return false;
}
bool CControlFSM::onCuBa(CMessage& msg)
{
	bool consumed = mSuperStateCuBa.dispatch(msg);

	if(false == consumed)
	{
		EEvent event = msg.getEvent();
		if(EEvent::CLIENT_DISCONNECT == event)
		{
			sAction.onExitCuBa();
			mSuperStateCuBa.exit();
			mState = sStandby;
			sAction.onEntryStandby();
			return true;
		}
	}
	return consumed;
}
