/**
 * @file	CTimerTask.cpp
 * @author	Michael Meindl
 * @date 28.9.2016
 * @brief	Method definitions for CTimerTask.
 */
#include "CTimerTask.h"
#include <iostream>
#include <unistd.h>

CTimerTask::CTimerTask(CProxy& proxy) : mRunningSem(false, true),
										mProxy(proxy)
{

}
void CTimerTask::init()
{
	std::cout << "[Timer-Task] Initializing" << std::endl;
}
void CTimerTask::run()
{
	while(true)
	{
		mRunningSem.take(true);
		mRunningSem.give();
		usleep(20*1000);
		mProxy.timerTick(true);
	}
}
bool CTimerTask::pause(bool waitForever)
{
	std::cout << "[Timer-Task] Pausing" << std::endl;
	return mRunningSem.take(waitForever);
}
bool CTimerTask::resume(bool waitForever)
{
	std::cout << "[Timer-Task] Resuming" << std::endl;
	mRunningSem.give();
	return true;
}