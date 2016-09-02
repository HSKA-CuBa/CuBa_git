/************************************************
 * Author: Michael Meindl
 * Datum : 17.04.2016
 ***********************************************/
#include "CMessage.h"
#include "CStateJump.h"
#include "CControlActionHandler.h"

CStateJump::CStateJump(CControlActionHandler& actionHandler) :
							CBasicFSM(actionHandler, ON_DEFAULT_INITIAL_JUMP) {}
bool CStateJump::onInitial(const CMessage& msg)
{
	bool eventConsumed = false;
	EControlEvent event = msg.getControlEvent();
	switch (event)
	{
		case EControlEvent::EV_INIT:
		{
			mAction.onEntryJump();
			mAction.onEntryWaiting();
			mState = ON_WAITING;
			eventConsumed = true;
			break;
		}
		default:
			break;
	}
	return eventConsumed;
}

bool CStateJump::onWaiting(const CMessage& msg)
{
	bool eventConsumed = false;
	EControlEvent event = msg.getControlEvent();
	switch (event)
	{
		case EControlEvent::EV_EXIT:
		{
			mAction.onExitWaiting();
			mAction.onExitJump();
			mState = ON_DEFAULT_INITIAL_JUMP;
			eventConsumed = true;
			break;
		}
		case EControlEvent::EV_RESTING:
		{
			mAction.onExitJump();
			mState = ON_ACCELERATE;
			mAction.onEntryAccelerate();
			eventConsumed = true;
			break;
		}
		case EControlEvent::EV_TIMER:
		{
			if(mAction.cubeIsResting())
			{
				sInternalQueue = CMessage(EComponentID::CONTROL_COMP,
										  EComponentID::CONTROL_COMP,
										  EControlEvent::EV_RESTING);
				sQueueLength++;
			}
			eventConsumed = true;
			break;
		}
		default:
			break;
	}
	return eventConsumed;
}


bool CStateJump::onAccelerate(const CMessage& msg)
{
	bool eventConsumed = false;
	EControlEvent event = msg.getControlEvent();
	switch (event)
	{
		case EControlEvent::EV_EXIT:
		{
			mAction.onExitAccelerate();
			mAction.onExitJump();
			mState = ON_DEFAULT_INITIAL_JUMP;
			eventConsumed = true;
			break;
		}
		case EControlEvent::EV_NOT_RESTING :
		{
			mAction.onExitJump();
			mState = ON_WAITING;
			mAction.onEntryWaiting();
			eventConsumed = true;
			break;
		}
		case EControlEvent::EV_JUMP_VELOCITY_REACHED:
		{
			mAction.onExitJump();
			mState = ON_BRAKE;
			mAction.onEntryBrake();
			eventConsumed = true;
			break;
		}
		case EControlEvent::EV_TIMER:
		{
			if(mAction.cubeIsResting())
			{
				if(mAction.jumpVelocityReached())
				{
					sInternalQueue = CMessage(EComponentID::CONTROL_COMP,
											  EComponentID::CONTROL_COMP,
											  EControlEvent::EV_JUMP_VELOCITY_REACHED);
					sQueueLength++;
				}
			}
			else
			{
				sInternalQueue = CMessage(EComponentID::CONTROL_COMP,
										  EComponentID::CONTROL_COMP,
										  EControlEvent::EV_NOT_RESTING);
				sQueueLength++;
			}
			eventConsumed = true;
			break;
		}
		default:
			break;
	}
	return eventConsumed;
}

bool CStateJump::onBrake(const CMessage& msg)
{
	bool eventConsumed = false;
	EControlEvent event = msg.getControlEvent();
	switch (event)
	{
		case EControlEvent::EV_EXIT:
		{
			mAction.onExitBrake();
			mAction.onExitJump();
			mState = ON_DEFAULT_INITIAL_JUMP;
			eventConsumed = true;
			break;
		}
		case EControlEvent::EV_TIMER:
		{
			if(mAction.breakingFinished())
			{
				sInternalQueue = CMessage(EComponentID::CONTROL_COMP,
										  EComponentID::CONTROL_COMP,
										  EControlEvent::EV_BRAKE);
				sQueueLength++;
			}
			eventConsumed = true;
			break;
		}
		default:
			break;
	}
	return eventConsumed;
}
