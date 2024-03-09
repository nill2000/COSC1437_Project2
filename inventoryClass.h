#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

void checkInput(string message); // Function prototype that takes in a message
struct Product					 // Struct named product
{
	int productID;		 // Variable used to store product ID
	string productName;	 // Variable used to store product name
	double productPrice; // Variable used to store product price
	int productQuantity; // Variable used to store product quantity
};

Product _Product[] = {}; // Create a Product struct named _Product that is an array to group certain products

int numOfProducts = 1; // Variable used to manipulate array contents in _Product[] (Using 1 instead there is no such thing as 0 products and readibility).
int removeID;		   // Variable used to hold user input for ID to check which ID product to remove
int displayID;		   // Variable used to hold user input for ID to check which ID product to display
int checkID;		   // Variable used to save contents of most current entered ID to check for if-statements
string checkName;
bool repeatID = false; // Boolean variable to control while loop
bool repeatName = false;

class Inventory // Inventory Class
{
public:
	void addProduct() // The function prompts the user to type an ID, name, price, and quantity for a product
	{
		cout << "Enter ID (Non-negative Integer): ";
		while (!(cin >> _Product[numOfProducts].productID) || _Product[numOfProducts].productID < 0) // Code checks if ID is valid by checking if input is an integer and not negative
		{
			checkInput("Enter a Valid ID: "); // Notifies the user that the code is invalid and prompts the "argument" message about the error
		}

		checkID = _Product[numOfProducts].productID;

		for (int i = 1; i < numOfProducts; i++) // Loop through the amount of products
		{
			if (checkID == _Product[i].productID) // Checks to see if ID is a dupe
			{
				bool repeatID = true;

				while (repeatID)
				{
					cout << "ID is taken" << endl;
					cout << "Try Another ID: ";
					while (!(cin >> _Product[numOfProducts].productID) || _Product[numOfProducts].productID < 0)
					{
						checkInput("Enter a Valid ID: ");
					}

					checkID = _Product[numOfProducts].productID;

					if (checkID == _Product[i].productID)
					{
						continue;
					}
					else
					{
						repeatID = false;
					}
				}
			}
		}

		cout << "Enter Product Name (Alphabet Letters): ";
		cin >> _Product[numOfProducts].productName;
		checkName = _Product[numOfProducts].productName;

		for (int i = 0; i < checkName.length(); i++)
		{
			if (!(isalpha(checkName[i])))
			{
				repeatName = true;

				while (repeatName)
				{
					cout << "Alphabet Letters Only" << endl;
					cout << "Try Again: ";
					cin >> _Product[numOfProducts].productName;
					checkName = _Product[numOfProducts].productName;

					for (int i = 0; i < checkName.length(); i++)
					{
						if (isalpha(checkName[i]))
						{
							repeatName = false;
						}

						else
						{
							continue;
						}
					}
				}
			}
		}

		cout << "NOTE: Inputs Should Be Non-negative Integers or Non-negative Floating Integers. Every Decimal After the Third is Ignored" << endl;
		cout << "Enter Price: ";
		while (!(cin >> _Product[numOfProducts].productPrice) || _Product[numOfProducts].productPrice < 0) // Code checks if the price is valid by checking if input is an integer and not negative
		{
			checkInput("Enter a Valid Price: "); // Notifies the user that the code is invalid and prompts the "argument" message about the error
		}

		cout << "Enter Quantity (Integers Only): ";
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
				for (int indexLocation = i; indexLocation < numOfProducts - 1; indexLocation++) // Start at the i-th index where the removeID was found and loop until the second to last index
				{																				// The code overwrites the information at the "i-th" index with the next array content respectively
																								// because C++ arrays are not dynamic and there is no such thing as a "delete" function.
																								// The only way to "delete" is to overwrite the item that I want to remove and shift the array contents down by one to maintain array consistency.
					_Product[indexLocation] = _Product[indexLocation + 1];
				}
			}
		}
		numOfProducts -= 1; // Reduce the amount of products by one because one was deleted
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

		for (int i = 1; i < numOfProducts; i++) // Loop through the entire array as many products available
		{
			if (displayID == _Product[i].productID) // Tries to find the ID from user input and see if input matches an ID.
													// If so, display the product contents at the "i-th" index where the ID was found.
			{
				cout << "Product ID: " << _Product[i].productID << endl;
				cout << "Product Name: " << _Product[i].productName << endl;
				cout << fixed << setprecision(2) << "Product Price: $" << _Product[i].productPrice << endl;
				cout << "Product Quantity: " << _Product[i].productQuantity << endl;
			}
		}

		cout << "--------------------" << endl;
	};

	void displayInventory() // Function to display entire inventory
	{
		cout << "Inventory: " << endl;
		cout << "--------------------" << endl;
		for (int i = 1; i < numOfProducts; i++) // Loop throguh the entire array as many products available
												// Display each content at the "i-th" index
		{
			cout << "Product ID: " << _Product[i].productID << endl;
			cout << "Product Name: " << _Product[i].productName << endl;
			cout << fixed << setprecision(2) << "Product Price: $" << _Product[i].productPrice << endl;
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
