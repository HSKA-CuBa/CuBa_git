/**
 * @file	CControlComponent.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Method definitions for CControlComponent.
 */
#include "CControlComponent.h"
#include <iostream>

CControlComponent::CControlComponent(CProxy& proxy) : AComponentBase(proxy),
													  mFSM(proxy)
{

}
void CControlComponent::run()
{
	std::cout << "[Control-Comp] Running" << std::endl;
	CMessage rxMsg;
	while(true)
	{
		if(mQueue.popFront(rxMsg, true))
		{
			mFSM.dispatch(rxMsg);
		}
	}

}
void CControlComponent::init()
{
	std::cout << "[Control-Comp] Initializing" << std::endl;
}
