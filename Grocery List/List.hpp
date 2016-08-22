/****************************************************************************************
** Program Filename: List.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 1/26/2016
** Description: List class header file.
** Input:
** Output:
*****************************************************************************************/
#ifndef LIST_HPP
#define LIST_HPP
#include "Items.hpp"

class List {
private:
	double totPrice;						// List total price of all var Items::extPrice
	int numItems;							// Number of items in list.
	Items *aList;							// Items pointer for List's dynmamic array/
	int sizeArray;							// sizeArray utility var.
public:
	List();									// List default constructor.
	~List();								// List destructor.
	void addItem(Items);					// Function adds Items objects to List.
	void removeItem(int);					// Function removes Items objects from List.
	double calcTotal();						// Function to calculate and retrun totPrice var.
	void displayCart();						// Function to print List to console.
	friend bool operator==(string, string);	// == overload for duplicate check via Item name comparison.
};
#endif // !LIST_HPP