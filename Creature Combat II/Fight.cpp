/****************************************************************************************
** Program Filename: Fight.cpp
** Author: Chris Kearns
** Date: 2/28/2016
** Description: Fight class implementation file. Utilizes virtual class Creature, then 
** Medusa, Barbarian, Vampire, BlueMen, and HarryPotter classes.
** Input: user, various functions from Creature, Medusa, Barbarain, Vampire, BlueMen,
** HarryPotter, Stack, and Queue.
** Output:	to console.
*****************************************************************************************/
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Fight.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;
#include<cstddef>
#include<ctime>


int main() {
	srand(time(0));				// Seed for roll rand functions.
	int attackResult;			// Intermediate attack result.
	int choice;				// Local user creature choice cin collection var.
	int displaySB;				// Local Display Score Board option cin collection var.
	Creature *theRing[2];			// The fighting ring with room for two Creatures!
	Creature *cret;				// Utiltity pointer for swapping Creatures around!
	string name;				// Local naming var for setting creature's name.
	string type;				// Local var for setting Creature object's type designator.
	int player;				// Local player id for assigning Creature to Player (1or2)
	int mRounds = 1;			// Individual match round counter for "Fight to the Death" to stop infinite loops.
	int tRounds = 1;			// Tournament rounds - increments until one of the queues is empty.
	Queue fighters1;			// Player 1 fighters lineup.
	Queue fighters2;			// Player 2 fighters lineup.
	Stack losers;				// Losers pile (both Player's losers stacked here).
	Stack losersHOH;			// Losers mirror pile for dispaly losers Hall Of Honor in FILO order option.
	int cLosersHOH;				// Local cin collection var for display Hall of Honor option.
	int cAll;				// Local cin var to display all fighters option.
	int numPlayer;				// Local cin var for number of players per team.
	int i = 0;				// Local for loop control var.
	int j = 0;				// Local for loop control var.
	string ess = "!";			// Trailing 's' on Creature(s).
	int cScore = 0;				// Individual Creatures score (accumulated healed score after each round.
	int p1score = 0;			// Player 1's team score, accumulated from each individual cScore.
	int p2score = 0;			// Player 2's team score, accumulated from each individual cScore.
	int p1_W = 0;				// Player 1's total wins accumulator.
	int p1_L = 0;				// Player 1's total losses accumulator.
	int p2_W = 0;				// Player 2's total wins accumulator.
	int p2_L = 0;				// Player 2's total losses accumulator.
	int tWinner;				// Local var for Which team won the tournament.
	int size = 0;				// Local var for sorting standings array.
	Fight my;				// A fight object so we can run sorting algorithms.
	string aP;				// Used for Awarding medals Posthumously.
	int determine;				// Local collection var for user to choose W-L or points for decision!
	string determ;				// For cout of which determine method user decided upon.


	cout << endl << "WELCOME TO CREATURE COMBAT TOUNAMENT OF CHAMPIONS" << endl
		<< "Players! How many Creatures per player? (Range is 1 to 10)" << endl;
	cin >> numPlayer;
	while (numPlayer < 1 || numPlayer > 10) {
		cout << "Error! Range is from 1 to 10" << endl
			<< "Please enter an int from 1 to 10." << endl;
		cin >> numPlayer;
	}

	// Plural for case of 1 Creature selected.
	if (numPlayer > 1) { ess = "s!"; }

	// Create an array to mirror Player1 selected Creature types to inform Player2.
	string *mirror = new string[numPlayer];

	//Player_1 fighters1 queue Creature lineup
	cout << "Player 1, choose " << numPlayer << " Creature" << ess << endl;
	for (i = 0; i < numPlayer; i++) {
		cout << "Player 1, please choose Creature #" << i + 1 << " from the list or 0 to quit." << endl
			<< "1. Medusa" << endl
			<< "2. Barbarian" << endl
			<< "3. Vampire" << endl
			<< "4. BlueMen" << endl
			<< "5. Harry Potter" << endl;
		cin >> choice;

		if (choice == 0) { exit(EXIT_SUCCESS); }

		while (choice < 0 || choice > 5) {
			cout << "Error!" << endl
				<< "Player 1, please choose Creature #" << i + 1 << " from the list or 0 to quit.." << endl
				<< "1. Medusa" << endl
				<< "2. Barbarian" << endl
				<< "3. Vampire" << endl
				<< "4. BlueMen" << endl
				<< "5. Harry Potter" << endl;
			cin >> choice;
		}
		if (choice == 0) { exit(EXIT_SUCCESS); }

		cout << "Player 1, what will Creature #" << i + 1 << "'s name be?" << endl;
		cin.ignore(256, '\n');
		getline(cin, name);

		// Set appropriate creature for Player 1 to our Creature Queue fighters1.
		if (choice == 1) {
			type = "Medusa";
			mirror[i] = type;
			Medusa *p1 = new Medusa(name, type, 1);
			fighters1.add(p1);
		} else if (choice == 2) {
			type = "Barbarian";
			mirror[i] = type;
			Barbarian *p1 = new Barbarian(name, type, 1);
			fighters1.add(p1);
		} else if (choice == 3) {
			type = "Vampire";
			mirror[i] = type;
			Vampire *p1 = new Vampire(name, type, 1);
			fighters1.add(p1);
		} else if (choice == 4) {
			type = "BlueMen";
			mirror[i] = type;
			BlueMen *p1 = new BlueMen(name, type, 1);
			fighters1.add(p1);
		} else if (choice == 5) {
			type = "HarryPotter";
			mirror[i] = type;
			HarryPotter *p1 = new HarryPotter(name, type, 1);
			fighters1.add(p1);
		}
	}

	//Player_2 fighters2 queue Creature lineup with mirror feature.
	cout << "Player 2, choose " << numPlayer << " Creature" << ess << endl;
	for (i = 0; i < numPlayer; i++) {
		cout << "Player 2, for this round, your opponenet chose a " << mirror[i] << "." << endl
			<< "Player 2, please choose Creature #" << i + 1 << " from the list or 0 to quit." << endl
			<< "1. Medusa" << endl
			<< "2. Barbarian" << endl
			<< "3. Vampire" << endl
			<< "4. BlueMen" << endl
			<< "5. Harry Potter" << endl;
		cin >> choice;
		if (choice == 0) { exit(EXIT_SUCCESS); }

		while (choice < 0 || choice > 5) {
			cout << "Error!" << endl
				<< "Player 2, for this round, your opponent chose a " << mirror[i] << "." << endl
				<< "Player 2, please choose Creature #" << i + 1 << " from the list or 0 to quit.." << endl
				<< "1. Medusa" << endl
				<< "2. Barbarian" << endl
				<< "3. Vampire" << endl
				<< "4. BlueMen" << endl
				<< "5. Harry Potter" << endl;
			cin >> choice;
		}
		if (choice == 0) { exit(EXIT_SUCCESS); }

		cout << "Player 2, what will Creature #" << i + 1 << "'s name be?" << endl;
		cin.ignore(256, '\n');
		getline(cin, name);

		// Set appropriate creature for Player 2 to our Creature Queue fighters1.
		if (choice == 1) {
			type = "Medusa";
			Medusa *p2 = new Medusa(name, type, 2);
			fighters2.add(p2);
		} else if (choice == 2) {
			type = "Barbarian";
			Barbarian *p2 = new Barbarian(name, type, 2);
			fighters2.add(p2);
		} else if (choice == 3) {
			type = "Vampire";
			Vampire *p2 = new Vampire(name, type, 2);
			fighters2.add(p2);
		} else if (choice == 4) {
			type = "BlueMen";
			BlueMen *p2 = new BlueMen(name, type, 2);
			fighters2.add(p2);
		} else if (choice == 5) {
			type = "HarryPotter";
			HarryPotter *p2 = new HarryPotter(name, type, 2);
			fighters2.add(p2);
		}
	}

	// Clean up mirror array.
	delete [] mirror;
	mirror = NULL;

	// Option selection for Display Tournament Scoreboard after each round.
	cout << "Now, before we begin the Tournament, would you" << endl
		<< "like to see the Tournament Scorebaord after each round?" << endl
		<< "Enter 1 for Yes, 0 for No" << endl;
	cin >> displaySB;
	while (displaySB < 0 || displaySB > 1) {
		cout << "Error! Enter 1 to see the scoreboard after each round, or 0 for no" << endl;
		cin >> displaySB;
	}

	// Option selection for Tournament decided on W-L recored vs. Points. 
	cout << "One last thing! Do you want the Tournament to be" << endl
		<< "decided on W-L record or Team Points accrued?" << endl
		<< "Enter 1 for W-L, 2 for points accrued." << endl;
	cin >> determine;
	while (determine < 1 || determine > 2) {
		cout << "Error!" << "Do you want the Tournament " << endl
			<< "decided on W-L record or Team Points accrued?" << endl
			<< "Enter 1 for W-L, 2 for points accrued." << endl;
		cin >> determine;
	}

	cout << endl;

	// Tournament Logic (continues until either Player's fighters queue is empty!
	while(fighters1.isEmpty() == false && fighters2.isEmpty() == false ) {
		theRing[0] = fighters1.remove();
		theRing[1] = fighters2.remove();

		while (theRing[0]->checkPulse() && theRing[1]->checkPulse()) {
			cout << "Tournament Round " << tRounds << ": " << theRing[0]->getType() << " "
				<< theRing[0]->getName() << " vs. " << theRing[1]->getType() << " "
				<< theRing[1]->getName() << endl << "  fighting Match Round #" << mRounds << endl;

			//Player 1 attacks Player 2, Player 2 defends and reports status.
			attackResult = theRing[0]->attack();
			theRing[1]->defend(attackResult);
			cout << "Player " << theRing[1]->getPlayer() << "'s " << theRing[1]->getType()
				<< " " << theRing[1]->getName() << " possesses strength = "
				<< theRing[1]->getStrength() << endl;
			if (theRing[1]->checkPulse() == 1) {
				cout << " and is alive." << endl;
			} else {
				cout << " and is thus defeated." << endl;
			}
			cout << endl;

			/* If Player 2 survived Player 1's attack, Player 2 attacks Player 1,
			   Player 1 defends and reports status. */
			if(theRing[1]->checkPulse() == true){
				attackResult = theRing[1]->attack();
				theRing[0]->defend(attackResult);
				cout << "Player " << theRing[0]->getPlayer() << "'s " << theRing[0]->getType()
					<< " " << theRing[0]->getName() << " possesses strength = "
					<< theRing[0]->getStrength() << endl;
				if (theRing[0]->checkPulse() == 1) {
					cout << " and is alive." << endl;
				} else {
					cout << " and is thus defeated." << endl;
				}
			}
			mRounds++;

			/* Winners are healed and recycled to the back of their respective (fighters1 or 2) queue.
			   Losers are sent to the 'losers' stack. Micro code commented for clarity. */
			if(theRing[0]->checkPulse() == false){			  // Player 2's Creature has won the Tournament Match Round.
				losers.add(theRing[0]);				  // Add theRing[0] Creature* to the loser stack.
				losersHOH.add(theRing[0]);			  // Also add theRing[0] Creature* to the mirror stack.
				theRing[1]->healer();				  // Call healer() on the winning Creature.
				theRing[1]->setcScore(theRing[1]->getStrength()); // Winner scores it's remaining strength points.
				p2score += theRing[1]->getStrength();		  // Player 2's team score accumulates tRound winner's score.
				p2_W++;						  // Player 2's team earns a win.
				p1_L++;						  // Player 1's team incurs a loss.
				fighters2.add(theRing[1]);			  // Add theRing[1] Creature* to the back of fighters2 queue.
			}else{
				if (theRing[1]->checkPulse() == false) {	  // Player 1's Creature has won the Tournament Match Round.
					losers.add(theRing[1]);			  // Add theRing[1] Creature* to the loser stack.
					losersHOH.add(theRing[1]);		  // Also add theRing[1] Creature* to the mirror stack.
					theRing[0]->healer();			  // Call healer() on the winning Creature.
					theRing[0]->setcScore(theRing[0]->getStrength()); // Winner scores it's remaining strength points.
					p1score += theRing[0]->getStrength();	  // Player 1's team score accumulates tRound winner's score.
					p1_W++;					  // Player 1's team earns a win.
					p2_L++;					 // Player 2's team incurs a loss.
					fighters1.add(theRing[0]);		  // Add theRing[0] Creature* to the back of fighters1 queue.
				}
			}

			cout << endl;

			/* Scorboard Report after each Tournament Round, NOT each Tournament Match Round!
			   Default: display Tournament Round Winner (& scores achieved). */
			if (theRing[0]->checkPulse() == false || theRing[1]->checkPulse() == false) {
				cout << "After Tournament Round " << tRounds << " here is the score!" << endl;

				cout << "Player " << theRing[0]->getPlayer() << "'s " << theRing[0]->getType()
					<< " " << theRing[0]->getName() << " has strength "
					<< theRing[0]->getStrength() << endl;

				cout << "Player " << theRing[1]->getPlayer() << "'s " << theRing[1]->getType()
					<< " " << theRing[1]->getName() << " has strength "
					<< theRing[1]->getStrength() << endl;

				if (theRing[0]->getStrength() > theRing[1]->getStrength()) {
					cout << "Player 1's " << theRing[0]->getType() << " named " << theRing[0]->getName()
						<< " is the winner of Tournament Round " << tRounds << "." << endl;
				} else {
					cout << "Player 2's " << theRing[1]->getType() << " named " << theRing[1]->getName()
						<< " is the winner of Tournament Round " << tRounds << "." << endl;
				}

				// ...and optionally, display the updated overall Tournament scores as of the end of this round.
				if (displaySB == 1) {
					if (theRing[0]->checkPulse() == false) {
						cout << "Player " << theRing[1]->getPlayer() << "'s " << theRing[1]->getType()
							<< " " << theRing[1]->getName() << " is Tournament Round " << tRounds
							<< " Winner, scoring " << theRing[1]->getStrength() << endl
							<< " points for themselves and their team!" << endl;
					} else {
						cout << "Player " << theRing[0]->getPlayer() << "'s " << theRing[0]->getType()
							<< " " << theRing[0]->getName() << " is Tournament Round " << tRounds
							<< " Winner, scoring " << theRing[0]->getStrength() << endl
							<< " points for themselves and their team!" << endl;
					}
					cout << "Player 1's Win-Loss Record is " << p1_W << "-" << p1_L << " with Team Points: " 
						<< p1score << "." <<  endl;
					cout << "Player 2's Win-Loss Record is " << p2_W << "-" << p2_L << " with Team Points: " 
						<< p2score << "." << endl;
				}
			}
			cout << endl;
		}
		tRounds++;
	}// End Tournament Logic while loop.

	// Tournament Scoreboard - Final Standings!
	// Decision based upon Team W-L record.
	if (determine == 1) {
		determ = "Win-Loss Record ";
		if (p1_W > p2_W) {
			tWinner = 1;
		} else if (p2_W > p1_W) {
			tWinner = 2;
		}else{
			tWinner = 3;
		}
	}else{
		// Decision based upon Team Points Scored.
		determ = "Team Points Scored ";
		if (p1score > p2score) {
			tWinner = 1;
		} else if (p2score > p1score) {
			tWinner = 2;
		}else{
			tWinner = 3;
		}
	}

	cout << "TOURNAMENT OF CHAMPIONS FINAL SCOREBOARD" << endl
		<< "(" << determ << "determines which Player wins!)" << endl
		<< "Player 1's Tournament score = " << p1score << endl
		<< "Player 1's Win-Loss Record is " << p1_W << "-" << p1_L << endl
		<< "Player 2's Tournament score = " << p2score << endl
		<< "Player 2's Win-Loss Record is " << p2_W << "-" << p2_L << endl;
	if (tWinner == 3) {
		cout << "The Tournament has ended in a draw!" << endl;
	}else{
		cout << "Player " << tWinner << " is the winner of the Tournament of Champions!" << endl;
	}
		cout << endl << "HERE ARE THE TOURNAMENT'S TOP SCORING CREATURES!" << endl;

	// Instantiate a new Creature* dynamic array just big enough to hold all the Creatures!
	Creature** standings = new Creature*[numPlayer * 2];

	// Empty losers stack into standings array.
	i = 0;
	while (losers.isEmpty() == false && i < (numPlayer * 2)) {
		standings[i] = losers.remove();
		i++;
		size++;
	}

	// If occupied, add the remaining creatures in the player 1's fighters1 queue.
		while (fighters1.isEmpty() == false) {
			standings[size] = fighters1.remove();
			size++;
		}
		// If occupied, add the remaining creatures in Player 2's fighters2 queue.
		while (fighters2.isEmpty() == false) {
			standings[size] = fighters2.remove();
			size++;
		}

	// Sort the standings array by individual Creature getcScore() value.
	my.creatureSort(standings, size);

	// Display top three Creature scores and award medals, even if the Creature died in combat!
	if (standings[(numPlayer * 2) - 1]->checkPulse() == false) { aP = "(AP*)"; } else { aP = "."; }
	cout << "Tournament's Gold Medalist is Player " << standings[(numPlayer * 2) - 1]->getPlayer()
		<< "'s " << standings[(numPlayer * 2) - 1]->getType() << " " 
		<< standings[(numPlayer * 2) - 1]->getName() << aP << endl;

	if (standings[(numPlayer * 2) - 2]->checkPulse() == false) { aP = "(AP*)"; } else { aP = "."; }
	cout << "Tournament's Silver Medalist is Player " << standings[(numPlayer * 2) - 2]->getPlayer()
		<< "'s " << standings[(numPlayer * 2) - 2]->getType()
		<< " " << standings[(numPlayer * 2) - 2]->getName() << aP << endl;

	if (numPlayer >= 2) {
		if (standings[(numPlayer * 2) - 3]->checkPulse() == false) { aP = "(AP*)"; } else { aP = "."; }
		cout << "Tournament's Bronze Medalist is Player " << standings[(numPlayer * 2) - 3]->getPlayer()
			<< "'s " << standings[(numPlayer * 2) - 3]->getType()
			<< " " << standings[(numPlayer * 2) - 3]->getName() << aP << endl;
	}
	cout << "*Awarded posthumously" << endl;

	// Optionally, display the standings array (All Creatures).
	cout << endl << "Would you like to see a list of all fighter's standings?" << endl
		<< "Enter 1 for Yes, 0 for No" << endl;
	cin >> cAll;
	while (cAll < 0 || cAll > 1) {
		cout << "Error! Enter 1 to display the losers stack, 0 for no!" << endl;
		cin >> cAll;
	}
	if (cAll == 1) {
		// Display the standings (reversed, as we are using an ascending order array sort)
		for (j = size - 1; j >= 0; j--) {
			cout << "Player " << standings[j]->getPlayer() << "'s " << standings[j]->getType()
				<< " " << standings[j]->getName() << " with a score of "
				<< standings[j]->getcScore() << "." << endl;
		}
	}

	// Optionally, display the Losers stack (actually the losers mirror stack losersHOS).
	cout << endl << "Would you like to see the Hall of Honor? (Losers stack in FILO order)" << endl
		<< "Enter 1 for Yes, 0 for No" << endl;
		cin >> cLosersHOH;
	while (cLosersHOH < 0 || cLosersHOH > 1) {
		cout << "Error! Enter 1 to display the losers stack, 0 for no!" << endl;
		cin >> cLosersHOH;
	}
	if (cLosersHOH == 1) {
		cout << "THE NEWEST INDUCTEES INTO THE TOURNAMENT OF CHAMPIONS' HALL OF HONOR!" << endl;
		while (losersHOH.isEmpty() == false) {
			cret = losersHOH.remove();
			cout << "Player " << cret->getPlayer() << "'s "	<< cret->getType() << " "
				<< cret->getName() << endl;
			cret = NULL;
		}
	}

	// Clean up Creatures in cLosersHOH stack if not displayed.
	if (cLosersHOH == 0) {
		while (losersHOH.isEmpty() == false) {
			cret = losersHOH.remove();
			cret = NULL;
		}
	}

	// Clean up standings array.
	for (i = 0; i < (numPlayer * 2); i++){
		standings[i] = NULL;
	}
	delete[] standings;
	standings = NULL;

	cout << endl << "Thank's for playing!" << endl;
}


/****************************************************************************
*                        creatureSort()
* This function performs an ascending-order selection sort on an array of
* creature object pointers by calling their getcScore() method. The parameter
* size holds the number of elements in the array.
*****************************************************************************/
void Fight::creatureSort(Creature* anArray[], int size) {
	int i;
	int minIdx;
	int minVal;
	Creature *temp;

	for (i = 0; i < (size - 1); i++) {
		minIdx = i;
		minVal = anArray[i]->getcScore();
		for (int index = i + 1; index < size; index++) {
			if (anArray[index]->getcScore() < minVal) {
				minVal = anArray[index]->getcScore();
				minIdx = index;
			}
		}
		temp = anArray[minIdx];
		anArray[minIdx] = anArray[i];
		anArray[i] = temp;
	}
}
