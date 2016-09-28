/**
 * @file	CReceiveTask.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Method definitions for CReceiveTask.
 */
#include "CReceiveTask.h"

CReceiveTask::CReceiveTask(CServer& server) : mServer(server),
											  mRunningSem(false, true),
											  mProxyPtr(nullptr)
{

}
bool CReceiveTask::setProxyPtr(CProxy* proxyPtr)
{
	bool success = false;
	if(mProxyPtr == nullptr)
	{
		success 	= true;
		mProxyPtr	= proxyPtr;
	}
	return success;
}
void CReceiveTask::init()
{
	;
}
void CReceiveTask::run()
{
	CMessage msg;
	while(true)
	{
		mRunningSem.take(true);
		mRunningSem.give();
		if(mServer.receiveMessage(msg))
		{
			mProxyPtr->routeMATLABMessage(msg, true);
		}
		else
		{
			mProxyPtr->clientDisconnect(true);
			mRunningSem.take(true); //Self block
		}
	}
}
bool CReceiveTask::pause(bool waitForever)
{
	return mRunningSem.take(waitForever);
}
bool CReceiveTask::resume(bool waitForever)
{
	mRunningSem.give();
	return true;
}
