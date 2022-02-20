#include "ProfileDatabase.h"
#include <fstream>
#include <iostream>


using namespace std;

void ProfileDatabase::addProfile(std::string nickName){
	
	ofstream dataFile;
	//dataFile.open(profileDatabasePath, ofstream::app);
	dataFile.open(profileDatabasePath, ofstream::app);
	cout << "Adding " << nickName.c_str() << " to list\n";
	if(dataFile.is_open()){
		//profiles.push_back(nickName);
					
			char* temp = new char[(nickName).length() + 1];
			
			//strcpy(temp, (nickName).c_str());
			strcpy_s(temp, (nickName).length()+1, (nickName).c_str()); //+1?
			dataFile << temp << '\n';
			
		
		
	//	dataFile.write((char*)&this, sizeof(ProfileDatabase)); 
			delete[] temp; 
	}
	else{
		
		cout<<"Error reading file\n";
		
	}
	
	dataFile.close();
}

bool ProfileDatabase::findProfile(std::string nickName){
	
		ifstream dataFile;

	dataFile.open(profileDatabasePath);

	cout << "Looking for " << nickName.c_str() << endl;

	
	if(dataFile.is_open()){
	
		//dataFile.read((char*)this, sizeof(ProfileDatabase)); 
		//*(

		char ch;
		string temp;
		while (dataFile.get(ch)) {

			
			if (ch != '\n') {
				temp += ch;
				
			}
			else {

			
				if (temp == nickName) return true;
				else { temp.clear(); }
			}

			

		}
		cout << "Not found\n";
		return false;//*/
		//return true;
	}
	else{
		
		cout<<"Error reading file\n";
		return false;
	}
	
	dataFile.close();
	
	//return true;
}
