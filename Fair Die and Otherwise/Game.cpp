/****************************************************************************************
** Program Filename: Game.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 1/24/2016
** Description: Implementation file for Game class - includes main().
** Input: all user input, Player, LoadedDie, and Die objects.
** Output: cout user messages and game play results to console.
*****************************************************************************************/
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Player.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setw;
#include<ctime>

/***************************************************************************************
** Function: createPlayer()
** Description: Constructor to set roundsToPlay for the Game object.
** Parameters: int roundsToPlay.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: void.
****************************************************************************************/
void Game::createGame(int rtp){
	setRoundsToPlay(rtp);
	}

// Setter for roundsToPlay var.
void Game::setRoundsToPlay(int rtp){
	roundsToPlay = rtp;
}

// Getter for roundsToPlay var.
int Game::getRoundsToPlay(){
	int rtp = roundsToPlay;
	return rtp;
}


// GAME PLAY, I/O FLOW, COLLECT USER INPUT. 
int main() {
	int rtp;		// local user input collector var for roundsToPlay.
	string name;	// Local user input collector var for name.
	int td;			// Local user input collector var for typeDie.
	string dt;		// Local var for cout typeDie string in Scoreboard. 
	int ns;			// Local user input collector var for (die) sides.
	int ready;		// Local var for controlling and early exit of game play.
	double rw;		// Local var for roundsWon input and cout.


	// Collect initial game setup inputs
	cout << endl << "Welcome to Chris' Game of Dice!" << endl << endl
		 << "Two players will each create a die, fair or otherwise, select the number" << endl
		 << " of rounds to play, and the winning score for each round. Players" << endl
		 << " alternately throw the die and the full score and standings are displayed." << endl << endl;

	cout << "Select the number of rounds to play." << endl
		 << "Enter an integer from 1 to 10 and press Enter or 0 to quit." << endl;
	cin >> rtp;

	// Input validation.
	while (cin.fail() || (rtp < 0) || (rtp > 10)) {
		cout << "Error! Enter an integer from 1 to 10 and press Enter or 0 to quit." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> rtp;
	}

	// Program exit if '0' selected.
	if (rtp == 0)
		return 0;

	//Declare a Game object
	Game bigGame;

	//Initialise game.
	bigGame.createGame(rtp);


	//PLAYER #1 setup information input.
	// Get Player 1 name.
	cout << "For Player #1, enter your desired name and press Enter" << endl;
	cin >> name;

	cout << endl << "For " << name << ", how many sides would you like on your die?" << endl
		 << "Enter an integer from 1 to 12 and press Enter." << endl;
	cin >> ns;

	// Input validation.
	while (cin.fail() || (ns < 1) || (ns > 12)) {
		cout << "Error! Enter an integer from 1 to 12." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> ns;
	}

	// Get Player 1 typeDie.
	cout << endl << "Does " << name << " want to play with a Loaded Die?" << endl
		 << "Enter 0 for a fair die, 1 for a Loaded Die" << endl;
	cin >> td;

	// Input validation.
	while (cin.fail() || (td < 0) || (td > 1)) {
		cout << "Error! Enter 0 for a fair die, or 1 for a Loaded die." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> td;
	}

	// Declare Player 1 object. 
	Player p1;

	//Initialise Player 1.
	p1.createPlayer(td, name);

	// Declare Player 1's die object.
	Die d1;

	// Initialise Player 1's die object.
	d1.createDice(ns, td);

	// Declare Player 1's loaded die object.
	LoadedDie D1;


	//PLAYER #2 setup information input.
	// Get Player 2 name.
	cout << endl << "For Player #2, enter your desired name and press Enter" << endl;
	cin >> name;

	cout << endl << "For " << name << ", how many sides would you like on your die?" << endl
		 << "Enter an integer from 1 to 12 and press Enter." << endl;
	cin >> ns;

	// Input validation loop.
	while (cin.fail() || (ns < 1) || (ns > 12)) {
		cout << "Error! Enter an integer from 1 to 12." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> ns;
	}

	// Get Player 2 typeDie.
	cout << endl << "Does " << name << " want to play with a Loaded Die?" << endl
		 << "Enter 0 for a fair die, 1 for a Loaded Die" << endl;
	cin >> td;

	// Input validation loop.
	while (cin.fail() || (td < 0) || (td > 1)) {
		cout << "Error! Enter 0 for a fair die, or 1 for a Loaded die." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> td;
	}

	// Declare Player 2 object. 
	Player p2;

	//Initialise Player 2.
	p2.createPlayer(td, name);

	// Declare Player 2's die object.
	Die d2;

	// Initialise Player 2's die object.
	d2.createDice(ns, td);

	// Declare Player 2's loaded die object.
	LoadedDie D2;


	// PLAY ROUNDS LOOP.
	for (int i = 1; i <= bigGame.getRoundsToPlay(); i++) {
		cout << endl << "Ready for round " << i << "? Press '1' and Enter to roll both "
			 << "players die or 0 to quit." << endl;
		cin >> ready;

		// Input validation.
		while (cin.fail() || ready < 0 || ready > 1) {
			cout << "Please try again! Ready for round " << i << "? Press '1' and Enter to"
				 << " roll both" << endl << "players die or 0 to quit." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> ready;
		}

		// Program exit if 0 entered.
		if (ready == 0)
			return 0;

		cout << "Rollem!! Dice are rolling..." << endl;

		// Messaage, roll Player 1 die, update Player 1 score.
		cout << endl << p1.getName() << ", you rolled ";
		p1.setScore(D1.reRoll(d1));

		// Sleep if both players are using fair die to preclude identical roll results.
		if ((p1.getTypeDice() == 0) && (p2.getTypeDice() == 0))
			usleep(1000000);

		// Messaage, roll Player 2 die, update Player 2 score.
		cout << endl << p2.getName() << ", you rolled ";
		p2.setScore(D2.reRoll(d2));

		// Output round just played results.
		cout << endl << "Round " << i << " complete!" << endl << endl;
		cout << p1.getName() << " rolled " << p1.getScore() << endl
			<< p2.getName() << " rolled " << p2.getScore() << endl;

		// Logic for determining whose score gets updated.
		// Player 1 wins.
		if (p1.getScore() > p2.getScore()) {
			rw = p1.getRoundsWon();
			rw += 1.0;
			p1.setRoundsWon(rw);
			cout << "Therefore, " << p1.getName() << " wins round " << i << endl;
		}
		else {
			//Player 2 wins
			if (p1.getScore() < p2.getScore()) {
				rw = p2.getRoundsWon();
				rw += 1.0;
				p2.setRoundsWon(rw);
				cout << "Therefore, " << p2.getName() << " wins round " << i << endl;
			}
			else {
				// It's a draw, both players get 0.5 points.
				if (p1.getScore() == p2.getScore()) {
					// Player 1.
					rw = p1.getRoundsWon();
					rw += 0.5;
					p1.setRoundsWon(rw);
					// Player 2.
					rw = p2.getRoundsWon();
					rw += 0.5;
					p2.setRoundsWon(rw);

					cout << "Therefore, it's a tie so both " << p1.getName() << " and "
						 << p2.getName() << " get 0.5 for round " << i << endl;
				}
			}
		}

		// Display Scoreboard.
		cout << endl << "SCOREBOARD" << endl << endl;
		cout << setw(12) << "PLAYER" << setw(12) << "ROUNDS WON" << setw(11) << "DIE SIDES" << setw(12) << "LOADED DIE?" << endl;

		// Convert bool to string for Player 1's dt (typeDie) display.
		if (p1.getTypeDice() == 0)
			dt = "NO";
		else
			dt = "YES";

		cout << setw(12) << p1.getName() << setw(12) << p1.getRoundsWon() << setw(11) << d1.getSides() << setw(12) << dt << endl;

		// Convert bool to string for Player 2's dt (typeDie) display.
		if (p2.getTypeDice() == 0)
			dt = "NO";
		else 
			dt = "YES";

		cout << setw(12) << p2.getName() << setw(12) << p2.getRoundsWon() << setw(11) << d2.getSides() << setw(12) << dt << endl;

	}//end Play Rounds Loop.


	// Program exit if user selects 0 to quit.
	if (ready == 0)
		return 0;

	// Final Game results and messages.
	if (p1.getRoundsWon() > p2.getRoundsWon()) {
		cout << endl << p1.getName() << " is the game winner!!!" << endl;
	}
	else {
		if (p2.getRoundsWon() > p1.getRoundsWon()) {
			cout << endl << p2.getName() << " is the game winner!!!" << endl;
		}
		else {
			if (p1.getRoundsWon() == p2.getRoundsWon()) {
				cout << endl << "It's a draw, therefore both " << p1.getName() << " and "
					<< p2.getName() << " are winners!!" << endl;
			}
		}
	}

	cout << endl << "Thanks for playing Chris' Game of Dice" << endl << endl;
}