// Andrew Wilson #16211406
// CS201R
// Program #7 - Hospital System
// May 10, 2018

#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

class Queue
{
public:
	struct Patient
	{
		string firstName;
		string lastName;
		int ssn;
		bool urgent = false;
		Patient *link;
	};

	void addPatient();
	void addPriorityPatient();
	void removePatient();
	void cancelPatient();
	void displayQueue();
	
private:
	Patient *front = nullptr;
	Patient *back = nullptr;
};

void printMainMenu();

void printSubMenu(Queue q, string type);

#endif