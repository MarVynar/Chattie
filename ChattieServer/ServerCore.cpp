#include "ServerCore.h"

//ServerCore::ServerCore():IServerCore()
//{
//}

ServerCore::~ServerCore()
{
}


bool ServerCore::checkNickName(std::string nickName){
	return profileDataBase->findProfile(nickName);
	
}
void ServerCore::addNickName(std::string nickName) // bool, success
{
	
	profileDataBase->addProfile(nickName);
}
		
void ServerCore::saveChatHistory(){
	
}
void ServerCore::loadChatHistory(){
	
	
}
void ServerCore::addMessage(std::string message){
	
	
}

//bool ServerCore::runServerCore() {
//	
//	while (true){
//		
//		
//		
//		
//	}
//	
//}
