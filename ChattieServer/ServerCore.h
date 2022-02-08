#ifndef SERVERCORE_H
#define SERVERCORE_H

#include "IServerCore.h"

class ServerCore : public IServerCore
{
//	bool runServerCore() override;
	

	public:
		//ServerCore();
		~ServerCore() override;
		
		bool checkNickName(std::string nickName);
		void addNickName(std::string nickName);
		
		void saveChatHistory();
		void loadChatHistory();
		void addMessage(std::string message);

};

#endif
