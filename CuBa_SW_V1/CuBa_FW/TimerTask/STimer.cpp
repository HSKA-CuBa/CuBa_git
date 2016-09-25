/**
 * @file STimer.cpp
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief Class definitions for the timer class, which is implemented as singleton.
 */
#include "STimer.h"
#include <unistd.h>
#include <iostream>
#include <new>

STimer* STimer::sInstance = nullptr;
CMutex STimer::sAccessMutex(false, true);
/**
 * Static memory to store the singleton instance, prevents the usage of dynamic memory allocation.
 */
static UInt8 sMemory[cMakeAlignmentSize(sizeof(STimer))];
STimer::STimer() : mRunningSem(true, 0)
{

}
STimer& STimer::getInstance()
{
	sAccessMutex.take(true);
	if(nullptr == sInstance)
	{
		sInstance = reinterpret_cast<STimer*>(sMemory);
		sInstance = reinterpret_cast<STimer*>(new(sMemory)STimer);
	}
	sAccessMutex.give();
	return *sInstance;
}
void STimer::run()
{
	std::cout << "[STimer] Running" << std::endl;
	while(true)
	{
		//In case the timer is stopped go to sleep
		mRunningSem.take(true);
		mRunningSem.give();
		usleep(20 * 1000);
		//TODO: Call proxy to create timer event
	}
}
void STimer::init()
{
	std::cout << "[STimer] Initializing" << std::endl;
}
