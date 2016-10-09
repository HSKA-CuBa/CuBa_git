/**
 * @file	CProxy.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef CPROXY_H
#define CPROXY_H
#include "CMessage.h"
#include "CMutex.h"

class AComponentBase;

class CProxy
{
public:
	static CProxy& getInstance();
	void registerCommComponent(AComponentBase* commComponent);
	void registerControlComponent(AComponentBase* controlComponent);

	bool clientConnect(bool waitForever);
	bool clientDisconnect(bool waitForever);
	bool routeMATLABMessage(CMessage& msg, bool waitForever);
	bool timerTick(bool waitForever);
private:
	CProxy();
	CProxy(const CProxy&) = delete;
	CProxy& operator=(const CProxy&) = delete;
	~CProxy() = default;
private:
	static volatile CProxy* sInstance;
	static CMutex sAccessMutex;
	AComponentBase* mCommPtr;
	AComponentBase* mControlPtr;
};

#endif
