#include "IRequestManager.h"


IRequestManager::IRequestManager()
{
	netCore = new NetCore();
}

IRequestManager::~IRequestManager(){
	
	delete netCore;
}


/////
void IRequestManager::sendRequest(requestType type, std::string requestText){



}



//bool IRequestManager::makeRequest(requestType type, std::string requestText ){}

