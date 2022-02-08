#ifndef IAPPMENU_H
#define IAPPMENU_H

#include "RequestManager.h"

class IAppMenu
{
	

		void processReply();
		
	public:
		
		IAppMenu(IRequestManager* requestManager);
	
		virtual ~IAppMenu() =0;
		
		virtual bool showMenu() = 0;
	

		
	protected:
		IRequestManager* requestManager;
};

#endif
