//11.9.16, Michael Meindl
//OO-Binary-Semaphore, is simulated by using a mutex
#ifndef CBINARYSEMAPHORE_H
#define CBINARYSEMAPHORE_H
#include "Global.h"
#include <pthread.h>

class CBinarySemaphore
{
public:
	bool take(bool waitForever);
	void give();
public:
	CBinarySemaphore(bool isFull, bool isProcessShared);
	CBinarySemaphore() = delete;
	CBinarySemaphore(const CBinarySemaphore&) = delete;
	CBinarySemaphore& operator=(const CBinarySemaphore&) = delete;
	~CBinarySemaphore();
private:
	pthread_mutex_t mMutex;
	pthread_cond_t mCondition;
	Int32 mCounter;
};

#endif
