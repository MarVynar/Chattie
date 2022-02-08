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


bool RequestManager::processReceivedRequest(std::string replyText){

	switch ((requestType) (replyText[0]-48)) {
			
	case nicknameChecking: 
		return (replyText == "Yes") ? true : false; 
		//return false;
		break;
	case  sendMessage: // adding to history
	// and sending
				break;
	case nicknameAdding: // adding to profile Database
		
		break;
			
	default : break;
		
		
		}

	return true; 

}


RequestManager::~RequestManager(){
	
	
}
