/****************************************************************************************
** Program Filename: List.cpp
** Author: Chris Kearns
** Date: 1/26/2016
** Description: List class implementation file.
** Input: User input in main, Items.cpp cout for item object var values, various Items
** class function returns.
** Output: cout to console, parameters to Items.cpp functions.
*****************************************************************************************/
#include "List.hpp"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;
using std::setprecision;
using std::fixed;


/***************************************************************************************
** Function: List()
** Description: List class default constructor.
** Parameters: 
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Instantiates a List object with dynamic array.
****************************************************************************************/
List::List(){
	sizeArray = 4;
	aList = new Items[sizeArray];
	numItems = 0;
}


/***************************************************************************************
** Function: ~List()
** Description: List class destructor.
** Parameters:
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Destroys List object on program end.
****************************************************************************************/
List::~List(){
	delete[] aList;
	aList = 0;
}


/***************************************************************************************
** Function: addItem()
** Description: Adds an Items Object to the List Object's dynamic array.
** Parameters: Items object.
** Pre-Conditions: A valid Items object and List object set freom main().
** Post-Conditions: An Items object added to the List object dynamic array, array is re-
** sized by x2 if full, rejected if Items object's name already exists in array.
** Increments numItems.
****************************************************************************************/
void List::addItem(Items anItem) {
	int sentinal = 0;
	for (int i = 0; i < numItems; i++) {
		if (anItem.getName() == aList[i].getName())		// operator== overload.
			sentinal = 1;
	}
	if (sentinal == 0) {						// Dynamic Array has room?
		if ((numItems < (sizeArray - 1))) {			// Yes, but early resize mandatory!!
			aList[numItems] = anItem;			// See removeItem() line 100.
			numItems++;
		}
		else {							// Resize array for next object.
			Items* temp = new Items[sizeArray * 2];
			for (int i = 0; i < numItems; i++)
				temp[i] = aList[i];
			delete[]aList;					// Delete the too small array.
			aList = temp;					// Repoint *aList
			aList[numItems] = anItem;
			sizeArray *= 2;
			numItems++;
		}
	}
	else {
		cout << endl << "Sorry, that name is already in your list!" << endl;
	}
}


/***************************************************************************************
** Function: removeItem()
** Description: Removes an Items Object from the List Object's dynamic array.
** Parameters: array index (+ 1, as seen from User console) of Items object in array.
** Pre-Conditions: A valid Items object and List object set freom main().
** Post-Conditions: An Items object removed from the List object's dynamic array, or an 
** error message stating fault condition. Decrements numItems.
****************************************************************************************/
void List::removeItem(int rem){
	if (numItems == 0) {
		cout << endl << "There are no items on your list" << endl;
	}
	else {
		int idx = rem - 1;			// - 1 to align index var 'rem' wtih object location in array.
		for (int i = idx; i < numItems; i++)
			aList[i] = aList[i + 1]; 	// [i + 1] out of bounds if array not resized early.
		numItems--;
		cout << endl << "List item " << rem << " has been removed!" << endl;
	}
}


/***************************************************************************************
** Function: calcTotal()
** Description: Calculates all Item Object's extPrice vars in the List Objects dynamic array.
** Parameters: void.
** Pre-Conditions: Valid Items objects in the List object array.
** Post-Conditions: A calculated and set totPrice var.
****************************************************************************************/
double List::calcTotal(){
	totPrice = 0;
	for (int i = 0; i < numItems; i++) {
		totPrice += aList[i].getExtPrice();
	}
	return totPrice;
}


/***************************************************************************************
** Function: displayCart()
** Description: Outputs all Items object's in List's array with totPrice.
** Parameters: void.
** Pre-Conditions: Valid List object set freom main() - will work with no objects in List.
** Post-Conditions:
****************************************************************************************/
void List::displayCart(){
	string spacer = " ";
	cout << endl << setw(2) << " # " << setw(15) << "Name" << setw(8) << "Amount" << setw(8)
		 << "Unit" << setw(10) << "Price" << setw(12) << "Ext. Price" << endl;
	for (int i = 0; i < numItems; i++) {
		if (aList[i].getExtPrice() != 0) {
			if (i >= 9) { spacer = ""; }		// Keeps List console display item #'s
			cout << spacer << i + 1;		// > 9 aligned properly on console. 
			aList[i].displayItems();
		}
	}
	cout << endl << "\t\tYour total comes to $ " << calcTotal() << endl << endl;
}


