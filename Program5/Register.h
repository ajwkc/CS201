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

#ifndef REGISTER_H
#define REGISTER_H

class Register
{
private:
	static const int max = 50;
	int numProducts;
	Product* cart[max];

public:
	Register();
	void addProduct(Product* prodPtr);
	void printReceipt(ostream& out);
};
#endif