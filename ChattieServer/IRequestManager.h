#ifndef IREQUESTMANAGER_H
#define IREQUESTMANAGER_H

#include <string>
#include "RequestType.h"
//#include "NetCore.h"
#include "ServerCore.h"

//enum requestType { nicknameChecking, sendMessage
//};

class IRequestManager
{
	public:
		
		IRequestManager(IServerCore* serverCore);
		virtual ~IRequestManager() =0;
		
		virtual bool makeReply(requestType type, std::string requestText ) =0;
		virtual void sendReply(requestType type, std::string requestText)=0;
		virtual std::string processReceivedRequest(std::string replyText)=0;

	protected:	

		//NetCore* netCore;
		IServerCore* serverCore;
			
		
};

#endif
