#include "IServerCore.h"

IServerCore::IServerCore()
{
//	this->requestManager = requestManager;

	//runServerCore();
	profileDataBase = new ProfileDatabase();
	chatHistory = new ChatHistory();
}

IServerCore::~IServerCore() {
//	delete requestManager;
	delete profileDataBase;
	delete chatHistory;
}

