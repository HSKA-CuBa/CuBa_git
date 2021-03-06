#include "CActionHandler.h"
#include "EEvent.h"
#include "EState.h"
#include "CSTMHardware.h"

static UInt32 sTickCounter = 0U;

extern "C"
{
void SysTick_Handler();
void SysTick_Handler()
{
	HAL_IncTick();
	sTickCounter++;
}
}


void main();
void main()
{
	EState state = EState::StateIdle;
	CSTMHardware hw;
	CActionHandler action(hw);
	EEvent event = EEvent::EV_DEFAULT_IGNORE;

	while(true)
	{
		if(sTickCounter >= static_cast<UInt32>(Config::T_a * 1000.0F))
		{
			sTickCounter = 0U;

			switch(state)
			{
			case EState::StateIdle:
			{
				event = action.onStateIdle();
				if(EEvent::EV_PHI_IN_BALANCE_AREA == event)
				{
					action.onExitIdle();
					state = EState::StateBalance;
					action.onEntryBalance();
				}
				else if(EEvent::EV_CUBE_RESTING == event)
				{
					action.onExitIdle();
					state = EState::StateJumpUp;
					action.onEntryJumpUp();
				}
				break;
			}
			case EState::StateJumpUp:
			{
				event = action.onStateJumpUp();
				if(EEvent::EV_BRAKING_FINISHED == event)
				{
					action.onExitJumpUp();
					state = EState::StateIdle;
					action.onEntryIdle();
				}
				break;
			}
			case EState::StateBalance:
			{
				event = action.onStateBalance();
				if(EEvent::EV_PHI_NOT_IN_BALANCE_AREA == event)
				{
					action.onExitBalance();
					state = EState::StateIdle;
					action.onEntryIdle();
				}
				break;
			}
			}
		}
	}
}