/***************************************************************************************
** Function: operator==()
** Description: Compares strings for equivalence. Used by addItem() to reject adding 
** Items objects already exisiting in List array by Item's string name comparison.
** Parameters: ItemA.getName(), ItemB.getName()
** Pre-Conditions: Valid List object set freom main() - no effect if no objects in List.
** Post-Conditions:
****************************************************************************************/
bool operator==(string a, string b) {
	return a == b;
}


int main() {
	string name;		// Local name user input collector var.
	string measure;		// Local unit of measure user input collector var.
	double num2Buy;		// Local num2Buy user input collector var.
	double unitPrice;	// Local unitPrice user input collector var.
	int choice = 0;		// Utility var for menu flow control.
	int rem = -1;		// Utility var for collecting List Items number for removal.
	int count = 0;		// Utiltiy var for use in main() - mirrors numItems var.
	List myList;		// Instantiate a List object.

	// Main menu.
	cout << endl << "Welcome to your Shopping List" << endl;
	while(choice != 4){
		cout << endl
			 << "Enter 1 to add items to your list." << endl
			 << "Enter 2 to remove items from your list." << endl
			 << "Enter 3 to display your list." << endl
			 << "Enter 4 to quit." << endl;
		cin.clear();
		cin >> choice;
		// Input validation.
		while (cin.fail() || choice < 1 || choice > 4) {
			cout << endl << "Error!" << endl
				 << "Enter 1 to add items to your list." << endl
				 << "Enter 2 to remove items from your list." << endl
				 << "Enter 3 to display your list." << endl
				 << "Enter 4 to quit." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> choice;
		}

		// Adding an Item Object to the List object.
		if (choice == 1) {
			cout << "Please enter an item name or 'f' if finished." << endl;
			cin.ignore(256, '\n');
			getline(cin, name);

			if (name != "f") {
				cout << "Please enter the item's unit of measure." << endl;
				getline(cin, measure);
				cout << "Please enter the number of " << name << " to purchase." << endl;
				cin >> num2Buy;
				// Input validation.
				while (cin.fail() || (num2Buy < 0.01)) {
					cout << "Error! Enter a double greater than 0 and press Enter." << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> num2Buy;
				}

				cout << "Please enter the unit price as a double i.e '0.99'" << endl;
				cin >> unitPrice;
				// Input validation.
				while (cin.fail() || (unitPrice < 0.01)) {
					cout << "Error! Enter a double greater than 0.01 and press Enter." << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> unitPrice;
				}

				// Inputs all valid, go ahead and create Items object...
				Items item = Items(name, measure, num2Buy, unitPrice);
				// ...and add it to the List object.
				myList.addItem(item);
				count++;
			}
			myList.displayCart();
		}

		else {// Remove an Items object from the List object.
			if (choice == 2) {
				cout << "Please enter the item number to remove from your list or 0" << endl
					 << "to return to the menu." << endl;
				cin >> rem;
				// Input validation.
				while (cin.fail() || rem < 0 || rem > count) {
					cout << "Error! Enter an int from your list or 0 to return to the menu." << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> rem;
				}
				// Inputs valid, so we check for valid List Items number.
				if (rem != 0 && rem <= count) {
					myList.removeItem(rem);
					count--;
					// Reset count if no Items in List when called.
					if (count < 0) { count = 0; }
				}
				else { cout << endl << "Your list was not changed!" << endl; }
			}

			else {// Display the List and all the Items and totPrice!!
				if(choice == 3)
					myList.displayCart();
			}
		}
	}// End Main Menu while loop.
	
	// End Program selected.
	if (choice == 4)
		return 0;
}
