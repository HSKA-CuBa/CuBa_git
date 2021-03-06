/**
 * @file	CTread.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Method definitions for CThread.
 */
#include "CThread.h"

void* threadProc(void* thisPtr)
{
	CThread* thisThreadPtr = reinterpret_cast<CThread*>(thisPtr);
	thisThreadPtr->run();
	return nullptr;
}
CThread::CThread(IRunnable* runnablePtr) : mThreadID(-1),
										   mRunablePtr(runnablePtr)
{

}
void CThread::start()
{
	pthread_create(&mThreadID, NULL, threadProc, this);
}
void CThread::run()
{
	mRunablePtr->init();
	mRunablePtr->run();
}
void CThread::join()
{
	pthread_join(mThreadID, NULL);
}
