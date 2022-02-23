#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include "IRequestManager.h"

class RequestManager : public IRequestManager
{

	void sendRequest(requestType type, std::string requestText) override;
	public:
		
		
		~RequestManager();
		
		bool makeRequest(requestType type, std::string requestText ) override;
		
		bool processReply( std::string replyText) override;
		std::string getReply() override;

};

#endif
