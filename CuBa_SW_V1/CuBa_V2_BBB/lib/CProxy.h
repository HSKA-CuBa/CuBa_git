/**
 * @file	CProxy.h
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Class definition for a proxy.
 */
#ifndef CPROXY_H
#define CPROXY_H
#include "CMessage.h"
#include "Global.h"
#include "CSensorData.h"
#include "CPhi.h"
#include "CPhi__d.h"
#include "CPsi__d.h"

class CCommComponent;
class CControlComponent;

class CProxy
{
public:
	bool transmitSensorData(const CSensorData& data, bool waitForever);
	bool transmitPhi(const CPhi& data, bool waitForever);
	bool transmitPhi__d(const CPhi__d& data, bool waitForever);
	bool transmitPsi__d(const CPsi__d& data, bool waitForever);
	bool timerTick(bool waitForever);
	bool routeMATLABMessage(const CMessage& msg, bool waitForever);
	bool clientDisconnect(bool waitForever);
	bool clientConnect(bool waitForever);
	bool setCommPtr(CCommComponent* commPtr);
	bool setControlPtr(CControlComponent* controlPtr);
public:
	CProxy();
	CProxy(const CProxy&) = delete;
	CProxy& operator=(const CProxy&) = delete;
	~CProxy() = default;
private:
	CCommComponent* mCommPtr;
	CControlComponent* mControlPtr;
};

#endif
