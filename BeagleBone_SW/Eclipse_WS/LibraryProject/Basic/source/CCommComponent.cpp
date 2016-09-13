#include "CCommComponent.h"
#include "AComponentBase.h"
#include <iostream>
#include <unistd.h>

CCommComponent::CCommComponent(TQueue<Config::QueueSize>& rxQueue,
							   TQueue<Config::QueueSize>& txQueue) : AComponentBase(rxQueue, txQueue, false)
{

}
void CCommComponent::init()
{
	std::cout << "Comm-Component: init()" << std::endl;
}
void CCommComponent::run()
{
	std::cout << "Comm-Component: run()" << std::endl;
	//Server-accept
	sleep(1);
	//Send run-event an Control-Comp
	CMessage msg(EEvent::EV_REQUEST_RUN);
	if(mTxQueue.addMessage(msg, true))
	{
		std::cout << "Run-Request transmitted." << std::endl;
	}

	while(true)
	{
		if(mRxQueue.getMessage(msg, true))
		{
			if(msg.mHeader.mEvent == EEvent::EV_REQUEST_TX_SENSORDATA)
			{
				std::cout << "Comm-Component: Sensor-Data received." << std::endl;
				std::cout << "X1__dd: " << msg.mData.mSensorData.mX1_raw__dd << std::endl;
				std::cout << "X2__dd: " << msg.mData.mSensorData.mX2_raw__dd << std::endl;
				std::cout << "Y1__dd: " << msg.mData.mSensorData.mY1_raw__dd << std::endl;
				std::cout << "Y2__dd: " << msg.mData.mSensorData.mY2_raw__dd << std::endl;
				std::cout << "Phi1__d: " << msg.mData.mSensorData.mPhi1_raw__d << std::endl;
				std::cout << "Phi2__d: " << msg.mData.mSensorData.mPhi2_raw__d << std::endl << std::endl;
			}
		}
	}
}
