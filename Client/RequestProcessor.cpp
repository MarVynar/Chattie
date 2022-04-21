#include "RequestProcessor.h"
#include "RequestType.h"



RequestProcessor::RequestProcessor()
{
}


RequestProcessor::~RequestProcessor()
{
}

bool RequestProcessor::processReply(std::string replyText)
{
	//switch (type) {
	//std::string request = replyText.substr(1);

	switch ((requestType)(replyText[0] - 48)) {

	case nicknameChecking:
		return (replyText == "0Yes") ? true : false;  // fix Hardcode
													  //return false;
		break;
	case  sendingMessage:
		break;

	default: break;


	}

	return true;
}
