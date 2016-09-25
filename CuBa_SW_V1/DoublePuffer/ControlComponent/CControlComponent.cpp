/**
 * @file 	CControlComponent.cpp
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief	Method definitions for CControlComponent.
 */
#include <CControlComponent.h>
#include "CDoubleBuffer.h"
#include <new>
#include <iostream>

void CControlComponent::init()
{
	std::cout << "[*] Control-Component: Initializing" << std::endl;
}
void CControlComponent::onStateRunning(CMessage& msg)
{

}
void CControlComponent::onStateStandby(CMessage& msg)
{

}
CControlComponent::CControlComponent() : AComponentBase()
{

}
