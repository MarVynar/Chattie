#include "ServerCore.h"
#include <iostream>



ServerCore::~ServerCore()
{
}


bool ServerCore::checkNickName(std::string nickName){
	
	//return profileDataBase->findProfile(nickName);
	bool result = profileDataBase->findProfile(nickName);
	
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


