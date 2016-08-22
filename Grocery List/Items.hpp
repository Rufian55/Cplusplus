/****************************************************************************************
** Program Filename: Items.hpp
** Author: Chris Kearns
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
	string name;
	string unit;
	double num2Buy;
	double unitPrice;
	double extPrice;
public:
	Items(string, string, double, double);
	Items();
	void setName(string);
	string getName();
	void setUnit(string);
	string getUnit();
	void setNum2Buy(double);
	double getNum2Buy();
	void setUnitPrice(double);
	double getUnitPrice();
	void setExtPrice(double, double);
	double getExtPrice();
	void displayItems();
};
#endif
