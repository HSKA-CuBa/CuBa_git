//11.9.2016, Michael Meindl
#include "CServer.h"
#include <unistd.h>		//close()
#include <strings.h>	//bzero()
#include <iostream>


void CServer::echo()
{
	Int32 retVal = -1;
	UInt8 buffer[1] = {0};
	Int32 counter = 0;
	while(counter < 10)
	{
		retVal = read(mConnectedSocketFD, buffer, 1);
		sAssertion(retVal >= 0, "(CServer::echo()): Failed to read from the socket.");
		std::cout << "Received Byte: " << static_cast<Int32>(buffer[0]) << std::endl;
		counter++;
	}
}
CServer::CServer() : mSocketFD(-1),
					 mConnectedSocketFD(-1)
{
	mSocketFD = socket(AF_INET, SOCK_STREAM, 0);
	sAssertion(mSocketFD >= 0, "(CServer::CServer()): Failed to open socket.");

	//Biund the socket to an address
	struct sockaddr_in server_addr;
	bzero(reinterpret_cast<Int8*>(&server_addr), sizeof(server_addr));
	server_addr.sin_family		= AF_INET;
	server_addr.sin_port		= htons(sPort);
	server_addr.sin_addr.s_addr = INADDR_ANY;		//Host-Addr aka this machins addr
	Int32 retVal = bind(mSocketFD,
						reinterpret_cast<struct sockaddr*>(&server_addr),
						sizeof(server_addr));
	sAssertion(retVal >= 0, "(CServer::CServer()): Failed to bind the socket.");

	retVal = listen(mSocketFD, 1);
	sAssertion(retVal >= 0, "(CServer::CServer()): Failed to listen().");

	std::cout << "Waiting to accept a connection . .  ." << std::endl;
	mConnectedSocketFD = accept(mSocketFD,
					   	   	    reinterpret_cast<struct sockaddr*>(&mClientAddr),
								&mClientLen);
	sAssertion(mConnectedSocketFD >= 0, "(CServer::CServer()): Failed to accep the client connection.");
}
CServer::~CServer()
{
	Int32 retVal = shutdown(mConnectedSocketFD, SHUT_RDWR);
	sAssertion(retVal >= 0, "(CServer::~CServer()): Failed to shutdown socket.");

	retVal = close(mConnectedSocketFD);
	sAssertion(retVal >= 0, "(CServer::~CServer()): Failed to close connected socket.");

	retVal = close(mSocketFD);
	sAssertion(retVal >= 0, "(CServer::~CServer()): Failed to close socket.");
}
