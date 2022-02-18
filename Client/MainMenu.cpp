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

	bool requestResult = false;
	do {
		try {
			std::cout << "Please enter your nickname\n";
			std::cin >> nickName;
		}
		
		catch (...) { std::cout << "Wrong input\n"; continue; }

		requestResult = requestManager->makeRequest(nicknameChecking, nickName);
		std::cout <<"Req result" <<requestResult << std::endl;
		if (!requestResult) {

			std::cout << "Would you like to save profile?Y/N";
			char result;
			std::cin >> result;
			if (result=='Y'|| result== 'y')requestManager->makeRequest(nicknameAdding, nickName);
		}

	} while (!requestResult);
	//if(requestManager->makeRequest(nicknameChecking, nickName )){}
	//else {}
		
	//if (false) return false;
	std::cout << "menu Ends \n";
	char ch;
	std::cin >> ch;
	return true;
	
}


//MainMenu::MainMenu(ChatApplication* application ): IAppMenu(application)
//{
//	
//	
//}
