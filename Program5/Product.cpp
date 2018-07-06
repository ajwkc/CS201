// Andrew Wilson - #16211406
// April 8, 2018
// CS201R - Gharibi
// Program #5 - Bookstore Application

#include "Product.h"

Product::Product()
{
	// Intentionally blank
}

Product::Product(double _price, int _quantity, string _description)
{
	// Intentionally blank
}

void Product::setPrice(double _price)
{
	price = _price;
}

void Product::setQuantity(int _quantity)
{
	quantity = _quantity;
}

void Product::setDescription(string _description)
{
	description = _description;
}

void Product::print(ostream& out)
{
	// Intentionally blank
}

double Product::calculateTotal()
{
	return (price * quantity);
}