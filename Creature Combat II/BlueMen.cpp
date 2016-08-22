/****************************************************************************************
** Program Filename: BlueMen.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/28/2016
** Description: BlueMen class implementation file.
*****************************************************************************************/
#include "BlueMen.hpp"
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
** Function: BlueMenn()
** Description: Constructor for BlueMen derived class.
**
** Parameters: user defind name and int player (which player's team this Creature is on.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
BlueMen::BlueMen(string name, string type, int player){
	setStrength(12);
	setNumDie_A(2);
	setDieSides_A(10);
	setNumDie_D(3);
	setDieSides_D(6);
	setArmor(3);
	setName(name);
	setPlayer(player);
	setType(type);
	setcScore(0);
}

BlueMen::~BlueMen(){}


/***************************************************************************************
** Function: roll()
** Description:	Returns a random int from the sum of numDie rolls for attack and defense
** funtions.
** Parameters: dieSides A or D for which diesides is to be utilized.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Need to delete array!
****************************************************************************************/
int BlueMen::roll(string aORd) {
	int i;
	int result = 0;
	int dSides;
	int die;
	vector<int> roller;

	mob();// Updates dieSides_D based on current strength value.

	if (aORd == "A") {
		dSides = getDieSides_A();
		die = getNumDie_A();
	}
	else {
		if (aORd == "D" || aORd == "H") {
			dSides = getDieSides_D();
			die = getNumDie_D();
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
		cout << "Player " << getPlayer() << "'s BlueMen " << getName() << " rolled "
			<< result << endl;
	}
	else if (aORd == "D") {
		cout << "Player " << getPlayer() << "'s BlueMen " << getName() << " rolled "
			<< result << " in defense!" << endl;
	}
	else {
		cout << "Player " << getPlayer() << "'s BlueMen " << getName() << " rolled "
			<< result << " for healing!" << endl;
	}
	return result;
}


/***************************************************************************************
** Function: mob()
** Description:	sets defense dieSides_D var based upon current strength value. dieSides_D
** decrements when stregth reachs 8, and again when stregth reachs 4.
** Parameters: void.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: reset dieSides_D (defense)
****************************************************************************************/
void BlueMen::mob() {
	int temp = getStrength();
	if (temp <= 8 && temp > 4) {
		setNumDie_D(2);
	}
	else {
		if (temp <= 4) {
			setNumDie_D(1);
		}
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
int BlueMen::attack() {
	int result;
	cout << "Player " << getPlayer() << "'s BlueMen " << getName() << " attacking!" << endl;
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
void BlueMen::defend(int aR) {
	mob();
	int defendResult;
	int damage;
	int newStrengthPoints;
	int armor = getArmor();
	int currentStrength = getStrength();

	int bmDie = getNumDie_D();
	cout << "Player " << getPlayer() << "'s BlueMen " << getName() << " defending with " << bmDie << " die." << endl;

	defendResult = roll("D");
	damage = aR - defendResult;
	if (damage > armor) {
		newStrengthPoints = currentStrength - damage + armor;
		setStrength(newStrengthPoints);
	}

	if (checkPulse()) {
		cout << "Player " << getPlayer() << "'s BlueMen " << getName()
			<< ": Your attack has failed, we will crawl inside" << endl
			<< " your dead body!" << endl;
	}
	else {
		cout << "Player " << getPlayer() << "'s BlueMen " << getName()
			<< ": We've died a good death!" << endl;
	}
}


/***************************************************************************************
** Function: checkPulse()
** Description:	Returns a bool checking strength following an attack.
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
bool BlueMen::checkPulse() {
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
void BlueMen::healer() {
	int result = roll("H");
	if (result > 12) { result = 12; }
	if (getStrength() < result) {
		setStrength(result);
	}
}


void BlueMen::setStrength(int strength){
	this->strength = strength;
}

int BlueMen::getStrength(){
	return strength;
}

void BlueMen::setDieSides_A(int dieSides_A){
	this->dieSides_A = dieSides_A;
}

int BlueMen::getDieSides_A(){
	return dieSides_A;
}

void BlueMen::setNumDie_A(int numDie_A){
	this->numDie_A = numDie_A;
}

int BlueMen::getNumDie_A(){
	return numDie_A;
}

void BlueMen::setDieSides_D(int dieSides_D){
	this->dieSides_D = dieSides_D;
}

int BlueMen::getDieSides_D(){
	return dieSides_D;
}

void BlueMen::setNumDie_D(int numDie_D){
	this->numDie_D = numDie_D;
}

int BlueMen::getNumDie_D(){
	return numDie_D;
}

void BlueMen::setArmor(int armor){
	this->armor = armor;
}

int BlueMen::getArmor(){
	return armor;
}

void BlueMen::setPlayer(int player) {
	this->player = player;
}

int BlueMen::getPlayer() {
	return player;
}

void BlueMen::setName(string name) {
	this->name = name;
}

string BlueMen::getName() {
	return name;
}

void BlueMen::setType(string type) {
	this->type = type;
}

string BlueMen::getType() {
	return type;
}

void BlueMen::setcScore(int cScore) {
	this->cScore = cScore;
}

int BlueMen::getcScore() {
	return cScore;
}