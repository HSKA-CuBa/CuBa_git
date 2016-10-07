/**
 * @file	CFSMControlTest.cpp
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#include "CFSMControlTest.h"
#include "CMessage.h"

bool CFSMControlTest::onInitial(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sIdle;
		sAction.entryIdle();
		return true;
	}
	return false;
}
bool CFSMControlTest::onIdle(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitIdle();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		if(sAction.inBalanceArea() == true)
		{
			sInternalQueue = CMessage(EEvent::IN_BALANCE_AREA);
			sQueueSize     = 1;
		}
		return true;
	}
	if(EEvent::IN_BALANCE_AREA == event)
	{
		sAction.exitIdle();
		mState = sBalancing;
		sAction.entryBalancing();
		return true;
	}
	return false;
}
bool CFSMControlTest::onBalancing(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitBalancing();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		if(sAction.inBalanceArea() == false)
		{
			sInternalQueue = CMessage(EEvent::IN_IDLE_AREA);
			sQueueSize 	   = 1;
		}
		else
		{
			sAction.controlIteration();
		}
		return true;
	}
	if(EEvent::IN_IDLE_AREA == event)
	{
		sAction.exitBalancing();
		mState = sIdle;
		sAction.entryIdle();
		return true;
	}
	return false;
}
