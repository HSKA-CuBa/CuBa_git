/**
 * @file AComponentBase.h
 * @author Michael Meindl
 * @date 25.9.2016
 * @brief Abstract base class for the different components.
 */
#ifndef ACOMPONENTBASE_H
#define ACOMPONENTBASE_H
#include "IRunnable.h"
#include "TQueue.h"
#include "CDoubleBuffer.h"
#include "Config.h"


class AComponentBase : public IRunnable
{
public:
	enum class EState { STANDBY, RUNNING };
public:
	void run() override;
	virtual void onStateRunning(CMessage& msg) = 0;
	virtual void onStateStandby(CMessage& msg) = 0;
	bool setProxy(CProxy& proxy);
	bool setBuffer(CDoubleBuffer& buffer);
	virtual void init() = 0;				/// Pure virtual method to initialize the component
public:
	AComponentBase();
	AComponentBase(const AComponentBase&) = delete;
	AComponentBase& operator=(const AComponentBase&) = delete;
	virtual ~AComponentBase() = default;
protected:
	friend CProxy;
	TQueue<Config::queueSize> mQueue;
	CProxy* mProxyPtr;
	CDoubleBuffer* mBufferPtr;
	EState mState;
};

#endif
