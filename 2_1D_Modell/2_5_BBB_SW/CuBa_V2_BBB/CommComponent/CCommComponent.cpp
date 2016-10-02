/**
 * @file	CCommComponent.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Method definitions for CCommComponent.
 */
#include "CCommComponent.h"
#include <iostream>

CCommComponent::CCommComponent(CProxy& proxy) : AComponentBase(proxy),
								   	   	   	    mFSM(proxy)
{

}
void CCommComponent::init()
{
	std::cout << "[Comm-Component] Initializing" << std::endl;
}
void CCommComponent::run()
{
	std::cout << "[Comm-Component] Running" << std::endl;

	CMessage msg;
	while(true)
	{
		if(mQueue.popFront(msg, true))
		{
			mFSM.dispatch(msg);
		}
	}
}
