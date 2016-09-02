/* Communication Komponent
 *
 * Created on: 16.08.2016
 * Author: Alexander Schleicher
 * From Foundation of Michael Meindl
 */

#include "SCommComponent.h"
#include "TUSART.h"
#include "ERegister.h"
#include "ECommEvent.h"
#include "FreeRTOS.h"
#include <new>

SCommComponent* SCommComponent::sInstance = nullptr;

SCommComponent::SCommComponent() : AComponentBase(EComponentID::COMM_COMP),
								   mUSART(),
								   mRxBuffer(mUSART),
								   mTxBuffer(mUSART) {}

SCommComponent& SCommComponent::getInstance()
{
	if(sInstance == nullptr)
		{
			sInstance = new(pvPortMalloc(sizeof(SCommComponent)))SCommComponent();
		}
	return *sInstance;
}

bool SCommComponent::dispatch(const CMessage& msg)
{
	ECommEvent event = msg.getCommEvent();

	switch (event)
	{
		case(ECommEvent::EV_COMM_MSG_RECEIVED):
		{
			mRxBuffer.proccessReceivedBuffer();
			return true;
		}
		case(ECommEvent::EV_TRANSMIT_ENTRY_STATE):
		{
			UInt8 buffer[] = { static_cast<UInt8>(msg.getReceiver()),
							   static_cast<UInt8>(msg.getCommEvent()),
							   static_cast<UInt8>(msg.getData()),
							   0U };
			mTxBuffer.writeMessage(buffer);
			return true;
		}

		case(ECommEvent::EV_TRANSMIT_VELOCITY):
		{
			UInt8 buffer[] = { static_cast<UInt8>(msg.getReceiver()),
							   static_cast<UInt8>(msg.getCommEvent()),
							   (UInt32)(UInt8)(msg.getData() & 0xff),
							   (UInt32)(UInt8)((msg.getData() >> 8 ) & 0xff) };
			mTxBuffer.writeMessage(buffer);
			return true;
		}

		case(ECommEvent::EV_TRANSMIT_ANGLE):
		{
			UInt8 buffer[] = { static_cast<UInt8>(msg.getReceiver()),
							   static_cast<UInt8>(msg.getCommEvent()),
							   (UInt32)(UInt8)(msg.getData() & 0xff),
							   (UInt32)(UInt8)((msg.getData() >> 8 ) & 0xff) };
			mTxBuffer.writeMessage(buffer);
			return true;
		}

		case(ECommEvent::EV_TRANSMIT_USART_SYNCHRO_CHECK):
		{
			//FIXME Usart Check
			UInt8 buffer[] = { 252, 253, 254, 255};
			mTxBuffer.writeMessage(buffer);
			return true;
		}

		default: {}

	}
	return false;
}

void SCommComponent::onUSARTIRQ()
{
	if(mUSART.checkRXIRQ())
	{
		mRxBuffer.onRXIRQ();
	}

	if(mUSART.checkTXIRQ())
	{
		mTxBuffer.onTXIRQ();
	}
}



