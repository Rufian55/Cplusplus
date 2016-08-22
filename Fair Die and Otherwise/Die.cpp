/****************************************************************************************
** Program Filename: Die.cpp
** Author: Chris Kearns
** Date: 1/24/2016
** Description: Implementation file for Die class.
** Input: int sides, bool load.
** Output: int sides, bool load, int result.
*****************************************************************************************/
#include "Die.hpp"
#include<ctime>
#include<cstdlib>

/***************************************************************************************
** Function: createDice()
** Description: sets sides and load for the die object.
** Parameters: int sides, bool load.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: None.
****************************************************************************************/
void Die::createDice(int ss, bool sl) {
	setSides(ss);
	setLoad(sl);
}

// Setter function for sides.
void Die::setSides(int ss) {
	sides = ss;
}

// Setter function for load.
void Die::setLoad(bool sl) {
	load = sl;
}

// Getter function for sides.
int Die::getSides() {
	int aSides = sides;
	return aSides;
}

// Getter function for load.
bool Die::getLoad() {
	bool aLoad = load;
	return aLoad;
}

/***************************************************************************************
** Function: roll()
** Description: random die rolling function.
** Parameters: void
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Returns int result.
****************************************************************************************/
int Die::roll() {
	int sides = getSides();
	
	unsigned seed = time(NULL);
	srand(seed);
	
	int result = rand() % sides + 1;

	return result;
}
