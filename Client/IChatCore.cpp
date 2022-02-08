#include "IChatCore.h"

IChatCore::IChatCore(IRequestManager * requestManager)
{
	this->requestManager = requestManager;
}

IChatCore::~IChatCore() {
	delete requestManager;
}

