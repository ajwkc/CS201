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

class Faculty : public Members
{
public:
	Faculty(const string& firstName_, const string& lastName_, const int& ID_, const double& salary_);
	Faculty();
	void printMember();
	void readWriteMembers(ifstream &instream_, ofstream &outstream_);
	double getSalary();
	void setSalary(double);

private:
	double salary;
};