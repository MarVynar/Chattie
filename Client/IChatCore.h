#ifndef ICHATCORE_H
#define ICHATCORE_H

#include "RequestManager.h"

class IChatCore
{

	

	virtual bool runChatCore()=0;
	public:
		
		IChatCore(IRequestManager* requestManager);
		
		virtual void updateChat() =0;
		virtual void sendMessage() =0;
		virtual ~IChatCore();
	protected:

		IRequestManager* requestManager;
};

#endif
