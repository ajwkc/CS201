// Andrew Wilson - #16211406
// April 8, 2018
// CS201R - Gharibi
// Program #5 - Bookstore Application

#include "Register.h"

Register::Register()
	: numProducts(0)
{}

void Register::addProduct(Product* prodPtr)
{
	// Adds product pointer to the array, increases size
	cart[numProducts] = prodPtr;
	numProducts++;
}

void Register::printReceipt(ostream& out)
{
	// Formatting all floats as $X.XX prices

	out.setf(ios::fixed);
	out.setf(ios::showpoint);
	out.precision(2);

	// Initializes receipt total
	double total = 0.00;

	// Receipt header
	out << "****************************************\n";
	out << "*   CS 201 Super Selling Stuff Store   *\n";
	out << "****************************************\n";
	out << endl;
	out << "Qty Description                 Total   \n";
	out << "--- --------------------------- --------\n";

	// Iterate through the pointer array for printing
	for (int i = 0; i < numProducts; i++)
	{
		cart[i]->print(out);
		// Add individual total to grand total
		total += cart[i]->calculateTotal();
	}

	// Receipt footer
	out << endl;	
	out << setw(13) << left <<"Grand total: $" << total << endl;
	out << setw(13) << left << "Items sold: " << numProducts << endl << endl;
	out << "* Thank you for shopping at our store! *\n";
}