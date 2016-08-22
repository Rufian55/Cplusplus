/****************************************************************************************
** Program Filename: Items.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 1/26/2016
** Description: Items class header file.
** Input:
** Output:
*****************************************************************************************/
#ifndef ITEMS_HPP
#define ITEMS_HPP
#include <string>
using std::string;

class Items {
private:
	string name;								// Items object name value.
	string unit;								// Items object unit value. 
	double num2Buy;								// Items object num2Buy value.
	double unitPrice;							// Items object unitPrice value.
	double extPrice;							// Items object extPrice calculated value. 
public:
	Items(string, string, double, double);		// Constructor.
	Items();									// Default Constructor
	void setName(string);						// var name setter.
	string getName();							// var name getter.
	void setUnit(string);						// var unit setter.
	string getUnit();							// var unit getter.
	void setNum2Buy(double);					// var num2Buy setter.
	double getNum2Buy();						// var num2Buy getter.
	void setUnitPrice(double);					// var unitPrice setter.
	double getUnitPrice();						// var unitPrice setter.
	void setExtPrice(double, double);			// var extPrice calculate and set.
	double getExtPrice();						// var extPrice getter.
	void displayItems();						// Individual Items object member vars print
};												//   to console function.
#endif // !ITEMS_HPP