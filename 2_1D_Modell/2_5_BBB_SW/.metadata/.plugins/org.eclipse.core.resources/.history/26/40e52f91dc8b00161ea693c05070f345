/**
 * @file 	CFSMExperiment7.cpp
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#include "CFSMExperiment7.h"

bool CFSMExperiment7::onInitial(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sWaiting;
		sAction.onEntryWaiting();
		return true;
	}
	return false;
}
bool CFSMExperiment7::onWaiting(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitWaiting();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		if(true == sAction.isResting())
		{
			sInternalQueue = CMessage(EEvent::RESTING);
			sQueueSize 	   = 1;
		}
		return true;
	}
	if(EEvent::RESTING == event)
	{
		sAction.onExitWaiting();
		mState = sAccelerating;
		sAction.onEntryAccelerating();
		return true;
	}
	return false;
}
bool CFSMExperiment7::onAccelerating(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitAccelerating();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		if(false == sAction.isResting())
		{
			sInternalQueue = CMessage(EEvent::MOVING);
			sQueueSize 	   = 1;
		}
		else if(true == sAction.jumpVelocityReached())
		{
			sInternalQueue = CMessage(EEvent::JUMP_VELOCITY_REACHED);
			sQueueSize     = 1;
		}
		return true;
	}
	if(EEvent::MOVING == event)
	{
		sAction.onExitAccelerating();
		mState = sWaiting;
		sAction.onEntryWaiting();
		return true;
	}
	if(EEvent::JUMP_VELOCITY_REACHED == event)
	{
		sAction.onExitAccelerating();
		mState = sBraking;
		sAction.onEntryBraking();
		return true;
	}
	return false;
}
bool CFSMExperiment7::onBraking(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.onExitBraking();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		if(sAction.brakingFinished())
		{
			sInternalQueue = CMessage(EEvent::BRAKING_FINISHED);
			sQueueSize 	   = 1;
		}
		return true;
	}
	return false;
}
