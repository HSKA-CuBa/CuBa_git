/**
 * @file 	main.cpp
 * @author  Michael Meindl
 * @date 	25.9.2016
 * @brief 	Contains main function, creates the different tasks and runs them.
 */
#include <CCommComponent.h>
#include <CControlComponent.h>
#include <CTimer.h>
#include "CDoubleBuffer.h"
#include <pthread.h>

void* controlTask(void*);
void* timerTask(void*);
void* commTask(void*);

CDoubleBuffer buffer;
CTimer timer;
CCommComponent commComp;
CControlComponent controlComp;
CProxy proxy(controlComp, commComp);

int main()
{
	timer.setProxy(proxy);
	commComp.setProxy(proxy);
	commComp.setBuffer(buffer);
	controlComp.setProxy(proxy);
	controlComp.setBuffer(buffer);

	pthread_t timerID;
	pthread_create(&timerID, NULL, timerTask, NULL);

	pthread_t controlID;
	pthread_create(&controlID, NULL, controlTask, NULL);

	pthread_t commID;
	pthread_create(&commID, NULL, commTask, NULL);

	pthread_join(timerID, NULL);
	pthread_join(controlID, NULL);
	pthread_join(commID, NULL);

	return 0;
}

void* timerTask(void*)
{
	timer.run();
	return nullptr;
}
void* controlTask(void*)
{
	controlComp.init();
	controlComp.run();
	return nullptr;
}
void* commTask(void*)
{
	commComp.init();
	commComp.run();
	return nullptr;
}
