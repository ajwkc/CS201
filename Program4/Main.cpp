// Andrew Wilson - #16211406
// March 14, 2018
// CS201R - Gharibi
// Program #4 - Gym Checkout System

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"

using namespace std;

int main()
{
	typedef Student* stuArray;
	stuArray arr = new Student[30];
	cout << "Student array created" << endl;

	ifstream fin("students.txt");
	cout << "students.txt stream opened." << endl;

	int nStudents = 0;
	while (!fin.eof())
	{
		fin >> arr[nStudents];
		cout << arr[nStudents];
		nStudents++;
	}

	cout << "variable i equals " << nStudents << endl;

	for (int j = 0; j < nStudents; j++)
		cout << arr[j];

	cout << "array built. Moving onto checkout stage\n";

	fin.close();
	cout << "Students.txt closed now\n";
	system("pause");
	
	fin.open("itemsCheckedOUT.txt");

	unsigned int IDout;
	string itemOut;

	while (fin.peek())
	{

		cout << "in the next while loop\n";
		fin >> IDout >> itemOut;
		cout << "IDout is " << IDout << " and itemOut is " << itemOut << endl;
		for (int j = 0; j < nStudents; j++)
		{
			if (arr[j].getID() == IDout)
			{
				arr[j] += itemOut;
				cout << itemOut << " was added to " << arr[j].getID() << endl;
				cout << arr[j];
				system("pause");
				break;
			}
		}
	}

	for (int j = 0; j < nStudents; j++)
		cout << arr[j];
	
	system("pause");
	return 0;
}