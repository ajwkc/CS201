// Andrew Wilson - #16211406
// February 27, 2018
// CS201R - Gharibi
// Program #3 - UMKC Faculty & Students

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Student.h"
#pragma once

using namespace std;

Student::Student(const string& firstName_, const string& lastName_,
	const int& ID_, const string& major_)
	: Members(firstName_, lastName_, ID_), major(major_)
{}

Student::Student()
	: Members(), major("NA")
{}

void Student::printMember()
{
	cout << "Student name is: " << getFirstName() << " " << getLastName() << ". "
		<< "The ID is: " << getID() << ". Major: " << getMajor() << endl;
}

void Student::readWriteMembers(ifstream &instream_, ofstream &outstream_)
// Precondition: input and output streams are declared; student object
// contains all relevant member variables
// Postcondition: student info written to file
{
	string f, fName_, lName_, major_;
	int ID_;

	while (!instream_.eof())
	{
		instream_.clear();
		if (instream_.peek() == 's')
		{
			instream_ >> f >> fName_ >> lName_ >> ID_ >> major_;
			setFirstName(fName_);
			setLastName(lName_);
			setID(ID_);
			setMajor(major_);
			outstream_ << "Student name is: " << getFirstName() << " " << getLastName() << ". "
				<< "The ID is: " << getID() << ". Major: " << getMajor() << endl;
		}
		else
		{
			getline(instream_, f);
		}
	}
	instream_.clear();
	instream_.seekg(0, ios::beg);
}

string Student::getMajor()
{
	return major;
}

void Student::setMajor(string major_)
{
	major = major_;
}

