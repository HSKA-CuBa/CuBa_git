/**
 * @file main.cpp
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief This file contains the main-function. Here the components are initialize and started as seperate threads.
 */
#include <iostream>
#include <pthread.h>
#include "STimer.h"

void* timerTask(void*)
{
	STimer& timer = STimer::getInstance();
	timer.init();
	timer.run();
	return nullptr;
}

int main()
{
	pthread_t timerID;
	pthread_create(&timerID, NULL, timerTask, NULL);

	pthread_join(timerID, NULL);
	std::cout << "Hello World" << std::endl;
	return 0;
}