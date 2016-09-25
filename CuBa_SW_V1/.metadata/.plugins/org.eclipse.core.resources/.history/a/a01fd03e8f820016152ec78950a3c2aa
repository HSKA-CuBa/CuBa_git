#ifndef CMUTEX_H
#define CMUTEX_H
#include "Global.h"
#include <pthread.h>

class CMutex
{
public:
	bool take(bool waitForever);
	void give();
public:
	CMutex(bool isFull = true, bool isProcessShared = false);
	CMutex(const CMutex&) = delete;
	CMutex& operator=(const CMutex&) = delete;
	~CMutex();
private:
	pthread_mutex_t mMutex;
};


#endif
