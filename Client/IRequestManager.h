#ifndef IREQUESTMANAGER_H
#define IREQUESTMANAGER_H

#include <string>
#include "RequestType.h"
#include "NetCore.h"

//enum requestType { nicknameChecking, sendMessage
//};

class IRequestManager
{
	virtual void sendRequest(requestType type, std::string requestText) = 0;
	public:
		
		IRequestManager();
		virtual ~IRequestManager() =0;
		
		virtual bool makeRequest(requestType type, std::string requestText ) =0;
		
		virtual bool processReply( std::string replyText)=0;
		virtual std::string getReply() = 0;

	protected:	

		NetCore* netCore;
			
		
};

#endif
