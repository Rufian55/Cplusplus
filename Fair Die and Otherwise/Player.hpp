/****************************************************************************************
** Program Filename: Player.hpp
** Author: Chris Kearns
** Date: 1/24/2016
** Description: Player class header file.
** Input:
** Output:
*****************************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
using std::string;

class Player {
private:
	int typeDice;		// Loaded or not (in int 0 or 1 input format)
	string name;		// Player's inputted name.
	int score;		// Player's score for each die roll.
	double roundsWon;	// Rounds won by Player.

public:
	void createPlayer(int typeDice, string name);	// Constructor.
	void setTypeDice(int);				// Setter for if fair or loaded die is used by player.
	int getTypeDice();				// Getter for typeDice.
	void setName(string);				// Setter for Player's name.
	string getName();				// Getter for Player's name.
	void setScore(int);				// Setter for Player's score each round.
	int getScore();					// Getter for Player's score each round.
	void setRoundsWon(double);			// Setter for Player's running total of rounds won.
	double getRoundsWon();				// Getter for Player's running total of rounds won.
};
#endif
