/**
 * @file	CThread.h
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Class definition for a thread-carrier.
 */
#ifndef CTHREAD_H
#define CTHREAD_H
#include "IRunnable.h"
#include <pthread.h>

class CThread
{
public:
	void start();
	void join();
private:
	friend void* threadProc(void*);
	void run();
public:
	CThread(IRunnable* runnablePtr);
	CThread(const CThread&) = delete;
	CThread& operator=(const CThread&) = delete;
	~CThread() = default;
private:
	pthread_t mThreadID;
	IRunnable* mRunablePtr;
};

#endif
