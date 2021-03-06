#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include "IRequestManager.h"
#include "RequestProcessor.h"

class RequestManager : public IRequestManager
{
	RequestProcessor* requestProcessor;

	public:
		
		RequestManager(IServerCore* serverCore);
		~RequestManager();
		
		bool makeReply(requestType type, std::string requestText ) override;
	 	void sendReply(requestType type, std::string requestText) override;
		std::string processReceivedRequest(std::string replyText) override;

};

#endif
