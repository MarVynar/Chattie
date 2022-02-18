#include "IRequestManager.h"


IRequestManager::IRequestManager(IServerCore* serverCore)
{
	//netCore = new NetCore();
	this->serverCore = serverCore;

}

IRequestManager::~IRequestManager(){
	
	//delete netCore;
}


/////
void IRequestManager::sendReply(requestType type, std::string requestText){



}



//bool IRequestManager::makeRequest(requestType type, std::string requestText ){}

