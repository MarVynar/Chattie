#include "ProfileDatabase.h"
#include <fstream>
#include <iostream>

using namespace std;

void ProfileDatabase::addProfile(std::string nickName){
	
	ofstream dataFile;
	//dataFile.open(profileDatabasePath, ofstream::app);
	dataFile.open(profileDatabasePath, ofstream::app);
	
	if(dataFile.is_open()){
		profiles.push_back(nickName);
		for (std::vector<string>::iterator iter= profiles.begin(); iter!=profiles.end(); iter++){
			
			
		}
		
	//	dataFile.write((char*)&this, sizeof(ProfileDatabase)); 
		
	}
	else{
		
		cout<<"Error reading file\n";
		
	}
	
	dataFile.close();
}

bool ProfileDatabase::findProfile(std::string nickName){
	
		ifstream dataFile;

	dataFile.open(profileDatabasePath);
	
	if(dataFile.is_open()){
	
		dataFile.read((char*)this, sizeof(ProfileDatabase)); 
		
	}
	else{
		
		cout<<"Error reading file\n";
		
	}
	
	dataFile.close();
	
	return true;
}
