/****************************************************************************************
** Program Filename: LoadedDie.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 1/24/2016
** Description: Implementation file for LoadedDie class.
** Input: Player's die object.
** Output: returns highest roll of 4.
*****************************************************************************************/
#include "LoadedDie.hpp"
#include<iostream>
using std::cout;
using std::endl;

/***************************************************************************************
** Function: reRoll()
** Description: random die rolling "consoidation" function. Note Player's "roll" this
** function regardless of a fair or loaded die selected.
** Parameters: Player's die object.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Returns int rollem, highest roll of 4 rolls.
****************************************************************************************/
int LoadedDie::reRoll(Die d){
	int rollem = 0;		// Accumulator for highest roll.
	int newResult;		// Local var for capturing each roll.

	// Cheat by rolling die 4 times and taking highest score. 
	if (d.getLoad()) {
		for (int i = 0; i < 4; i++) {
			newResult = d.roll();
			if (newResult > rollem) {
				rollem = newResult;
			}
			// Sleep to inhibit identical rolls due to loop completing in < 1 sec.
			usleep(1000000);
		}
		cout << rollem << endl;
	}
	else {
		// Player selected a fair die.
		rollem = d.roll();
		cout << rollem << endl;
	}
	return rollem;
}