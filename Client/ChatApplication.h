#ifndef CHATAPPLICATION_H
#define CHATAPPLICATION_H

#include "MainMenu.h"
#include "RequestManager.h"

#include <iostream>
#include <memory>

class ChatApplication
{
	//std::unique_ptr<IAppMenu> mainMenu;
	RequestManager* requestManager;
	IAppMenu* mainMenu;
	void run();
	public:
		ChatApplication();
		~ChatApplication();
				
	protected:
};

#endif