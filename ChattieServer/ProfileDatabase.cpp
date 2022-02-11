#include "ProfileDatabase.h"
#include <fstream>
#include <iostream>

using namespace std;

void ProfileDatabase::addProfile(std::string nickName){
	
	ofstream dataFile;
	//dataFile.open(profileDatabasePath, ofstream::app);
	dataFile.open(profileDatabasePath, ofstream::app);
	
	if(dataFile.is_open()){
		//profiles.push_back(nickName);
					
			char* temp = new char[(nickName).length() + 1];
			//strcpy(temp, (nickName).c_str());
			strcpy_s(temp, (nickName).length(), (nickName).c_str()); //+1?
			dataFile << temp << '\n';
			
		
		
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
	
		//dataFile.read((char*)this, sizeof(ProfileDatabase)); 
		char ch;
		while (dataFile.get(ch)) {

			string temp;
			while (ch != '\n') {
				temp += ch;

			}

			///cout<<temp<<endl; //
			if (temp == nickName) return true;

		}
		return false;
	}
	else{
		
		cout<<"Error reading file\n";
		return false;
	}
	
	dataFile.close();
	
	return true;
}
