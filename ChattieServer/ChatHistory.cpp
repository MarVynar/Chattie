#include "ChatHistory.h"
#include <fstream>

using namespace std;


bool ChatHistory::getHistory()
{
	ifstream chatHistoryFile;
	chatHistoryFile.open(chatHistoryPath);
	char ch;
	while (chatHistoryFile.get(ch)) {


		return true;
	}
	return false;
}

void ChatHistory::saveHistory()
{
}

ChatHistory::ChatHistory()
{
	capacityCount = 0;
	saveCount = 0;
	getHistory();


}


ChatHistory::~ChatHistory()
{
}

void ChatHistory::addMessage(std::string nickName)
{
	//add message
	messages.push_back(nickName);
	if (capacityCount < CAPACITY) { capacityCount++; }
	else { messages.pop_front(); }
	saveCount++;
	if (saveCount == SAVECOUNT) {

		saveHistory();
		saveCount = 0;
	}
	
	
}
