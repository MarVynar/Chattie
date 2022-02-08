#include<iostream>
#include <thread>
#include<cstdlib>

#include "ChatCore.h"

void ChatCore::updateChat() {

	while(true) {

		string messageHistory;
		//requestManager->processReply(sendingMessage, messageHistory);

		if (system("CLS")) system("clear");
		cout << messageHistory << endl;
	}


}


void ChatCore::sendMessage() {
	
	string message;
	while (true) {
		
		//cin >> message; //? getline
		getline(cin, message);
		requestManager->makeRequest(sendingMessage, message);

	}
	

}


bool ChatCore::runChatCore()
{
	cout << "entering the chat...\n";
	//threads 

	thread first(&ChatCore::updateChat, this);
	//thread second(&ChatCore::sendMessage);

	sendMessage();
	
	
	first.join();
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
