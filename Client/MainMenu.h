#ifndef MAINMENU_H
#define MAINMENU_H

#include "IAppMenu.h"
#include "Requestmanager.h"

class MainMenu : public IAppMenu
{
	public:
	
	MainMenu(IRequestManager* requestManager);
	~MainMenu();
		
	bool	showMenu() override;

};

#endif
