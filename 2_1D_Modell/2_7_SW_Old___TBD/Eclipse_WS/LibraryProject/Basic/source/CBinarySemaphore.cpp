#include "CBinarySemaphore.h"

CBinarySemaphore::CBinarySemaphore(bool isFull, bool isProcessShared) : mCounter(1)
{
	Int32 retVal;
	pthread_mutexattr_t mutexAttr;
	retVal = pthread_mutexattr_init(&mutexAttr);
	sAssertion(0 == retVal, "(CBinarySemaphore::CBinarySemaphore()) : Failed to init Mutex-Attribute!");

	retVal = pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_ERRORCHECK);
	sAssertion(0 == retVal, "(CBinarySemaphore::CBinarySemaphore()) : Failed to set Mutex-Type!");

	retVal = pthread_mutex_init(&mMutex, &mutexAttr);
	sAssertion(0 == retVal, "(CBinarySemaphore::CBinarySemaphore()) : Failed to init Mutex!");

	retVal = pthread_mutexattr_destroy(&mutexAttr);
	sAssertion(0 == retVal, "(CBinarySemaphore::CBinarySemaphore()) : Failed to destroy Mutex-Attribute!");

	pthread_condattr_t conditionAttr;
	retVal = pthread_condattr_init(&conditionAttr);
	sAssertion(0 == retVal, "(CBinarySemaphore::CBinarySemaphore()) : Failed to init Condition-Attribute!");

	retVal = pthread_condattr_setpshared(&conditionAttr,
										 isProcessShared ? PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE);
	sAssertion(0 == retVal, "(CBinarySemaphore::CBinarySemaphore()) : Failed to set Condition-Attribute!");

	pthread_cond_init(&mCondition, &conditionAttr);
	pthread_condattr_destroy(&conditionAttr);


	if(false == isFull)
	{
		mCounter = 0;
	}
}
CBinarySemaphore::~CBinarySemaphore()
{
	pthread_mutex_destroy(&mMutex);
}
bool CBinarySemaphore::take(bool waitForever)
{
	bool result = true;
	pthread_mutex_lock(&mMutex);
	if(1 == mCounter)
	{
		mCounter = 0;
	}
	else if(false == waitForever)
	{
		result = false;
	}
	else
	{
		while(0 == mCounter)
		{
			pthread_cond_wait(&mCondition, &mMutex);
			//Mutex wird hier freigegeben, deshalb wird kein waitForever == false blockiert
			//Aber der Mutex wird anschließend nur weider gelocked falls kein Fehler bei pthread_cond_wait auftritt
			//Error gibts nur wenn:
			//EINVAL: condition oder mutex sind schlecht, wurde schon im ctor geprüft
			//EINVALL: verschiedene mutexe rufen die selbe condition-variable auf //geht auch nicht
			//EPERM: der mutex gehört nicht dem aufrufen thread, ghet eigt auch nicht
		}
		mCounter = 0;
	}
	pthread_mutex_unlock(&mMutex);	//Sollte in if(1 == mCounter) !?!
	return result;
}
void CBinarySemaphore::give()
{
	pthread_mutex_lock(&mMutex);
	mCounter = 1;
	pthread_mutex_unlock(&mMutex);
	pthread_cond_signal(&mCondition);
}
