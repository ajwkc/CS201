// Andrew Wilson - #16211406
// February 18, 2018
// CS201R - Gharibi
// Program #2 - Bank Customer Data

// ALGORITHM
// 1) Open file containing account names and balances
// 2) Input each line at a time, placing all data into separate arrays
// 3) Close file
// 4) Display menu, prompting user to make a selection
// 5) If option 1, print all data in columns (each index matches one customer)
// 6) If option 2, print just IDs, first and last names
// 7) If option 3, print IDs, savings and checking balances as well as total balance
// 8) If option Q, quit program
// 9) If invalid input, alert user and display menu again

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Account.h"
// I created an Account class that I did not end up using in my code.
// It is included here anyway.

using namespace std;

void printMenu();
// Precondion: User has different choices in displaying data
// Postcondition: Display options and instructions are printed

void printCustomersData(const int id[], const string first[], const string last[], const double
	savings_Account[], const double checking_Account[], int size);
// Precondition: IDs, names and balances are stored in separate arrays
// Postcondition: all of this data is printed, one line for each customer

void printNames(const int id[], const string first[], const string last[], int size);
// Precondition: IDs, names and balances are stored in separate arrays
// Postcondition: only IDs and names are printed

void printTotal(const int id[], const double savings_Account[], const double checking_Account[], const double total[], int size);
// Precondition: IDs, names and balances are stored in separate arrays
// Postcondition: only IDs, balances and totals are printed

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	// Sets all doubles to two decimal places, which makes sense for account balances

	const int size = 10;
	// All input files contain at most 10 customer accounts
	
	ifstream fin;
	fin.open("input.txt");

	Account account[size];
	// This is an array of all the accounts. It is filled, but never used.

	int IDArray[size];
	string fNameArray[size];
	string lNameArray[size];
	double savingsArray[size];
	double checkingArray[size];
	double totalArray[size];

	int ID_;
	string fName_, lName_;
	double savings_, checking_;
	// These are temporary variables for filling the arrays. 

	int i = 0;
	do
	{
		fin >> ID_ >> fName_ >> lName_ >> savings_
			>> checking_;
		// All of the data is read from each line.

		IDArray[i] = ID_;	
		fNameArray[i] = fName_;	
		lNameArray[i] = lName_;		
		savingsArray[i] = savings_;	
		checkingArray[i] = checking_;
		totalArray[i] = savings_ + checking_; // Array contains the total balance for each customer
		account[i] = Account(ID_, fName_, lName_, savings_, checking_);
		i++;
		// Each customer has the same index for all arrays
	} while (!fin.eof());

	fin.close();

	char choice;
	bool repeat = true;
	do
	{
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case '1':
			printCustomersData(IDArray, fNameArray, lNameArray, savingsArray, checkingArray, size);
			break;

		case '2':
			printNames(IDArray, fNameArray, lNameArray, size);
			break;

		case '3':
			printTotal(IDArray, checkingArray, savingsArray, totalArray, size);
			break;

		case '4':
		case 'q':
		case 'Q':
			repeat = false;
			cout << endl << "Thanks for using my program. Goodbye!!" << endl;
			system("pause");
			return 0;

		default:
			cout << "Invalid entry. Please select an option from the menu." << endl << endl;
		}
	} while (repeat == true);
	// Loop repeats after each option, unless '4', 'q' or 'Q' are selected.
}

void printMenu()
{
	cout << "1. Print all customer's data" << endl;
	cout << "2. Print names and IDs" << endl;
	cout << "3. Print accounts total" << endl;
	cout << "4. Enter q/Q to quit" << endl << endl;
	cout << "Enter your choice, or 'q' or 'Q' to quit: ";
}

void printCustomersData(const int id[], const string first[], const string last[], const double
	savings_Account[], const double checking_Account[], int size)
{
	int i;
	const char space = ' ';

	cout << endl;
	cout << left << setw(10) << setfill(space) << "ID";
	cout << left << setw(10) << setfill(space) << "First";
	cout << left << setw(20) << setfill(space) << "Last";
	cout << left << setw(20) << setfill(space) << "Savings Account";
	cout << left << setw(20) << setfill(space) << "Checking Account" << endl;
	// Prints the header line for the table

	for (i = 0; i < size; i++)
	{
		if (id[i] != 0)
		{
			cout << left << setw(10) << setfill(space) << id[i];
			cout << left << setw(10) << setfill(space) << first[i];
			cout << left << setw(20) << setfill(space) << last[i];
			cout << "$" << left << setw(19) << setfill(space) << savings_Account[i];
			cout << "$" << left << setw(19) << setfill(space) << checking_Account[i] << endl;
			// Prints the table
		}
	}
	cout << endl;
}

void printNames(const int id[], const string first[], const string last[], int size)
{
	int i;
	const char space = ' ';

	cout << endl;
	cout << left << setw(10) << setfill(space) << "ID";
	cout << left << setw(10) << setfill(space) << "First";
	cout << left << setw(20) << setfill(space) << "Last" << endl;
	// Prints the header line for the table

	for (i = 0; i < size; i++)
	{
		if (id[i] != 0)
		{
			cout << left << setw(10) << setfill(space) << id[i];
			cout << left << setw(10) << setfill(space) << first[i];
			cout << left << setw(20) << setfill(space) << last[i] << endl;
			// Prints the table
		}
	}
	cout << endl;
}

void printTotal(const int id[], const double savings_Account[], const double checking_Account[], const double total[], int size)
{
	int i;
	const char space = ' ';

	cout << endl;
	cout << left << setw(10) << setfill(space) << "ID";
	cout << left << setw(20) << setfill(space) << "Savings Account";
	cout << left << setw(20) << setfill(space) << "Checking Account";
	cout << left << setw(20) << setfill(space) << "Total" << endl;
	// Prints the header line for the table

	for (i = 0; i < size; i++)
	{
		if (id[i] != 0)
		{
			cout << left << setw(10) << setfill(space) << id[i];
			cout << "$" << left << setw(19) << setfill(space) << savings_Account[i];
			cout << "$" << left << setw(19) << setfill(space) << checking_Account[i];
			cout << "$" << left << setw(19) << setfill(space) << total[i] << endl;
			// Prints the table
		}
	}
	cout << endl;
}