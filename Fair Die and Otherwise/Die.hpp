/****************************************************************************************
** Program Filename: Die.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 1/24/2016
** Description: Die class header file.
** Input: 
** Output: 
*****************************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die{

private:
	int sides;					// Die # of sides.
	bool load;					// Die loaded T/F

public:
	void createDice(int, bool);	// Constructor.
	void setSides(int);			// Sets # of sides.
	void setLoad(bool);			// Sets loaded doe T/F.
	int getSides();				// Returns die object's number of sides.
	bool getLoad();				// Returns die object's loaded T/F.
	int roll();					// Returns result of die object being rolled.
};
#endif