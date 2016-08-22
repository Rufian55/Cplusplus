/****************************************************************************************
** Program Filename: ThrowBack.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/17/2016
** Description: Contains the ThrowBack class definition file.
** Input: Accepts input from Space and derived color classes.
** Output: Linked to all Space class derived classes.
*****************************************************************************************/
#include "Space.hpp"
#include "Blue.hpp"
#include "Yellow.hpp"
#include "Cyan.hpp"
#include "Green.hpp"
#include "Red.hpp"
#include "Magenta.hpp"
#include "White.hpp"
#include "ThrowBack.hpp"
#include "GrandPrize.hpp"
#include<iostream>
using std::cout;
using std::cin;
#include<iomanip>
using std::setfill;
using std::setw;
#include<cstdlib>
#include<ctime>


/*************************************************************************************************************
**						function throwBack()
** ThrowBack game driver function. Contains main control loop for running the game, accumulation logic for 
** collecting puzzle pieces and out of time, out of stregnth and game won conditions. memory management done 
** here with helpers in each room and Space class.
** Input: 7 room pointers, Player pointer, and throwBack utility pointer. 
** Output: All game calls to individual rooms as Player navigates game.
*************************************************************************************************************/
void ThrowBack::throwBack(Space* blue, Space* yellow, Space* cyan, Space* green, Space* red,
						  Space* magenta, Space* white, Space* Player, ThrowBack* tBack) {
	int choice1;
	int choice2;
	int var;

	tBack->initBP();
	
	choice1 = Player->welcome();

	if (choice1 == 0) {
		delete tBack;
		tBack = NULL;
		Player->exitGame(blue, yellow, cyan, green, red, magenta, white, Player);
	}

	tBack->setGameTime();

	choice2 = Player->go2Room();

	// Player Enters rooms per choice2 var.
	while (choice2 != 0) {
		if (choice2 == 1) {
			Player = blue;
			tBack->updateBP();
			tBack->displayBP();
			Player->acceptStrength(tBack->getStrength());
			choice2 = Player->runRoom();
			tBack->setStrength(Player->getStrength());
			tBack->setPPBlue(Player->getPPBlue());
		}
		else if (choice2 == 2) {
			Player = yellow;
			tBack->updateBP();
			tBack->displayBP();
			Player->acceptStrength(tBack->getStrength());
			choice2 = Player->runRoom();
			tBack->setStrength(Player->getStrength());
			tBack->setPPYellow(Player->getPPYellow());
		}
		else if (choice2 == 3) {
			Player = cyan;
			tBack->updateBP();
			tBack->displayBP();
			Player->acceptStrength(tBack->getStrength());
			choice2 = Player->runRoom();
			tBack->setStrength(Player->getStrength());
			tBack->setPPCyan(Player->getPPCyan());
		}
		else if (choice2 == 4) {
			Player = green;
			tBack->updateBP();
			tBack->displayBP();
			Player->acceptStrength(tBack->getStrength());
			choice2 = Player->runRoom();
			tBack->setStrength(Player->getStrength());
			tBack->setPPGreen(Player->getPPGreen());
		}
		else if (choice2 == 5) {
			Player = red;
			tBack->updateBP();
			tBack->displayBP();
			Player->acceptStrength(tBack->getStrength());
			choice2 = Player->runRoom();
			tBack->setStrength(Player->getStrength());
			tBack->setPPRed(Player->getPPRed());
		}
		else if (choice2 == 6) {
			Player = magenta;
			tBack->updateBP();
			tBack->displayBP();
			Player->acceptStrength(tBack->getStrength());
			choice2 = Player->runRoom();
			tBack->setStrength(Player->getStrength());
			tBack->setPPMagenta(Player->getPPMagenta());
		}
		else if (choice2 == 7) {
			Player = white;
			tBack->updateBP();
			tBack->displayBP();
			Player->acceptStrength(tBack->getStrength());
			choice2 = Player->runRoom();
			tBack->setStrength(Player->getStrength());
			tBack->setPPWhite(Player->getPPWhite());
		}
		else if (choice2 == 8) {// Change Rooms call from any Color Class ::runController()
			if (Player->getStrength() < 0) {
				cout << Player->palette(9) << "\nYOU HAVE INSUFFCIENT STRENGTH"
					<< " TO CONTINUE PLAYING!" << Player->palette(1) << "\n";
				delete tBack;
				tBack = NULL;
				Player->exitGame(blue, yellow, cyan, green, red, magenta, white, Player);
			}
			if (tBack->checkTime() == true) {
				cout << Player->palette(9) << "\nYOU ARE OUT OF TIME AND HAVE LOST THE GAME!"
					<< Player->palette(1) << "\n";
				delete tBack;
				tBack = NULL;
				Player->exitGame(blue, yellow, cyan, green, red, magenta, white, Player);
			}
			if (tBack->getWin() == 7) // Winner!
				break;
		choice2 = Player->go2Room();
		}
	}

	// Player Quits game.
	if (choice2 == 0) {
		delete tBack;
		tBack = NULL;
		Player->exitGame(blue, yellow, cyan, green, red, magenta, white, Player);
	}

	// Winner - break @ Line 138 takes Player out of control loop!!
	tBack->updateBP();
	tBack->setSuppress(true);
	tBack->displayBP();
	cout << "\n\n";
	GrandPrize *gP = new GrandPrize;
	gP->grandPrize();
	delete gP;
	gP = NULL;
	delete tBack;
	tBack = NULL;
	Player->exitGame(blue, yellow, cyan, green, red, magenta, white, Player);
}


