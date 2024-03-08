#include <iostream>
using namespace std;

void checkInput(string message); // Function prototype that takes in a message
struct Product					 // Struct named product
{
	int productID;
	string productName;
	double productPrice;
	int productQuantity;
};

Product _Product[] = {}; // Create a Product struct named _Product that is an array to group certain products

int numOfProducts = 1; // Variable used to manipulate array contents in _Product[] (Using 1 instead there is no such thing as 0 products and readibility).
int removeID;		   // Variable used to hold user input for ID to check which ID product to remove
int displayID;		   // Variable used to hold user input for ID to check which ID product to display

class Inventory // Inventory Class
{
public:
	void addProduct() // The function prompts the user to type an ID, name, price, and quantity for a product
	{
		cout << "Enter ID (Nonnegative Integer): ";
		while (!(cin >> _Product[numOfProducts].productID) || _Product[numOfProducts].productID < 0) // Code checks if ID is valid by checking if input is an integer and not negative
		{
			checkInput("Enter a Valid ID: "); // Notifies the user that the code is invalid and prompts the "argument" message about the error
		}

		cout << "Enter Product Name: ";
		cin >> _Product[numOfProducts].productName;
		// while (!(cin >> _Product[numOfProducts].productName))
		// {
		// 	cout << "Type a valid integer for ID: ";
		// 	cin.clear();
		// 	cin.ignore(100, '\n');
		// }

		cout << "Enter Price: ";
		while (!(cin >> _Product[numOfProducts].productPrice) || _Product[numOfProducts].productPrice < 0) // Code checks if the price is valid by checking if input is an integer and not negative
		{
			checkInput("Enter a Valid Price: "); // Notifies the user that the code is invalid and prompts the "argument" message about the error
		}

		cout << "Enter Quantity: ";
		while (!(cin >> _Product[numOfProducts].productQuantity) || _Product[numOfProducts].productQuantity < 0) // Code checks if the quantity is valid by checking if input is not negative
		{
			checkInput("Enter a Valid Quantity: "); // Notifies the user that the code is invalid and prompts the "argument" message about the error
		}

		numOfProducts += 1; // Increase the amount of products by one because one was added
	};

	void removeProduct() // Function removes the desired product from inventory
	{
		cout << "Note: If ID Doesn't Exist, Nothing Will Delete" << endl;
		cout << "Type Product ID to Remove Product: ";
		while (!(cin >> removeID)) // Code checks if input ID is valid for product removal
		{
			checkInput("Enter a Valid ID: "); // Notifies the user that the code is invalid and prompts the "argument" message about the error
		}

		for (int i = 1; i < numOfProducts; i++) // Loop through the code as many products available
		{
			if (removeID == _Product[i].productID) // Checks if the ID from user input matches an ID in the inventory for a product for removal
			{
				for (int indexLocation = i; indexLocation < numOfProducts - 1; indexLocation++)
				{
					_Product[indexLocation].productID = _Product[indexLocation + 1].productID;
					_Product[indexLocation].productName = _Product[indexLocation + 1].productName;
					_Product[indexLocation].productPrice = _Product[indexLocation + 1].productPrice;
					_Product[indexLocation].productQuantity = _Product[indexLocation + 1].productQuantity;
				}
			}
		}
		numOfProducts -= 1;
		cout << "Product Removed" << endl;
	};

	void displayInfo() // Function to display information about a certain product information
	{
		cout << "Note: If ID Doesn't Exist, Nothing Will Display" << endl;
		cout << "Type Product ID to Display Info: ";
		while (!(cin >> displayID)) // Code checks if input ID is valid for product display
		{
			checkInput("Enter a Valid ID: "); // Notifies the user that the code is invalid and prompts the "argument" message about the error
		}

		cout << "Product Info: " << endl;
		cout << "--------------------" << endl;

		for (int i = 1; i < numOfProducts; i++)
		{
			if (displayID == _Product[i].productID)
			{
				cout << "Product ID: " << _Product[i].productID << endl;
				cout << "Product Name: " << _Product[i].productName << endl;
				cout << "Product Price: $" << _Product[i].productPrice << endl;
				cout << "Product Quantity: " << _Product[i].productQuantity << endl;
			}
		}

		cout << "--------------------" << endl;
	};

	void displayInventory() // Function to display entire inventory
	{
		cout << "Inventory: " << endl;
		cout << "--------------------" << endl;
		for (int i = 1; i < numOfProducts; i++)
		{
			cout << "Product ID: " << _Product[i].productID << endl;
			cout << "Product Name: " << _Product[i].productName << endl;
			cout << "Product Price: $" << _Product[i].productPrice << endl;
			cout << "Product Quantity: " << _Product[i].productQuantity << endl;
			cout << "--------------------" << endl;
		}
	};
};

void checkInput(string message) // Function that prompts the user the input is invalid and takes a "message argument" that notifies them the issue
{
	cout << "Invalid Input." << endl;
	cout << message;
	cin.clear();
	cin.ignore(100, '\n');
}
