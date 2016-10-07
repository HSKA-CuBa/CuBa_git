/**
 * @file	CFSMJump.cpp
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#include "CFSMJump.h"

bool CFSMJump::onInitial(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sWaiting;
		sAction.entryWaiting();
		return true;
	}
	return false;
}
bool CFSMJump::onWaiting(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitWaiting();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		if(sAction.isResting() == true)
		{
			sInternalQueue = CMessage(EEvent::RESTING);
			sQueueSize     = 1;
		}
		return true;
	}
	if(EEvent::RESTING == event)
	{
		sAction.exitWaiting();
		mState = sAccelerating;
		sAction.entryAccelerating();
		return true;
	}
	return false;
}
bool CFSMJump::onAccelerating(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitAccelerating();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		if(sAction.isResting() == false)
		{
			sInternalQueue = CMessage(EEvent::MOVING);
			sQueueSize     = 1;
		}
		else if(sAction.jumpVelocityReached() == true)
		{
			sInternalQueue = CMessage(EEvent::JUMP_VELOCITY_REACHED);
			sQueueSize	   = 1;
		}
		return true;
	}
	if(EEvent::MOVING == event)
	{
		sAction.exitAccelerating();
		mState = sWaiting;
		sAction.entryWaiting();
		return true;
	}
	if(EEvent::JUMP_VELOCITY_REACHED == event)
	{
		sAction.exitAccelerating();
		mState = sBraking;
		sAction.entryBraking();
		return true;
	}
	return false;
}
bool CFSMJump::onBraking(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitBraking();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		if(sAction.breakingFinished() == true)
		{
			sInternalQueue = CMessage(EEvent::BRAKING_FINISHED);
			sQueueSize 	   = 1;
		}
		return true;
	}
	return false;
}
