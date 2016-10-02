/**
 * @file	CCommAction.h
 * @author	Michael Meindl
 * @date	29.9.2016
 * @brief	Class definition for the comm action handler.
 */
#ifndef CCOMMACTION_H
#define CCOMMACTION_H
#include "CMessage.h"
#include "CServer.h"
#include "CThread.h"
#include "CReceiveTask.h"

class CCommAction
{
public:
	void onEntryStandby();
	void onExitStandby();
	void onEntryRunning();
	void onExitRunning();

	bool transmitMessage(CMessage& msg);
public:
	CCommAction(CProxy& proxy);
	CCommAction(const CCommAction&) = delete;
	CCommAction& operator=(const CCommAction&) = delete;
	~CCommAction() = default;
private:
	CServer mServer;
	CProxy& mProxy;
	CReceiveTask mReceiveTask;
	CThread	mReceiveThread;
};

#endif
