#include "CServer.h"
#include <unistd.h>
#include <iostream>

int main()
{
	CServer server;
	server.init();
	server.waitForClient();
	Float32 msg = 1.0F;
	while(true)
	{
		if(false == server.receiveMessage(msg,true))
		{
			break;
		}
		std::cout << "Received Message: " << msg << std::endl;
	}
	server.waitForClient();
	while(true)
	{
		if(false == server.receiveMessage(msg,true))
		{
			break;
		}
		std::cout << "Received Message: " << msg << std::endl;
	}
	return 0;
}
