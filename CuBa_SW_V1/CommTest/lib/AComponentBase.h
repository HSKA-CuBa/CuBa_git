/**
 * @file	AComponentBase.h
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Abstract class definition for the different components.
 */
#ifndef ACOMPONENTBASE_H
#define ACOMPONENTBASE_H
#include "IRunnable.h"
#include "TQueue.h"
#include "Config.h"

class CProxy;

class AComponentBase : public IRunnable
{
public:
	virtual void init() override = 0;
	virtual void run() override = 0;
public:
	AComponentBase(CProxy& proxy);
	AComponentBase(const AComponentBase&) = delete;
	AComponentBase& operator=(const AComponentBase&) = delete;
	~AComponentBase() = default;
protected:
	friend class CProxy;
	TQueue<Config::sQueueSize> mQueue;
	CProxy& mProxy;
};

#endif
