/**
 * @file	CFSMExperiment6.cpp
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#include "CFSMExperiment6.h"
#include "CMessage.h"
#include "CAction.h"

bool CFSMExperiment6::onInitial(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sIdle;
		sAction.onEntryIdle();
		return true;
	}
	return false;
}
bool CFSMExperiment6::onIdle(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitExperiment6();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		if(true == sAction.inBalanceArea())
		{
			sInternalQueue = CMessage(EEvent::IN_BALANCE_AREA);
			sQueueSize = 1;
		}
		return true;
	}
	if(EEvent::IN_BALANCE_AREA == event)
	{
		sAction.onExitIdle();
		mState = sBalancing;
		sAction.onEntryBalancing();
	}
	return false;
}
bool CFSMExperiment6::onBalancing(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitExperiment6();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		if(false == sAction.inBalanceArea())
		{
			sInternalQueue = CMessage(EEvent::IN_IDLE_AREA);
			sQueueSize = 1;
		}
		else
		{
			sAction.controlIteration();
		}
	}
	if(EEvent::IN_IDLE_AREA == event)
	{
		sAction.onExitBalancing();
		mState = sIdle;
		sAction.onEntryBalancing();
		return true;
	}
	return false;
}
