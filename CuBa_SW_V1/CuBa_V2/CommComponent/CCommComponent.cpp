/**
 * @file	CCommComponent.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Method definitions for CCommComponent.
 */
#include "CCommComponent.h"
#include <iostream>

CCommComponent::CCommComponent(CProxy& proxy) : AComponentBase(proxy),
								   	   	   	    mConnectedFlag(false),
												mServer(),
												mReceiveTask(mServer),
												mReceiveThread(&mReceiveTask)
{

}
void CCommComponent::init()
{
	std::cout << "[Comm-Component] Initializing" << std::endl;
	mServer.init();
	mReceiveThread.start();
}
void CCommComponent::run()
{
	std::cout << "[Comm-Component] Running" << std::endl;
	CMessage rxMsg;
	while(true)
	{
		if(false == mConnectedFlag)
		{
			mServer.waitForClient();
			mConnectedFlag = true;
			mReceiveTask.resume(true);
		}
		else
		{
			if(mQueue.popFront(rxMsg, true))
			{
				if(mServer.transmitMessage(rxMsg) == false)
				{
					//TODO Call proxy? Stop receive task? Rx is supposed to detect disconnect himself and than signal . . .
					//TODO Empty the queue?
					mConnectedFlag = false;
				}
			}
		}
	}
}
