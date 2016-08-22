/****************************************************************************************
** Program Filename: Blue.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/17/2016
** Description: Contains the Blue class definition file.
** Input: exitGame() takes 6 Space pointers for linking rooms.
** Output: Linked to all ThrowBack derived classes.
*****************************************************************************************/
#include "Blue.hpp"
#include <string>
using std::string;
#include<iostream>
using std::cout;
using std::cin;


/*******************************************************************************
**						function set'Color'Pointers()
** Sets color pointers to all other rooms.  Called from ThrowBack.cpp main()
** Input: Space class color pointers other than this class.
** Output:void
******************************************************************************/
void Blue::setBluePtrs(Space* yellow, Space* cyan, Space* green, Space* red, Space* magenta, Space* white) {
	setYellow(yellow);
	setCyan(cyan);
	setGreen(green);
	setRed(red);
	setMagenta(magenta);
	setWhite(white);
	setPPBlue(false);
	setStrength();
	initCharBools();
}

// Destructor.
Blue::~Blue(){
	B_Yellow = NULL;
	B_Cyan = NULL;
	B_Green = NULL;
	B_Red = NULL;
	B_Magenta = NULL;
	B_White = NULL;
}


/*******************************************************************************
**						function setTrngth() 3 each.
** Setters for stregth. setStrength() for initialization, setSTregth(int) for
** updating local room strength changes. getStrength for logic control, and
** acceptStrength() sets overall current Player strength upon Player entry to 
** this room.  acceptSTrength() also returns current Player to ThrowBack.cpp for
** use as Player enters other rooms or re-enters this room.
** Input: acceptStregnth() current strength int from Throwback.cpp
** Output: sets local stregth int.
******************************************************************************/
void Blue::setStrength() {
	this->strength = 0;
}

void Blue::setStrength(int strength) {
	this->strength = getStrength() + strength;
}

int Blue::getStrength() {
	return strength;
}

// Throwback passes overall Player strength for update here.
int Blue::acceptStrength(int strength){
	this->strength = strength;
}


/*******************************************************************************
**					function setPPColor() 3 each.
** Initializes Player color puzzle piece, logic control locally to ths room, and 
** getPPBlue used by ThrowBack.cpp for logic control and displayBP()
** Input: bool to initialize and set when Player finds color puzzle piece.
** Output:
******************************************************************************/
void Blue::setPPBlue(bool f) {
	this->pPiece = f;
}

void Blue::setPPBlue() {
	this->pPiece = true;
}

bool Blue::getPPBlue() {
	return pPiece;
}


/*******************************************************************************
**						function initCharBools()
** Initializes individual characters variables at room initializaton.
******************************************************************************/
void Blue::initCharBools() {
	this->sullyFood = false;
	this->sullyDrink = false;
	this->sullyVisit = false;
	this->clawsFood = false;
	this->clawsDrink = false;
	this->clawsVisit = false;
	this->naviFood = false;
	this->naviDrink = false;
	this->naviVisit = false;
	this->cookieMonsterFood = false;
	this->cookieMonsterDrink = false;
	this->cookieMonsterVisit = false;
	this->bobBlobFood = false;
	this->bobBlobDrink = false;
	this->bobBlobVisit = false;
}


/*******************************************************************************
**						function runRoom()
** Virtual function used by Throwback.cpp main logic loop. Calls to this function
** initiates runCharacters() for Player to choosw which character to visit, calls
** the special virtual funtion boostStregnth(), and calls the local runController() 
** function appropriately in a loop until Player exits room.
** Input: Player input
** Output: callse to boostStrength and runController with chocie parameter set.
******************************************************************************/
int Blue::runRoom() {
	int choice = 1;
	cout << palette(24) << "You are in the Blue Room!" << palette(1) << "\n";
	if (getStrength() < 25) {
		cout << palette(24) << "You're looking a bit weak!" << palette(1) << "\n";
		boostStrength();
	}
	while (choice > 0 && choice <= 6) {
		choice = runCharacters();
		if (choice == 1) {
			choice = runController(1);	// Sully
		}
		else if (choice == 2) {
			choice = runController(2);	// Claws
		}
		else if (choice == 3) {
			choice = runController(3);	// Navi
		}
		else if (choice == 4) {
			choice = runController(4);	// Cookie
		}
		else if (choice == 5) {
			choice = runController(5);	// BobBlob
		}
		else if (choice == 0 || choice == 6) {
			break;
		}
	}
	return 8;
}


