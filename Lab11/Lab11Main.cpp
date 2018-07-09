// Andrew Wilson - #16211406
// CS201L
// April 24, 2018
// Lab #11 - Templates

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<class T>
void mySwap(T a[], int i, int j);

template<class T>
T myMin(T a[]);

template<class T>
T myMax(T a[]);

template<class T>
int mySearch(T a[], T target);

int main()
{
	// Open the output file
	ofstream fout("output.txt");

	// Create an array of doubles and fill it
	double dblArray[100];
	ifstream finDbl("doubles.txt");
	for (int i = 0; i < 100; i++)
	{
		finDbl >> dblArray[i];
	}
	
	// Create an array of integers and fill it
	int intArray[100];
	ifstream finInt("integers.txt");
	for (int i = 0; i < 100; i++)
	{
		finInt >> intArray[i];
	}

	// Create an array of strings and fill it
	string strArray[100];
	ifstream finStr("strings.txt");
	for (int i = 0; i < 100; i++)
	{
		finStr >> strArray[i];
	}

	// Print the integer file data
	fout << "Integers:\n";
	fout << "Swapped items at positions 10 and 20\n";
	fout << "Before: [10] " << intArray[10] << " [20] " << intArray[20] << endl;
	mySwap(intArray, 10, 20);
	fout << "After: [10] " << intArray[10] << " [20] " << intArray[20] << endl;
	fout << "Minimum: " << myMin(intArray) << endl;
	fout << "Maximum: " << myMax(intArray) << endl;
	fout << "The number 1 is at position " << mySearch(intArray, 1) << endl;
	fout << "The number 5 is at position " << mySearch(intArray, 5) << endl << endl;

	// Print the double file data
	fout << "Doubles:\n";
	fout << "Swapped items at positions 10 and 20\n";
	fout << "Before: [10] " << dblArray[10] << " [20] " << dblArray[20] << endl;
	mySwap(dblArray, 10, 20);
	fout << "After: [10] " << dblArray[10] << " [20] " << dblArray[20] << endl;
	fout << "Minimum: " << myMin(dblArray) << endl;
	fout << "Maximum: " << myMax(dblArray) << endl;
	fout << "The number 4.62557 is at position " << mySearch(dblArray, 4.62557) << endl;
	fout << "The number 1.23456 is at position " << mySearch(dblArray, 1.23456) << endl << endl;

	// Print the string file data
	fout << "Strings:\n";
	fout << "Swapped items at positions 10 and 20\n";
	fout << "Before: [10] " << strArray[10] << " [20] " << strArray[20] << endl;
	mySwap(strArray, 10, 20);
	fout << "After: [10] " << strArray[10] << " [20] " << strArray[20] << endl;
	fout << "Minimum: " << myMin(strArray) << endl;
	fout << "Maximum: " << myMax(strArray) << endl;
	string target1 = "Shoes";
	string target2 = "Pumpkin";
	fout << "The word Shoes is at position " << mySearch(strArray, target1) << endl;
	fout << "The word Pumpkin is at position " << mySearch(strArray, target2) << endl << endl;
	
	// Close all of the streams
	finDbl.close();
	finInt.close();
	finStr.close();
	fout.close();

	return 0;
}

template<class T>
void mySwap(T a[], int i, int j)
// Swap two values in array, using a temporary variable
{
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

template<class T>
T myMin(T a[])
// Iterate through the array and return the minimum value
{
	T min = a[0];
	for (int i = 1; i < 100; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}

template<class T>
// Iterate through the array and return the maximum value
T myMax(T a[])
{
	T max = a[0];
	for (int i = 1; i < 100; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

template<class T>
// Iterate through the array searching for target
// If found, return the index number
// If not found, return -1
int mySearch(T a[], T target)
{
	for (int i = 0; i < 100; i++)
	{
		if (a[i] == target)
			return i;
	}
	return -1;
}