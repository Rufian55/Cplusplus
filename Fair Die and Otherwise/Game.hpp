/****************************************************************************************
** Program Filename: Game.hpp
** Author: Chris Kearns
** Date: 1/24/2016
** Description: Game class header file.
** Input:
** Output:
*****************************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

class Game {
private:
	int roundsToPlay;			// roundsToPlay as input by user.

public:
	void createGame(int);			// Constructor.
	void setRoundsToPlay(int);		// Setter.
	int getRoundsToPlay();			// Getter.
};
#endif
