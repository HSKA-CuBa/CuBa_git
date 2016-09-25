/**
 * @file AComponentBase.cpp
 * @author Michael Meindl
 * @date 25.9.2016
 * @brief Method definitions for AComponentBase.
 */
#include "AComponentBase.h"

AComponentBase::AComponentBase() : mQueue(),
								   mProxyPtr(nullptr),
								   mBufferPtr(nullptr),
								   mState(EState::STANDBY)
{

}
void AComponentBase::run()
{
	CMessage msg;
	while(true)
	{
		if(mQueue.popFront(msg, true))
		{
			if(mState == EState::STANDBY)
			{
				this->onStateStandby(msg);
			}
			else
			{
				this->onStateRunning(msg);
			}
		}
	}
}
bool AComponentBase::setBuffer(CDoubleBuffer& buffer)
{
	bool success = false;
	if(mBufferPtr == nullptr)
	{
		mBufferPtr = &buffer;
		success = true;
	}
	return success;
}
bool AComponentBase::setProxy(CProxy& proxy)
{
	bool success = false;
	if(mBufferPtr == nullptr)
	{
		mProxyPtr = &proxy;
		success = true;
	}
	return success;
}
