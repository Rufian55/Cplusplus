/****************************************************************************************
** Program Filename: Vampire.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/14/2016
** Description: Vampire class implementation file.
** Input:
** Output:
*****************************************************************************************/
#include "Vampire.hpp"
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
** Function: Vampire()
** Description: Constructor for Vampire derived class.
**
** Parameters: none.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
Vampire::Vampire() {
	setStrength(18);
	setNumDie(1);
	setDieSides_A(12);
	setDieSides_D(6);
	setArmor(1);
	setCharm(false);
}

Vampire::~Vampire() {}


/***************************************************************************************
** Function: roll()
** Description:	Returns a random int from the sum of numDie rolls for attack and defense
** funtions.
** Parameters: string A or D for which dieSides to use.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Need to delete array!
****************************************************************************************/
int Vampire::roll(string aORd) {
	int i;
	int result = 0;
	int dSides;
	int die = getNumDie();;
	vector<int> roller;

	if (aORd == "A") {
		dSides = getDieSides_A();
	}
	else {
		if (aORd == "D") {
			dSides = getDieSides_D();
		}
	}

	//Roll
	for (i = 1; i < dSides + 1; i++) {
		roller.push_back(i);
	}
	for (i = 0; i < die; i++) {
		random_shuffle(roller.begin(), roller.end());
		result += roller.at(0);
	}

	cout << "Vampire rolled " << result << endl;

	return result;
}


/***************************************************************************************
** Function: charmer()
** Description:	Returns a bool randomly. Used with Vampire class for supressing
** opponeents attack() functions via Vampire defense().
** Parameters: void
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: 
****************************************************************************************/
void Vampire::charmer() {
	int i;
	int aCharm;
	vector<int> charmer;

	for (i = 0; i < 2; i++) {
		charmer.push_back(i);
	}
	for (i = 0; i < 2; i++) {
		random_shuffle(charmer.begin(), charmer.end());
		aCharm = charmer.at(0);
	}

	if (aCharm == 0) {
		setCharm(false);
	}
	else {
		setCharm(true);
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
int Vampire::attack() {
	int result;
	cout << "Vampire attacking" << endl;
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
void Vampire::defend(int aR) {
	bool charmed = getCharm();
	if (charmed == false) {
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
			cout << "Vampire: My fangs will now suck your blood!" << endl;
		}
		else {
			cout << "Vampire: I've died a good death!" << endl;
		}
	}
	else {
		cout << "You've been charmed and did not attack." << endl;
	}
}


/***************************************************************************************
** Function: checkPulse()
** Description:	Returns a bool checking strength following an attack.
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
bool Vampire::checkPulse() {
	int pulse;
	pulse = getStrength();
	if (pulse > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Vampire::setStrength(int strength) {
	this->strength = strength;
}

int Vampire::getStrength() {
	return strength;
}

void Vampire::setDieSides_A(int dieSides_A) {
	this->dieSides_A = dieSides_A;
}

int Vampire::getDieSides_A() {
	return dieSides_A;
}

void Vampire::setDieSides_D(int dieSides_D) {
	this->dieSides_D = dieSides_D;
}

int Vampire::getDieSides_D() {
	return dieSides_D;
}

void Vampire::setNumDie(int numDie) {
	this->numDie = numDie;
}

int Vampire::getNumDie() {
	return numDie;
}

void Vampire::setArmor(int armor) {
	this->armor = armor;
}

int Vampire::getArmor() {
	return armor;
}

void Vampire::setCharm(bool aCharm) {
	this->charm = aCharm;
}


/***************************************************************************************
** Function: getCharm()
** Description:	calls charmer that sets charm var with a coin flip, returns bool.
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: charm var is reset.
****************************************************************************************/
bool Vampire::getCharm(){
	charmer();
	return charm;
}
