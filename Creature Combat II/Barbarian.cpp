/****************************************************************************************
** Program Filename: Barbarian.cpp
** Author: Chris Kearns
** Date: 2/28/2016
** Description: Barbarian class implementation file.
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
using std::endl;


/***************************************************************************************
** Function: Barbarian()
** Description: Constructor for Barbarian derived class.
** Parameters: user defind name and int player (which player's team this Creature is on.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
Barbarian::Barbarian(string name, string type, int player) {
	setStrength(12);
	setNumDie(2);
	setDieSides(6);
	setArmor(0);
	setName(name);
	setPlayer(player);
	setType(type);
	setcScore(0);
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
int Barbarian::roll(string aORd) {
	int i;
	int result = 0;
	int dSides;
	int die;
	vector<int> roller;

	if (aORd == "A") {
		dSides = getDieSides();
		die = getNumDie();
	}
	else {
		if (aORd == "D" || aORd == "H") {
			dSides = getDieSides();
			die = getNumDie();
		}
	}

	for (i = 1; i < dSides + 1; i++) {
		roller.push_back(i);
	}
	for (i = 0; i < die; i++) {
		random_shuffle(roller.begin(), roller.end());
		result += roller.at(0);
	}

	if (aORd == "A") {
		cout << "Player " << getPlayer() << "'s Barbarian " << getName() << " rolled "
			<< result << endl;
	}
	else if (aORd == "D") {
		cout << "Player " << getPlayer() << "'s Barbarian " << getName() << " rolled "
			<< result << " in defense!" << endl;
	}
	else {
		cout << "Player " << getPlayer() << "'s Barbarian " << getName() << " rolled "
			<< result << " for healing!" << endl;
	}
	return result;
}


/***************************************************************************************
** Function: attack()
** Description:	Returns result of object's attack function.
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
int Barbarian::attack() {
	int result;
	cout << "Player " << getPlayer() << "'s Barbarian " << getName() << " attacking!" << endl;
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
		cout << "Player " << getPlayer() << "'s Barbarian " << getName()
			<< ": Growl!! I have survived your attack!" << endl;
	}
	else {
		cout << "Player " << getPlayer() << "'s Barbarian " << getName()
			<< ": I've died a good death!" << endl;
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


/***************************************************************************************
** Function: healer()
** Description:	Resets strength var when called (Creature survived a combat round).
** Parameters: int result represents a roll of the Creatures default defense die to be
** used as a parameter for this Creature's setStrength var.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: resets this Creature's strength var following combat round victory.
****************************************************************************************/
void Barbarian::healer() {
	int result = roll("H");
	if (getStrength() < result) {
		setStrength(result);
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

void Barbarian::setPlayer(int player) {
	this->player = player;
}

int Barbarian::getPlayer() {
	return player;
}

void Barbarian::setName(string name) {
	this->name = name;
}

string Barbarian::getName() {
	return name;
}

void Barbarian::setType(string type) {
	this->type = type;
}

string Barbarian::getType() {
	return type;
}

void Barbarian::setcScore(int cScore) {
	this->cScore = cScore;
}

int Barbarian::getcScore() {
	return cScore;
}
