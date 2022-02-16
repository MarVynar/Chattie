#include "RequestManager.h"


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

	std::string request = replyText.substr(1);

	switch ((requestType) (replyText[0]-48)) {
				
	case nicknameChecking: 
		
		return (replyText[0] +(serverCore->checkNickName(request)) ? "Yes" : "No");
		
		break;
	case  sendMessage: 

		serverCore->addMessage(request);
		//return replyText[0] +  request;
		return replyText;
	
				break;
	case nicknameAdding: // adding to profile Database
		
		serverCore->addNickName(request);
		
		//adding returns success or fail
		return replyText[0] + "Added"; 
		break;
			
	default : break;
		
		
		}

	return "0"; 

}


RequestManager::RequestManager(IServerCore * serverCore) : IRequestManager(serverCore)
{
}

RequestManager::~RequestManager(){
	
	
}
