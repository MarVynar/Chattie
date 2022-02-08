#ifndef PROFILEDATABASE_H
#define PROFILEDATABASE_H

//#include "Profile.h"
#include <vector>

class ProfileDatabase
{
//	std::vector<Profile> profiles;
	std::vector<std::string> profiles;
	std::string profileDatabasePath= "Profiles.dat";
	
	//void sortDatabase();
	public:
		
		void addProfile(std::string nickName);
		bool findProfile(std::string nickName);
};

#endif
