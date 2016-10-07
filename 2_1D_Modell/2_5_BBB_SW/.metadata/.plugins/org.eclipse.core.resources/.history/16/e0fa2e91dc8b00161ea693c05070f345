/**
 * @file	CBasciFSM.cpp
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#include "CBasicFSM.h"
#include "CAction.h"
#include "CMessage.h"

CAction  CBasicFSM::sAction{};
CMessage CBasicFSM::sInternalQueue{};
Int32	 CBasicFSM::sQueueSize = 0;

CBasicFSM::CBasicFSM() : mState(&CBasicFSM::onInitial)
{

}
bool CBasicFSM::dispatch(CMessage& msg)
{
	return (this->*mState)(msg);
}
void CBasicFSM::entry()
{
	CMessage msg(EEvent::INIT);
	this->dispatch(msg);
}
void CBasicFSM::exit()
{
	CMessage msg(EEvent::EXIT);
	this->dispatch(msg);
}
