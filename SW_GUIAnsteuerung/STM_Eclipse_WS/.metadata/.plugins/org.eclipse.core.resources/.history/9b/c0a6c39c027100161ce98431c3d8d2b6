/* Base class for Components
 *
 * Created on: 16.08.2016
 * Author: Alexander Schleicher
 * From Foundation of Michael Meindl
 */

#include "CMessage.h"
#include "AComponentBase.h"
#include "Config.h"


AComponentBase::AComponentBase(EComponentID id) : mID(id)
{
	mQueue = xQueueCreate(EConfig::COMPONENT_QUEUE_SIZE,
						  sizeof(CMessage));
}


void AComponentBase::run()
{
	UInt8 receiveBuffer[sizeof(CMessage)] {0U};
	CMessage* receivedMessage = reinterpret_cast<CMessage*>(receiveBuffer);

	while(true)
	{
		//This should always be evaluated as true
		//The Task only wakes up once there is data to receive
		if(pdPASS == xQueueReceive(mQueue,
								   static_cast<void*>(receivedMessage),
								   portMAX_DELAY))

		{
			this->dispatch(*receivedMessage);
		}
	}
}
AComponentBase::~AComponentBase(void){}
