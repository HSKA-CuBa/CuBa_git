/**
 * @file	CReceiveTask.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Method definitions for CReceiveTask.
 */
#include "CReceiveTask.h"
#include <iostream>

CReceiveTask::CReceiveTask(CServer& server,
						   CProxy* proxyPtr) : mServer(server),
											   mRunningSem(false, true),
											   mProxyPtr(proxyPtr)
{

}
void CReceiveTask::init()
{
	mServer.init();
}
void CReceiveTask::run()
{
	CMessage msg;
	while(true)
	{
		if(mServer.waitForClient())
		{
			mProxyPtr->clientConnect(true);
		}

		while(mServer.receiveMessage(msg))
		{
			//mProxyPtr->routeMATLABMessage(msg, true);
			msg.display();
		}
		mProxyPtr->clientDisconnect(true);
	}
}
bool CReceiveTask::pause(bool waitForever)
{
	std:: cout << "[Receive-Task] Pausing" << std::endl;
	return mRunningSem.take(waitForever);
}
bool CReceiveTask::resume(bool waitForever)
{
	std::cout << "[Receive-Task] Resuming" << std::endl;
	mRunningSem.give();
	return true;
}
