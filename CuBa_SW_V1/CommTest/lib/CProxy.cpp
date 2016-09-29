/**
 * @file	CProxy.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Class definition for the proxy.
 */
#include "CProxy.h"
#include "CMessage.h"
#include "CControlComponent.h"
#include "CCommComponent.h"

bool CProxy::clientDisconnect(bool waitForever)
{
	CMessage msg(EEvent::EV_CLIENT_DISCONNECT);
	bool controlSuccess = true; //mControlPtr->mQueue.pushBack(msg, waitForever);
	bool commSuccess    = mCommPtr->mQueue.pushBack(msg, waitForever);
	return controlSuccess && commSuccess;
}
bool CProxy::clientConnect(bool waitForever)
{
	CMessage msg(EEvent::EV_CLIENT_CONNECT);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::routeMATLABMessage(const CMessage& msg, bool waitForever)
{
	return mControlPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::timerTick(bool waitForever)
{
	CMessage msg(EEvent::EV_TIMER_TICK);
	return mControlPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitSensorData(const CSensorData& data,
								bool waitForever)
{
	CMessage msg(data);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitPhi(const CPhi& data,
						 bool waitForever)
{
	CMessage msg(data);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitPhi__d(const CPhi__d& data,
							bool waitForever)
{
	CMessage msg(data);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitPsi__d(const CPsi__d& data,
							 bool waitForever)
{
	CMessage msg(data);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::setCommPtr(CCommComponent* commPtr)
{
	bool success = false;
	if(nullptr == mCommPtr)
	{
		mCommPtr = commPtr;
		success  = true;
	}
	return success;
}
bool CProxy::setControlPtr(CControlComponent* controlPtr)
{
	bool success = false;
	if(nullptr == mControlPtr)
	{
		mControlPtr = controlPtr;
		success 	= true;
	}
	return success;
}
CProxy::CProxy() : mCommPtr(nullptr),
				   mControlPtr(nullptr)
{

}
