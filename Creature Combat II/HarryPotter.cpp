/****************************************************************************************
** Program Filename: Harrypotter.cpp
** Author: Chris Kearns
** Date: 2/28/2016
** Description: HarryPotter class implementation file.
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
using std::endl;


/***************************************************************************************
** Function: HarryPotter()
** Description: Constructor for HarryPotter derived class.
**
** Parameters: user defind name and int player (which player's team this Creature is on.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
HarryPotter::HarryPotter(string name, string type, int player){
	setStrength(10);
	setNumDie(2);
	setDieSides(6);
	setArmor(0);
	setDeadOnce(0);
	setName(name);
	setPlayer(player);
	setType(type);
	setcScore(0);
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
int HarryPotter::roll(string aORd){
	int i;
	int result = 0;
	int dSides;
	int die;
	vector<int> roller;

	dSides = getDieSides();
	die = getNumDie();

	for (i = 1; i < dSides + 1; i++) {
		roller.push_back(i);
	}
	for (i = 0; i < die; i++) {
		random_shuffle(roller.begin(), roller.end());
		result += roller.at(0);
	}

	if (aORd == "A") {
		cout << "Player " << getPlayer() << "'s HarryPotter " << getName() << " rolled "
			<< result << endl;
	}
	else if (aORd == "D") {
		cout << "Player " << getPlayer() << "'s HarryPotter " << getName() << " rolled "
			<< result << " in defense!" << endl;
	}
	else {
		cout << "Player " << getPlayer() << "'s HarryPotter " << getName() << " rolled "
			<< result << " for healing!" << endl;
	}
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
	cout << "Player " << getPlayer() << "'s HarryPotter " << getName() << " attacking!" << endl;
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
		cout << "Player " << getPlayer() << "'s HarryPotter " << getName()
			<< ": The more you care the more you have to lose!" << endl;
		if (deadOnce == 1) {
			cout << "Player " << getPlayer() << "'s HarryPotter " << getName()
				<< ": I'm on my second life!" << endl;
		}
	}
	else {
		if (deadOnce == 1) {
			cout << "Player " << getPlayer() << "'s HarryPotter " << getName()
				<< ": I've died a seconcd death!" << endl;
		}
		else {
			cout << "Player " << getPlayer() << "'s HarryPotter " << getName()
				<< ": You've won, but I've another life to live!" << endl;
		}
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


/***************************************************************************************
** Function: healer()
** Description:	Resets strength var when called (Creature survived a combat round).
** Parameters: int result represents a roll of the Creatures default defense die to be
** used as a parameter for this Creature's setStrength var.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: resets this Creature's strength var following combat round victory.
****************************************************************************************/
void HarryPotter::healer() {
	int result = roll("H");
	if (result > 10) { result = 10; }
	if (getStrength() < result) {
		setStrength(result);
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

void HarryPotter::setPlayer(int player) {
	this->player = player;
}

int HarryPotter::getPlayer() {
	return player;
}

void HarryPotter::setName(string name) {
	this->name = name;
}

string HarryPotter::getName() {
	return name;
}

void HarryPotter::setType(string type) {
	this->type = type;
}

string HarryPotter::getType() {
	return type;
}

void HarryPotter::setcScore(int cScore) {
	this->cScore = cScore;
}

int HarryPotter::getcScore() {
	return cScore;
}
