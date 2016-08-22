/****************************************************************************************
** Program Filename: Player.cpp
** Author: Chris Kearns
** Date: 1/24/2016
** Description: Implementation file for Player class.
** Input: int typeDice, string name, int score, int roundsWon.
** Output: returns int typeDice, string name, int score, int roundsWon. 
*****************************************************************************************/
#include "Player.hpp"

/***************************************************************************************
** Function: createPlayer()
** Description: Constructor to set Player object vars.
** Parameters: int tyoeDice, string name.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: void, sets typeDice, name, score, and roundsWon for Player object.
****************************************************************************************/
void Player::createPlayer(int typeDice, string name) {
	setTypeDice(typeDice);
	setName(name);
	setScore(0);
	setRoundsWon(0);
}

// Setter for typeDice var.
void Player::setTypeDice(int td) {
	typeDice = td;
}

// Getter for typeDice var.
int Player::getTypeDice() {
	int td = typeDice;
	return td;
}

// Setter for name var.
void Player::setName(string aname) {
	name = aname;
}

// Getter for name var.
string Player::getName(){
	string aname = name;
	return aname;
}

// Setter for score var (each individual round).
void Player::setScore(int sc) {
	score = sc;
}

// Getter for score var (each individual round).
int Player::getScore() {
	int sc = score;
	return sc;
}

// Setter for roundsWon var.
void Player::setRoundsWon(double rw) {
	roundsWon = rw;
}

// Getter for roundsWon var.
double Player::getRoundsWon() {
	double rw = roundsWon;
	return rw;
}