/*******************************************************************************
**						function initBP()
**  Initializes backPack continer to all char 'X'. Called by constructor.
** Input: none 
** Output: void
******************************************************************************/
void ThrowBack::initBP() {
	int i;
	for (i = 0; i < 7; i++)
		backPack[i] = 'X';
}


/*******************************************************************************
**						function displayBP()
** Displays contents of Players backPack contents with apprropirate text
** decoration. Also diplays time remaining to Player.
** Input: none, but multiple calls to backPack array and win var for status.
** Output: Void.
******************************************************************************/
void ThrowBack::displayBP() {
	int time2go = 0;
	int mins = 0;
	int secs = 0;

	// Display banner statement.
	if (getWin() < 7) {
		cout << "Your BackPack contains ";
	} else { cout << palette(4) << "\n\tYour BackPack contains "; }

	if (getWin() == 0) {
		cout << "0 Puzzle Pieces. ";
	}
	else if (getWin() == 1) {
		cout << getWin() << " Puzzle Piece: ";
	}
	else if (getWin() == 0 || (getWin() > 1 && getWin() < 8)) {
		cout << getWin() << " Puzzle Pieces: ";
	}

	// Display pieces found.
	if (backPack[0] == 'B') {
	cout << palette(22) << " " << backPack[0] << " " << palette(1) << " ";
	} else { cout << " "; }

	if (backPack[1] == 'Y') {
	cout << palette(17) << " " << backPack[1] << " " << palette(1) << " ";
	} else { cout << " "; }

	if (backPack[2] == 'C') {
	cout << palette(32) << " " << backPack[2] << " " << palette(1) << " ";
	} else { cout << " "; }

	if (backPack[3] == 'G') {
	cout << palette(12) << " " << backPack[3] << " " << palette(1) << " ";
	} else { cout << " "; }

	if (backPack[4] == 'R') {
	cout << palette(7) << " " << backPack[4] << " " << palette(1) << " ";
	} else { cout << " "; }

	if (backPack[5] == 'M') {
	cout << palette(27) << " " << backPack[5] << " " << palette(1) << " ";
	} else { cout << " "; }

	if (backPack[6] == 'W') {
	cout << palette(2) << " " << backPack[6] << " " << palette(1) << " ";
	} else { cout << " "; }

	if (getSuppress() == false) {
		time2go = getGameTime() + getUnixTime() - time(NULL);
		if (time2go < 0) {
			mins = 0;
			secs = 0;
		} else {
			mins = time2go / 60;
			secs = time2go % 60;
		}
		if (secs > 9)
			cout << "\nYou have " << mins << ":" << secs << " remaining to play.\n";
		else
			cout << "\nYou have " << mins << ":" << "0" << secs << " remaining to play.\n";
	}
}


/*******************************************************************************
**						function updateBP()
** Polls individual room puzle piece vars to see if found in room and updates
** backPack char array accordingly for output by displayBP()
** Input: none.
** Output: void.
******************************************************************************/
void ThrowBack::updateBP() {
	if (getPPBlue() == true)
		backPack[0] = 'B';
	if (getPPYellow() == true)
		backPack[1] = 'Y';
	if (getPPCyan() == true)
		backPack[2] = 'C';
	if (getPPGreen() == true)
		backPack[3] = 'G';
	if (getPPRed() == true)
		backPack[4] = 'R';
	if (getPPMagenta() == true)
		backPack[5] = 'M';
	if (getPPWhite() == true)
		backPack[6] = 'W';
}


/*******************************************************************************
**						function setWin() 2 each.
** Called by ThrowBack Constructor to set win var. win var reported by throwBack()
** control loop and wins acculated to 7 for a Player game win condition.
** Input:
** Output:
******************************************************************************/
void ThrowBack::setWin(int win) {
	this->win = getWin() + win;
}

int ThrowBack::getWin() {
	return win;
}


/*******************************************************************************
**						function initPPiece()
** Initializes room Puzzle Pieces and room win flags for determining a win.
** Input: Called by ThrowBack constructor.
** Output: void
******************************************************************************/
void ThrowBack::initPPieces() {
	this->ppBlue = false;
	this->blueWinFlag = false;
	this->ppYellow = false;
	this->yellowWinFlag = false;
	this->ppCyan = false;
	this->cyanWinFlag = false;
	this->ppGreen = false;
	this->greenWinFlag = false;
	this->ppRed = false;
	this->redWinFlag = false;
	this->ppMagenta = false;
	this->magentaWinFlag = false;
	this->ppWhite = false;
	this->whiteWinFlag = false;
}


