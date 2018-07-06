// Andrew Wilson - #16211406
// April 8, 2018
// CS201R - Gharibi
// Program #5 - Bookstore Application

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Product.h"
#include "Shirt.h"
#include "OfficeSupplies.h"
#include "Register.h"
using namespace std;

int main()
{
	// Open input and output streams
	ifstream fin("products.txt");
	ofstream fout("receipt.txt");

	// Initialize register that will keep track of items
	Register theRegister;

	// Variables for file input
	string type, description, size;
	int quantity, count;
	double price;

	// Input the items while file is not empty
	while (fin >> type)
	{
		// Create a pointer to a new item
		Product *item;
		item = new Product;

		if (type == "SHIRT")
		{
			// Ignore is used to throw away newline chars
			fin.ignore();
			getline(fin, description);
			getline(fin, size);
			fin >> quantity >> price;
			fin.ignore();
			// Product pointer now points at the shirt
			item = new Shirt(price, quantity, description, size);
			// Add shirt pointer to register array
			theRegister.addProduct(item);
		}
		else if (type == "SUPPLIES")
		{
			fin.ignore();
			getline(fin, description);
			fin >> count >> quantity >> price;
			fin.ignore();
			// Product pointer now points at the supplies
			item = new OfficeSupplies(price, quantity, description, count);
			// Add supplies to the register array
			theRegister.addProduct(item);
		}
	}

	// Print the items to receipt
	theRegister.printReceipt(fout);

	// Close the file streams
	fin.close();
	fout.close();

	return 0;
}