/**
 * @file	CThread.cpp
 * @author	Michael Meindl
 * @date	27.9.2016
 * @brief	Method definitions for CThread.
 */
#include <cstdlib>
#include "CThread.h"

void* threadProc(void* threadPtr)
{
	CThread* thisThreadPtr = reinterpret_cast<CThread*>(threadPtr);
	thisThreadPtr->run();
	return nullptr;
}
CThread::CThread(IRunnable* runObj) : mRunPtr(runObj),
									  mThreadID(0)
{

}
void CThread::run()
{
	mRunPtr->init();
	mRunPtr->run();
}
void CThread::start()
{
	pthread_create(&mThreadID, NULL, threadProc, this);
}
void CThread::join()
{
	pthread_join(mThreadID, NULL);
}
