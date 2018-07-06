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

#ifndef OFFICESUPPLIES_H
#define OFFICESUPPLIES_H

class OfficeSupplies : public Product
{
protected:
	int count;
public:
	OfficeSupplies();
	OfficeSupplies(double _price, int _quantity, string _description, int _count);

	// Overridden inherited functions
	void setCount(int _count);
	void print(ostream& out) override;
};

#endif