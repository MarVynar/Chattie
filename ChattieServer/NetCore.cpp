#include "NetCore.h"


NetCore::NetCore(IServerCore* serverCore)
{
	this->serverCore = serverCore ;
	requestManager = new RequestManager();
 runAsServer(); 

}

NetCore::~NetCore()
{
	closesocket(ConnectSocket);
	closesocket(ListenSocket);
	WSACleanup();
	
	delete requestManager;
}

int NetCore::runAsServer()
{



	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;


	iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}


	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}


	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}


	ConnectSocket = accept(ListenSocket, NULL, NULL);
	if (ConnectSocket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}


	int iSendResult = 0;

	
	return 0;
}



int NetCore::sendReply(requestType rType, std::string requestText)
{
	int iSendResult = 0;

	if (iSendResult != SOCKET_ERROR) {

		/*char* replyMessage = new char[2];
		replyMessage[0] = reply;
		replyMessage[1] = '\0';*/
		std::string reply;
		std::cout << "Sending reply " <<reply.c_str() << "." << std::endl;
		iSendResult = send(ConnectSocket, reply.c_str(), reply.length()+1, 0);

		if (iSendResult == SOCKET_ERROR) {
			printf("send failed with error: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}
	
	}
}



//char NetCore::receiveReply()
std::string  NetCore::receiveRequest()
{
	iResult = recv(ConnectSocket, recvbuf, recvbuflen + 1, 0);

	std::cout << "RecvBuf" << recvbuf << "!" << std::endl;
	
	requestManager->processReceivedRequest((recvbuf));
	//return recvbuf[0];
	return recvbuf;
}

void NetCore::serverCycle(){
	
	
	//threads
	while(true){
		
		receiveRequest();
		
		
		
	}
	
}