/*******************************************************************************
**						function boostStrength()
** Pure virtual function that ascertains and offers a strength boost for a 
** Player whose stregnth is below 25.  Calls local setStregnth() with int
** paramter set.
** Input: Player
** Output: void, call to setStrength(20)
******************************************************************************/
void Blue::boostStrength() {
	int answer = 0;
	cout << palette(24) << "Would you like a 21 point strength boost to keep playing?\n" << palette(1)
		<< "1. Yes!\n"
		<< "2. What? In our moment of triumph? NO!\n";
	while (!(cin >> answer) || answer < 1 || answer > 2) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(24)
			<< "Would you like a strength Boost to keep playing?\n" << palette(1)
			<< "1. Yes!\n"
			<< "2. No!\n";
	}
	if (answer == 1) {
		setStrength(21);
		cout << palette(24) << "New Strength = " << getStrength() << palette(1) << "\n";
	}
}


/*******************************************************************************
**						function runCharacters()
** Player chocie cout/cin input validation module. Returns an int for choice of
** character to visit to runController()
** Input: Player
** Output: int choice to local runController()
******************************************************************************/
int Blue::runCharacters() {
	int utter = 0;
	cout << "Which" << palette(24) << " Blue Room " << palette(1) << "character do you want to converse with?\n"
		<< "1. " << palette(24) << "Sully (Monsters Inc.)" << palette(1) << "\n"
		<< "2. " << palette(24) << "Claws (Monsters Inc.)" << palette(1) << "\n"
		<< "3. " << palette(24) << "A Pandorian Na'vi (Avatar)" << palette(1) << "\n"
		<< "4. " << palette(24) << "Cookie Monster (Sesame Street)" << palette(1) << "\n"
		<< "5. " << palette(24) << "Bob the Blob (Monsters vs. Aliens: Cloning Around)" << palette(1) << "\n"
		<< "6. " << palette(9) << "Change Rooms now!" << palette(1) << "\n";
	while (!(cin >> utter) || utter < 1 || utter > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< "Which" << palette(24) << " Blue Room " << palette(1) << "character do you want to converse with?\n"
			<< "1. " << palette(24) << "Sully (Monsters Inc.)" << palette(1) << "\n"
			<< "2. " << palette(24) << "Claws (Monsters Inc.)" << palette(1) << "\n"
			<< "3. " << palette(24) << "A Pandorian Na'vi (Avatar)" << palette(1) << "\n"
			<< "4. " << palette(24) << "Cookie Monster (Sesame Street)" << palette(1) << "\n"
			<< "5. " << palette(24) << "Bob the Blob (Monsters vs. Aliens: Cloning Around)" << palette(1) << "\n"
			<< "6. " << palette(9) << "Change Rooms now!" << palette(1) << "\n";
	}
	return utter;
}


