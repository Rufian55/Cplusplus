/****************************************************************************************
** Program Filename: White.cpp
** Author: Chris Kearns
** Date: 3/17/2016
** Description: Contains the White class definition file.
** Input: exitGame() takes 6 Space pointers for linking rooms.
** Output: Linked to all ThrowBack derived classes.
*****************************************************************************************/
#include "White.hpp"
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
void White::setWhitePtrs(Space* blue, Space* yellow, Space* cyan, Space* green, Space* red, Space* magenta) {
	setBlue(blue);
	setYellow(yellow);
	setCyan(cyan);
	setGreen(green);
	setRed(red);
	setMagenta(magenta);
	setPPWhite(false);
	setStrength();
	initCharBools();
}

// Destructor.
White::~White() {
	W_Blue = NULL;
	W_Yellow - NULL;
	W_Cyan = NULL;
	W_Green = NULL;
	W_Red = NULL;
	W_Magenta = NULL;
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
void White::setStrength() {
	this->strength = 0;
}

void White::setStrength(int strength) {
	this->strength = getStrength() + strength;
}

int White::getStrength() {
	return strength;
}

// Throwback passes overall Player strength for update here.
int White::acceptStrength(int strength) {
	this->strength = strength;
}


/*******************************************************************************
**			function setPPColor() 3 each.
** Initializes Player color puzzle piece, logic control locally to ths room, and
** getPPBlue used by ThrowBack.cpp for logic control and displayBP()
** Input: bool to initialize and set when Player finds color puzzle piece.
** Output:
******************************************************************************/
void White::setPPWhite(bool f) {
	this->pPiece = f;
}

void White::setPPWhite() {
	this->pPiece = true;
}

bool White::getPPWhite() {
	return pPiece;
}


/*******************************************************************************
**			function initCharBools()
** Initializes individual characters variables at room initializaton.
******************************************************************************/
void White::initCharBools() {
	this->mrWhiteFood = false;
	this->mrWhiteDrink = false;
	this->mrWhiteVisit = false;
	this->yetiFood = false;
	this->yetiDrink = false;
	this->yetiVisit = false;
	this->brianFood = false;
	this->brianDrink = false;
	this->brianVisit = false;
	this->stormTrooperFood = false;
	this->stormTrooperDrink = false;
	this->stormTrooperVisit = false;
	this->wilmaFood = false;
	this->wilmaDrink = false;
	this->wilmaVisit = false;
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
int White::runRoom() {
	int choice = 1;
	cout << palette(4) << "You are in the White Room!" << palette(1) << "\n";
	if (getStrength() < 25) {
		cout << palette(4) << "You're looking a bit pale!" << palette(1) << "\n";
		boostStrength();
	}
	while (choice > 0 && choice <= 6) {
		choice = runCharacters();
		if (choice == 1) {
			choice = runController(1);	// MrWhite
		}
		else if (choice == 2) {
			choice = runController(2);	// Yeti
		}
		else if (choice == 3) {
			choice = runController(3);	// Brian
		}
		else if (choice == 4) {
			choice = runController(4);	// Cookie
		}
		else if (choice == 5) {
			choice = runController(5);	// Wilma
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
void White::boostStrength() {
	int answer = 0;
	cout << palette(4) << "Would you like a 3 point strength boost to keep playing?\n" << palette(1)
		<< "1. Yes!\n"
		<< "2. No, I hear that Heisenberger guy lives here!\n";
	while (!(cin >> answer) || answer < 1 || answer > 2) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(4)
			<< "Would you like a strength Boost to keep playing?\n" << palette(1)
			<< "1. Yes!\n"
			<< "2. No!\n";
	}
	if (answer == 1) {
		setStrength(3);
		cout << palette(4) << "New Strength = " << getStrength() << palette(1) << "\n";
	}
}


/*******************************************************************************
**			function runCharacters()
** Player chocie cout/cin input validation module. Returns an int for choice of
** character to visit to runController()
** Input: Player
** Output: int choice to local runController()
******************************************************************************/
int White::runCharacters() {
	int utter = 0;
	cout << "Which" << palette(4) << " White Room " << palette(1) << "character do you want to converse with?\n"
		<< "1. " << palette(4) << "Mr. White (Breaking Bad)" << palette(1) << "\n"
		<< "2. " << palette(4) << "Yeti (Monsters Inc.)" << palette(1) << "\n"
		<< "3. " << palette(4) << "Storm Trooper (StarWars)" << palette(1) << "\n"
		<< "4. " << palette(4) << "Brian (Family Guy)" << palette(1) << "\n"
		<< "5. " << palette(4) << "Wilma (Flintstones)" << palette(1) << "\n"
		<< "6. " << palette(9) << "Change Rooms now!" << palette(1) << "\n";
	while (!(cin >> utter) || utter < 1 || utter > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< "Which" << palette(4) << " White Room " << palette(1) << "character do you want to converse with?\n"
			<< "1. " << palette(4) << "Mr. White (Breaking Bad)" << palette(1) << "\n"
			<< "2. " << palette(4) << "Yeti (Monsters Inc.)" << palette(1) << "\n"
			<< "3. " << palette(4) << "Storm Trooper (StarWars)" << palette(1) << "\n"
			<< "4. " << palette(4) << "Brian (Family Guy)" << palette(1) << "\n"
			<< "5. " << palette(4) << "Wilma (Flintstones)" << palette(1) << "\n"
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
int White::runController(int in) {
	int arg = in;
	int choice1;
	int choice2;
	while (arg > 0 && arg < 7) {
		if (arg == 1) {			/**** Mr. White ****/
			while (arg == 1) {
				choice1 = playerAI();
				choice2 = runMrWhite(choice1);
				if (choice2 == 1) { setStrength(-1); }
				else if (choice2 == 2) { setStrength(-1); setMrWhiteFood(true); }
				else if (choice2 == 3) { setStrength(-1); setMrWhiteDrink(true); }
				else if (choice2 == 4) { setStrength(-1); }
				else if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				else if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 2) {		/**** Yeti ****/
			while (arg == 2) {
				choice1 = playerAI();
				choice2 = runYeti(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setYetiFood(true); }
				if (choice2 == 3) {
					if (getYetiDrink() == false) {
						setStrength(2);
						setYetiDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 3) {		/**** Storm Trooper ****/
			while (arg == 3) {
				choice1 = playerAI();
				choice2 = runStormTrooper(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setStormTrooperFood(true); }
				if (choice2 == 3) {
					if (getStormTrooperDrink() == false) {
						setStrength(15);
						setStormTrooperDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 4) {		/**** Brian ****/
			while (arg == 4) {
				choice1 = playerAI();
				choice2 = runBrian(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setBrianFood(true); }
				if (choice2 == 3) { setStrength(-10); setBrianDrink(true); }
				if (choice2 == 4) {
					setStrength(-1);
					if (getPPWhite() == false) {
						setPPWhite();
						cout << "\nThe " << palette(2) << " W " << palette(1) << palette(4)
							<< " Puzzle Piece " << palette(1) << "is in your Backpack!!\n\n";
					}
				}
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 5) {		/**** Wilma ****/
			while (arg == 5) {
				choice1 = playerAI();
				choice2 = runWilma(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) {
					if (getWilmaFood() == false) {
						setStrength(5);
						setWilmaFood(true);
					}
				}
				if (choice2 == 3) {
					if (getWilmaDrink() == false) {
						setStrength(15);
						setWilmaDrink(true);
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
int White::playerAI() {
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
	cout << "There's a " << palette(4) << "White" << palette(1) << " Character in front of you. Say:\n"
		<< "1. Greatings " << palette(4) << "White Room" << palette(1) << " Character!\n"
		<< "2. Do you have anything to eat?\n"
		<< "3. Do you have anything to drink?\n"
		<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
		<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
		<< "5. I'm going to visit a different " << palette(4) << "White Room" << palette(1) << " Character.\n"
		<< "6. " << palette(9) << "I'm changing rooms now!" << palette(1) << "\n";
	while (!(cin >> out) || out < 1 || out > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< palette(3) << "You're going to upset it!" << palette(1) << " What do you want to say?\n"
			<< "1. Greatings " << palette(4) << "White Room" << palette(1) << " Character!\n"
			<< "2. Do you have anything to eat?\n"
			<< "3. Do you have anything to drink?\n"
			<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
			<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
			<< "5. I'm going to visit a different " << palette(4) << "White Room" << palette(1) << " Character.\n"
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
int White::runMrWhite(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getMrWhiteVisit() == false) {
			cout << palette(4) << "Walter: ...your best course would be to tread lightly." << palette(1) << "\n";
			setMrWhiteVisit(true);
			out = 1;
		}
		else {
			cout << palette(4) << "Walter: Did Tuco send you?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getMrWhiteFood() == false) {
			cout << palette(4) << "Walter: El Pollo's has something for you!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(4) << "Walter: You've already had three entire bags of Funyuns?" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getMrWhiteDrink() == false) {
			cout << palette(4) << "Walter: Stay out of my territory." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(4) << "Walter: I don't imagine you'll be here long." << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(4) << "Walter: I only have Blue pieces." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(4) << "Walter: We're done when I say we're done." << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(4) << "Walter: It's over, I won!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int White::runYeti(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getYetiVisit() == false) {
			cout << palette(4) << "Yeti: Welcome to the Himalayas!" << palette(1) << "\n";
			setYetiVisit(true);
			out = 1;
		}
		else {
			cout << palette(4) << "Yeti: Did you see me with Rudolph?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getYetiFood() == false) {
			cout << palette(4) << "Yeti: I don't even have have children's screams any more! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(4) << "Yeti: No, try Sully! Another -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getYetiDrink() == false) {
			cout << palette(4) << "Yeti: Lemon Snow Cone? +2 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(4) << "Yeti: It's possibly not lemon!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(4) << "Yeti: I have a lot of white snow, but no White Puzzle Piece." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(4) << "Yeti: Do I look abominable?" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(4) << "Yeti: Wait, how about Agreeable Snowman?" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int White::runBrian(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getBrianVisit() == false) {
			cout << palette(4) << "Brian: Let's start with polite conversation." << palette(1) << "\n";
			setBrianVisit(true);
			out = 1;
		}
		else {
			cout << palette(4) << "Brian: Just for the heck of it, let's try it again" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getBrianFood() == false) {
			cout << palette(4) << "Brian: I'm dieting after all the chocolate. -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(4) << "Brian: You don't know how to haggle.  -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getBrianDrink() == false) {
			cout << palette(4) << "Brian: I only have my Martini! -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(4) << "Brian: We're out of gin, again! Another -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		if (getPPWhite() == false) {
			cout << palette(4) << "Brian: Swing and a miss. I jest, here you go!" << palette(1) << "\n";
			out = 4;
		}
		else {
			cout << palette(4) << "Brian: I have a date, be on your way!" << palette(1) << "\n";
		}
	}
	else if (inMessage == 5) {
		cout << palette(4) << "Brian: Call me!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(4) << "Brian: Sorry I'm late. Did I miss anything?" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int White::runStormTrooper(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getStormTrooperVisit() == false) {
			cout << palette(4) << "Storm Trooper: TK-421 at my post!" << palette(1) << "\n";
			setStormTrooperVisit(true);
			out = 1;
		}
		else {
			cout << palette(4) << "Storm Trooper: He's your brother? That's just weird!" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getStormTrooperFood() == false) {
			cout << palette(4) << "Storm Trooper: Wookie Steak, but it's a little chewy. -5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(4) << "Storm Trooper: Keep chewing! Another -5 Strength." << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getStormTrooperDrink() == false) {
			cout << palette(4) << "Storm Trooper: Yes, here is some Bantha milk. +15 Stregth." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(4) << "Storm Trooper: The rebels took the Bantha! No milk for you!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(4) << "Storm Trooper: Jabba the Hut got it!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(4) << "Storm Trooper: Don't blame you, management is overbearing on this Death Star!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(4) << "Storm Trooper: Are we the bad guy's or are they?" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int White::runWilma(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getWilmaVisit() == false) {
			cout << palette(4) << "Wilma: That Betty Rubble sent you, didn't she?" << palette(1) << "\n";
			setWilmaVisit(true);
			out = 1;
		}
		else {
			cout << palette(4) << "Wilma: Betty's been wearing that same Cyan colored dress for years." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getWilmaFood() == false) {
			cout << palette(4) << "Wilma: Brontosaurus Burger, just for you! +5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(4) << "Wilma: Fred got the last of the gravelberry pie." << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getWilmaDrink() == false) {
			cout << palette(4) << "Wilma: Yes, here is some Yabba Dabba Dew. +15 Strength." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(4) << "Wilma: No, you've finished the lot!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(4) << "Wilma: I only have rocks, I'm afraid!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(4) << "Wilma: Send that Rock Hudson fellow over!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(4) << "Wilma: I'll be in Bedrock!" << palette(1) << "\n";
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
void White::setMrWhiteVisit(bool visit) {
	this->mrWhiteVisit = visit;
}

bool White::getMrWhiteVisit() {
	return mrWhiteVisit;
}

void White::setMrWhiteFood(bool mrWhiteFood) {
	this->mrWhiteFood = mrWhiteFood;
}

bool White::getMrWhiteFood() {
	return mrWhiteFood;
}

void White::setMrWhiteDrink(bool mrWhiteDrink) {
	this->mrWhiteDrink = mrWhiteDrink;
}

bool White::getMrWhiteDrink() {
	return mrWhiteDrink;
}


void White::setYetiVisit(bool visit) {
	this->yetiVisit = visit;
}

bool White::getYetiVisit() {
	return yetiVisit;
}

void White::setYetiFood(bool yetiFood) {
	this->yetiFood = yetiFood;
}

bool White::getYetiFood() {
	return yetiFood;;
}

void White::setYetiDrink(bool yetiDrink) {
	this->yetiDrink = yetiDrink;
}

bool White::getYetiDrink() {
	return yetiDrink;
}


void White::setBrianVisit(bool visit) {
	this->brianVisit = visit;
}

bool White::getBrianVisit() {
	return brianVisit;
}

void White::setBrianFood(bool brianFood) {
	this->brianFood = brianFood;
}

bool White::getBrianFood() {
	return brianFood;
}

void White::setBrianDrink(bool brianDrink) {
	this->brianDrink = brianDrink;
}

bool White::getBrianDrink() {
	return brianDrink;
}


void White::setStormTrooperVisit(bool visit) {
	this->stormTrooperVisit = visit;
}

bool White::getStormTrooperVisit() {
	return stormTrooperVisit;
}

void White::setStormTrooperFood(bool stormTrooperFood) {
	this->stormTrooperFood = stormTrooperFood;
}

bool White::getStormTrooperFood() {
	return stormTrooperFood;
}

void White::setStormTrooperDrink(bool stormTrooperDrink) {
	this->stormTrooperDrink = stormTrooperDrink;
}

bool White::getStormTrooperDrink() {
	return stormTrooperDrink;
}


void White::setWilmaVisit(bool visit) {
	this->wilmaVisit = visit;
}

bool White::getWilmaVisit() {
	return wilmaVisit;
}

void White::setWilmaFood(bool wilmaFood) {
	this->wilmaFood = wilmaFood;
}

bool White::getWilmaFood() {
	return wilmaFood;
}

void White::setWilmaDrink(bool wilmaDrink) {
	this->wilmaDrink = wilmaDrink;
}

bool White::getWilmaDrink() {
	return wilmaDrink;
}


/*******************************************************************************
**			function set Color() 6 each
** Setters for the 6 rooms other than this one.  This is how a player can
** travel between rooms. Called and used by ThrowBack.cpp
** Input: Space* for each individual room.
** Output: void.
******************************************************************************/
void White::setBlue(Space *ptr) {
	W_Blue = ptr;
}

void White::setYellow(Space *ptr) {
	W_Yellow = ptr;
}

void White::setCyan(Space *ptr) {
	W_Cyan = ptr;
}

void White::setGreen(Space *ptr) {
	W_Green = ptr;
}

void White::setRed(Space *ptr) {
	W_Red = ptr;
}

void White::setMagenta(Space *ptr) {
	W_Magenta = ptr;
}
