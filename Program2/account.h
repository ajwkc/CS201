// Andrew Wilson - #16211406
// February 17, 2018
// CS201R - Gharibi
// Program #2 - Bank Customer Data

#include <iostream>
#include <string>

// I created an Account class that I did not end up using in my code.
// It is included here anyway.

using namespace std;

class Account
{
private:
	// Data members
	int ID;
	double savings, checking;
	string fName, lName;

public:
	// Default constructor
	Account(int, string, string, double, double);
	Account();

	// Get functions
	int getID();
	double getSavings();
	double getChecking();
	string getFName();
	string getLName();

	// Set functions
	void setID(int);
	void setSavings(double);
	void setChecking(double);
	void setFName(string);
	void setLName(string);	
};

