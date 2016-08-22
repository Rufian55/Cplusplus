/****************************************************************************************
** Program Filename: Critter.cpp
** Author: Chris Kearns
** Date: 2/7/2016
** Description: Critter class implementation file.
*****************************************************************************************/
#include "Critter.hpp"
#include<cstdlib>

/***************************************************************************************
** Function: getRan()
** Description:	Returns a random int from 1 to 4 for object movement up, down, left, right.
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: None.
****************************************************************************************/
int Critter::getRand() {
	return rand() % 4 + 1;
}
