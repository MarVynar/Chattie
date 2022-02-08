#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include "IRequestManager.h"

class RequestManager : public IRequestManager
{
	public:
		
		
		~RequestManager();
		
		bool makeReply(requestType type, std::string requestText );
	 	void sendReply(requestType type, std::string requestText);
		bool processReceivedRequest(std::string replyText);

};

#endif
