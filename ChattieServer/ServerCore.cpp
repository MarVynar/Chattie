#include "ServerCore.h"
#include <iostream>

//ServerCore::ServerCore():IServerCore()
//{
//}

ServerCore::~ServerCore()
{
}


bool ServerCore::checkNickName(std::string nickName){
	std::cout <<"Looking for "<<nickName << std::endl;
	//return profileDataBase->findProfile(nickName);
	bool result = profileDataBase->findProfile(nickName);
	std::cout << "Search res " << result << std::endl;
	return result;
	
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
