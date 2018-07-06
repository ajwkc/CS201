#include "Student.h"
using namespace std;

Student::Student()
	: ID(0), first(""), last(""), arrSize(0), arrCap(5)
{
	itemArray = new string[arrCap];
}

Student::Student(unsigned int& _ID, string& _first, string& _last)
	: ID(_ID), first(_first), last(_last), arrSize(0), arrCap(5)
{
	itemArray = new string[arrCap];
}

unsigned int const Student::getID()
{
	return ID;
}

string const Student::getFirst()
{
	return first;
}

string const Student::getLast()
{
	return last;
}

void Student::setID(const unsigned int& _i)
{
	if ((_i >= 1000) && (_i <= 100000))
		ID = _i;
	else
		ID = 1001;
}

void Student::setFirst(const string& _s)
{
	first = _s;
}

void Student::setLast(const string& _s)
{
	last = _s;
}

int const Student::checkoutCount()
{
	return arrSize;
}

bool Student::checkOut(const string& _item)
{
	if (hasCheckedOut(_item))
		return false;
	if (arrSize == 0)
	{
		itemArray = new string[5];
	}
	itemArray[arrSize] = _item;
	arrSize++;
	if (arrSize == (arrCap - 1))
		resizeArray();
	return true;
}

bool Student::checkIn(const string& _item)
{
	if (hasCheckedOut(_item))
		for (int i = 0; i < arrSize; i++)
		{
			if (itemArray[i] == _item)
			{
				itemArray[i] = "";
				arrSize--;
				return true;
			}
		}
	return false;
}

bool Student::hasCheckedOut(const string& _item)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (itemArray[i] == _item)
			return true;
	}
	return false;
}

void Student::resizeArray()
{
	
	int newSize = arrCap * 2;
	strPtr temp = new string[newSize];
	for (int i = 0; i < arrSize; i++)
	{
		temp[i] = itemArray[i];
	}
	
	itemArray = temp;
	arrCap = newSize;
}

void Student::clear()
{
	ID = 0;
	first = "";
	last = "";
	delete[] itemArray;
	arrCap = 5;
	arrSize = 0;
	cout << "Studnet was cleared\n";
}

Student::~Student()
{

}

Student Student::operator+(const string& _item)
{
	if (!hasCheckedOut(_item))
	{
		if (arrSize == (arrCap - 1))
		{
			resizeArray();
		}
		itemArray[arrSize] = _item;
		arrSize++;
	}
	return *this;
}

void Student::operator+=(const string& _item)
{
	if (!hasCheckedOut(_item))
	{
		for (int i = 0; i < arrCap; i++)
		{
			if (itemArray[i] == "")
			{
				itemArray[i] = _item;
				arrSize++;
				break;
			}
		}
	}
}

bool Student::operator ==(const Student& _rhs) const
{
	return (ID == _rhs.ID);
}

bool Student::operator !=(const Student & _rhs) const
{
	return !(ID == _rhs.ID);
}

ostream &operator<<(ostream & output, const Student& _s)
{
	output << _s.ID << " " << _s.first << " " << _s.last << endl;
	output << _s.arrSize << endl;
	if (_s.arrSize == 0)
	{
		output << endl;
		return output;
	}
	for (int i = 0; i < _s.arrSize; i++)
		output << _s.itemArray[i] << " ";
	output << endl << endl;
	return output;
}

istream &operator>>(istream & input, Student& _s)
{
	int nFill;
	cout << "In the extraction\n";
	_s.clear();
	input >> _s.ID >> _s.first >> _s.last >> nFill;
	cout << _s.ID << " " << _s.first << " " << _s.last << " " << nFill << endl;
	if (nFill == 0)
	{
		cout << "no items checked out, moving on\n";
		return input;
	}

	string item;
	cout << "about to add some items, increasing array capacity to 5\n";
	_s.arrCap = 5;
	_s.itemArray = new string[_s.arrCap];

	for (int i = 0; i < nFill; i++)
	{
		input >> item;
		_s = _s + item;
		cout << "array index " << i << " contains " << _s.itemArray[i] << endl;
			
	}
	return input;
}
