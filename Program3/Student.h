// Andrew Wilson - #16211406
// February 27, 2018
// CS201R - Gharibi
// Program #3 - UMKC Faculty & Students

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Members.h"
#pragma once

using namespace std;

class Student : public Members
{
public:
	Student(const string& firstName_, const string& lastName_, const int& ID_, const string& major_);
	Student();
	void printMember();
	void readWriteMembers(ifstream &instream_, ofstream &outstream_);
	string getMajor();
	void setMajor(string);

private:
	string major;
};