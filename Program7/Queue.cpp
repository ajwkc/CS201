// Andrew Wilson #16211406
// CS201R
// Program #7 - Hospital System
// May 10, 2018

#include <iostream>
#include "Queue.h"

using namespace std;

void Queue::addPatient()
{
	string first, last;
	int ssn;
	cout << "Enter patient's first name: ";
	cin >> first;
	cout << "Enter patient's last name: ";
	cin >> last;
	cout << "Enter patient's social security number: ";
	cin >> ssn;
	if (cin.fail())
	{
		cout << "Invalid SSN. Patient cancelled.";
	}
	else if (front == nullptr)
	{
		front = back = new Patient;
		front->firstName = first;
		front->lastName = last;
		front->ssn = ssn;
		front->link = nullptr;
		cout << first << " " << last << " " << " #" << ssn << " added to queue\n\n";
	}
	else
	{
		back->link = new Patient;
		back = back->link;
		back->firstName = first;
		back->lastName = last;
		back->ssn = ssn;
		back->link = nullptr;
		cout << first << " " << last << " " << " #" << ssn << " added to queue\n\n";
	}
}

void Queue::addPriorityPatient()
{
	string first, last;
	int ssn;
	cout << "Enter patient's first name: ";
	cin >> first;
	cout << "Enter patient's last name: ";
	cin >> last;
	cout << "Enter patient's social security number: ";
	cin >> ssn;
	if (cin.fail())
	{
		cout << "Invalid SSN. Patient cancelled.";
	}
	else if (front == nullptr)
	{
		front = back = new Patient;
		front->firstName = first;
		front->lastName = last;
		front->ssn = ssn;
		front->urgent = true;
		front->link = nullptr;
		cout << first << " " << last << " " << " #" << ssn << " added to queue\n\n";
	}
	else
	{
		Patient *firstReg = front;
		Patient *lastPri = nullptr;
		int count = 0;
		while (firstReg->urgent)
		{
			lastPri = firstReg;
			firstReg = firstReg->link;
		}
		if (lastPri == nullptr) // If there are no priority patients
		{
			Patient *addMe = new Patient;
			addMe->firstName = first;
			addMe->lastName = last;
			addMe->ssn = ssn;
			addMe->link = front;
			front = addMe;
		}
		else
		{
			lastPri->link = new Patient;
			lastPri = lastPri->link;
			lastPri->firstName = first;
			lastPri->lastName = last;
			lastPri->ssn = ssn;
			lastPri->urgent = true;
			lastPri->link = firstReg;
		}
	}

}

void Queue::removePatient()
{
	if (front == nullptr)
	{
		cout << "No more patients.\n\n";
	}
	else
	{
		cout << front->firstName << " " << front->lastName << " " << front->ssn << " has been moved to operating room\n\n";
		Patient *remove;
		remove = front;
		front = front->link;
		if (front == nullptr)
			back = nullptr;
		delete remove;
	}
}

void Queue::cancelPatient()
{
	string first, last;
	int ssn;
	cout << "Enter patient's first name: ";
	cin >> first;
	cout << "Enter patient's last name: ";
	cin >> last;
	cout << "Enter patient's social security number: ";
	cin >> ssn;
	Patient *before, *cancel;
	cancel = front;

	if (front == nullptr) // Queue is empty
	{
		cout << "No patients to cancel\n\n";
	}

	else if (front->firstName == first && front->lastName == last && front->ssn == ssn)
	// Cancel patient is at front of queue
	{
		cout << first << " " << last << " #" << ssn << " is removed from the queue\n\n";
		front = front->link;
		delete cancel;
	}

	else
	{
		while (cancel->link != nullptr)
		{
			before = cancel;
			cancel = cancel->link;
			if (cancel->firstName == first && cancel->lastName == last && cancel->ssn == ssn)
			{
				cout << first << " " << last << " #" << ssn << " is removed from the queue\n\n";
				before->link = cancel->link;
				delete cancel;
				break;
			}
		}
		cout << "Patient does not exist.\n\n";
	}

}

void Queue::displayQueue()
{
	Patient *print;
	print = front;

	if (print == nullptr)
		cout << "Queue is empty\n\n";
	else
	{
		while (print != nullptr)
		{
			cout << print->firstName << " " << print->firstName << " #" << print->ssn << endl;
			print = print->link;
		}
	}
}

void printMainMenu()
{
	cout << "Welcome to Starling City Hospital\n";
	cout << "1: Heart Clinic\n";
	cout << "2: Lung Clinic\n";
	cout << "3: Plastic Surgery\n";
	cout << "4: Exit\n";
	cout << "Please enter your choice: ";
}

void printSubMenu(Queue q, string type)
{
	int subchoice = 0;
	while (subchoice != 6)
	{
		cout << endl << endl;
		cout << "Welcome to the " << type << " clinic\n";
		cout << "1: Add patient\n";
		cout << "2: Add critically ill patient\n";
		cout << "3: Take out next patient for operation\n";
		cout << "4: Cancel patient\n";
		cout << "5: List the queue of patients\n";
		cout << "6: Change department or exit\n";
		cout << "Please enter your choice: ";

		cin >> subchoice;

		switch (subchoice)
		{
		case 1:
		{
			q.addPatient();
			break;
		}
		case 2:
		{
			q.addPriorityPatient();
			break;
		}
		case 3:
		{
			q.removePatient();
			break;
		}
		case 4:
		{
			q.cancelPatient();
			break;
		}
		case 5:
		{
			q.displayQueue();
			break;
		}
		case 6:
		{
			cout << "Now exiting " << type << " department\n";
			break;
		}
		}
		
	}
}