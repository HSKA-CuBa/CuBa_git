/**
 * @file	SProxy.cpp
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief	Method definitions for SProxy.
 */
#include <CControlComponent.h>
#include <CProxy.h>
#include <new>

bool CProxy::timerTick(bool waitForever)
{
	CMessage msg;
	msg.setEvent(EEvent::EV_TIMER_TICK);
	return mControlComp.mQueue.pushFront(msg, waitForever);
}
CProxy::CProxy(CControlComponent& controlComp,
			   CCommComponent& commComp) : mControlComp(controlComp),
					   	   	   	   	       mCommComp(commComp)
{

}
