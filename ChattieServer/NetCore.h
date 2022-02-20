#ifndef NETCORE_H
#define NETCORE_H

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include <utility>
#include <set>

//#include "RequestType.h"
#include "RequestManager.h"
#include "ServerCore.h"

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 30
#define DEFAULT_PORT "27015"
//#define DEFAULT_PORT "4876"


class NetCore
{
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ConnectSocket = INVALID_SOCKET;
	std::set <SOCKET> connectedSockets;



	//char* recvbuf;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	const char *sendbuf = "Go!";
	

	IRequestManager* requestManager;
	IServerCore* serverCore;


	int listenChosenSocket(SOCKET socketToListen);
	void sendChatHistoryToAll();

public:
	NetCore(IServerCore* serverCore);
	~NetCore();

	int runAsServer();

	void serverCycle();

	//int sendReply(requestType rType, std::string requestText);
	int sendReply(std::string requestText);

	std::string receiveRequest();


};

#endif
