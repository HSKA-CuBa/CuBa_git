/**
 * @file	CProxy.h
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief	Class definition for the proxy.
 */
#ifndef CPROXY_H
#define CPROXY_H
#include "Global.h"

class CControlComponent;
class CCommComponent;

/**
 * Class to handle the creation and transmission of messages.
 * The class is a friend of AComponentBase.
 */
class CProxy
{
public:
	/**
	 * Method to notify the control component, that a sampling intervall has passed.
	 * @param[in] waitForever	Specifies whether the caller wants to wait forever.
	 * @return					Specifies whether the message was transmitted.
	 */
	bool timerTick(bool waitForever);
public:
	CProxy(CControlComponent& controlComp,
		   CCommComponent& commComp);
	CProxy(const CProxy&) = delete;
	CProxy& operator=(const CProxy&) = delete;
	~CProxy() = default;
	CProxy() = delete;
private:
	CControlComponent& mControlComp;
	CCommComponent& mCommComp;
};

#endif
