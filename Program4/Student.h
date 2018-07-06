#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

typedef string* strPtr;

class Student
{
private:
	string first, last;
	unsigned int ID, arrSize, arrCap;
	strPtr itemArray;

public:
	Student();
	Student(unsigned int& _ID, string& _first, string& _last);
	~Student();

	unsigned int const getID();
	string const getFirst();
	string const getLast();
	void setID(const unsigned int& _i);
	void setFirst(const string& _s);
	void setLast(const string& _s);
	int const checkoutCount();
	bool checkOut(const string& _item);
	bool checkIn(const string& _item);
	bool hasCheckedOut(const string& _item);
	void resizeArray();
	void clear();

	Student operator+(const string& _item);
	void operator+=(const string& _item);
	bool operator==(const Student& _rhs) const;
	bool operator!=(const Student& _rhs) const;

	friend ostream &operator<<(ostream &output, const Student& s);
	friend istream &operator>>(istream &input, Student& s);
};


#endif