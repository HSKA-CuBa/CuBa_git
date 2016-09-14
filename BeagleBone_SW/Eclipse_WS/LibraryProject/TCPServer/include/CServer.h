//11.9.16, Michael Meindl
//Class to create the TCP/IP server in order to connect to Matlab
#ifndef CSERVER_H
#define CSERVER_H
#include "CMessage.h"
#include "Global.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class CServer
{
public:
	void init();
	void waitForClient();
	bool transmitMessage(const CMessage& msg);	///< Returns ture if the message was transmitted, false represents a connection shutdown.
public:
	CServer();
	CServer(const CServer&) = delete;
	CServer& operator=(const CServer&) = delete;
	~CServer();
private:
	static constexpr Int32 sPort = 40000;
	Int32 mSocketFD;
	Int32 mConnectedSocketFD;
	struct sockaddr_in mClientAddr;
	socklen_t mClientLen;
};

#endif
