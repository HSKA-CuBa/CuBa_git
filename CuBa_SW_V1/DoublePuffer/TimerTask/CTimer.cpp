/**
 * @file CTimer.cpp
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief Method definitions for the timer class.
 */
#include <CProxy.h>
#include <CTimer.h>
#include <unistd.h>
#include <iostream>
#include <new>

CTimer::CTimer() : mRunningSem(true, 1),
				   mProxyPtr(nullptr)
{

}
void CTimer::run()
{
	std::cout << "[STimer] Running" << std::endl;
	while(true)
	{
		//In case the timer is stopped go to sleep
		mRunningSem.take(true);
		mRunningSem.give();
		usleep(1000 * 1000);

		mProxyPtr->timerTick(false);
	}
}
bool CTimer::setProxy(CProxy& proxy)
{
	bool success = false;
	if(mProxyPtr == nullptr)
	{
		mProxyPtr = &proxy;
		success = true;
	}
	return success;
}
