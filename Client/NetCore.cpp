#include "NetCore.h"
#include <Windows.h>


NetCore::NetCore()
{
 runAsClient();
	
}

NetCore::~NetCore()
{
	std::cout << "Deleting Netcore\n";
	closesocket(ConnectSocket);
	closesocket(ListenSocket);
	WSACleanup();
}


int NetCore::runAsClient()
{
	

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;


	iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}


	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
		
		do
		{
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		std::cout << ConnectSocket << std::endl;
			if (ConnectSocket == INVALID_SOCKET) {
				printf("socket failed with error: %ld\n", WSAGetLastError());
				WSACleanup();
				return 1;
			}

		////do
		////{

			iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(ConnectSocket);
				ConnectSocket = INVALID_SOCKET;
				printf("Unable to connect to server!\n");
				WSACleanup();
				Sleep(5000);
				continue;
			}
			//else { ConnectSocket = 188; }
			std::cout << ConnectSocket << std::endl;
		} while (ConnectSocket == INVALID_SOCKET);
		////} while (iResult == SOCKET_ERROR);//


		break;
	}

	//std::cout << ConnectSocket << std::endl;
	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}

	


	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf) + 1, 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	printf("Bytes Sent: %ld\n", iResult);



	return 0;

}




int NetCore::sendRequest(requestType rType, std::string requestText)
{
	int iSendResult = 0;

	if (iSendResult != SOCKET_ERROR) {

		
		///
		std::string reply = std::to_string((int)(rType))+ requestText;
		std::cout << reply<<std::endl;
		/////
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


std::string  NetCore::receiveReply()
{
	iResult = recv(ConnectSocket, recvbuf, recvbuflen + 1, 0);

	std::cout << "RecvBuf" << recvbuf << "!" << std::endl;
	//return recvbuf[0];
	return recvbuf;
}
