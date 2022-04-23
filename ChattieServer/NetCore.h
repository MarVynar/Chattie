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
#include <map>

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
#define MAX_CONNECTIONS 5 //SOMAXCONN
//#define DEFAULT_PORT "4876"


class NetCore
{
	 WSADATA wsaData;
	 int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ConnectSocket = INVALID_SOCKET;
	// std::map <SOCKET, std::thread> connectedSockets;
	std::vector<SOCKET>connectedSockets;
	 unsigned int currentConnections;


	//char* recvbuf;
	 char recvbuf[DEFAULT_BUFLEN];
	 const int recvbuflen = 30;

	
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	const char *sendbuf = "Go!";
	

	 IRequestManager* requestManager;
	IServerCore* serverCore;


	int listenChosenSocket(SOCKET socketToListen);
	void sendToAll(std::string message);
	void sendToAllExcept(SOCKET socket, std::string message);
	 void serveSocket(SOCKET socket);

	int runAsServer();



	//int sendReply(requestType rType, std::string requestText);
	int sendReply(SOCKET socket, std::string requestText);

	 std::string receiveRequest(SOCKET socket);

	 
	 std::vector<std::thread > threads;

public:
	NetCore(IServerCore* serverCore);
	~NetCore();



};

#endif
