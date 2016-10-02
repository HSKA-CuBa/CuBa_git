/**
 * @file	CCommComponent.h
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Class definition for the comm-component.
 */
#ifndef CCOMMCOMPONENT_H
#define CCOMMCOMPONENT_H
#include "AComponentBase.h"
#include "CServer.h"
#include "CThread.h"
#include "CReceiveTask.h"
#include "CCommFSM.h"

class CCommComponent : public AComponentBase
{
public:
	/**
	 * Initialize the TCP/IP-Server.
	 */
	void init() override;
	/**
	 * Run the comm component.
	 */
	void run() override;
public:
	CCommComponent(CProxy& proxy);
	CCommComponent(const CCommComponent&) = delete;
	CCommComponent& operator=(const CCommComponent&) = delete;
	~CCommComponent() = default;
private:
	CCommFSM mFSM;
};

#endif
