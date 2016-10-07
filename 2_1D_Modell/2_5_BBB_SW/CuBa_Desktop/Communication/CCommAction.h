/**
 * @file	CCommAction.h
 * @author	Michael Meindl
 * @date	6.10.2016
 */
#ifndef CCOMMACTION_H
#define CCOMMACTION_H
#include "Global.h"
#include "CMessage.h"

class CCommAction
{
public:
	void entryStandby();
	void exitStandby();
	void entryRunning();
	void exitRunning();

	void transmitMessage(CMessage& msg);
public:
	CCommAction();
	CCommAction(const CCommAction&) = delete;
	CCommAction& operator=(const CCommAction&) = delete;
	~CCommAction() = default;
private:

};


#endif
