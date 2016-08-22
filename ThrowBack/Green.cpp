/****************************************************************************************
** Program Filename: Green.cpp
** Author: Chris Kearns
** Date: 3/17/2016
** Description: Contains the Green class definition file.
** Input: exitGame() takes 6 Space pointers for linking rooms.
** Output: Linked to all ThrowBack derived classes.
*****************************************************************************************/
#include "Green.hpp"
#include <string>
using std::string;
#include<iostream>
using std::cout;
using std::cin;


/*******************************************************************************
**				function set'Color'Pointers()
** Sets color pointers to all other rooms.  Called from ThrowBack.cpp main()
** Input: Space class color pointers other than this class.
** Output:void
******************************************************************************/
void Green::setGreenPtrs(Space* blue, Space* yellow, Space* cyan, Space* red, Space* magenta, Space* white) {
	setBlue(blue);
	setYellow(yellow);
	setCyan(cyan);
	setRed(red);
	setMagenta(magenta);
	setWhite(white);
	setPPGreen(false);
	setStrength();
	initCharBools();
}

// Destructor.
Green::~Green() {
	G_Blue = NULL;
	G_Yellow = NULL;
	G_Cyan = NULL;
	G_Red = NULL;
	G_Magenta = NULL;
	G_White = NULL;
}


/*******************************************************************************
**			function setTrngth() 3 each.
** Setters for stregth. setStrength() for initialization, setSTregth(int) for
** updating local room strength changes. getStrength for logic control, and
** acceptStrength() sets overall current Player strength upon Player entry to
** this room.  acceptSTrength() also returns current Player to ThrowBack.cpp for
** use as Player enters other rooms or re-enters this room.
** Input: acceptStregnth() current strength int from Throwback.cpp
** Output: sets local stregth int.
******************************************************************************/
void Green::setStrength() {
	this->strength = 0;
}

void Green::setStrength(int strength) {
	this->strength = getStrength() + strength;
}

int Green::getStrength() {
	return strength;
}

// Throwback passes overall Player strength for update here.
int Green::acceptStrength(int strength) {
	this->strength = strength;
}


/*******************************************************************************
**			function setPPColor() 3 each.
** Initializes Player color puzzle piece, logic control locally to ths room, and
** getPPBlue used by ThrowBack.cpp for logic control and displayBP()
** Input: bool to initialize and set when Player finds color puzzle piece.
** Output:
******************************************************************************/
void Green::setPPGreen(bool f) {
	this->pPiece = f;
}

void Green::setPPGreen() {
	this->pPiece = true;
}

bool Green::getPPGreen() {
	return pPiece;
}


