#ifndef SERVERAPPLICATION_H
#define SERVERAPPLICATION_H

//#include "RequestManager.h"
#include "ServerCore.h"
#include "NetCore.h"

#include <iostream>
#include <memory>

class ServerApplication
{
	//std::unique_ptr<IAppMenu> mainMenu;
//	IRequestManager* requestManager;
	IServerCore* serverCore;
	NetCore* netCore;
	
	void run();
	public:
		ServerApplication();
		~ServerApplication();
				
	protected:
};

#endif