/*******************************************************************************
**						function runController()
** Main contol module for room.  Calls, sets, and manages program control as 
** Plyer navigates characters responses to PlayerAI() generted query.
** Input: int arg from runCharacters()
** Output: int arg to runRoom() charcter control function. 
******************************************************************************/
int Blue::runController(int in) {
	int arg = in;
	int choice1;
	int choice2;
	while (arg > 0 && arg < 7) {
		if (arg == 1) {				/**** Sully ****/
			while (arg == 1) {
				choice1 = playerAI();
				choice2 = runSully(choice1);
				if (choice2 == 1) { setStrength(-1); }
				else if (choice2 == 2) { setStrength(-1); setSullyFood(true); }
				else if (choice2 == 3) { setStrength(-1); setSullyDrink(true); }
				else if (choice2 == 4) { setStrength(-1); }
				else if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				else if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 2) {		/**** Claws ****/
			while (arg == 2) {
				choice1 = playerAI();
				choice2 = runClaws(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setClawsFood(true); }
				if (choice2 == 3) {
					if (getClawsDrink() == false) {
						setStrength(2);
						setClawsDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 3) {		/**** Navi ****/
			while (arg == 3) {
				choice1 = playerAI();
				choice2 = runNavi(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setNaviFood(true); }
				if (choice2 == 3) { setStrength(-10); setNaviDrink(true); }
				if (choice2 == 4) {
					setStrength(-1);
					if (getPPBlue() == false) {
						setPPBlue();
						cout << "\nThe " << palette(22) << " B " << palette(1) << palette(24)
							<< " Puzzle Piece " << palette(1) << "is in your Backpack!!\n\n";
					}
				}
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 4) {		/**** Cookie Monster ****/
			while (arg == 4) {
				choice1 = playerAI();
				choice2 = runCookieMonster(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setCookieMonsterFood(true); }
				if (choice2 == 3) {
					if (getCookieMonsterDrink() == false) {
						setStrength(15);
						setCookieMonsterDrink(true);
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
				choice2 = runBobBlob(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) {
					if (getBobBlobFood() == false) {
						setStrength(5);
						setBobBlobFood(true);
					}
				}
				if (choice2 == 3) {
					if (getBobBlobDrink() == false) {
						setStrength(15);
						setBobBlobDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
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
**						function playerAI()
** Player's query module for asking questions to each character as selected by
** Player. Returns int arg for run CharacterName().
** Input: Player out arg selected.
** Output: int out as chosed by Player.
******************************************************************************/
int Blue::playerAI() {
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
	cout << "There's a " << palette(24) << "Blue" << palette(1) << " Character in front of you. Say:\n"
		<< "1. Greatings " << palette(24) << "Blue Room" << palette(1) << " Character!\n"
		<< "2. Do you have anything to eat?\n"
		<< "3. Do you have anything to drink?\n"
		<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
		<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
		<< "5. I'm going to visit a different " << palette(24) << "Blue Room" << palette(1) << " Character.\n"
		<< "6. " << palette(9) << "I'm changing rooms now!" << palette(1) << "\n";
	while (!(cin >> out) || out < 1 || out > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< palette(3) << "You're going to upset it!" << palette(1) << " What do you want to say?\n"
			<< "1. Greatings " << palette(24) << "Blue Room" << palette(1) << " Character!\n"
			<< "2. Do you have anything to eat?\n"
			<< "3. Do you have anything to drink?\n"
			<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
			<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
			<< "5. I'm going to visit a different " << palette(24) << "Blue Room" << palette(1) << " Character.\n"
			<< "6. " << palette(9) << "I'm changing rooms now!" << palette(1) << "\n";
	}
	return out;
}


/***************************************************************************************************************
**						function run Characters() 5 each.
** Indivdual character responses to PlayerAI query. Player is assesed and awarded points based upon query and 
** characters call stack in runController()
** Input: PlayerAI query choice.
** Output: reutrns int response to runController()
***************************************************************************************************************/
int Blue::runSully(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getSullyVisit() == false) {
			cout << palette(24) << "Sully: I am Sulley from Monsters Inc. What do you seek?" << palette(1) << "\n";
			setSullyVisit(true);
			out = 1;
		}
		else {
			cout << palette(24) << "Sully: I have a lot of kids to scare! What do you seek?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getSullyFood() == false) {
			cout << palette(24) << "Sully: I have nothing for you to eat!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(24) << "Sully: I already told you I have nothing for you to eat!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getSullyDrink() == false) {
			cout << palette(24) << "Sully: I have nothing for you to drink!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(24) << "Sully: You're not very bright! No drink for you!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(24) << "Sully: I do not have the Blue Room Puzzle Piece!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(24) << "Sully: See ya!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(24) << "Sully: You'll be back!!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Blue::runClaws(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getClawsVisit() == false) {
			cout << palette(24) << "Claws: I am Claws, from Monsters Inc. How can I assist you?" << palette(1) << "\n";
			setClawsVisit(true);
			out = 1;
		}
		else {
			cout << palette(24) << "Claws: Back again? What do you seek?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getClawsFood() == false) {
			cout << palette(24) << "Claws: I only have children's screams for you to eat! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(24) << "Claws: I already told you I have nothing for you to eat! Another -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getClawsDrink() == false) {
			cout << palette(24) << "Claws: I have a glass of cold sweat for you to drink! +2 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(24) << "Claws: I already gave you a drink! No more for you!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(24) << "Claws: I do not have the Blue Room Puzzle Piece." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(24) << "Claws: So long!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(24) << "Claws: I'll be waiting for you, in your closet, tonight!!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Blue::runNavi(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getNaviVisit() == false) {
			cout << palette(24) << "I am a Na'vi from planet Pandora. What brings you to the blue room, " << palette(4) << "Human?" << palette(1) << "\n";
			setNaviVisit(true);
			out = 1;
		}
		else {
			cout << palette(24) << "Why are you here again, " << palette(4) << "Human?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getNaviFood() == false) {
			cout << palette(24) << "Na'vi: My food is poison to you! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(24) << "Na'vi: You must be very hungry. My food is poison!\nAnother -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getNaviDrink() == false) {
			cout << palette(24) << "Na'vi: My drink is poison to you! -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(24) << "Na'vi: What is it about you Humans? My drink is poison! Another -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		if (getPPBlue() == false) {
			cout << palette(24) << "Na'vi: Yes, I have the Puzzle Piece. I've placed it in your backpack for you!" << palette(1) << "\n";
			out = 4;
		}
		else {
			cout << palette(24) << "Na'vi: You have what you seek, go from this place!" << palette(1) << "\n";
		}
	}
	else if (inMessage == 5) {
		cout << palette(24) << "Na'vi: Be gone, puny Human!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(24) << "Na'vi: May a Galactonotus Viperwolf dine on your carcass!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Blue::runCookieMonster(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getCookieMonsterVisit() == false) {
			cout << palette(24) << "Cookie Monster: I am Cookie Monster from Seasame Street! You're rather old\n"
				<< "for me!" << palette(1) << "\n";
			setCookieMonsterVisit(true);
			out = 1;
		}
		else {
			cout << palette(24) << "Cookie Monster: Back on Sesame Street again?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getCookieMonsterFood() == false) {
			cout << palette(24) << "Cookie Monster: No Cookie For You! -5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(24) << "Cookie Monster: NO COOKIE FOR YOU! Another -5 Strength." << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getCookieMonsterDrink() == false) {
			cout << palette(24) << "Cookie Monster: Yes, here is some warm milk. +15 Stregth." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(24) << "Cookie Monster: The milk has soured! No milk for you!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(24) << "Cookie Monster: I only have cookies and milk, no Puzzle Piece for you!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(24) << "Cookie Monster: Come back soon!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(24) << "Cookie Monster: Bring me Cookies!!!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Blue::runBobBlob(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getBobBlobVisit() == false) {
			cout << palette(24) << "B.O.B: I am B.O.B. the Blob from Monsters vs. Aliens: Cloning Around!" << palette(1) << "\n";
			setBobBlobVisit(true);
			out = 1;
		}
		else {
			cout << palette(24) << "B.O.B: I'm busy jiggling the jello, what-da-ya-want?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getBobBlobFood() == false) {
			cout << palette(24) << "B.O.B: Yes, here is some Jiggly Jello to eat. +5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(24) << "B.O.B: You've eaten the Jiggly Jello. The rest is mine!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getBobBlobDrink() == false) {
			cout << palette(24) << "B.O.B: Yes, here is some Benzoate Ostylezene Bicarbonate. +15 Strength." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(24) << "B.O.B: No,, the Benzoate Ostylezene Bicarbonate is all gone!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(24) << "B.O.B: I DO! ...NOT have the puzzle piece for you!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(24) << "B.O.B: I'll be visiting you soon!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(24) << "B.O.B: Oh! I just scared myself!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


/*******************************************************************************
**						function set Bools() 30 each
** Individual getter and setter functions for each character. Used chiefly by
** runContoller() locally but also by ThrowBack.cpp
** Input: various bool per character queried.
** Output: various bool per character response..
******************************************************************************/
void Blue::setSullyVisit(bool visit) {
	this->sullyVisit = visit;
}

bool Blue::getSullyVisit() {
	return sullyVisit;
}

void Blue::setSullyFood(bool sullyFood) {
	this->sullyFood = sullyFood;
}

bool Blue::getSullyFood() {
	return sullyFood;
}

void Blue::setSullyDrink(bool sullyDrink) {
	this->sullyDrink = sullyDrink;
}

bool Blue::getSullyDrink() {
	return sullyDrink;
}


void Blue::setClawsVisit(bool visit) {
	this->clawsVisit = visit;
}

bool Blue::getClawsVisit() {
	return clawsVisit;
}

void Blue::setClawsFood(bool clawsFood) {
	this->clawsFood = clawsFood;
}

bool Blue::getClawsFood() {
	return clawsFood;;
}

void Blue::setClawsDrink(bool clawsDrink) {
	this->clawsDrink = clawsDrink;
}

bool Blue::getClawsDrink() {
	return clawsDrink;
}


void Blue::setNaviVisit(bool visit) {
	this->naviVisit = visit;
}

bool Blue::getNaviVisit() {
	return naviVisit;
}

void Blue::setNaviFood(bool naviFood) {
	this->naviFood = naviFood;
}

bool Blue::getNaviFood() {
	return naviFood;
}

void Blue::setNaviDrink(bool naviDrink) {
	this->naviDrink = naviDrink;
}

bool Blue::getNaviDrink() {
	return naviDrink;
}


void Blue::setCookieMonsterVisit(bool visit) {
	this->cookieMonsterVisit = visit;
}

bool Blue::getCookieMonsterVisit() {
	return cookieMonsterVisit;
}

void Blue::setCookieMonsterFood(bool cookieMonsterFood) {
	this->cookieMonsterFood = cookieMonsterFood;
}

bool Blue::getCookieMonsterFood() {
	return cookieMonsterFood;
}

void Blue::setCookieMonsterDrink(bool cookieMonsterDrink) {
	this->cookieMonsterDrink = cookieMonsterDrink;
}

bool Blue::getCookieMonsterDrink() {
	return cookieMonsterDrink;
}


void Blue::setBobBlobVisit(bool visit) {
	this->bobBlobVisit = visit;
}

bool Blue::getBobBlobVisit() {
	return bobBlobVisit;
}

void Blue::setBobBlobFood(bool bobBlobFood) {
	this->bobBlobFood = bobBlobFood;
}

bool Blue::getBobBlobFood() {
	return bobBlobFood;
}

void Blue::setBobBlobDrink(bool bobBlobDrink) {
	this->bobBlobDrink = bobBlobDrink;
}

bool Blue::getBobBlobDrink() {
	return bobBlobDrink;
}

/*******************************************************************************
**						function set Color() 6 each
** Setters for the 6 rooms other than this one.  This is how a player can 
** travel between rooms. Called and used by ThrowBack.cpp
** Input: Space* for each individual room.
** Output: void.
******************************************************************************/
void Blue::setYellow(Space *ptr){
	B_Yellow = ptr;
}

void Blue::setCyan(Space *ptr) {
	B_Cyan = ptr;
}

void Blue::setGreen(Space *ptr) {
	B_Green = ptr;
}

void Blue::setRed(Space *ptr) {
	B_Red = ptr;
}

void Blue::setMagenta(Space *ptr) {
	B_Magenta = ptr;
}

void Blue::setWhite(Space *ptr) {
	B_White = ptr;
}