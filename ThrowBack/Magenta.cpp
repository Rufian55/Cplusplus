/****************************************************************************************
** Program Filename: Magenta.cpp
** Author: Chris Kearns
** Date: 3/17/2016
** Description: Contains the Magenta class definition file.
** Input: exitGame() takes 6 Space pointers for linking rooms.
** Output: Linked to all ThrowBack derived classes.
*****************************************************************************************/
#include "Magenta.hpp"
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
void Magenta::setMagentaPtrs(Space* blue, Space* yellow, Space* cyan, Space* green, Space* red, Space* white) {
	setBlue(blue);
	setYellow(yellow);
	setCyan(cyan);
	setGreen(green);
	setRed(red);
	setWhite(white);
	setPPMagenta(false);
	setStrength();
	initCharBools();
}

// Destructor.
Magenta::~Magenta() {
	M_Blue = NULL;
	M_Yellow = NULL;
	M_Cyan = NULL;
	M_Green = NULL;
	M_Red = NULL;
	M_White = NULL;
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
void Magenta::setStrength() {
	this->strength = 0;
}

void Magenta::setStrength(int strength) {
	this->strength = getStrength() + strength;
}

int Magenta::getStrength() {
	return strength;
}

// Throwback passes overall Player strength for update here.
int Magenta::acceptStrength(int strength) {
	this->strength = strength;
}


/*******************************************************************************
**			function setPPColor() 3 each.
** Initializes Player color puzzle piece, logic control locally to ths room, and
** getPPBlue used by ThrowBack.cpp for logic control and displayBP()
** Input: bool to initialize and set when Player finds color puzzle piece.
** Output:
******************************************************************************/
void Magenta::setPPMagenta(bool f) {
	this->pPiece = f;
}

void Magenta::setPPMagenta() {
	this->pPiece = true;
}

bool Magenta::getPPMagenta() {
	return pPiece;
}


/*******************************************************************************
**			function initCharBools()
** Initializes individual characters variables at room initializaton.
******************************************************************************/
void Magenta::initCharBools() {
	this->randallBoggsFood = false;
	this->randallBoggsDrink = false;
	this->randallBoggsVisit = false;
	this->pinkyFood = false;
	this->pinkyDrink = false;
	this->pinkyVisit = false;
	this->thePinkPantherFood = false;
	this->thePinkPantherDrink = false;
	this->thePinkPantherVisit = false;
	this->jokerFood = false;
	this->jokerDrink = false;
	this->jokerVisit = false;
	this->ursulaFood = false;
	this->ursulaDrink = false;
	this->ursulaVisit = false;
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
int Magenta::runRoom() {
	int choice = 1;
	cout << palette(29) << "You are in the Magenta Room!" << palette(1) << "\n";
	if (getStrength() < 25) {
		cout << palette(29) << "You're looking a bit peaked!" << palette(1) << "\n";
		boostStrength();
	}
	while (choice > 0 && choice <= 6) {
		choice = runCharacters();
		if (choice == 1) {
			choice = runController(1);	// RandallBoggs
		}
		else if (choice == 2) {
			choice = runController(2);	// Pinky
		}
		else if (choice == 3) {
			choice = runController(3);	// ThePinkPanther
		}
		else if (choice == 4) {
			choice = runController(4);	// Cookie
		}
		else if (choice == 5) {
			choice = runController(5);	// Ursula
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
void Magenta::boostStrength() {
	int answer = 0;
	cout << palette(29) << "Would you like a 6 point strength boost to keep playing?\n" << palette(1)
		<< "1. Yes!\n"
		<< "2. No thanks, had a lite snack in the Red Room.\n";
	while (!(cin >> answer) || answer < 1 || answer > 2) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(29)
			<< "Would you like a strength Boost to keep playing?\n" << palette(1)
			<< "1. Yes!\n"
			<< "2. No!\n";
	}
	if (answer == 1) {
		setStrength(6);
		cout << palette(29) << "New Strength = " << getStrength() << palette(1) << "\n";
	}
}


/*******************************************************************************
**			function runCharacters()
** Player chocie cout/cin input validation module. Returns an int for choice of
** character to visit to runController()
** Input: Player
** Output: int choice to local runController()
******************************************************************************/
int Magenta::runCharacters() {
	int utter = 0;
	cout << "Which" << palette(29) << " Magenta Room " << palette(1) << "character do you want to converse with?\n"
		<< "1. " << palette(29) << "Randall Boggs (Monsters Inc.)" << palette(1) << "\n"
		<< "2. " << palette(29) << "Pinky (Pacman)" << palette(1) << "\n"
		<< "3. " << palette(29) << "The Pink Panther" << palette(1) << "\n"
		<< "4. " << palette(29) << "Joker (Batman)" << palette(1) << "\n"
		<< "5. " << palette(29) << "Ursula (The Little Mermaid)" << palette(1) << "\n"
		<< "6. " << palette(9) << "Change Rooms now!" << palette(1) << "\n";
	while (!(cin >> utter) || utter < 1 || utter > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< "Which" << palette(29) << " Magenta Room " << palette(1) << "character do you want to converse with?\n"
			<< "1. " << palette(29) << "Randall Boggs (Monsters Inc.)" << palette(1) << "\n"
			<< "2. " << palette(29) << "Pinky (Pacman)" << palette(1) << "\n"
			<< "3. " << palette(29) << "The Pink Panther" << palette(1) << "\n"
			<< "4. " << palette(29) << "Joker (Batman)" << palette(1) << "\n"
			<< "5. " << palette(29) << "Ursula (The Little Mermaid)" << palette(1) << "\n"
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
int Magenta::runController(int in) {
	int arg = in;
	int choice1;
	int choice2;
	while (arg > 0 && arg < 7) {
		if (arg == 1) {			/**** Randall Boggs ****/
			while (arg == 1) {
				choice1 = playerAI();
				choice2 = runRandallBoggs(choice1);
				if (choice2 == 1) { setStrength(-1); }
				else if (choice2 == 2) { setStrength(-1); setRandallBoggsFood(true); }
				else if (choice2 == 3) { setStrength(-1); setRandallBoggsDrink(true); }
				else if (choice2 == 4) { setStrength(-1); }
				else if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				else if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 2) {		/**** Pinky ****/
			while (arg == 2) {
				choice1 = playerAI();
				choice2 = runPinky(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setPinkyFood(true); }
				if (choice2 == 3) {
					if (getPinkyDrink() == false) {
						setStrength(2);
						setPinkyDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 3) {		/**** The Pink Panther ****/
			while (arg == 3) {
				choice1 = playerAI();
				choice2 = runThePinkPanther(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setThePinkPantherFood(true); }
				if (choice2 == 3) { setStrength(-10); setThePinkPantherDrink(true); }
				if (choice2 == 4) {
					setStrength(-1);
					if (getPPMagenta() == false) {
						setPPMagenta();
						cout << "\nThe " << palette(27) << " M " << palette(1) << palette(29)
							<< " Puzzle Piece " << palette(1) << "is in your Backpack!!\n\n";
					}
				}
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 4) {		/**** Joker ****/
			while (arg == 4) {
				choice1 = playerAI();
				choice2 = runJoker(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setJokerFood(true); }
				if (choice2 == 3) {
					if (getJokerDrink() == false) {
						setStrength(15);
						setJokerDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 5) {		/**** Bob the Blob ****/
			while (arg == 5) {
				choice1 = playerAI();
				choice2 = runUrsula(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) {
					if (getUrsulaFood() == false) {
						setStrength(5);
						setUrsulaFood(true);
					}
				}
				if (choice2 == 3) {
					if (getUrsulaDrink() == false) {
						setStrength(15);
						setUrsulaDrink(true);
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
**				function playerAI()
** Player's query module for asking questions to each character as selected by
** Player. Returns int arg for run CharacterName().
** Input: Player out arg selected.
** Output: int out as chosed by Player.
******************************************************************************/
int Magenta::playerAI() {
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
	cout << "There's a " << palette(29) << "Magenta" << palette(1) << " Character in front of you. Say:\n"
		<< "1. Greatings " << palette(29) << "Magenta Room" << palette(1) << " Character!\n"
		<< "2. Do you have anything to eat?\n"
		<< "3. Do you have anything to drink?\n"
		<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
		<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
		<< "5. I'm going to visit a different " << palette(29) << "Magenta Room" << palette(1) << " Character.\n"
		<< "6. " << palette(9) << "I'm changing rooms now!" << palette(1) << "\n";
	while (!(cin >> out) || out < 1 || out > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< palette(3) << "You're going to upset it!" << palette(1) << " What do you want to say?\n"
			<< "1. Greatings " << palette(29) << "Magenta Room" << palette(1) << " Character!\n"
			<< "2. Do you have anything to eat?\n"
			<< "3. Do you have anything to drink?\n"
			<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
			<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
			<< "5. I'm going to visit a different " << palette(29) << "Magenta Room" << palette(1) << " Character.\n"
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
int Magenta::runRandallBoggs(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getRandallBoggsVisit() == false) {
			cout << palette(29) << "Randall Boggs: You still think this is about that stupid scare record?" << palette(1) << "\n";
			setRandallBoggsVisit(true);
			out = 1;
		}
		else {
			cout << palette(29) << "Randall Boggs: So, how about this kid getting loose? Crazy, huh?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getRandallBoggsFood() == false) {
			cout << palette(29) << "Randall Boggs: Everyone goes to lunch! Which means the scare floor will be..." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(29) << "Randall Boggs: There's no food at the scare factory!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getRandallBoggsDrink() == false) {
			cout << palette(29) << "Randall Boggs: There's no drinking on the factory floor!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(29) << "Randall Boggs: You're fired!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(29) << "Randall Boggs: No, but I do have a scare machine." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(29) << "Randall Boggs: I'd put my money on Waxford." << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(29) << "Randall Boggs: Shh. Shh. Shh. Do you hear that? It's the winds of change." << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Magenta::runPinky(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getPinkyVisit() == false) {
			cout << palette(29) << "Pinky: You don't actually think you're going to find the puzzle piece do you?" << palette(1) << "\n";
			setPinkyVisit(true);
			out = 1;
		}
		else {
			cout << palette(29) << "Pinky: That weird noise when Pacman ends, yeah that!" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getPinkyFood() == false) {
			cout << palette(29) << "Pinky: I told you, nothing here! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(29) << "Pinky: Perhaps Inky can help you. Another -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getPinkyDrink() == false) {
			cout << palette(29) << "Pinky: I do, flat soda some kid left at the arcade. +2 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(29) << "Pinky: It's got mold!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(29) << "Pinky: There is no puzzle piece here, move along." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(29) << "Pinky: That was a waste of time, wasn't it!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(29) << "Pinky: Chomp!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Magenta::runThePinkPanther(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getThePinkPantherVisit() == false) {
			cout << palette(29) << "Pink Panther: You've been speaking with that oaf, Clouseau!"<< palette(1) << "\n";
			setThePinkPantherVisit(true);
			out = 1;
		}
		else {
			cout << palette(29) << "Pink Panther: Get a clue." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getThePinkPantherFood() == false) {
			cout << palette(29) << "Pink Panther: I don't eat! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(29) << "Pink Panther: Very Clouseau like. Another -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getThePinkPantherDrink() == false) {
			cout << palette(29) << "Pink Panther: Some Pink Champagne? -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(29) << "Pink Panther: Bubbly's all gone, old boy. Another -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		if (getPPMagenta() == false) {
			cout << palette(29) << "Pink Panther: Yes, that Clouseau fellow missed it. Into your backpack!" << palette(1) << "\n";
			out = 4;
		}
		else {
			cout << palette(29) << "Pink Panther: I wouldn't stay too long, the pink decor..." << palette(1) << "\n";
		}
	}
	else if (inMessage == 5) {
		cout << palette(29) << "Pink Panther: Peter Sellers was best!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(29) << "Pink Panther: To do, to do, to do, to do!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Magenta::runJoker(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getJokerVisit() == false) {
			cout << palette(29) << "Joker: Have you ever danced with the devil in the pale moonlight?" << palette(1) << "\n";
			setJokerVisit(true);
			out = 1;
		}
		else {
			cout << palette(29) << "Joker: If you're good at something never do it for feee." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getJokerFood() == false) {
			cout << palette(29) << "Joker: Would ya like fries with that? -5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(29) << "Joker: You did not just ask again?! Another -5 Strength." << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getJokerDrink() == false) {
			cout << palette(29) << "Joker: Sure, that green goop I fell in! +15 Stregth." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(29) << "Joker: Drink up, but it's on you!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(29) << "Joker: If you brought Kim Bassinger with you we can talk." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(29) << "Joker: The only sensible way to live is without rules." << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(29) << "Joker: Have you shipped a million?" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Magenta::runUrsula(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getUrsulaVisit() == false) {
			cout << palette(29) << "Ursula: Now I am the ruler of all the ocean! The waves obey my every whim!" << palette(1) << "\n";
			setUrsulaVisit(true);
			out = 1;
		}
		else {
			cout << palette(29) << "Ursula: We mustn't lurk in doorways. It's rude." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getUrsulaFood() == false) {
			cout << palette(29) << "Ursula: One double cluck combo. +5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(29) << "Ursula: Make it two, not!!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getUrsulaDrink() == false) {
			cout << palette(29) << "Ursula: Have a Disney thememd cocktail on me. +15 Strength." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(29) << "Ursula: That's enough!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(29) << "Ursula: Impudent fools will never find the Puzzle Piece!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(29) << "Ursula: So much for true love!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(29) << "Ursula: Yes, hurry home, princess!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


/*******************************************************************************
**				function set Bools() 30 each
** Individual getter and setter functions for each character. Used chiefly by
** runContoller() locally but also by ThrowBack.cpp
** Input: various bool per character queried.
** Output: various bool per character response..
******************************************************************************/
void Magenta::setRandallBoggsVisit(bool visit) {
	this->randallBoggsVisit = visit;
}

bool Magenta::getRandallBoggsVisit() {
	return randallBoggsVisit;
}

void Magenta::setRandallBoggsFood(bool randallBoggsFood) {
	this->randallBoggsFood = randallBoggsFood;
}

bool Magenta::getRandallBoggsFood() {
	return randallBoggsFood;
}

void Magenta::setRandallBoggsDrink(bool randallBoggsDrink) {
	this->randallBoggsDrink = randallBoggsDrink;
}

bool Magenta::getRandallBoggsDrink() {
	return randallBoggsDrink;
}


void Magenta::setPinkyVisit(bool visit) {
	this->pinkyVisit = visit;
}

bool Magenta::getPinkyVisit() {
	return pinkyVisit;
}

void Magenta::setPinkyFood(bool pinkyFood) {
	this->pinkyFood = pinkyFood;
}

bool Magenta::getPinkyFood() {
	return pinkyFood;;
}

void Magenta::setPinkyDrink(bool pinkyDrink) {
	this->pinkyDrink = pinkyDrink;
}

bool Magenta::getPinkyDrink() {
	return pinkyDrink;
}


void Magenta::setThePinkPantherVisit(bool visit) {
	this->thePinkPantherVisit = visit;
}

bool Magenta::getThePinkPantherVisit() {
	return thePinkPantherVisit;
}

void Magenta::setThePinkPantherFood(bool thePinkPantherFood) {
	this->thePinkPantherFood = thePinkPantherFood;
}

bool Magenta::getThePinkPantherFood() {
	return thePinkPantherFood;
}

void Magenta::setThePinkPantherDrink(bool thePinkPantherDrink) {
	this->thePinkPantherDrink = thePinkPantherDrink;
}

bool Magenta::getThePinkPantherDrink() {
	return thePinkPantherDrink;
}


void Magenta::setJokerVisit(bool visit) {
	this->jokerVisit = visit;
}

bool Magenta::getJokerVisit() {
	return jokerVisit;
}

void Magenta::setJokerFood(bool jokerFood) {
	this->jokerFood = jokerFood;
}

bool Magenta::getJokerFood() {
	return jokerFood;
}

void Magenta::setJokerDrink(bool jokerDrink) {
	this->jokerDrink = jokerDrink;
}

bool Magenta::getJokerDrink() {
	return jokerDrink;
}


void Magenta::setUrsulaVisit(bool visit) {
	this->ursulaVisit = visit;
}

bool Magenta::getUrsulaVisit() {
	return ursulaVisit;
}

void Magenta::setUrsulaFood(bool ursulaFood) {
	this->ursulaFood = ursulaFood;
}

bool Magenta::getUrsulaFood() {
	return ursulaFood;
}

void Magenta::setUrsulaDrink(bool ursulaDrink) {
	this->ursulaDrink = ursulaDrink;
}

bool Magenta::getUrsulaDrink() {
	return ursulaDrink;
}


/*******************************************************************************
**			function set Color() 6 each
** Setters for the 6 rooms other than this one.  This is how a player can
** travel between rooms. Called and used by ThrowBack.cpp
** Input: Space* for each individual room.
** Output: void.
******************************************************************************/
void Magenta::setBlue(Space *ptr) {
	M_Blue = ptr;
}

void Magenta::setYellow(Space *ptr) {
	M_Yellow = ptr;
}

void Magenta::setCyan(Space *ptr) {
	M_Cyan = ptr;
}

void Magenta::setGreen(Space *ptr) {
	M_Green = ptr;
}

void Magenta::setRed(Space *ptr) {
	M_Red = ptr;
}

void Magenta::setWhite(Space *ptr) {
	M_White = ptr;
}
