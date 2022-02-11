#ifndef ISERVERCORE_H
#define ISERVERCORE_H

//#include "NetCore.h"
#include "ProfileDatabase.h"
#include "ChatHistory.h"
//#include "RequestManager.h"

class IServerCore
{

	//IRequestManager* requestManager;
	//NetCore* netCore;


	//virtual bool runServerCore()=0;	
		
	public:
		
	//	IServerCore(IRequestManager* requestManager);
		IServerCore();

		virtual bool checkNickName(std::string nickName) =0;
		virtual void addNickName(std::string nickName) =0;
		//sort Profiles
		
		virtual void saveChatHistory() =0;
		virtual void loadChatHistory() =0;
		virtual void addMessage(std::string message) =0;
		
		virtual ~IServerCore();
		
	protected:
		
		
		//std::string chatHistoryPath ="ChatHistory.dat";
		ProfileDatabase* profileDataBase;
		ChatHistory* chatHistory;
};

#endif
