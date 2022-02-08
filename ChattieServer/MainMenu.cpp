#include "MainMenu.h"
#include <iostream>

#include <string>

MainMenu::MainMenu(IRequestManager * requestManager) :IAppMenu(requestManager)
{
}

MainMenu::~MainMenu() 
{
}

bool MainMenu::showMenu(){
	
	std::string nickName;

	do {
		try {
			std::cout << "Please enter your nickname\n";
			std::cin >> nickName;
		}
		
		catch (...) { std::cout << "Wrong input\n"; continue; }

	} while (!requestManager->makeRequest(nicknameChecking, nickName));
	//if(requestManager->makeRequest(nicknameChecking, nickName )){}
	//else {}
		
	if (false) return false;

	return true;
	
}


//MainMenu::MainMenu(ChatApplication* application ): IAppMenu(application)
//{
//	
//	
//}
