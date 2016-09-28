/**
 * @file	CTimerTask.cpp
 * @author	Michael Meindl
 * @date 28.9.2016
 * @brief	Method definitions for CTimerTask.
 */
#include "CTimerTask.h"
#include <iostream>
#include <unistd.h>

CTimerTask::CTimerTask(CProxy& proxy) : mRunningSem(true, true),
										mProxy(proxy)
{

}
void CTimerTask::init()
{
	std::cout << "[TimerTask] Initializing" << std::endl;
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
	return mRunningSem.take(waitForever);
}
bool CTimerTask::resume(bool waitForever)
{
	mRunningSem.give();
	return true;
}
