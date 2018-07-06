// Andrew Wilson - #16211406
// April 8, 2018
// CS201R - Gharibi
// Program #5 - Bookstore Application

#include "Shirt.h"

Shirt::Shirt()
{}

Shirt::Shirt(double _price, int _quantity, string _description, string _size)
: Product(_price, _quantity, _description), size(_size)
{
	price = _price;
	quantity = _quantity;
	description = _description;
	size = _size;
}

void Shirt::setSize(string _size)
{
	size = _size;
}

void Shirt::print(ostream& out)
{
	// Formatting for printing shirt info
	out << setw(3) << right << quantity << " ";
	out << setw(28) << left << size + " " + description; // Concatenates size and descrip into one string
	out << "$" << setw(7) << right << calculateTotal() << endl;
}

double Shirt::calculateTotal()
{
	// Increases price by $1 if shirt is really big
	if ((size == "2XL" || size == "3XL") && !priceUp)
	{
		price += 1.00;
		priceUp = true; // Prevents price increase during receipt printing
	}
	return (price * quantity);
}