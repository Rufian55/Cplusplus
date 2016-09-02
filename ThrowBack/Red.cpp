/****************************************************************************************
** Program Filename: Red.cpp
** Author: Chris Kearns
** Date: 3/17/2016
** Description: Contains the Red class definition file.
** Input: exitGame() takes 6 Space pointers for linking rooms.
** Output: Linked to all ThrowBack derived classes.
*****************************************************************************************/
#include "Red.hpp"
#include <string>
using std::string;
#include<iostream>
using std::cout;
using std::cin;

/*******************************************************************************
**			function set'Color'Pointers()
** Sets color pointers to all other rooms.  Called from ThrowBack.cpp main()
** Input: Space class color pointers other than this class.
** Output:void
******************************************************************************/
void Red::setRedPtrs(Space* blue, Space* yellow, Space* cyan, Space* green, Space* magenta, Space* white) {
	setBlue(blue);
	setYellow(yellow);
	setCyan(cyan);
	setGreen(green);
	setMagenta(magenta);
	setWhite(white);
	setPPRed(false);
	setStrength();
	initCharBools();
}

// Destructor.
Red::~Red() {
	R_Blue = NULL;
	R_Yellow = NULL;
	R_Cyan = NULL;
	R_Green = NULL;
	R_Magenta = NULL;
	R_White = NULL;
}


/*******************************************************************************
**			function setSrength() 3 each.
** Setters for stregth. setStrength() for initialization, setSTregth(int) for
** updating local room strength changes. getStrength for logic control, and
** acceptStrength() sets overall current Player strength upon Player entry to
** this room.  acceptSTrength() also returns current Player to ThrowBack.cpp for
** use as Player enters other rooms or re-enters this room.
** Input: acceptStregnth() current strength int from Throwback.cpp
** Output: sets local stregth int.
******************************************************************************/
void Red::setStrength() {
	this->strength = 0;
}

void Red::setStrength(int strength) {
	this->strength = getStrength() + strength;
}

int Red::getStrength() {
	return strength;
}

// Throwback passes overall Player strength for update here.
int Red::acceptStrength(int strength) {
	this->strength = strength;
}


/*******************************************************************************
**			function setPPColor() 3 each.
** Initializes Player color puzzle piece, logic control locally to ths room, and
** getPPBlue used by ThrowBack.cpp for logic control and displayBP()
** Input: bool to initialize and set when Player finds color puzzle piece.
** Output:
******************************************************************************/
void Red::setPPRed(bool f) {
	this->pPiece = f;
}

void Red::setPPRed() {
	this->pPiece = true;
}

bool Red::getPPRed() {
	return pPiece;
}


/*******************************************************************************
**			function initCharBools()
** Initializes individual characters variables at room initializaton.
******************************************************************************/
void Red::initCharBools() {
	this->jeffFungusFood = false;
	this->jeffFungusDrink = false;
	this->jeffFungusVisit = false;
	this->blinkeyFood = false;
	this->blinkeyDrink = false;
	this->blinkeyVisit = false;
	this->redElmoFood = false;
	this->redElmoDrink = false;
	this->redElmoVisit = false;
	this->yosemiteSamFood = false;
	this->yosemiteSamDrink = false;
	this->yosemiteSamVisit = false;
	this->chefFood = false;
	this->chefDrink = false;
	this->chefVisit = false;
}


/*******************************************************************************
**			function runRoom()
** Virtual function used by Throwback.cpp main logic loop. Calls to this function
** initiates runCharacters() for Player to choosw which character to visit, calls
** the special virtual funtion boostStregnth(), and calls the local runController()
** function appropriately in a loop until Player exits room.
** Input: Player input
** Output: callse to boostStrength and runController with chocie parameter set.
******************************************************************************/
int Red::runRoom() {
	int choice = 1;
	cout << palette(9) << "You are in the Red Room!" << palette(1) << "\n";
	if (getStrength() < 25) {
		cout << palette(9) << "You're looking a bit red in the face!" << palette(1) << "\n";
		boostStrength();
	}
	while (choice > 0 && choice <= 6) {
		choice = runCharacters();
		if (choice == 1) {
			choice = runController(1);	// Jeff Fungus
		}
		else if (choice == 2) {
			choice = runController(2);	// Blinkey
		}
		else if (choice == 3) {
			choice = runController(3);	// RedElmo
		}
		else if (choice == 4) {
			choice = runController(4);	// Yosemite Sam
		}
		else if (choice == 5) {
			choice = runController(5);	// Chef
		}
		else if (choice == 0 || choice == 6) {
			break;
		}
	}
	return 8;
}


