#pragma once
#include "IRequestProcessor.h"
class RequestProcessor :
	public IRequestProcessor
{
public:
	RequestProcessor();
	~RequestProcessor();
	std::string processReceivedRequest(std::string replyText, IServerCore* serverCore) override;
};

