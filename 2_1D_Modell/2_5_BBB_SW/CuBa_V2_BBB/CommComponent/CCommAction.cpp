/**
 * @file	CCommAction.cpp
 * @author	Michael Meindl
 * @date	29.9.2016
 * @brief	Method definition for CCommAction.
 */
#include "CCommAction.h"
#include <iostream>

CCommAction::CCommAction(CProxy& proxy) : mServer(),
										  mProxy(proxy),
										  mReceiveTask(mServer, &proxy),
										  mReceiveThread(&mReceiveTask)
{
	mReceiveThread.start();
}
bool CCommAction::transmitMessage(CMessage& msg)
{
	return mServer.transmitMessage(msg);
}
void CCommAction::onEntryRunning()
{
	std::cout << "[Comm-Component] Entering RUNNING" << std::endl;
}
void CCommAction::onExitRunning()
{
	std::cout << "[Comm-Component] Exiting RUNNING" << std::endl;
}
void CCommAction::onEntryStandby()
{
	std::cout << "[Comm-Component] Entering STANDBY" << std::endl;
}
void CCommAction::onExitStandby()
{
	std::cout << "[Comm-Component] Exiting STANDBY" << std::endl;
}
