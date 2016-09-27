/**
 * @file 	IRunnable.h
 * @author	Michael Meindl
 * @date 	27.9.2016
 * @brief	Interface for objects which can be run as a thread.
 */
#ifndef IRUNNABLE_H
#define IRUNNABLE_H
#include "Global.h"

class IRunnable
{
public:
	virtual void run() = 0;
	virtual void init() = 0;
	virtual void pause() = 0;
	virtual void resume() = 0;
public:
	IRunnable() = default;
	IRunnable(const IRunnable&) = delete;
	IRunnable& operator=(const IRunnable&) = delete;
	virtual ~IRunnable() = default;
};

#endif
