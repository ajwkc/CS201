// Andrew Wilson - #16211406
// February 3, 2018
// CS201R - Gharibi
// Program #1: Bank Account Interface


#include <iostream>
#include <string>
#include <limits> // For catching invalid input
#include <math.h> // For pow()
using namespace std;

double account = 1000000;

void printRow(string, int);
void printMenu();
void promptSelection();
void systemExit();
void withdrawMoney(double& balance);
void depositMoney(double& balance);
void applyLoan();
double monthlyPayment(double, double, double);

int main()
{
	// Rounds all double output to two decimal points
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	printMenu();
	promptSelection();
	return 0;
}

void printRow(string s, int i) 
{
	do
	{
		cout << s;
		i--;
	} while (i > 0);
	cout << endl;
}

void printMenu()
{
	printRow("=", 75);
	cout << "Welcome to our system!\n"
		<< "Below are the operations you can make.\n";
	printRow("-", 75);
	cout << "1: Withdraw the cost from your account\n"
		<< "2: Deposit to your account\n"
		<< "3: Apply for a loan\n"
		<< "0: Exit the system\n";
	printRow("=", 75);
}

void promptSelection()
{
	int j = 4;
	while (j > 0)
	{
		cout << "Your account currently holds $" << account
			<< "\nPlease select the operation you would like to use.\n";
		cin >> j;

		// Catches invalid or out-of-bounds input
		// Used from https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
		if (cin.fail() || j > 4 || j < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please make a valid selection\n\n";
		}

		else if (j == 0)
			systemExit();

		else if (j == 1)
			withdrawMoney(account);

		else if (j == 2)
			depositMoney(account);

		else if (j == 3)
			applyLoan();
	}
}

void systemExit()
{
	cout << "Thank you for using our system.\n\n";
	system("pause");
}

void withdrawMoney(double& balance)
{
	double withdraw;
	cout << "Please enter the amount of your withdrawl: $";
	cin >> withdraw;
	cout << endl;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter only a number\n\n";
	}

	else if (withdraw > balance)
	{
		cout << "You may not withdraw more than what you have.\n\n";
	}

	else
	{
		balance -= withdraw;
		cout << "Your account has been debited $" << withdraw
			<< ". Please take your cash.\n\n";
	}
}

void depositMoney(double& balance)
{
	double deposit;
	cout << "Please enter the amount of your deposit: $";
	cin >> deposit;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter only a number\n\n";
	}

	else if (deposit < 0)
	{
		cout << "You may not deposit a negative amount.\n\n";
	}

	else
	{
		balance += deposit;
		cout << "Your account has been credited $" << deposit << "\n\n";
	}
}

void applyLoan()
{
	double score, rate, loan, months;

	cout << "Please enter your credit score: ";
	cin >> score;
	if (cin.fail() || score <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid credit score\n\n";
		return;
	}
	else if (score <= 500)
		rate = 0.05;
	else if (score > 500 && score <= 700)
		rate = 0.02;
	else rate = 0.01;

	cout << "Please enter the loan size you would like to apply for: $";
	cin >> loan;
	if (cin.fail() || loan <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid loan amount\n\n";
		return;
	}
	
	cout << "Please enter how many months you will pay the loan back in: ";
	cin >> months;

	if (cin.fail() || months <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid number of months\n\n";
		return;
	}

	cout << "Your monthly payment will be $ "
		<< monthlyPayment(loan, rate, months) << "\n\n";
}

double monthlyPayment(double p, double r, double n)
{
	double a;
	a = (p*(pow((1 + r), (n / 12)))) / n;
	return a;
}