/*******************************************************************************
**			function boostStrenght()
** Pure virtual function that ascertains and offers a strength boost for a
** Player whose stregnth is below 25.  Calls local setStregnth() with int
** paramter set.
** Input: Player
** Output: void, call to setStrength(20)
******************************************************************************/
void Red::boostStrength() {
	int answer = 0;
	cout << palette(9) << "Would you like a 9 point strength boost to keep playing?\n" << palette(1)
		<< "1. Yes!\n"
		<< "2. I'm not into red velvet cake!\n";
	while (!(cin >> answer) || answer < 1 || answer > 2) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(9)
			<< "Would you like a strength Boost to keep playing?\n" << palette(1)
			<< "1. Yes!\n"
			<< "2. No!\n";
	}
	if (answer == 1) {
		setStrength(9);
		cout << palette(9) << "New Strength = " << getStrength() << palette(1) << "\n";
	}
}


/*******************************************************************************
**			function runCharacters()
** Player chocie cout/cin input validation module. Returns an int for choice of
** character to visit to runController()
** Input: Player
** Output: int choice to local runController()
******************************************************************************/
int Red::runCharacters() {
	int utter = 0;
	cout << "Which" << palette(9) << " Red Room " << palette(1) << "character do you want to converse with?\n"
		<< "1. " << palette(9) << "Red Elmo (Sesame Street)" << palette(1) << "\n"
		<< "2. " << palette(9) << "Blinkey (PacMan)" << palette(1) << "\n"
		<< "3. " << palette(9) << "Jeff Fungus (Monsters Inc.)" << palette(1) << "\n"
		<< "4. " << palette(9) << "Yosemite Sam (Hanna Barbera)" << palette(1) << "\n"
		<< "5. " << palette(9) << "Chef (Southpark)" << palette(1) << "\n"
		<< "6. " << palette(4) << "Change Rooms now!" << palette(1) << "\n";
	while (!(cin >> utter) || utter < 1 || utter > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< "Which" << palette(9) << " Red Room " << palette(1) << "character do you want to converse with?\n"
			<< "1. " << palette(9) << "Red Elmo (Sesame Street)" << palette(1) << "\n"
			<< "2. " << palette(9) << "Blinkey (PacMan)" << palette(1) << "\n"
			<< "3. " << palette(9) << "Jeff Fungus (Monsters Inc.)" << palette(1) << "\n"
			<< "4. " << palette(9) << "Yosemite Sam (Hanna Barbera)" << palette(1) << "\n"
			<< "5. " << palette(9) << "Chef (Southpark)" << palette(1) << "\n"
			<< "6. " << palette(4) << "Change Rooms now!" << palette(1) << "\n";
	}
	return utter;
}


