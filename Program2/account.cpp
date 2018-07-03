// Andrew Wilson - #16211406
// February 17, 2018
// CS201R - Gharibi
// Program #2 - Bank Customer Data

#include <iostream>
#include <string>
#include "Account.h"
// I created an Account class that I did not end up using in my code.
// It is included here anyway.

using namespace std;


Account::Account(int i, string fn, string ln, double s, double c)
{
	ID = i;
	fName = fn;
	lName = ln;
	savings = s;
	checking = c;
}

Account::Account()
{}

int Account::getID()
{
	return ID;
}

double Account::getSavings()
{
	return savings;
}

double Account::getChecking()
{
	return checking;
}

string Account::getFName()
{
	return fName;
}

string Account::getLName()
{
	return lName;
}

void Account::setID(int i)
{
	ID = i;
}
void Account::setSavings(double d)
{
	savings = d;
}

void Account::setChecking(double d)
{
	checking = d;
}

void Account::setFName(string s)
{
	fName = s;
}

void Account::setLName(string s)
{
	lName = s;
}