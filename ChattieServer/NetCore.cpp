#include "NetCore.h"


int NetCore::listenChosenSocket(SOCKET socketToListen)
{
	SOCKET connectSocket = accept(socketToListen, NULL, NULL); 
	if (ConnectSocket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}


	int iSendResult = 0;

	
}

void NetCore::sendToAll(std::string message)
{
	//for each (auto it in connectedSockets)
	for (auto it = connectedSockets.begin(); it!= connectedSockets.end(); it++)
	{
	//	sendReply(it->first, message);
	}
}

void NetCore::sendToAllExcept(SOCKET socket, std::string message)
{

	//for (auto it = connectedSockets.begin(); it != connectedSockets.end(); it++)
	//{
	//	if (it->first!= socket) sendReply(it->first, message);
	//}
	/*for (auto it = connectedSockets.begin(); it != connectedSockets.end; it++) {

		sendReply(*it, message);
	}*/

	std::cout << "To Send " << message << std::endl;
	for (int it = 0; it < connectedSockets.size(); it++) {
		std::cout << "To Socket " << it << std::endl;
		sendReply(connectedSockets[it], message);
	}
}

NetCore::NetCore(IServerCore* serverCore)
{
	currentConnections = 0; //decrease on disconnect and delete from set
	this->serverCore = serverCore ;
	requestManager = new RequestManager(serverCore);
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
	std::cout << "Running Server" << std::endl;


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
			//return 1;
			//runAsServer();
		}

		else
		{
		
			printf("sock n go");
			SOCKET tempSocket = ListenSocket;

			iResult = bind(tempSocket, result->ai_addr, (int)result->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				printf("bind failed with error: %d\n", WSAGetLastError());
				freeaddrinfo(result);
				closesocket(ListenSocket);
				WSACleanup();
				//return 1;
				//runAsServer();
			}

			freeaddrinfo(result);
			do { //
			iResult = listen(tempSocket, MAX_CONNECTIONS); //Max connects
			if (iResult == SOCKET_ERROR) {
				printf("listen failed with error: %d\n", WSAGetLastError());
				closesocket(tempSocket);
				WSACleanup();
				continue;
			}

			


			ConnectSocket = accept(tempSocket, NULL, NULL); 
			if (ConnectSocket == INVALID_SOCKET) {
				printf("accept failed with error: %d\n", WSAGetLastError());
				closesocket(tempSocket);
				WSACleanup();
				continue;
			}


			int iSendResult = 0;



			currentConnections++;
			connectedSockets.push_back(ConnectSocket);
			std::cout << "Connections " << connectedSockets.size() << std::endl;
	
			threads.push_back( std::thread(&NetCore::serveSocket, this, ConnectSocket));

			
			} while (currentConnections < MAX_CONNECTIONS);
		}

		for (auto it = threads.begin(); it != threads.end(); it++)
		{
			std::cout << "Join\n";
			//it->second.join(); 
			it->join();
		}
		
	
	return 0;
}




int NetCore::sendReply(SOCKET socket, std::string requestText)
{
	int iSendResult = 0;

	if (iSendResult != SOCKET_ERROR) {

		std::cout << "Reply Text" << requestText<< std::endl;
		std::cout << "Sending reply " << requestText.c_str() << "." << std::endl;
		iSendResult = send(socket, requestText.c_str(), requestText.length()+1, 0);

		if (iSendResult == SOCKET_ERROR) {
			printf("send failed with error: %d\n", WSAGetLastError());
			closesocket(socket);
			WSACleanup();
			//currentConnections--;
			return 1;
		}
	
	}
}




 std::string  NetCore::receiveRequest(SOCKET socket)
{
	iResult = recv(socket, recvbuf, recvbuflen + 1, 0);

	std::cout << "RecvBuf" << recvbuf << "!" << std::endl;
	
	return requestManager->processReceivedRequest((recvbuf));

}



void NetCore::serveSocket(SOCKET socket){
	
	std::cout << "Running Cycle" << std::endl;
	
	
	{
		bool isLogged = false;
		do {

			
			std::string reply = receiveRequest(socket);
			std::cout << "To Reply" << reply << std::endl;
			
			if (reply!= "0") sendReply(socket, reply);
			if (reply == "0Yes" || reply == "2Added") isLogged = true;   //Hardcode? fix

			


		} while (!isLogged);

		std::cout << "Logged" << std::endl;
		while (true) {	
			std::string message = receiveRequest(socket);
			serverCore->addMessage(message);
			sendToAllExcept(socket, message);
		}
	}

	
}

