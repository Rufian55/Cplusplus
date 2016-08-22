/****************************************************************************************
** Program Filename: Items.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 1/26/2016
** Description: Items class implementation file.
** Input: All input originates from List.cpp
** Output: Function returns and cout individual Items objects member var values. 
*****************************************************************************************/
#include "Items.hpp"
#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;
using std::setprecision;
using std::fixed;

/***************************************************************************************
** Function: Items()
** Description:Items class constructor.
** Parameters: string name, string unit, double num2Buy, double unitPrice.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Sets above Items object member var values.
****************************************************************************************/
Items::Items(string aName, string aUnit, double aNum2Buy, double aUnitPrice){
	setName(aName);
	setUnit(aUnit);
	setNum2Buy(aNum2Buy);
	setUnitPrice(aUnitPrice);
	setExtPrice(aNum2Buy, aUnitPrice);
}


/***************************************************************************************
** Function: Items()
** Description:Items class default constructor/
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: None.
****************************************************************************************/
Items::Items() {
	setName("");
	setUnit("");
	setNum2Buy(0);
	setUnitPrice(0.0);
	setExtPrice(0.0, 0.0);
}

// name setter function.
void Items::setName(string aName){
	name = aName;
}

// name getter function.
string Items::getName(){
	return name;
}

// unit setter function.
void Items::setUnit(string aUnit){
	unit = aUnit;

}

// unit getter function.
string Items::getUnit(){
	return unit;
}

// num2Buy setter function.
void Items::setNum2Buy(double aNum2Buy){
	num2Buy = aNum2Buy;
}

// num2Buy getter function. 
double Items::getNum2Buy(){
	return num2Buy;
}

// unitPrice setter function.
void Items::setUnitPrice(double aUnitPrice){
	unitPrice = aUnitPrice;
}

// unitPrice getter function.
double Items::getUnitPrice() {
	return unitPrice;
}


/***************************************************************************************
** Function: setExtPrice()
** Description:Items class extPrice calculator and setter fucntion.
** Parameters: double num2Buy, double unitPrice.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Item object extPrice var calculated and set.
****************************************************************************************/
void Items::setExtPrice(double aNum2Buy, double aUnitPrice){
	extPrice = getNum2Buy() * getUnitPrice();
}


// extPrice getter function.
double Items::getExtPrice(){
	return extPrice;
}


/***************************************************************************************
** Function: displayItems()
** Description:Items class indivudual object member var value output to List.cpp
** Parameters: void, called from List::displayCart()
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: None.
****************************************************************************************/
void Items::displayItems(){
	cout << setw(16) << getName() << fixed << setprecision(2) << setw(8) <<  getNum2Buy() << setw(8) << getUnit()
		 << setw(4) << "$" << setw(6) << getUnitPrice() << setw(3) << "$" << setw(9) << getExtPrice() << endl;
}