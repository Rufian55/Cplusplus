/****************************************************************************************
** Program Filename: Play.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/7/2016
** Description: Play class implementation file. Utilizes virtual class Critter, then Ant
** and Doodlbug classes.
** Input:	user, various functions from Critter, Ant, and Doodlebug.
** Output:	to console.
*****************************************************************************************/
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "Play.hpp"
#include<iostream>
using std::cout;


int main() {
	srand(time(NULL));

	Play *pp = new Play();
	pp->grid();

	// Finally, clear console and output message.
	cout << "\033[40A"
		<< "\033[2J"
		<< "\033[1; 1H"
		<< "\nThank's for trying the Predator Prey Cellular Automaton Simulator!\n";

	delete pp;
	pp = NULL;
}