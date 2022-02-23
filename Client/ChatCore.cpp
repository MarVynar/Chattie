#include<iostream>
#include <thread>
#include<cstdlib>

#include "ChatCore.h"

void ChatCore::updateChat() {

	while (true) {

		cout << requestManager->getReply() << endl;

	}
}


void ChatCore::sendMessage() {
	
	string message;
	
	while (true) {
		
	
		getline(cin, message);

		requestManager->makeRequest(sendingMessage, message); //

	}
	
	
}

void ChatCore::getChathistory()
{
	string messageHistory;
	//requestManager->processReply(sendingMessage, messageHistory);

	if (system("CLS")) system("clear");
	cout << messageHistory << endl;
}



bool ChatCore::runChatCore()
{
	cout << "entering the chat...\n";
	//threads 

	//thread first(&ChatCore::updateChat, this);
	//thread second(&ChatCore::sendMessage);
	thread tr1;
	
	cout << "Before Sending" << endl;
	//char ch;
	//cin >> ch;
	sendMessage();
	tr1 = thread(&ChatCore::updateChat, this);
	
	tr1.join();
	//first.join();
	//second.join();
	//
	return true;
}

ChatCore::ChatCore(IRequestManager * requestManager) :IChatCore(requestManager)
{
	runChatCore();
}



 ChatCore::~ChatCore(){
 	
 }
