/****************************************************************************************
** Program Filename: Barbarian.cpp
** Author: Chris Kearns
** Date: 2/14/2016
** Description: Barbarian class implementation file.
** Input:
** Output:
*****************************************************************************************/
#include "Barbarian.hpp"
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
** Function: Barbarian()
** Description: Constructor for Barbarian derived class.
** Parameters: none.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
Barbarian::Barbarian() {
	setStrength(12);
	setNumDie(2);
	setDieSides(6);
	setArmor(0);
}

Barbarian::~Barbarian() {}


/***************************************************************************************
** Function: roll()
** Description:	Returns a random int from the sum of numDie rolls for attack and defense
** functions.
** Parameters: string "AorD" dummy parameter to avoid overloading virtual function.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Need to delete object and set pointer to null
****************************************************************************************/
int Barbarian::roll(string aorD) {
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

	cout << "Barbarian rolled " << result << endl;

	return result;
}


/***************************************************************************************
** Function: attack()
** Description:	Returns result of object's attack function.
**
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
int Barbarian::attack() {
	int result;
	cout << "Barbarian attacking" << endl;
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
void Barbarian::defend(int aR) {
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

	if (checkPulse()) {
		cout << "Barbarian: Conan has absorbed your attack!" << endl;
	}
	else {
		cout << "Barabarian: I've died a good death!" << endl;
	}
}


/***************************************************************************************
** Function: checkPulse()
** Description:	Returns a bool checking strength following an attack.
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
bool Barbarian::checkPulse() {
	int pulse;
	pulse = getStrength();
	if (pulse > 0) {
		return true;
	}
	else {
		return false;
	}
}


void Barbarian::setStrength(int strength) {
	this->strength = strength;
}

int Barbarian::getStrength() {
	return strength;
}

void Barbarian::setDieSides(int dieSides) {
	this->dieSides = dieSides;
}

int Barbarian::getDieSides() {
	return dieSides;
}

void Barbarian::setNumDie(int numDie) {
	this->numDie = numDie;
}


int Barbarian::getNumDie() {
	return numDie;
}


void Barbarian::setArmor(int armor) {
	this->armor = armor;
}

int Barbarian::getArmor() {
	return armor;
}
