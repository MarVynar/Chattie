#pragma once

#include<string>

class IRequestProcessor
{
public:
	IRequestProcessor();
	virtual ~IRequestProcessor();

	virtual bool processReply(std::string replyText) = 0;
};

