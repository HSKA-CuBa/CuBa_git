/**
 * @file	AComponentBase.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Method definitions for AComponentBase.
 */
#include "AComponentBase.h"
#include "CProxy.h"

AComponentBase::AComponentBase(CProxy& proxy) : mQueue(),
								 	 	 	 	mProxy(proxy)
{

}
