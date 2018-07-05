// Andrew Wilson - #16211406
// February 27, 2018
// CS201R - Gharibi
// Program #3 - UMKC Faculty & Students

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#pragma once

using namespace std;

class Members
{
public:
	Members(const string& firstName_, const string& lastName_, const int& ID_);
	Members();
	void printMember();
	void readWriteMembers(ifstream &instream_, ofstream &outstream_);
	string getFirstName();
	string getLastName();
	int getID();
	void setFirstName(string);
	void setLastName(string);
	void setID(int);
	
private:
	string firstName, lastName;
	int ID;
};
