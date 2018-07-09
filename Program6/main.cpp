// Andrew Wison - #16211406
// April 22, 2018
// CS201R - Gharibi
// Program #6 - Recursion

#include <iostream>
#include <cmath>

using namespace std;

// LHS calculates sum of squares using iteration
int LHS(int n);

// RHS calculates sum of squares using recursion
int RHS(int n);

// arrayReverse swaps array entries starting from the outside
void reverseArray(int i, int size);

// Create the array to be reversed
int a[100];

int main()
{
	cout << "Let's use recursion" << endl << "Enter a positive integer: ";

	int n;
	cin >> n;

	cout << "LHS yields " << LHS(n) << endl << "RHS yields " << RHS(n) << endl << endl;

	cout << "Now let's use recursion to reverse the entries in an array.\n";
	cout << "Enter the size of the array (between 1 and 100): ";

	int size;
	cin >> size;

	// Array entries are entered by user
	for (int i = 0; i < size; i++)
	{
		cout << "Enter value for a[" << i << "]: ";
		cin >> a[i];
	}
	cout << endl;
	
	// Prints the array before reversing
	cout << "The array was: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// First index is zero; last index is size - 1
	reverseArray(0, size - 1);

	// Prints the array after reversing
	cout << "And now it is: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

int LHS(int n)
// Precondition: user enters an integer
// Postcondition: returns sum of squares of all integers up to n
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += (i * i);
	return sum;
}

int RHS(int n)
// Precondition: user enters an integer
// Postcondition: returns 1 if n = 1; otherwise returns n*n + RHS(n-1)
{
	// Base case
	if (n == 1)
		return 1;

	// Recursive step
	else
		return (n * n) + RHS(n - 1);
}

void reverseArray(int first, int last)
// Precondition: first and last are the "outside" indexes of an unswapped array
// Postcondition: the outside values are swapped; if the indexes aren't at the middle yet,
// return reverseArray on the next inner index pair
{
	// Base case: the indexes have passed each other (when the array size is even),
	// or they're at the same index (when the array size is odd)
	if (abs(first - last) <= 1)
		return;

	// Recursion step: the array has at least two indexes that need to be swapped
	else
	{
		int temp = a[first];
		a[first] = a[last];
		a[last] = temp;
		return reverseArray(first + 1, last - 1); // Swap the next inner pair, if applicable
	}
}