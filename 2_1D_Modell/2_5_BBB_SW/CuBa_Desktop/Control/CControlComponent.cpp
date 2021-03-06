/**
 * @file	CControlComponent.cpp
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#include "CControlComponent.h"
#include "CProxy.h"
#include <iostream>
using namespace std;

CControlComponent::CControlComponent()
{

}
void CControlComponent::init()
{
	cout << "[*] Control-Component: Initializing" << endl;
	CMessage init(EEvent::INIT);
	mFSM.dispatch(init);
}
void CControlComponent::run()
{
	cout << "[*] Control-Component: Running" << endl;
	CMessage msg;
	while(true)
	{
		if(mQueue.popFront(msg, true))
		{
			mFSM.dispatch(msg);
		}
	}
}
