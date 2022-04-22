#include "RequestProcessor.h"
#include "RequestType.h"


RequestProcessor::RequestProcessor()
{
}


RequestProcessor::~RequestProcessor()
{
}

std::string RequestProcessor::processReceivedRequest(std::string replyText, IServerCore* serverCore)
{
	std::string request = replyText.substr(1);

	std::string result;
	switch ((requestType)(replyText[0] - 48)) {
		bool found;
	case nicknameChecking:

		found = serverCore->checkNickName(request);

		result = replyText[0];
		if (found) result += "Yes";
		else result += "No";
		//result = (replyText[0] + (serverCore->checkNickName(request)) ? "Yes" : "No");

		return result;
		//return (replyText[0] +(serverCore->checkNickName(request)) ? "Yes" : "No");

		break;
	case  sendMessage:

		serverCore->addMessage(request);
		//return replyText[0] +  request;
		return replyText;

		break;
	case nicknameAdding: // adding to profile Database

		serverCore->addNickName(request);

		//adding returns success or fail
		return replyText[0] + "Added";
		break;

	default: break;


	}

	return "0";
}
