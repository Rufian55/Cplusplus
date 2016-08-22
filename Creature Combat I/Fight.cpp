/****************************************************************************************
** Program Filename: Fight.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/14/2016
** Description: Fight class implementation file. Utilizes virtual class Creature, then 
** Medusa, Barbarian, Vampire, blueMen, and GarryPotter classes.
** Input:	user, various functions from Creature, Vampire, BlueMen, HarrPotter.
** Output:	to console.
*****************************************************************************************/
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Fight.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<iomanip>
using std::setw;
#include<cstdlib>
using std::srand;
using std::rand;
#include<string>
using std::string;
#include<sstream>

int main() {
	srand(time(NULL));			// Seed for roll rand functions.
	int attackResult;			// Intermediate attack result.
	int choice;					// Local user creature choice.
//	Fight *fight = new Fight;	// A new fight!
	Creature *theRing[2];		// The fighting ring with room for two Creatures!
	string p1name;				// Local naming var for creature picked by Player 1.
	string p2name;				// Local naming var for creature picked by Player 2.
	int rounds;					// round counter for "Fight to the Death".

	// Main menu loop for Player 1 creature selection.
	cout << "Welcome to Creature Combat!" << endl << endl;
	cout << "Player 1, please choose your Creature from the list or 0 to quit.." << endl;
	cout << "1. Medusa" << endl;
	cout << "2. Barbarian" << endl;
	cout << "3. Vampire" << endl;
	cout << "4. BlueMen" << endl;
	cout << "5. Harry Potter" << endl;
	cin >> choice;
	if (choice == 0) {
		return 0;
	}
	while (choice < 0 || choice > 5) {
		cout << "Player 1, please choose your Creature from the list or 0 to quit.." << endl;
		cout << "1. Medusa" << endl;
		cout << "2. Barbarian" << endl;
		cout << "3. Vampire" << endl;
		cout << "4. BlueMen" << endl;
		cout << "5. Harry Potter" << endl;
		cin >> choice;
		// Exit while loop if user inputs 0 for quit.
		if (choice == 0)
			return 0;
	}
	// Program exit if user has input 0 for quit.
	if (choice == 0)
		return 0;

	// Set appropriate creature for Player 1 to our Creature pointer array.
	if (choice == 1) {
		Medusa *p1 = new Medusa;
		theRing[0] = p1;
		p1name = "Medusa_P1";
	}
	else {
		if (choice == 2) {
			Barbarian *p1 = new Barbarian;
			theRing[0] = p1;
			p1name = "Barbarian_P1";
		}
		else {
			if (choice == 3) {
				Vampire *p1 = new Vampire;
				theRing[0] = p1;
				p1name = "Vampire_P1";
			}
			else {
				if (choice == 4) {
					BlueMen *p1 = new BlueMen;
					theRing[0] = p1;
					p1name = "BlueMen_P1";
				}
				else {
					if (choice == 5) {
						HarryPotter *p1 = new HarryPotter;
						theRing[0] = p1;
						p1name = "Harry Potter_P1";
					}
				}
			}
		}
	}

	// Main menu loop for Player 2 creature selection.
	cout << endl;
	cout << "Player 2, please choose your Creature from the list or 0 to quit.." << endl;
	cout << "1. Medusa" << endl;
	cout << "2. Barbarian" << endl;
	cout << "3. Vampire" << endl;
	cout << "4. BlueMen" << endl;
	cout << "5. Harry Potter" << endl;
	cin >> choice;
	if (choice == 0) {
		return 0;
	}
	while (choice < 0 || choice > 5) {
		cout << "Player 2, please choose your Creature from the list or 0 to quit.." << endl;
		cout << "1. Medusa" << endl;
		cout << "2. Barbarian" << endl;
		cout << "3. Vampire" << endl;
		cout << "4. BlueMen" << endl;
		cout << "5. Harry Potter" << endl;
		cin >> choice;
		// Exit while loop if user inputs 0 for quit.
		if (choice == 0)
			return 0;
	}
	// Program exit if user has input 0 for quit.
	if (choice == 0)
		return 0;

	// Set appropriate creature for Player 2 to our Creature pointer array.
	if (choice == 1) {
		Medusa *p2 = new Medusa;
		theRing[1] = p2;
		p2name = "Medusa_P2";
	}
	else {
		if (choice == 2) {
			Barbarian *p2 = new Barbarian;
			theRing[1] = p2;
			p2name = "Barbarian_P1";
		}
		else {
			if (choice == 3) {
				Vampire *p2 = new Vampire;
				theRing[1] = p2;
				p2name = "Vampire_P2";
			}
			else {
				if (choice == 4) {
					BlueMen *p2 = new BlueMen;
					theRing[1] = p2;
					p2name = "BlueMen_P2";
				}
				else {
					if (choice == 5) {
						HarryPotter *p2 = new HarryPotter;
						theRing[1] = p2;
						p2name = "Harry Potter_P2";
					}
				}
			}
		}
	}
	cout << endl;

	cout << "Press 1 for Single Round, 2 for Fight to the Death, or 0 to Quit." << endl;
	cin >> choice;
	if (choice == 0)
		return 0;
	while (choice < 0 || choice > 2) {
		cout << "Pay attention!!" << endl;
		cout << "Press 1 for Single Round, 2 for Fight to the Death, or 0 to Quit." << endl;
		cin >> choice;
		if (choice == 0)
			return 0;
	}
	if (choice == 0)
		return 0;

	if (choice == 1) {
		//Player 1 attacks Player 2, Player 2 defends and reports status.
		attackResult = theRing[0]->attack();
		theRing[1]->defend(attackResult);
		cout << p2name << "'s strength = " << theRing[1]->getStrength() << endl;
		cout << p2name << " is ";
		if (theRing[1]->checkPulse() == 1) {
			cout << "alive." << endl;
		}
		else {
			cout << "dead." << endl;
		}

		cout << endl;

		//Player 2 attacks Player 1, Player 1 defends and reports status.
		attackResult = theRing[1]->attack();
		theRing[0]->defend(attackResult);
		cout << p1name << "'s strength = " << theRing[0]->getStrength() << endl;
		cout << p1name << " is ";
		if (theRing[0]->checkPulse() == 1) {
			cout << "alive." << endl;
		}
		else {
			cout << "dead." << endl;
		}
	}else{
		rounds = 1;
		while (theRing[0]->checkPulse() && theRing[1]->checkPulse() && rounds < 101) {
			cout << "Round # " << rounds << endl;
			//Player 1 attacks Player 2, Player 2 defends and reports status.
			attackResult = theRing[0]->attack();
			theRing[1]->defend(attackResult);
			cout << p2name << "'s strength = " << theRing[1]->getStrength() << endl;
			cout << p2name << " is ";
			if (theRing[1]->checkPulse() == 1) {
				cout << "alive." << endl;
			}
			else {
				cout << "dead." << endl;
				return 0;
			}
			cout << endl;

			//Player 2 attacks Player 1, Player 1 defends and reports status.
			attackResult = theRing[1]->attack();
			theRing[0]->defend(attackResult);
			cout << p1name << "'s strength = " << theRing[0]->getStrength() << endl;
			cout << p1name << " is ";
			if (theRing[0]->checkPulse() == 1) {
				cout << "alive." << endl;
			}
			else {
				cout << "dead." << endl;
				return 0;
			}
			cout << endl;
			rounds++;
		}
	}
	cout << endl << endl << "Thank's for playing!" << endl; 
}