/*******************************************************************************
**			function runController()
** Main contol module for room.  Calls, sets, and manages program control as
** Plyer navigates characters responses to PlayerAI() generted query.
** Input: int arg from runCharacters()
** Output: int arg to runRoom() charcter control function.
******************************************************************************/
int Red::runController(int in) {
	int arg = in;
	int choice1;
	int choice2;
	while (arg > 0 && arg < 7) {
		if (arg == 1) {			/**** Red Elmo ****/
			while (arg == 1) {
				choice1 = playerAI();
				choice2 = runRedElmo(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setRedElmoFood(true); }
				if (choice2 == 3) { setStrength(-10); setRedElmoDrink(true); }
				if (choice2 == 4) {
					setStrength(-1);
					if (getPPRed() == false) {
						setPPRed();
						cout << "\nThe " << palette(7) << " R " << palette(1) << palette(9)
							<< " Puzzle Piece " << palette(1) << "is in your Backpack!!\n\n";

					}
				}
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 2) {		/**** Blinkey ****/
			while (arg == 2) {
				choice1 = playerAI();
				choice2 = runBlinkey(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setBlinkeyFood(true); }
				if (choice2 == 3) {
					if (getBlinkeyDrink() == false) {
						setStrength(2);
						setBlinkeyDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 3) {		/**** Jeff Fungus ****/
			while (arg == 3) {
				choice1 = playerAI();
				choice2 = runJeffFungus(choice1);
				if (choice2 == 1) { setStrength(-1); }
				else if (choice2 == 2) { setStrength(-1); setJeffFungusFood(true); }
				else if (choice2 == 3) { setStrength(-1); setJeffFungusDrink(true); }
				else if (choice2 == 4) { setStrength(-1); }
				else if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				else if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 4) {		/**** Yosemite Sam ****/
			while (arg == 4) {
				choice1 = playerAI();
				choice2 = runYosemiteSam(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setYosemiteSamFood(true); }
				if (choice2 == 3) {
					if (getYosemiteSamDrink() == false) {
						setStrength(15);
						setYosemiteSamDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 5) {		/**** Chef ****/
			while (arg == 5) {
				choice1 = playerAI();
				choice2 = runChef(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) {
					if (getChefFood() == false) {
						setStrength(5);
						setChefFood(true);
					}
				}
				if (choice2 == 3) {
					if (getChefDrink() == false) {
						setStrength(15);
						setChefDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 6) {		/**** Change Rooms ****/
			arg = 8;
		}
	}
	return arg;
}


/*******************************************************************************
**			function playerAI()
** Player's query module for asking questions to each character as selected by
** Player. Returns int arg for run CharacterName().
** Input: Player out arg selected.
** Output: int out as chosed by Player.
******************************************************************************/
int Red::playerAI() {
	int out = 0;
	if (getStrength() < 26 && getStrength() >= 1) {
		cout << "Current Strength = " << palette(19) << getStrength() << palette(1) << "\n";
	}
	else if (getStrength() < 1) {
		cout << "Current Strength = " << palette(9) << getStrength() << palette(1) << "\n";
	}
	else {
		cout << "Current Strength = " << palette(14) << getStrength() << palette(1) << "\n";
	}
	cout << "There's a " << palette(9) << "Red" << palette(1) << " Character in front of you. Say:\n"
		<< "1. Greatings " << palette(9) << "Red Room" << palette(1) << " Character!\n"
		<< "2. Do you have anything to eat?\n"
		<< "3. Do you have anything to drink?\n"
		<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
		<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
		<< "5. I'm going to visit a different " << palette(9) << "Red Room" << palette(1) << " Character.\n"
		<< "6. " << palette(9) << "I'm changing rooms now!" << palette(1) << "\n";
	while (!(cin >> out) || out < 1 || out > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< palette(3) << "You're going to upset it!" << palette(1) << " What do you want to say?\n"
			<< "1. Greatings " << palette(9) << "Red Room" << palette(1) << " Character!\n"
			<< "2. Do you have anything to eat?\n"
			<< "3. Do you have anything to drink?\n"
			<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
			<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
			<< "5. I'm going to visit a different " << palette(9) << "Red Room" << palette(1) << " Character.\n"
			<< "6. " << palette(9) << "I'm changing rooms now!" << palette(1) << "\n";
	}
	return out;
}


/***************************************************************************************************************
**				function run Characters() 5 each.
** Indivdual character responses to PlayerAI query. Player is assesed and awarded points based upon query and
** characters call stack in runController()
** Input: PlayerAI query choice.
** Output: reutrns int response to runController()
***************************************************************************************************************/
int Red::runJeffFungus(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getJeffFungusVisit() == false) {
			cout << palette(9) << "Jeff Fungus: Uh, sir?" << palette(1) << "\n";
			setJeffFungusVisit(true);
			out = 1;
		}
		else {
			cout << palette(9) << "Jeff Fungus: What do you seek at the factory?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getJeffFungusFood() == false) {
			cout << palette(9) << "Jeff Fungus: You like my chiken legs, don't you?" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(9) << "Jeff Fungus: No legs for you!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getJeffFungusDrink() == false) {
			cout << palette(9) << "Jeff Fungus: Try Sully in the Blue Room!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(9) << "Jeff Fungus: Perhpas Randall Boggs?" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(9) << "Jeff Fungus: I'm going to tell Mr Boggs about your plot." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(9) << "Jeff Fungus: Oh, this is great!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(9) << "Jeff Fungus: Wazowski! I knew it!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Red::runBlinkey(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getBlinkeyVisit() == false) {
			cout << palette(9) << "Blinkey: They wern't sure if I belonged here or in the Magenta room!" << palette(1) << "\n";
			setBlinkeyVisit(true);
			out = 1;
		}
		else {
			cout << palette(9) << "Blinkey: Anoterh $0.50 please." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getBlinkeyFood() == false) {
			cout << palette(9) << "Blinkey: I'm a ghost, we don't eat! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(9) << "Blinkey: That'll cost you -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getBlinkeyDrink() == false) {
			cout << palette(9) << "Blinkey: Have a Mrs. Pepper. +2 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(9) << "Blinkey: She's gone, PacMan got her!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(9) << "Blinkey: No, but see that Mr. White fellow, I hear he's got one." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(9) << "Blinkey: Chomp 'em!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(9) << "Blinkey: Chase that Packy!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Red::runRedElmo(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getRedElmoVisit() == false) {
			cout << palette(9) << "Elmo: Hello, I'm yet another Sesaame Street character in this game!" << palette(1) << "\n";
			setRedElmoVisit(true);
			out = 1;
		}
		else {
			cout << palette(9) << "Elmo: I'm busy sweeping the street!" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getRedElmoFood() == false) {
			cout << palette(9) << "Elmo: Straight from my garbage can! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(9) << "Elmo: Still in school?  Another -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getRedElmoDrink() == false) {
			cout << palette(9) << "Elmo: Only diet soda! -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(9) << "Elmo: Red furry things don't drink! Another -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		if (getPPRed() == false) {
			cout << palette(9) << "Elmo: Surprisingly, I do, that Big Bird character left it here!" << palette(1) << "\n";
			out = 4;
		}
		else {
			cout << palette(9) << "Elmo: I'm a fire fighter!" << palette(1) << "\n";
		}
	}
	else if (inMessage == 5) {
		cout << palette(9) << "Elmo: You hear about Ms. Piggy and Kermit?" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(9) << "Elmo: Oh, Jeez!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Red::runYosemiteSam(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getYosemiteSamVisit() == false) {
			cout << palette(9) << "Sam: Welcome to the House of Sam!" << palette(1) << "\n";
			setYosemiteSamVisit(true);
			out = 1;
		}
		else {
			cout << palette(9) << "Sam: Come to papa baby!" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getYosemiteSamFood() == false) {
			cout << palette(9) << "Sam: I haven't caught that rabbit yet! -5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(9) << "Sam: That's what you get for trustin a rabbit! Another -5 Strength." << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getYosemiteSamDrink() == false) {
			cout << palette(9) << "Sam: Now drink up varmint! +15 Stregth." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(9) << "Sam: All right now ya wise guy, dance!!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(9) << "Sam: Whoa camel! Whoa!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(9) << "Sam: Ooooo, I'll keelhaul you for this!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(9) << "Sam: Goodbye rabbit!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Red::runChef(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getChefVisit() == false) {
			cout << palette(9) << "Chef: How's it going children?" << palette(1) << "\n";
			setChefVisit(true);
			out = 1;
		}
		else {
			cout << palette(9) << "Chef: Move along children." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getChefFood() == false) {
			cout << palette(9) << "Chef: Yes, quick before Cartman get's it all +5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(9) << "Chef: Cartman beat you to it, children!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getChefDrink() == false) {
			cout << palette(9) << "Chef: Sure, here Kenny liked this before his illness. +15 Strength." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(9) << "Chef: Kenny's not done well with it." << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(9) << "Chef: Er, no, it's gone in the soup." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(9) << "Chef: Wait! What the - WHAT?" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(9) << "Chef: This game's R rated version is much more entertaining!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


/*******************************************************************************
**			function set Bools() 30 each
** Individual getter and setter functions for each character. Used chiefly by
** runContoller() locally but also by ThrowBack.cpp
** Input: various bool per character queried.
** Output: various bool per character response..
******************************************************************************/
void Red::setJeffFungusVisit(bool visit) {
	this->jeffFungusVisit = visit;
}

bool Red::getJeffFungusVisit() {
	return jeffFungusVisit;
}

void Red::setJeffFungusFood(bool jeffFungusFood) {
	this->jeffFungusFood = jeffFungusFood;
}

bool Red::getJeffFungusFood() {
	return jeffFungusFood;
}

void Red::setJeffFungusDrink(bool jeffFungusDrink) {
	this->jeffFungusDrink = jeffFungusDrink;
}

bool Red::getJeffFungusDrink() {
	return jeffFungusDrink;
}


void Red::setBlinkeyVisit(bool visit) {
	this->blinkeyVisit = visit;
}

bool Red::getBlinkeyVisit() {
	return blinkeyVisit;
}

void Red::setBlinkeyFood(bool blinkeyFood) {
	this->blinkeyFood = blinkeyFood;
}

bool Red::getBlinkeyFood() {
	return blinkeyFood;;
}

void Red::setBlinkeyDrink(bool blinkeyDrink) {
	this->blinkeyDrink = blinkeyDrink;
}

bool Red::getBlinkeyDrink() {
	return blinkeyDrink;
}


void Red::setRedElmoVisit(bool visit) {
	this->redElmoVisit = visit;
}

bool Red::getRedElmoVisit() {
	return redElmoVisit;
}

void Red::setRedElmoFood(bool redElmoFood) {
	this->redElmoFood = redElmoFood;
}

bool Red::getRedElmoFood() {
	return redElmoFood;
}

void Red::setRedElmoDrink(bool redElmoDrink) {
	this->redElmoDrink = redElmoDrink;
}

bool Red::getRedElmoDrink() {
	return redElmoDrink;
}


void Red::setYosemiteSamVisit(bool visit) {
	this->yosemiteSamVisit = visit;
}

bool Red::getYosemiteSamVisit() {
	return yosemiteSamVisit;
}

void Red::setYosemiteSamFood(bool yosemiteSamFood) {
	this->yosemiteSamFood = yosemiteSamFood;
}

bool Red::getYosemiteSamFood() {
	return yosemiteSamFood;
}

void Red::setYosemiteSamDrink(bool yosemiteSamDrink) {
	this->yosemiteSamDrink = yosemiteSamDrink;
}

bool Red::getYosemiteSamDrink() {
	return yosemiteSamDrink;
}


void Red::setChefVisit(bool visit) {
	this->chefVisit = visit;
}

bool Red::getChefVisit() {
	return chefVisit;
}

void Red::setChefFood(bool chefFood) {
	this->chefFood = chefFood;
}

bool Red::getChefFood() {
	return chefFood;
}

void Red::setChefDrink(bool chefDrink) {
	this->chefDrink = chefDrink;
}

bool Red::getChefDrink() {
	return chefDrink;
}


/*******************************************************************************
**			function set Color() 6 each
** Setters for the 6 rooms other than this one.  This is how a player can
** travel between rooms. Called and used by ThrowBack.cpp
** Input: Space* for each individual room.
** Output: void.
******************************************************************************/
void Red::setBlue(Space *ptr) {
	R_Blue = ptr;
}

void Red::setYellow(Space *ptr) {
	R_Yellow = ptr;
}

void Red::setCyan(Space *ptr) {
	R_Cyan = ptr;
}

void Red::setGreen(Space *ptr) {
	R_Green = ptr;
}

void Red::setMagenta(Space *ptr) {
	R_Magenta = ptr;
}

void Red::setWhite(Space *ptr) {
	R_White = ptr;
}
