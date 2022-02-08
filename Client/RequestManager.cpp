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

sendRequest(type, requestToSend);
if (type == nicknameChecking)return processReply(type, netCore->receiveReply());
else return true;
}

void RequestManager::sendRequest(requestType type, std::string requestText){

	netCore->sendRequest( type, requestText);

}


bool RequestManager::processReply(requestType type, std::string replyText){

	switch (type) {
			
	case nicknameChecking: 
		return (replyText == "Yes") ? true : false; 
		//return false;
		break;
			case  sendingMessage:
				break;
			
			default : break;
		
		
		}

	return true; 

}


RequestManager::~RequestManager(){
	
	
}
