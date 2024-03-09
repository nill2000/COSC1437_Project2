// Stephen Lin
// Dr. Nina Javaher
// 4/26/2023
/*
DESCRIPTION:
The code is a menu-driven inventory management system utilizing OOP fundamentals
In the system, the user is able to add, remove, display product info, and display full inventory
 */

#include <iostream>			//Header for input and output
#include <string>			//Header for utilizing string object
#include "inventoryClass.h" //Header to obtain the necessary class and struct
#include <cctype>			//Header for "toupper" functions
using namespace std;

void menuPrompt(); // Function prototype for menu options

int main()
{
	Inventory Item;		 // Create a class called Item
	int menuChoice;		 // Variable used to store user input for menu choice
	bool runMenu = true; // Flag-controlled variable used to continue the menu system
	char repeatChoice;	 // Variable used to hold user input and check whether this wish to continue the code

	while (runMenu)
	{
		menuPrompt();
		while (!(cin >> menuChoice) || menuChoice <= 0 || menuChoice >= 6) // Code checks to see if input is an integer and between 0 and 5 because there are only five menu options - 1, 2, 3, 4, or 5.
		{																   // If not, loop will continue until input is either 1, 2, 3, 4, or 5.
			checkInput("Menu Choice 1/2/3/4/5: ");
		}

		cout << endl;

		switch (menuChoice) // After the user selects their menu choice, it activates the respective case
		{
		case 1:
			Item.addProduct(); // Function to add a product
			break;
		case 2:
			Item.removeProduct(); // Function to remove a product
			break;
		case 3:
			Item.displayInfo(); // Function to display info about a specific product
			break;
		case 4:
			Item.displayInventory(); // Function to display entire inventory
			break;
		case 5:									 // Program will terminate if user input is 5
			cout << "Program Terminate" << endl; // Prompts the user code has ended
			return 0;
		};

		cout << "Repeat Menu? Y/N: ";
		while (!(cin >> repeatChoice) || toupper(repeatChoice) != 'Y' && toupper(repeatChoice) != 'N') // Code checks to see if user input is either a Y or N
		{																							   // If not, code will repeat until input is either a Y or N
			checkInput("Repeat Menu? Y/N: ");														   // If input is a Y, continue the while loop
			continue;
		}

		if (toupper(repeatChoice) == 'N') // If input is an N, escape the loop by turning the flag-controlled variable to false and end the program
		{
			runMenu = false;
		}
		cout << endl;
	}

	cout << "Program Terminate" << endl; // Prompts the user that code has ended
	return 0;
}

void menuPrompt() // Function that displays available options and placed into a function for clean code
{
	cout << "1. Add a Product" << endl;
	cout << "2. Remove a Product" << endl;
	cout << "3. Display Specific Product" << endl;
	cout << "4. Display Inventory" << endl;
	cout << "5. Quit Menu" << endl;
	cout << "Menu Choice 1/2/3/4/5: ";
}