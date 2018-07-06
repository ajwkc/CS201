// Andrew Wilson - #16211406
// April 8, 2018
// CS201R - Gharibi
// Program #5 - Bookstore Application

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Product.h"
using namespace std;

#ifndef SHIRT_H
#define SHIRT_H

class Shirt : public Product
{
protected:
	string size;
	bool priceUp = false; // Flag for price increase
public:
	Shirt();
	Shirt(double _price, int _quantity, string _description, string _size);
	void setSize(string _size);

	// Overridden inherited functions
	void print(ostream& out) override;
	double calculateTotal() override;
};

#endif