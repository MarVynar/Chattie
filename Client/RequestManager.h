#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include "IRequestManager.h"
#include "RequestProcessor.h"

class RequestManager : public IRequestManager
{

	RequestProcessor * requestProcessor;

	void sendRequest(requestType type, std::string requestText) override;
	public:
		RequestManager();
		
		~RequestManager();
		
		bool makeRequest(requestType type, std::string requestText ) override;
		
		bool processReply( std::string replyText) override;
		std::string getReply() override;

};

#endif
