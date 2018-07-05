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

Members::Members(const string& firstName_, const string& lastName_, const int& ID_)
	: firstName(firstName_), lastName(lastName_), ID(ID_)
{}

Members::Members()
	: firstName("NA"), lastName("NA"), ID(0)
{}

void Members::printMember()
{
	cout << "Member name is: " << getFirstName() << " " << getLastName() << ". "
		<< "The ID is: " << getID() << "." << endl;
}

void Members::readWriteMembers(ifstream &instream_, ofstream &outstream_)
{}
// This function is used with Faculty & Students, but not with Members base class

string Members::getFirstName()
{
	return firstName;
}


string Members::getLastName()
{
	return lastName;
}

int Members::getID()
{
	return ID;
}

void Members::setFirstName(string firstName_)
{
	firstName = firstName_;
}

void Members::setLastName(string lastName_)
{
	lastName = lastName_;
}

void Members::setID(int ID_)
{
	ID = ID_;
}