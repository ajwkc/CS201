// Andrew Wilson #16211406
// CS201R
// Program #7 - Hospital System
// May 10, 2018

#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue heart, lung, plastic;
	int choice = 0;

	while (choice != 4)
	{
		printMainMenu();

		
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				printSubMenu(heart, "Heart");
				break;
			}

			case 2:
			{
				printSubMenu(lung, "Lung");
				break;
			}

			case 3:
			{
				printSubMenu(plastic, "Plastic surgery");
				break;
			}

			case 4:
			{
				cout << "Thanks for using the system\n";
				system("pause");
				return 0;
			}
			default:
			{
				cout << "Please enter a valid choice.\n";
				break;
			}
		}
	}
	return 0;
}