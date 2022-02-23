#ifndef CHATCORE_H
#define CHATCORE_H

#include "IChatCore.h"
#include <string>

using namespace std;

class ChatCore : public IChatCore
{
	bool runChatCore() override; 

	public:
		
		ChatCore(IRequestManager* requestManager);

		void updateChat() override;
		void sendMessage() override ;
		void getChathistory() override;
		 ~ChatCore() override;
	
};

#endif
