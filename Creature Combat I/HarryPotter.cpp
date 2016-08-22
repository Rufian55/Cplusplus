/****************************************************************************************
** Program Filename: Harrypotter.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/14/2016
** Description: HarryPotter class implementation file.
** Input:
** Output:
*****************************************************************************************/
#include "HarryPotter.hpp"
#include<cstdlib>
#include<vector>
using std::vector;
#include<algorithm>
using std::random_shuffle;
#include<string>
using std::string;

#include<iostream>
using std::cout;
using std::cin;
using std::endl;


/***************************************************************************************
** Function: HarryPotter()
** Description: Constructor for HarryPotter derived class.
**
** Parameters: none.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
HarryPotter::HarryPotter(){
	setStrength(10);
	setNumDie(2);
	setDieSides(6);
	setArmor(0);
	setDeadOnce(0);
}

HarryPotter::~HarryPotter(){}


/***************************************************************************************
** Function: roll()
** Description:	Returns a random int from the sum of numDie rolls for attack and defense
** funtions.
** Parameters: string "AorD" dummy parameter to avoid overloading virtual function.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Need to delete object and set pointer to null
****************************************************************************************/
int HarryPotter::roll(string){
	int i;
	int result = 0;
	int dSides = getDieSides();
	int die = getNumDie();
	vector<int> roller;

	for (i = 1; i < dSides + 1; i++) {
		roller.push_back(i);
	}
	for (i = 0; i < die; i++) {
		random_shuffle(roller.begin(), roller.end());
		result += roller.at(0);
	}

	cout << "HarryPotter rolled " << result << endl;

	return result;
}


/***************************************************************************************
** Function: hogWarts();
** Description: Helper function that resets HarryPotter object strength var on first 
** occurence of death!
** Parameters: void
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
void HarryPotter::hogWarts(){
	if (getDeadOnce() == 0 && getStrength() <= 0) {
		setStrength(20);
		setDeadOnce(1);
	}
}


/***************************************************************************************
** Function: attack()
** Description:	Returns result of object's attack function.
**
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
int HarryPotter::attack() {
	int result;
	cout << "Harry Potter attacking" << endl;
	result = roll("A");
	return result;
}


/***************************************************************************************
** Function: defend()
** Description:	Returns a random int from the sum of numDie rolls for attack and defense
**
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
void HarryPotter::defend(int aR) {
	int defendResult;
	int damage;
	int newStrengthPoints;
	int armor = getArmor();
	int currentStrength = getStrength();

	defendResult = roll("D");
	damage = aR - defendResult;
	if (damage > armor) {
		newStrengthPoints = currentStrength - damage + armor;
		setStrength(newStrengthPoints);
	}

	hogWarts();

	if (checkPulse()) {
		cout << "Harry Potter: Give her hell from us, Peeves." << endl;
		if (deadOnce == 1) {
			cout << "Harry Potter: I'm on my second life!" << endl;
		}
	}
	else {
		cout << "Harry Potter: I've died a good death!" << endl;
	}
}


/***************************************************************************************
** Function: checkPulse()
** Description:	Returns a bool checking strength following an attack.
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
bool HarryPotter::checkPulse() {
	int pulse;
	pulse = getStrength();
	if (pulse > 0) {
		return true;
	}
	else {
		return false;
	}
}


void HarryPotter::setStrength(int strength){
	this->strength = strength;
}

int HarryPotter::getStrength(){
	return strength;
}

void HarryPotter::setDieSides(int dieSides){
	this->dieSides = dieSides;
}

int HarryPotter::getDieSides(){
	return dieSides;
}

void HarryPotter::setNumDie(int numDie){
	this->numDie = numDie;
}

int HarryPotter::getNumDie(){
	return numDie;
}

void HarryPotter::setArmor(int armor){
	this->armor = armor;
}

int HarryPotter::getArmor(){
	return armor;
}

void HarryPotter::setDeadOnce(int deadOnce){
	this->deadOnce = deadOnce;
}

int HarryPotter::getDeadOnce(){
	return deadOnce;
}