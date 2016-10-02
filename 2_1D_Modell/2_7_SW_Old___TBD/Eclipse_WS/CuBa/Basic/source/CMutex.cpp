#include "CMutex.h"
#include <pthread.h>
#include <iostream> //cerr


static void myAssertion(bool assert)
{
	if(false == assert)
	{
		std::cerr << "(CMutex::) Assertion-Error. . . " << std::endl;
		exit(-1);
	}
}

CMutex::CMutex(bool isFull, bool isProcessShared)
{
	pthread_mutexattr_t attr;
	Int32 retVal = pthread_mutexattr_init(&attr);
	myAssertion(0 == retVal);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE); //Prevent selfblocking
	retVal = pthread_mutexattr_setpshared(&attr,
										  isProcessShared ? PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE);
	myAssertion(0 == retVal);

	retVal = pthread_mutex_init(&mMutex, &attr);
	myAssertion(0 == retVal);

	if(false == isFull)
	{
		pthread_mutex_lock(&mMutex);
	}
	pthread_mutexattr_destroy(&attr);
}
bool CMutex::take(bool waitForever)
{
	//Versuche zu locken
	bool haveSem = (0 == pthread_mutex_trylock(&mMutex));

	if((false == haveSem) && (true == waitForever))
	{
		haveSem = (0 == pthread_mutex_lock(&mMutex));
	}
	return haveSem;
}
void CMutex::give()
{
	sAssertion(0 == pthread_mutex_unlock(&mMutex), "(CMutex::give()): Failed to give Mutex!");
}
CMutex::~CMutex()
{
	pthread_mutex_destroy(&mMutex);
}
