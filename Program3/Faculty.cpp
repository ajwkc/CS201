// Andrew Wilson - #16211406
// February 27, 2018
// CS201R - Gharibi
// Program #3 - UMKC Faculty & Students

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Faculty.h"
#pragma once

using namespace std;

Faculty::Faculty(const string& firstName_, const string& lastName_,
	const int& ID_, const double& salary_)
	: Members(firstName_, lastName_, ID_), salary(salary_)
{}

Faculty::Faculty()
	: Members(), salary(0)
{}

void Faculty::printMember()
{
	cout << "Faculty name is: " << getFirstName() << " " << getLastName() << ". "
		<< "The ID is: " << getID() << ". Salary: " << getSalary() << endl;
}

void Faculty::readWriteMembers(ifstream &instream_, ofstream &outstream_)
// Precondition: input and output streams are declared; faculty object
// contains all relevant member variables
// Postcondition: faculty info written to file
{
	string f, fName_, lName_;
	int ID_;
	double salary_;

	while (!instream_.eof())
	{
		instream_.clear();
		if (instream_.peek() == 'f')
		{
			instream_ >> f >> fName_ >> lName_ >> ID_ >> salary_;
			setFirstName(fName_);
			setLastName(lName_);
			setID(ID_);
			setSalary(salary_);
			outstream_ << "Faculty name is: " << getFirstName() << " " << getLastName() << ". "
				<< "The ID is: " << getID() << ". Salary: " << getSalary() << endl;
		}
		else
		{
			getline(instream_, f);
		}
	}
	instream_.clear();
	instream_.seekg(0, ios::beg);
}

double Faculty::getSalary()
{
	return salary;
}

void Faculty::setSalary(double salary_)
{
	salary = salary_;
}
