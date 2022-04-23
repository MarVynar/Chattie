#include "RequestManager.h"



bool RequestManager::makeRequest(requestType type, std::string requestText ){

std::string requestToSend;
//switch (type){
//	
//	case nicknameChecking:  break;
//	case  sendMessage: break;
//	
//	default : break;
//
//
//}
//std::cout << "request text " << requestText << std::endl; // to delete reqToSend
requestToSend = requestText;
sendRequest(type, requestToSend);
//std::cout << "request sent\n ";
if (type == nicknameChecking) return processReply(netCore->receiveReply()); //waiting for needed reply
else { return true; }
}

void RequestManager::sendRequest(requestType type, std::string requestText){

	netCore->sendRequest( type, requestText);

}

RequestManager::RequestManager() :IRequestManager()
{
	requestProcessor = new RequestProcessor();
}


bool RequestManager::processReply( std::string replyText){

	return requestProcessor->processReply(replyText);
}


std::string RequestManager::getReply()
{
	return (netCore->receiveReply()).substr(1);
}


RequestManager::~RequestManager(){
	
	delete requestProcessor;
}
