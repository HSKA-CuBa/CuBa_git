/************************************************
 * Author: Michael Meindl
 * Datum : 17.04.2016
 ***********************************************/
#include "CMessage.h"
#include "CStateRunning.h"
#include "CControlActionHandler.h"

CStateRunning::CStateRunning(CControlActionHandler& actionHandler) :
									CBasicFSM(actionHandler, ON_DEFAULT_INITIAL_RUNNING),
									mStateJump(actionHandler) {}
bool CStateRunning::onInitial(const CMessage& msg)
{
	bool eventConsumed = false;
	EControlEvent event = msg.getControlEvent();

	switch (event)
	{
		case EControlEvent::EV_INIT:
		{
			mAction.onEntryRunning();
			mAction.onEntryIdle();
			mState = ON_IDLE;
			eventConsumed = true;
			break;
		}
		default:
			break;
	}
	return eventConsumed;
}

bool CStateRunning::onIdle(const CMessage& msg)
{
	bool eventConsumed = false;
	EControlEvent event = msg.getControlEvent();
	switch (event)
	{
		case EControlEvent::EV_EXIT:
		{
			mAction.onExitIdle();
			mAction.onExitRunning();
			mState = ON_DEFAULT_INITIAL_RUNNING;
			eventConsumed = true;
			break;
		}

		case EControlEvent::EV_PHIK_IN_BALANCEAREA:
		{
			if (mAction.getBalanceFlag())
			{
				mAction.onExitIdle();
				mState = ON_BALANCE;
				mAction.onEntryBalance();
				eventConsumed = true;
			}
			break;
		}

		case EControlEvent::EV_JUMP:
		{
			if (mAction.getJumpFlag())
			{
				mAction.onExitIdle();
				mState = ON_JUMP;
				mStateJump.entry(CMessage(EComponentID::CONTROL_COMP,
										  EComponentID::CONTROL_COMP,
										  EControlEvent::EV_INIT));
				eventConsumed = true;
			}
			break;
		}

		case EControlEvent::EV_TIMER:
		{
			if(mAction.phiK_inBalanceArea())
			{
				sInternalQueue = CMessage(EComponentID::CONTROL_COMP,
										  EComponentID::CONTROL_COMP,
										  EControlEvent::EV_PHIK_IN_BALANCEAREA);

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

bool CStateRunning::onBalance(const CMessage& msg)
{
	bool eventConsumed = false;
	EControlEvent event = msg.getControlEvent();
	switch (event)
	{
		case EControlEvent::EV_EXIT:
		{
			mAction.onExitBalance();
			mAction.onExitRunning();
			mState = ON_DEFAULT_INITIAL_RUNNING;
			eventConsumed = true;
			break;
		}

		case EControlEvent::EV_PHIK_NOT_IN_BALANCEAREA:
		{
			mAction.onExitBalance();
			mState = ON_IDLE;
			mAction.onEntryIdle();
			eventConsumed = true;
			break;
		}

		case EControlEvent::EV_TIMER:
		{
			if(mAction.phiK_inBalanceArea())
			{
				mAction.controlIteration();
			}
			else
			{
				sInternalQueue = CMessage(EComponentID::CONTROL_COMP,
										  EComponentID::CONTROL_COMP,
										  EControlEvent::EV_PHIK_NOT_IN_BALANCEAREA);
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

bool CStateRunning::onJump(const CMessage& msg)
{
	bool eventConsumed = false;
	EControlEvent event = msg.getControlEvent();
	switch (event)
	{
		case EControlEvent::EV_EXIT:
		{
			mStateJump.exit();
			mAction.onExitRunning();
			mState = ON_DEFAULT_INITIAL_RUNNING;
			eventConsumed = true;
			break;
		}
		case EControlEvent::EV_BRAKE:
		{
			mStateJump.exit();
			mState = ON_IDLE;
			mAction.onEntryIdle();
			eventConsumed = true;
			break;
		}
		default:
			break;
	}

	if(eventConsumed == false)
	{
		eventConsumed = mStateJump.dispatch(msg);
	}

	return eventConsumed;
}
