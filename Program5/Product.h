// Andrew Wilson - #16211406
// April 8, 2018
// CS201R - Gharibi
// Program #5 - Bookstore Application

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
protected:
	string description;
	double price;
	int quantity;
	

public:
	Product();
	Product(double _price, int _quantity, string _description);

	// Setter functions
	void setPrice(double _price);
	void setQuantity(int _quantity);
	void setDescription(string _description);

	// Virtual functions will be overridden by child class objects
	virtual void print(ostream& out);
	virtual double calculateTotal();
};

#endif