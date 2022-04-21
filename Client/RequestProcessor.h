#pragma once
#include "IRequestProcessor.h"
class RequestProcessor :
	public IRequestProcessor
{
public:
	RequestProcessor();
	~RequestProcessor();

	 bool processReply(std::string replyText) override;
};

