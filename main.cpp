#include <iostream>
#include <string>
#include "inventoryClass.h"
#include <cctype>
using namespace std;

void menuPrompt();

int main()
{
	Inventory Item;
	int menuChoice;
	bool runMenu = true;
	char repeatChoice;

	while (runMenu)
	{
		menuPrompt();
		while (!(cin >> menuChoice) || menuChoice <= 0 || menuChoice >= 5)
		{
			checkInput("Menu Choice 1/2/3/4: ");
		}

		cout << endl;

		switch (menuChoice)
		{
		case 1:
			Item.addProduct();
			break;
		case 2:
			Item.removeProduct();
			break;
		case 3:
			Item.displayInfo();
			break;
		case 4:
			Item.displayInventory();
			break;
		};

		cout << "Repeat Menu? Y/N: ";
		while (!(cin >> repeatChoice) || toupper(repeatChoice) != 'Y' && toupper(repeatChoice) != 'N')
		{
			checkInput("Repeat Menu? Y/N: ");
		}

		if (toupper(repeatChoice) == 'N')
		{
			runMenu = false;
		}
		cout << endl;
	}

	cout << "Program Terminate" << endl;
	return 0;
}

void menuPrompt()
{
	cout << "1. Add a Product" << endl;
	cout << "2. Remove a Product" << endl;
	cout << "3. Display Specific Product" << endl;
	cout << "4. Display Inventory" << endl;
	cout << "Menu Choice 1/2/3/4: ";
}