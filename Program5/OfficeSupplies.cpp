// Andrew Wilson - #16211406
// April 8, 2018
// CS201R - Gharibi
// Program #5 - Bookstore Application

#include "OfficeSupplies.h"

OfficeSupplies::OfficeSupplies()
{}

OfficeSupplies::OfficeSupplies(double _price, int _quantity, string _description, int _count)
{
	price = _price;
	quantity = _quantity;
	description = _description;
	count = _count;
}

void OfficeSupplies::setCount(int _count)
{
	count = _count;
}

void OfficeSupplies::print(ostream& out)
{
	// Formatting for printing supplies info
	out << setw(3) << right << quantity << " ";
	out << setw(28) << left << description + " ("  + to_string(count) + " count)"; // Converts count to string and concatenates
	out << "$" << setw(7) << right << calculateTotal() << endl;
}