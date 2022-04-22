#pragma once

#include <string>
#include "IServerCore.h"

class IRequestProcessor
{
public:
	IRequestProcessor();
	virtual ~IRequestProcessor();
	virtual std::string processReceivedRequest(std::string replyText, IServerCore* serverCore ) = 0;
};

