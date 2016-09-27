/**
 * @file	CRxTask.h
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief	Class definition for the rx task.
 */
#ifndef CRXTASK_H
#define CRXTASK_H
#include "IRunnable.h"
#include "CBinarySemaphore.h"
#include <iostream>
#include <unistd.h>

class CRxTask : public IRunnable
{
public:
	void init() override;
	void run() override;
	void pause() override;
	void resume() override;
public:
	CRxTask();
	CRxTask(const CRxTask&) = delete;
	CRxTask& operator=(const CRxTask&) = delete;
	~CRxTask() = default;
public:
	CBinarySemaphore mRunningSem;
};

#endif