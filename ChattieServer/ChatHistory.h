#pragma once
#include <string>
#include<list>

#define CAPACITY 10
#define SAVECOUNT 5

class ChatHistory
{
	std::string chatHistoryPath = "ChatHistory.dat";
	std::list<std::string> messages;

	bool getHistory();
	void saveHistory();
	unsigned int capacityCount;
	unsigned int saveCount;

public:
	ChatHistory();
	~ChatHistory();

	void addMessage(std::string nickName);
	//getHistory();


};

