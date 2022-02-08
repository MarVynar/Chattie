#include "IAppMenu.h"

//IAppMenu::IAppMenu(ChatApplication* application ){
//	this->application = application;
//	
//}

IAppMenu::IAppMenu(IRequestManager * requestManager)
{
	this->requestManager = requestManager;
}

IAppMenu::~IAppMenu() {	delete requestManager;}
