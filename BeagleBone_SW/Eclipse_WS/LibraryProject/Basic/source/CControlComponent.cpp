//12.9.16, Michael Meindl
#include "CControlComponent.h"
#include <iostream>
#include <unistd.h>

CControlComponent::CControlComponent(TQueue<Config::QueueSize>& rxQueue,
									 TQueue<Config::QueueSize>& txQueue) :
									 	 AComponentBase(rxQueue, txQueue, true)
{

}
void CControlComponent::init()
{
	std::cout << "Control-Component: init()" << std::endl;
	Int32 retVal = mHardware.initializeHardware();
	sAssertion( retVal >= 0, "(CControlComponent::init()): Failed to initialize HW.");
}
void CControlComponent::run()
{
	CMessage msg;
	Float32 time = 0.0F;
	while(true)
	{
		if(true == mStandbyState)
		{
			if(mRxQueue.getMessage(msg, true))
			{
				if(msg.mHeader.mEvent == EEvent::EV_REQUEST_RUN)
				{
					std::cout << "Control-Component: Switching from standby to running." << std::endl;
					mStandbyState = false;
				}
			}
		}
		else
		{
			sleep(1);
			mHardware.fetchValues();
			CSensorData sensorData(time,
					mHardware.getX1__dd_raw(),
					mHardware.getY1__dd_raw(),
					mHardware.getPhi1__d_raw(),
					mHardware.getX2__dd_raw(),
					mHardware.getY2__dd_raw(),
					mHardware.getPhi2__d_raw());
			CMessage sensorMsg(EEvent::EV_REQUEST_TX_SENSORDATA,
								EDataType::SENSOR_DATA,
								sensorData);
			time += 1.0F;
			mTxQueue.addMessage(sensorMsg, false);
		}
	}
}
