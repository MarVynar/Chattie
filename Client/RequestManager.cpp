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
std::cout << "request text " << requestText << std::endl; // to delete reqToSend
requestToSend = requestText;
sendRequest(type, requestToSend);
std::cout << "request sent\n ";
if (type == nicknameChecking) return processReply(netCore->receiveReply()); //waiting for needed reply
else { return true; }
}

void RequestManager::sendRequest(requestType type, std::string requestText){

	netCore->sendRequest( type, requestText);

}


bool RequestManager::processReply( std::string replyText){

	//switch (type) {
	//std::string request = replyText.substr(1);

	switch ((requestType)(replyText[0] - 48)) {
			
	case nicknameChecking: 
		return (replyText == "0Yes") ? true : false;  // fix Hardcode
		//return false;
		break;
			case  sendingMessage:
				break;
			
			default : break;
		
		
		}

	return true; 

}

std::string RequestManager::getReply()
{
	return (netCore->receiveReply()).substr(1);
}


RequestManager::~RequestManager(){
	
	
}
