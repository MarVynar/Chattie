#include "RequestManager.h"
#include <iostream>


bool RequestManager:: makeReply(requestType type, std::string requestText ){

std::string replyToSend;
//switch (type){
//	
//	case nicknameChecking:  break;
//	case  sendMessage: break;
//	
//	default : break;
//
//
//}

//sendReply(type, requestToSend);
//return processReceivedRequest(netCore->receiveReply());
return true;
}

void RequestManager::sendReply(requestType type, std::string requestText){

	//netCore->sendRequest( type, requestText);

}


std::string RequestManager::processReceivedRequest(std::string replyText){

	return requestProcessor->processReceivedRequest(replyText, serverCore);
	
}


RequestManager::RequestManager(IServerCore * serverCore) : IRequestManager(serverCore)
{
	requestProcessor = new RequestProcessor();
}

RequestManager::~RequestManager(){
	
	delete requestProcessor;
}
