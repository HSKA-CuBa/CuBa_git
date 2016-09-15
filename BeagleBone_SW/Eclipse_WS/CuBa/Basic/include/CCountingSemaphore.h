//11.9.16, Michael Meindl
//OO-Couting-Semaphore, simulated by using an access-mutex
#ifndef CCOUNTINGSEMAPHORE_H
#define CCOUNTINGSEMAPHORE_H
#include "Global.h"
#include <pthread.h>

class CCountingSemaphore
{
public:
	bool take(bool waitForever);
	void give();
public:
	CCountingSemaphore(bool isProcessShared, Int32 startingValue);
	CCountingSemaphore() = delete;
	CCountingSemaphore(const CCountingSemaphore&) = delete;
	~CCountingSemaphore();
private:
	pthread_mutex_t mMutex;
	pthread_cond_t mCondition;
	Int32 mCounter;
};

#endif