/*******************************************************************************
**			function initCharBools()
** Initializes individual characters variables at room initializaton.
******************************************************************************/
void Green::initCharBools() {
	this->shrekFood = false;
	this->shrekDrink = false;
	this->shrekVisit = false;
	this->kermitFood = false;
	this->kermitDrink = false;
	this->kermitVisit = false;
	this->yodaFood = false;
	this->yodaDrink = false;
	this->yodaVisit = false;
	this->theGrinchVisit = false;
	this->theGrinchFood = false;
	this->theGrinchDrink = false;
	this->theHulkFood = false;
	this->theHulkDrink = false;
	this->theHulkVisit = false;
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
int Green::runRoom() {
	int choice = 1;
	cout << palette(14) << "You are in the Green Room!" << palette(1) << "\n";
	if (getStrength() < 25) {
		cout << palette(14) << "You're looking green around the gills friend!" << palette(1) << "\n";
		boostStrength();
	}
	while (choice > 0 && choice <= 6) {
		choice = runCharacters();
		if (choice == 1) {
			choice = runController(1);	// Shrek
		}
		else if (choice == 2) {
			choice = runController(2);	// Kermit
		}
		else if (choice == 3) {
			choice = runController(3);	// Yoda
		}
		else if (choice == 4) {
			choice = runController(4);	// Cookie
		}
		else if (choice == 5) {
			choice = runController(5);	// TheHulk
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
void Green::boostStrength() {
	int answer = 0;
	cout << palette(14) << "Would you like a strength boost to keep playing?\n" << palette(1)
		<< "1. Yes!\n"
		<< "2. I don't do that sort of thing!\n";
	while (!(cin >> answer) || answer < 1 || answer > 2) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(14)
			<< "Would you like a strength Boost to keep playing?\n" << palette(1)
			<< "1. Yes!\n"
			<< "2. No!\n";
	}
	if (answer == 1) {
		setStrength(12);
		cout << palette(14) << "New Strength = " << getStrength() << palette(1) << "\n";
	}
}


/*******************************************************************************
**			function runCharacters()
** Player chocie cout/cin input validation module. Returns an int for choice of
** character to visit to runController()
** Input: Player
** Output: int choice to local runController()
******************************************************************************/
int Green::runCharacters() {
	int utter = 0;
	cout << "Which" << palette(14) << " Green Room " << palette(1) << "character do you want to converse with?\n"
		<< "1. " << palette(14) << "Shrek" << palette(1) << "\n"
		<< "2. " << palette(14) << "Kermit" << palette(1) << "\n"
		<< "3. " << palette(14) << "The Hulk" << palette(1) << "\n"
		<< "4. " << palette(14) << "The Grinch" << palette(1) << "\n"
		<< "5. " << palette(14) << "Yoda" << palette(1) << "\n"
		<< "6. " << palette(9) << "Change Rooms now!" << palette(1) << "\n";
	while (!(cin >> utter) || utter < 1 || utter > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< "Which" << palette(14) << " Green Room " << palette(1) << "character do you want to converse with?\n"
			<< "1. " << palette(14) << "Shrek" << palette(1) << "\n"
			<< "2. " << palette(14) << "Kermit" << palette(1) << "\n"
			<< "3. " << palette(14) << "The Hulk" << palette(1) << "\n"
			<< "4. " << palette(14) << "The Grinch" << palette(1) << "\n"
			<< "5. " << palette(14) << "Yoda" << palette(1) << "\n"
			<< "6. " << palette(9) << "Change Rooms now!" << palette(1) << "\n";
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
int Green::runController(int in) {
	int arg = in;
	int choice1;
	int choice2;
	while (arg > 0 && arg < 7) {
		if (arg == 1) {			/**** Shrek ****/
			while (arg == 1) {
				choice1 = playerAI();
				choice2 = runShrek(choice1);
				if (choice2 == 1) { setStrength(-1); }
				else if (choice2 == 2) { setStrength(-1); setShrekFood(true); }
				else if (choice2 == 3) { setStrength(-1); setShrekDrink(true); }
				else if (choice2 == 4) { setStrength(-1); }
				else if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				else if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 2) {		/**** Kermit ****/
			while (arg == 2) {
				choice1 = playerAI();
				choice2 = runKermit(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setKermitFood(true); }
				if (choice2 == 3) {
					if (getKermitDrink() == false) {
						setStrength(2);
						setKermitDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 3) {		/**** The Hulk ****/
			while (arg == 3) {
				choice1 = playerAI();
				choice2 = runTheGrinch(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) {
					if (getTheHulkFood() == false) {
						setStrength(5);
						setTheHulkFood(true);
					}
				}
				if (choice2 == 3) {
					if (getTheHulkDrink() == false) {
						setStrength(15);
						setTheHulkDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 4) {		/**** The Grinch ****/
			while (arg == 4) {
				choice1 = playerAI();
				choice2 = runTheGrinch(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setTheGrinchFood(true); }
				if (choice2 == 3) {
					if (getTheGrinchDrink() == false) {
						setStrength(15);
						setTheGrinchDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 5) {		/**** Yoda ****/
			while (arg == 5) {
				choice1 = playerAI();
				choice2 = runYoda(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setYodaFood(true); }
				if (choice2 == 3) { setStrength(-10); setYodaDrink(true); }
				if (choice2 == 4) {
					setStrength(-1);
					if (getPPGreen() == false) {
						setPPGreen();
						cout << "\nThe " << palette(12) << " G " << palette(1) << palette(14)
							<< " Puzzle Piece " << palette(1) << "is in your Backpack!!\n\n";
					}
				}
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 6) {			/**** Change Rooms ****/
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
int Green::playerAI() {
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
	cout << "There's a " << palette(14) << "Green" << palette(1) << " Character in front of you. Say:\n"
		<< "1. Greatings " << palette(14) << "Green Room" << palette(1) << " Character!\n"
		<< "2. Do you have anything to eat?\n"
		<< "3. Do you have anything to drink?\n"
		<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
		<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
		<< "5. I'm going to visit a different " << palette(14) << "Green Room" << palette(1) << " Character.\n"
		<< "6. " << palette(9) << "I'm changing rooms now!" << palette(1) << "\n";
	while (!(cin >> out) || out < 1 || out > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< palette(3) << "You're going to upset it!" << palette(1) << " What do you want to say?\n"
			<< "1. Greatings " << palette(14) << "Green Room" << palette(1) << " Character!\n"
			<< "2. Do you have anything to eat?\n"
			<< "3. Do you have anything to drink?\n"
			<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
			<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
			<< "5. I'm going to visit a different " << palette(14) << "Green Room" << palette(1) << " Character.\n"
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
int Green::runShrek(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getShrekVisit() == false) {
			cout << palette(14) << "Shrek: I hope you didn't bring that Donkey with you." << palette(1) << "\n";
			setShrekVisit(true);
			out = 1;
		}
		else {
			cout << palette(14) << "Shrek: What do I have to do to get a little privacy?!" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getShrekFood() == false) {
			cout << palette(14) << "Shrek: You wouldn't like rotting snail soup!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(14) << "Shrek: I eat gamers, be gone from my swamp!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getShrekDrink() == false) {
			cout << palette(14) << "Shrek: Only fresh squeezed villagers!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(14) << "Shrek: No, go talk to the Donkey!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(14) << "Shrek: No, I'm an ogre!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(14) << "Shrek: Good and don't come back!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(14) << "Shrek: I'll squeeze the jelly from your eyes!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Green::runKermit(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getKermitVisit() == false) {
			cout << palette(14) << "Kermit: That ridiculous Big bird sent you, didn't it?" << palette(1) << "\n";
			setKermitVisit(true);
			out = 1;
		}
		else {
			cout << palette(14) << "Kermit: Can't get enuough!?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getKermitFood() == false) {
			cout << palette(14) << "Kermit: I'm a muppet! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(14) << "Kermit: What don't you get? Another -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getKermitDrink() == false) {
			cout << palette(14) << "Kermit: Frogs love rain water! +2 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(14) << "Kermit: It's gone dry here Mr. Henson!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(14) << "Kermit: Puzzle piece? ...that's none of my business!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(14) << "Kermit: Send that Ms. Piggy by if you see her!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(14) << "Kermit: Loser! ...but that's none of my business!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Green::runYoda(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getYodaVisit() == false) {
			cout << palette(14) << "Yoda: Yoda I am, come Jedi, converse we shall." << palette(1) << "\n";
			setYodaVisit(true);
			out = 1;
		}
		else {
			cout << palette(14) << "Yoda: Why are you here again?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getYodaFood() == false) {
			cout << palette(14) << "Yoda: Do. Or do not, There is no try (or drink)! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(14) << "Yoda: This is why you fail. Another -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getYodaDrink() == false) {
			cout << palette(14) << "Yoda: A Jedi craves not this drink. -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(14) << "Yoda: This is why you fail! -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		if (getPPGreen() == false) {
			cout << palette(14) << "Yoda: Judge me by my size, do you? Yes!" << palette(1) << "\n";
			out = 4;
		}
		else {
			cout << palette(14) << "Yoda: You have what you seek, go from this place!" << palette(1) << "\n";
		}
	}
	else if (inMessage == 5) {
		cout << palette(14) << "Yoda: When nine hundred years old you reach, look as good you will not" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(14) << "Yoda: Wait for it... May the force be with you!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Green::runTheGrinch(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getTheGrinchVisit() == false) {
			cout << palette(14) << " The Grinch: Are you having a holly jolly Christmas?" << palette(1) << "\n";
			setTheGrinchVisit(true);
			out = 1;
		}
		else {
			cout << palette(14) << " The Grinch: Well pucker up and kiss it Whoville." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getTheGrinchFood() == false) {
			cout << palette(14) << " The Grinch: What's that stench? It's fantastic! -5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(14) << " The Grinch: Stupid, stupid stupid! Another -5 Strength." << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getTheGrinchDrink() == false) {
			cout << palette(14) << " The Grinch: I don't know, here, it's some kind of soup. +15 Stregth." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(14) << " The Grinch: One man's toxic waste is anothers potpourri." << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(14) << " The Grinch: It's because I'm green, isn't it?" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(14) << " The Grinch: Oh the Who-manity!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(14) << " The Grinch: Loath Entirely!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Green::runTheHulk(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getTheHulkVisit() == false) {
			cout << palette(14) << "Hulk: Don't make me mad!" << palette(1) << "\n";
			setTheHulkVisit(true);
			out = 1;
		}
		else {
			cout << palette(14) << "Hulk: You woudn't like me mad." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getTheHulkFood() == false) {
			cout << palette(14) << "Hulk: Sure, Bruce Banner brought this by. +5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(14) << "Hulk: Do I look like that pretender Hogan?" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getTheHulkDrink() == false) {
			cout << palette(14) << "Hulk: Here, have one of these guarana sodas. +15 Strength." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(14) << "Hulk: No, you'll get gamma sickness!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(14) << "Hulk: Betty?!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(14) << "Hulk: Grrrrr!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(14) << "Hulk: Leave me alone!" << palette(1) << "\n";
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
void Green::setShrekVisit(bool visit) {
	this->shrekVisit = visit;
}

bool Green::getShrekVisit() {
	return shrekVisit;
}

void Green::setShrekFood(bool ShrekFood) {
	this->shrekFood = ShrekFood;
}

bool Green::getShrekFood() {
	return shrekFood;
}

void Green::setShrekDrink(bool ShrekDrink) {
	this->shrekDrink = ShrekDrink;
}

bool Green::getShrekDrink() {
	return shrekDrink;
}


void Green::setKermitVisit(bool visit) {
	this->kermitVisit = visit;
}

bool Green::getKermitVisit() {
	return kermitVisit;
}

void Green::setKermitFood(bool KermitFood) {
	this->kermitFood = KermitFood;
}

bool Green::getKermitFood() {
	return kermitFood;;
}

void Green::setKermitDrink(bool KermitDrink) {
	this->kermitDrink = KermitDrink;
}

bool Green::getKermitDrink() {
	return kermitDrink;
}


void Green::setYodaVisit(bool visit) {
	this->yodaVisit = visit;
}

bool Green::getYodaVisit() {
	return yodaVisit;
}

void Green::setYodaFood(bool YodaFood) {
	this->yodaFood = YodaFood;
}

bool Green::getYodaFood() {
	return yodaFood;
}

void Green::setYodaDrink(bool YodaDrink) {
	this->yodaDrink = YodaDrink;
}

bool Green::getYodaDrink() {
	return yodaDrink;
}


void Green::setTheGrinchVisit(bool visit) {
	this->theGrinchVisit = visit;
}

bool Green::getTheGrinchVisit() {
	return theGrinchVisit;
}

void Green::setTheGrinchFood(bool TheGrinchFood) {
	this->theGrinchFood = TheGrinchFood;
}

bool Green::getTheGrinchFood() {
	return theGrinchFood;
}

void Green::setTheGrinchDrink(bool TheGrinchDrink) {
	this->theGrinchDrink = TheGrinchDrink;
}

bool Green::getTheGrinchDrink() {
	return theGrinchDrink;
}


void Green::setTheHulkVisit(bool visit) {
	this->theHulkVisit = visit;
}

bool Green::getTheHulkVisit() {
	return theHulkVisit;
}

void Green::setTheHulkFood(bool TheHulkFood) {
	this->theHulkFood = TheHulkFood;
}

bool Green::getTheHulkFood() {
	return theHulkFood;
}

void Green::setTheHulkDrink(bool TheHulkDrink) {
	this->theHulkDrink = TheHulkDrink;
}

bool Green::getTheHulkDrink() {
	return theHulkDrink;
}


/*******************************************************************************
**			function set Color() 6 each
** Setters for the 6 rooms other than this one.  This is how a player can
** travel between rooms. Called and used by ThrowBack.cpp
** Input: Space* for each individual room.
** Output: void.
******************************************************************************/
void Green::setBlue(Space *ptr) {
	G_Blue = ptr;
}

void Green::setYellow(Space *ptr) {
	G_Yellow = ptr;
}

void Green::setCyan(Space *ptr) {
	G_Cyan = ptr;
}

void Green::setRed(Space *ptr) {
	G_Red = ptr;
}

void Green::setMagenta(Space *ptr) {
	G_Magenta = ptr;
}

void Green::setWhite(Space *ptr) {
	G_White = ptr;
}