/*******************************************************************************
**						function setGameTime()
** Player input collection module for determining how long the game is to run.
** Sets unixtime stamp and Player start time for use by Time function below.
** Input:
** Output:
******************************************************************************/
void ThrowBack::setGameTime() {
	int choice;
	cout << palette(19) << "How many minutes (maximun 15) do you want"
		<< " to play before you admit defeat?" << palette(1) << "\n";
	while (!(cin >> choice) || choice < 1 || choice > 15) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!" << palette(19) << "\n"
			<< "How many minutes (maximun of 15) do you want to play"
			<< " before you admit defeat?" << palette(1) << "\n";
	}
	choice = choice * 60;
	this->gameTime = choice;
	this->unixTime = time(NULL);
}


/*******************************************************************************
**						functions xxxTime() 3 each
** Group of three funtions that uses unix time stamp at Player begining game, 
** to report to Player on each room change how much time is left.
** Input: called by main()
** Output: bool for time has expired.
******************************************************************************/
int ThrowBack::getGameTime() {
	return gameTime;
}

int ThrowBack::getUnixTime() {
	return unixTime;
}

bool ThrowBack::checkTime() {
	if ((time(NULL) - getUnixTime()) > getGameTime())
	return true;
}


/*******************************************************************************
**						function setSupress() 2 each
** Initializes suppres var and resets depending on where the call to display
** the backPack comes from.  If a winner, backPAck output is shifted and text
** decorated.
** Input: bool from main control loop
** Output: void.
******************************************************************************/
void ThrowBack::setSuppress(bool tORf) {
	if (tORf == false)
		this->suppress = false;
	else
		this->suppress = true;
}

bool ThrowBack::getSuppress() {
	return suppress;
}


/*******************************************************************************
**						functions set/gEtStrength() 2 each
** Sets strength here in ThrowBack() based upon report back funtions in each
** room. getter reports overall Player strength status.
** Input: int from main contol loop.
** Output: int to main contol loop.
******************************************************************************/
void ThrowBack::setStrength(int change) {
	this->strength = change; 
}

int ThrowBack::getStrength() {
	return strength;
}


/*******************************************************************************
**						function setPP'color'() 14 each
** Sets individual room color Pusslepiece based upon the player finding the 
** piece in a room and then this room status being reported here. Also calls
** setWin functions for main game control logic for assessing player has won. 
** Input: bool pp'color'
** Output: void or bool
******************************************************************************/
void ThrowBack::setPPBlue(bool ppBlue) {
	this->ppBlue = ppBlue;
	if (ppBlue == true && blueWinFlag == false)
		setWin(1);
	if (ppBlue == true)
		this->blueWinFlag = true;
}

bool ThrowBack::getPPBlue() {
	return ppBlue;
}

void ThrowBack::setPPYellow(bool ppYellow) {
	this->ppYellow = ppYellow;
	if (ppYellow == true && yellowWinFlag == false)
		setWin(1);
	if (ppYellow == true)
		this->yellowWinFlag = true;
}

bool ThrowBack::getPPYellow() {
	return ppYellow;
}

void ThrowBack::setPPCyan(bool ppCyan) {
	this->ppCyan = ppCyan;
	if (ppCyan == true && cyanWinFlag == false)
		setWin(1);
	if (ppCyan == true)
		this->cyanWinFlag = true;
}

bool ThrowBack::getPPCyan() {
	return ppCyan;
}

void ThrowBack::setPPRed(bool ppRed) {
	this->ppRed = ppRed;
	if (ppRed == true && redWinFlag == false)
		setWin(1);
	if (ppRed == true)
		this->redWinFlag = true;
}

bool ThrowBack::getPPRed() {
	return ppRed;
}

void ThrowBack::setPPGreen(bool ppGreen) {
	this->ppGreen = ppGreen;
	if (ppGreen == true && greenWinFlag == false)
		setWin(1);
	if (ppGreen == true)
		this->greenWinFlag = true;
}

bool ThrowBack::getPPGreen() {
	return ppGreen;
}

void ThrowBack::setPPMagenta(bool ppMagenta) {
	this->ppMagenta = ppMagenta;
	if (ppMagenta == true && magentaWinFlag == false)
		setWin(1);
	if (ppMagenta == true)
		this->magentaWinFlag = true;
}

bool ThrowBack::getPPMagenta() {
	return ppMagenta;
}

void ThrowBack::setPPWhite(bool ppWhite) {
	this->ppWhite = ppWhite;
	if (ppWhite == true && whiteWinFlag == false)
		setWin(1);
	if (ppWhite == true)
		this->whiteWinFlag = true;
}

bool ThrowBack::getPPWhite() {
	return ppWhite;
}