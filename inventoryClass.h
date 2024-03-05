#include <iostream>
using namespace std;

struct Product
{
	int productID;
	string productName;
	double productPrice;
	int productQuantity;
};

Product _Product[] = {};

int numOfProducts = 0;
int removeID;
int displayID;

class Inventory
{
public:
	void addProduct()
	{
		cout << "Note: Non-negative integers only" << endl;
		cout << "What is the ID?: ";
		while (!(cin >> _Product[numOfProducts].productID) || _Product[numOfProducts].productID < 0)
		{
			cout << "Invalid Input, Please enter a valid ID: ";
			cin.clear();
			cin.ignore(100, '\n');
		}

		cout << "What is the product name?: ";
		cin >> _Product[numOfProducts].productName;
		// while (!(cin >> _Product[numOfProducts].productName))
		// {
		// 	cout << "Type a valid integer for ID: ";
		// 	cin.clear();
		// 	cin.ignore(100, '\n');
		// }

		cout << "What is the price?: ";
		while (!(cin >> _Product[numOfProducts].productPrice) || _Product[numOfProducts].productPrice < 0)
		{
			cout << "Invalid Input. Please enter a valid price: ";
			cin.clear();
			cin.ignore(100, '\n');
		}

		cout << "What is the quantity?: ";
		while (!(cin >> _Product[numOfProducts].productQuantity) || _Product[numOfProducts].productQuantity < 0)
		{
			cout << "Invalid Input. Please enter a valid quantity: ";
			cin.clear();
			cin.ignore(100, '\n');
		}

		numOfProducts += 1;
		cout << endl;
	};

	void removeProduct()
	{
		cout << "Note: If ID Doesn't Exist, Nothing Will Delete" << endl;
		cout << "Type product ID to remove product: ";
		while (!(cin >> removeID))
		{
			cout << "Type a valid ID: ";
			cin.clear();
			cin.ignore(100, '\n');
		}

		for (int i = 0; i < numOfProducts; i++)
		{
			if (removeID == _Product[i].productID)
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
		cout << endl;
	};

	void displayInfo()
	{
		cout << "Note: If ID Doesn't Exist, Nothing Will Display" << endl;
		cout << "Type product ID to display info: ";
		while (!(cin >> displayID))
		{
			cout << "Type a valid ID: ";
			cin.clear();
			cin.ignore(100, '\n');
		}

		cout << "Product Info: " << endl;
		cout << "--------------------" << endl;

		for (int i = 0; i < numOfProducts; i++)
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

	void displayInventory()
	{
		cout << "Full Inventory: " << endl;
		cout << "--------------------" << endl;
		for (int i = 0; i < numOfProducts; i++)
		{
			cout << "Product ID: " << _Product[i].productID << endl;
			cout << "Product Name: " << _Product[i].productName << endl;
			cout << "Product Price: $" << _Product[i].productPrice << endl;
			cout << "Product Quantity: " << _Product[i].productQuantity << endl;
			cout << "--------------------" << endl;
		}
	};
};
