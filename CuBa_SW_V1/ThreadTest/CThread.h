/**
 * @file	CThread.h
 * @author	Michael Meindl
 * @date	27.9.2016
 * @brief	Class to create a thread-carrier.
 */
#ifndef CTHREAD_H
#define CTHREAD_H
#include "IRunnable.h"
#include "CBinarySemaphore.h"
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
	CThread(IRunnable* runnableObj);
	CThread(const CThread&) = delete;
	CThread& operator=(const CThread&) = delete;
	~CThread() = default;
private:
	IRunnable* mRunPtr;
	pthread_t mThreadID;

};

#endif
