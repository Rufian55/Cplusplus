#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setw;
#include<ctime>

int main() {
	int rtp;
	string name;
	int td;
	string dt;
	int ns;
	int ready;
	double rw;

	// START GAME
	cout << endl << "Welcome to Chris' Game of Dice!" << endl << endl
		 << "Two players will each create a die, fair or otherwise, select the number" << endl
		 << " of rounds to play, and the winning score for each round. Players" << endl
		 << " alternately throw the die and the full score and standings are displayed." << endl << endl;
	
	cout << "Select the number of rounds to play." << endl
		<< "Enter an integer from 1 to 10 and press Enter or 0 to quit." << endl;
	cin >> rtp;
	
	while (cin.fail() || (rtp < 0) || (rtp > 10)) {
		cout << "Error! Enter an integer from 1 to 10 and press Enter or 0 to quit." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> rtp;
	}
	
	// Program exit if '0' selcted.
	if (rtp == 0)
		return 0;

	Game bigGame;
	
	bigGame.createGame(rtp);


	//PLAYER #1
	cout << "For Player #1, enter your desired name and press Enter" << endl;
	cin >> name;

	cout << endl <<  "For " << name << ", how many sides would you like on your die?" << endl
		<< "Enter an integer from 1 to 12 and press Enter." << endl;
	cin >> ns;

	while (cin.fail() || (ns < 1) || (ns > 12)) {
		cout << "Error! Enter an integer from 1 to 12." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> ns;
	}

	cout << endl << "Does " << name << " want to play with a Loaded Die?" << endl
		 << "Enter 0 for a fair die, 1 for a Loaded Die" << endl;
	cin >> td;
	
	while (cin.fail() || (td < 0) || (td > 1)) {
		cout << "Error! Enter 0 for a fair die, or 1 for a Loaded die." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> td;
	}

	Player p1;

	p1.createPlayer(td, name);

	Die d1;
	
	d1.createDice(ns, td);

	LoadedDie D1;
	
	// PLAYER #2
	cout << endl << "For Player #2, enter your desired name and press Enter" << endl;
	cin >> name;

	cout << endl << "For " << name << ", how many sides would you like on your die?" << endl
		<< "Enter an integer from 1 to 12 and press Enter." << endl;
	cin >> ns;

	while (cin.fail() || (ns < 1) || (ns > 12)) {
		cout << "Error! Enter an integer from 1 to 12." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> ns;
	}

	cout << endl << "Does " << name << " want to play with a Loaded Die?" << endl
		<< "Enter 0 for a fair die, 1 for a Loaded Die" << endl;
	cin >> td;

	while (cin.fail() || (td < 0) || (td > 1)) {
		cout << "Error! Enter 0 for a fair die, or 1 for a Loaded die." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> td;
	}

	Player p2;

	p2.createPlayer(td, name);

	Die d2;

	d2.createDice(ns, td);

	LoadedDie D2;

	// Play Rounds Loop.
	for (int i = 1; i <= bigGame.getRoundsToPlay(); i++) {
		cout << endl << "Ready for round " << i << "? Press '1' and Enter to roll both "
			 << "players die or 0 to quit." << endl;
		cin >> ready;
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

		cout << endl << p1.getName() << ", you rolled ";
		p1.setScore(D1.reRoll(d1));

		if((p1.getTypeDice() == 0) && (p2.getTypeDice() == 0))
			usleep(1000000);

		cout << endl << p2.getName() << ", you rolled ";
		p2.setScore(D2.reRoll(d2));

		cout << endl << "Round " << i << " complete!" << endl << endl;	
		cout << p1.getName() << " rolled a " << p1.getScore() << endl
			 << p2.getName() << " rolled a " << p2.getScore() << endl;

		if (p1.getScore() > p2.getScore()) {
			rw = p1.getRoundsWon();
			rw += 1.0;
			p1.setRoundsWon(rw);
			cout << "Therefore, " << p1.getName() << " wins round " << i << endl;
		}
		else {
			if (p1.getScore() < p2.getScore()) {
				rw = p2.getRoundsWon();
				rw += 1.0;
				p2.setRoundsWon(rw);
				cout << "Therefore, " << p2.getName() << " wins round " << i << endl;
			}
			else {
				if (p1.getScore() == p2.getScore()) {
					rw = p1.getRoundsWon();
					rw += 0.5;
					p1.setRoundsWon(rw);
					rw = p2.getRoundsWon();
					rw += 0.5;
					p2.setRoundsWon(rw);
					cout << "Therefore, it's a tie so both " << p1.getName() << " and "
						 << p2.getName() << " get 0.5 for round " << i << endl;
				}
			}
		}

		// Display Scoreboard.
		cout << endl <<  "SCOREBOARD" << endl << endl;
		cout << setw(12) << "PLAYER" << setw(12) << "ROUNDS WON" << setw(11) << "DIE SIDES" << setw(12) << "LOADED DIE?" << endl;

		if (p1.getTypeDice() == 0) {
			dt = "NO";
		}
		else {
			dt = "YES";
		}

		cout << setw(12) << p1.getName() << setw(12) << p1.getRoundsWon() << setw(11) << d1.getSides() << setw(12) << dt << endl;

		if (p2.getTypeDice() == 0) {
			dt = "NO";
		}
		else {
			dt = "YES";
		}

		cout << setw(12) << p2.getName() << setw(12) << p2.getRoundsWon() << setw(11) << d2.getSides() << setw(12) << dt << endl;

	}//end Play Rounds Loop.

	if (ready == 0)
		return 0;

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