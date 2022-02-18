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
	ofstream chatHistoryFile;
	chatHistoryFile.open(chatHistoryPath, ostream::app);
	char* temp;
	if (chatHistoryFile.is_open()) {
		for (list<std::string>::iterator it = messages.begin(); it != messages.end(); it++) {
		
			temp = new char[(*it).length() + 1];
			strcpy_s(temp, (*it).length() + 1, (*it).c_str());
			chatHistoryFile << temp; //+nickname

			delete[] temp;
		}
		
	}
	
	

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

void ChatHistory::addMessage(std::string nickName, std::string message)
{
	//add message
	messages.push_back(nickName+": "+ message);
	if (capacityCount < CAPACITY) { capacityCount++; }
	else { messages.pop_front(); }
	saveCount++;
	if (saveCount == SAVECOUNT) {

		saveHistory();
		saveCount = 0;
	}
	
	
}
