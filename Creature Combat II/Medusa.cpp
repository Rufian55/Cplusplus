/****************************************************************************************
** Program Filename: Medusa.cpp
** Author: Chris Kearns
** Date: 2/28/2016
** Description: Medussa class implementation file.
*****************************************************************************************/
#include "Medusa.hpp"
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
** Function: Medusan()
** Description: Constructor for Medusa derived class.
** Parameters: user defind name and int player (which player's team this Creature is on. 
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
Medusa::Medusa(string name, string type, int player){
	setStrength(8);
	setNumDie_A(2);
	setDieSides_A(6);
	setNumDie_D(1);
	setDieSides_D(6);
	setArmor(3);
	setName(name);
	setPlayer(player);
	setType(type);
	setcScore(0);
}

Medusa::~Medusa(){}


/***************************************************************************************
** Function: roll()
** Description:	Returns a random int from the sum of numDie rolls for attack and defense
** funtions.
** Parameters: dieSides A or D depending on which dieSides is requrired.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
int Medusa::roll(string aORd) {
	int i;
	int result = 0;
	int dSides;
	int die;
	vector<int> roller;

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
		cout << "Player " << getPlayer() << "'s Medusa " << getName() << " rolled "
			<< result << endl;
	}
	else if (aORd == "D") {
		cout << "Player " << getPlayer() << "'s Medusa " << getName() << " rolled "
			<< result << " in defense!" << endl;
	}else{
		cout << "Player " << getPlayer() << "'s Medusa " << getName() << " rolled "
			<< result << " for healing!" << endl;
	}
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
int Medusa::attack() {
	int result;
	cout << "Player " << getPlayer()  << "'s Medusa " << getName() << " attacking!" << endl;
	result = roll("A");
	if (result == 12) {
		result = 100;
		cout << "Player " << getPlayer() << "'s Medusa " << getName() 
			<< ": You've looked at Me and you will turn	to stone!" << endl;
	}
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
void Medusa::defend(int aR) {
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
		cout << "Player " << getPlayer() << "'s Medusa " << getName() 
			<< ": Hiss!!! I have survived your attack!" << endl;
	}else{
		cout << "Player " << getPlayer() << "'s Medusa " << getName() 
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
bool Medusa::checkPulse() {
	int pulse;
	pulse = getStrength();
	if (pulse > 0) {
		return true;
	}else{
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
void Medusa::healer(){
	int result = roll("H");
	if (getStrength() < result) {
		setStrength(result);
	}
}

void Medusa::setStrength(int strength) {
	this->strength = strength;
}

int Medusa::getStrength() {
	return strength;
}

void Medusa::setDieSides_A(int dieSides_A){
	this->dieSides_A = dieSides_A;
}

int Medusa::getDieSides_A(){
	return dieSides_A;
}

void Medusa::setNumDie_A(int numDie_A){
	this->numDie_A = numDie_A;
}


int Medusa::getNumDie_A(){
	return numDie_A;
}

void Medusa::setDieSides_D(int dieSides_D) {
	this->dieSides_D = dieSides_D;
}

int Medusa::getDieSides_D() {
	return dieSides_D;
}

void Medusa::setNumDie_D(int numDie_D) {
	this->numDie_D = numDie_D;
}


int Medusa::getNumDie_D() {
	return numDie_D;
}

void Medusa::setArmor(int armor){
	this->armor = armor;
}

int Medusa::getArmor() {
	return armor;
}

void Medusa::setPlayer(int player){
	this->player = player;
}

int Medusa::getPlayer(){
	return player;
}

void Medusa::setName(string name){
	this->name = name;
}

string Medusa::getName(){
	return name;
}

void Medusa::setType(string type){
	this->type = type;
}

string Medusa::getType(){
	return type;
}

void Medusa::setcScore(int cScore){
	this->cScore = cScore;
}

int Medusa::getcScore(){
	return cScore;
}
