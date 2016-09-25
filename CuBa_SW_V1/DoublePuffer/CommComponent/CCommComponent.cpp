/**
 * @file 	CCommComponent.cpp
 * @author 	Michael Meindl
 * @date	25.9.2016
 * @brief	Class definitions of CCommComponent.
 */
#include <CCommComponent.h>
#include "CDoubleBuffer.h"
#include <iostream>
#include <new>

void CCommComponent::init()
{
	std::cout << "[*] Comm-Component: Initializing" << std::endl;
}
void CCommComponent::onStateRunning(CMessage& msg)
{

}
void CCommComponent::onStateStandby(CMessage& msg)
{

}
CCommComponent::CCommComponent()
{

}

