/****************************************************************************************
** Program Filename: Cyan.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/17/2016
** Description: Contains the Cyan class definition file.
** Input: exitGame() takes 6 Space pointers for linking rooms.
** Output: Linked to all ThrowBack derived classes.
*****************************************************************************************/
#include "Cyan.hpp"
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
void Cyan::setCyanPtrs(Space* blue, Space* yellow, Space* green, Space* red, Space* magenta, Space* white) {
	setBlue(blue);
	setYellow(yellow);
	setGreen(green);
	setRed(red);
	setMagenta(magenta);
	setWhite(white);
	setPPCyan(false);
	setStrength();
	initCharBools();
}

// Destructor.
Cyan::~Cyan() {
	C_Blue = NULL;
	C_Yellow = NULL;
	C_Green = NULL;
	C_Red = NULL;
	C_Magenta = NULL;
	C_White = NULL;
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
void Cyan::setStrength() {
	this->strength = 0;
}

void Cyan::setStrength(int strength) {
	this->strength = getStrength() + strength;
}

int Cyan::getStrength() {
	return strength;
}

// Throwback passes overall Player strength for update here.
int Cyan::acceptStrength(int strength) {
	this->strength = strength;
}


/*******************************************************************************
**					function setPPColor() 3 each.
** Initializes Player color puzzle piece, logic control locally to ths room, and
** getPPBlue used by ThrowBack.cpp for logic control and displayBP()
** Input: bool to initialize and set when Player finds color puzzle piece.
** Output:
******************************************************************************/
void Cyan::setPPCyan(bool f) {
	this->pPiece = f;
}

void Cyan::setPPCyan() {
	this->pPiece = true;
}

bool Cyan::getPPCyan() {
	return pPiece;
}


/*******************************************************************************
**						function initCharBools()
** Initializes individual characters variables at room initializaton.
******************************************************************************/
void Cyan::initCharBools() {
	this->inkyFood = false;
	this->inkyDrink = false;
	this->inkyVisit = false;
	this->bruceFood = false;
	this->bruceDrink = false;
	this->bruceVisit = false;
	this->elsaFood = false;
	this->elsaDrink = false;
	this->elsaVisit = false;
	this->huckleBerryHoundFood = false;
	this->huckleBerryHoundDrink = false;
	this->huckleBerryHoundVisit = false;
	this->bettyRubbleFood = false;
	this->bettyRubbleDrink = false;
	this->bettyRubbleVisit = false;
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
int Cyan::runRoom() {
	int choice = 1;
	cout << palette(34) << "You are in the Cyan Room!" << palette(1) << "\n";
	if (getStrength() < 25) {
		cout << palette(34) << "You're have a pale blue tint about you!" << palette(1) << "\n";
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
**						function boostStrenght()
** Pure virtual function that ascertains and offers a strength boost for a
** Player whose stregnth is below 25.  Calls local setStregnth() with int
** paramter set.
** Input: Player
** Output: void, call to setStrength(20)
******************************************************************************/
void Cyan::boostStrength() {
	int answer = 0;
	cout << palette(34) << "Would you like a 15 point strength boost to keep playing?\n" << palette(1)
		<< "1. Yes!\n"
		<< "2. We don't need no education!\n";
	while (!(cin >> answer) || answer < 1 || answer > 2) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(34)
			<< "Would you like a strength Boost to keep playing?\n" << palette(1)
			<< "1. Yes!\n"
			<< "2. No!\n";
	}
	if (answer == 1) {
		setStrength(15);
		cout << palette(34) << "New Strength = " << getStrength() << palette(1) << "\n";
	}
}


/*******************************************************************************
**						function runCharacters()
** Player chocie cout/cin input validation module. Returns an int for choice of
** character to visit to runController()
** Input: Player
** Output: int choice to local runController()
******************************************************************************/
int Cyan::runCharacters() {
	int utter = 0;
	cout << "Which" << palette(34) << " Cyan Room " << palette(1) << "character do you want to converse with?\n"
		<< "1. " << palette(34) << "Inky (Pacman)" << palette(1) << "\n"
		<< "2. " << palette(34) << "Elsa (Frozen)" << palette(1) << "\n"
		<< "3. " << palette(34) << "Bruce (Finding Nemo)" << palette(1) << "\n"
		<< "4. " << palette(34) << "Huckleberry Hound" << palette(1) << "\n"
		<< "5. " << palette(34) << "Betty Rubble (Flintstones)" << palette(1) << "\n"
		<< "6. " << palette(9) << "Change Rooms now!" << palette(1) << "\n";
	while (!(cin >> utter) || utter < 1 || utter > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< "Which" << palette(34) << " Cyan Room " << palette(1) << "character do you want to converse with?\n"
			<< "1. " << palette(34) << "Inky (Pacman)" << palette(1) << "\n"
			<< "2. " << palette(34) << "Elsa (Frozen)" << palette(1) << "\n"
			<< "3. " << palette(34) << "Bruce (Finding Nemo)" << palette(1) << "\n"
			<< "4. " << palette(34) << "Huckleberry Hound" << palette(1) << "\n"
			<< "5. " << palette(34) << "Betty Rubble (Flintstones)" << palette(1) << "\n"
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
int Cyan::runController(int in) {
	int arg = in;
	int choice1;
	int choice2;
	while (arg > 0 && arg < 7) {
		if (arg == 1) {				/**** Inky ****/
			while (arg == 1) {
				choice1 = playerAI();
				choice2 = runInky(choice1);
				if (choice2 == 1) { setStrength(-1); }
				else if (choice2 == 2) { setStrength(-1); setInkyFood(true); }
				else if (choice2 == 3) { setStrength(-1); setInkyDrink(true); }
				else if (choice2 == 4) { setStrength(-1); }
				else if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				else if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 2) {		/**** Elsa ****/
			while (arg == 2) {
				choice1 = playerAI();
				choice2 = runElsa(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setElsaFood(true); }
				if (choice2 == 3) { setStrength(-10); setElsaDrink(true); }
				if (choice2 == 4) {
					setStrength(-1);
					if (getPPCyan() == false) {
						setPPCyan();
						cout << "\nThe " << palette(32) << " C " << palette(1) << palette(34)
							<< " Puzzle Piece " << palette(1) << "is in your Backpack!!\n\n";
					}
				}
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 3) {		/**** Bruce ****/
			while (arg == 3) {
				choice1 = playerAI();
				choice2 = runBruce(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setBruceFood(true); }
				if (choice2 == 3) {
					if (getBruceDrink() == false) {
						setStrength(2);
						setBruceDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 4) {		/**** HuckleBerry Hound ****/
			while (arg == 4) {
				choice1 = playerAI();
				choice2 = runHuckleBerryHound(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setHuckleBerryHoundFood(true); }
				if (choice2 == 3) {
					if (getHuckleBerryHoundDrink() == false) {
						setStrength(15);
						setHuckleBerryHoundDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 5) {		/**** Betty Rubble ****/
			while (arg == 5) {
				choice1 = playerAI();
				choice2 = runBettyRubble(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) {
					if (getBettyRubbleFood() == false) {
						setStrength(5);
						setBettyRubbleFood(true);
					}
				}
				if (choice2 == 3) {
					if (getBettyRubbleDrink() == false) {
						setStrength(15);
						setBettyRubbleDrink(true);
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
int Cyan::playerAI() {
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
	cout << "There's a " << palette(34) << "Cyan" << palette(1) << " Character in front of you. Say:\n"
		<< "1. Greatings " << palette(34) << "Cyan Room" << palette(1) << " Character!\n"
		<< "2. Do you have anything to eat?\n"
		<< "3. Do you have anything to drink?\n"
		<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
		<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
		<< "5. I'm going to visit a different " << palette(34) << "Cyan Room" << palette(1) << " Character.\n"
		<< "6. " << palette(9) << "I'm changing rooms now!" << palette(1) << "\n";
	while (!(cin >> out) || out < 1 || out > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< palette(3) << "You're going to upset it!" << palette(1) << " What do you want to say?\n"
			<< "1. Greatings " << palette(34) << "Cyan Room" << palette(1) << " Character!\n"
			<< "2. Do you have anything to eat?\n"
			<< "3. Do you have anything to drink?\n"
			<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
			<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
			<< "5. I'm going to visit a different " << palette(34) << "Cyan Room" << palette(1) << " Character.\n"
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
int Cyan::runInky(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getInkyVisit() == false) {
			cout << palette(34) << "Inky: Hello, hurry, the ghost is coming!" << palette(1) << "\n";
			setInkyVisit(true);
			out = 1;
		}
		else {
			cout << palette(34) << "Inky: The ghost, run!!" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getInkyFood() == false) {
			cout << palette(34) << "Inky: There's no food here, I'm a memory leak!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(34) << "Inky: No, and you'd better go, the ghost'll getcha!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getInkyDrink() == false) {
			cout << palette(34) << "Inky: Not with the elctronics, dude!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(34) << "Inky: Not again?!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(34) << "Inky: No, but the ghost might, if he doesn't chomp you first." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(34) << "Inky: Give the guy a break Clyde!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(34) << "Inky: Ooh, I never knew I had such big feet! " << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Cyan::runBruce(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getBruceVisit() == false) {
			cout << palette(34) << "Bruce: I am a nice shark, not a mindless eating machine." << palette(1) << "\n";
			setBruceVisit(true);
			out = 1;
		}
		else {
			cout << palette(34) << "Bruce: Keep it up, I could change!" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getBruceFood() == false) {
			cout << palette(34) << "Bruce: You are food to me!! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(34) << "Bruce: And I'm mindlessly hungry! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getBruceDrink() == false) {
			cout << palette(34) << "Bruce:  Have some nice seawater. +2 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(34) << "Bruce: Too much salt isn't good for you!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(34) << "Bruce: I do not have the Cyan Room Puzzle Piece." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(34) << "Bruce: For a clown fish, you're not that funny. " << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(34) << "Bruce: Good on ya, mate!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Cyan::runElsa(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getElsaVisit() == false) {
			cout << palette(34) << "Elsa: I wanna build a snowman!" << palette(1) << "\n";
			setElsaVisit(true);
			out = 1;
		}
		else {
			cout << palette(34) << "Elsa: There's so much fear here!" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getElsaFood() == false) {
			cout << palette(34) << "Elsa: It's frozen, sorry! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(34) << "Elsa: You have to try harder! -5 Strength!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getElsaDrink() == false) {
			cout << palette(34) << "Elsa: We haven't had a thaw in decades. -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(34) << "Elsa: No, what were you expecting, so sorry! -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		if (getPPCyan() == false) {
			cout << palette(34) << "Elsa: Yes, I have the Puzzle Piece. I've placed it in your backpack for you!" << palette(1) << "\n";
			out = 4;
		}
		else {
			cout << palette(34) << "Elsa: You have what you seek, time is short!" << palette(1) << "\n";
		}
	}
	else if (inMessage == 5) {
		cout << palette(34) << "Elsa: And now you're gone!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(34) << "Elsa: Beware the frozen heart!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Cyan::runHuckleBerryHound(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getHuckleBerryHoundVisit() == false) {
			cout << palette(34) << "Huckleberry Hound: Hello, would you like to hear \"Clmentine\"?" << palette(1) << "\n";
			setHuckleBerryHoundVisit(true);
			out = 1;
		}
		else {
			cout << palette(34) << "Huckleberry Hound: Loveth me, loveth my hound." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getHuckleBerryHoundFood() == false) {
			cout << palette(34) << "Huckleberry Hound: Only got this dry dog food from Brian. -5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(34) << "Hucklebearry Hound: Sorry, very dry! Another -5 Strength." << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getHuckleBerryHoundDrink() == false) {
			cout << palette(34) << "Huckleberry Hound: Refreshements! +15 Stregth." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(34) << "Huckleberry Hound: You've had your share, off you go!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(34) << "Huckleberry Hound: No but see that frozen girl in the next village!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(34) << "Huckleberry Hound: Sure I can't sing \"Clemntine\" for you?" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(34) << "Huckleberry Hound: Say hello to Brian for me." << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Cyan::runBettyRubble(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getBettyRubbleVisit() == false) {
			cout << palette(34) << "Betty Rubble: I am Betty Rubble from the Flintstones!" << palette(1) << "\n";
			setBettyRubbleVisit(true);
			out = 1;
		}
		else {
			cout << palette(34) << "Betty Rubble: My dress is prettier than Wilma's." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getBettyRubbleFood() == false) {
			cout << palette(34) << "Betty Rubble: Some teradactyl eggs? +5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(34) << "BettyRubble: Out of teradactyl eggs, sorry." << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getBettyRubbleDrink() == false) {
			cout << palette(34) << "Betty Rubble: Yes, drink from the Mammoth's trunk! +15 Strength." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(34) << "Betty Rubble: The Mammoth has a cold in it's trunk!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(34) << "Betty Rubble: No, but don't you think BamBam is adorable?" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(34) << "Betty Rubble: Stop in at the Flintstones." << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(34) << "Betty Rubble: Send Barney home if you see him at Wilma's" << palette(1) << "\n";
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
void Cyan::setInkyVisit(bool visit) {
	this->inkyVisit = visit;
}

bool Cyan::getInkyVisit() {
	return inkyVisit;
}

void Cyan::setInkyFood(bool sullyFood) {
	this->inkyFood = sullyFood;
}

bool Cyan::getInkyFood() {
	return inkyFood;
}

void Cyan::setInkyDrink(bool sullyDrink) {
	this->inkyDrink = sullyDrink;
}

bool Cyan::getInkyDrink() {
	return inkyDrink;
}


void Cyan::setBruceVisit(bool visit) {
	this->bruceVisit = visit;
}

bool Cyan::getBruceVisit() {
	return bruceVisit;
}

void Cyan::setBruceFood(bool clawsFood) {
	this->bruceFood = clawsFood;
}

bool Cyan::getBruceFood() {
	return bruceFood;;
}

void Cyan::setBruceDrink(bool clawsDrink) {
	this->bruceDrink = clawsDrink;
}

bool Cyan::getBruceDrink() {
	return bruceDrink;
}


void Cyan::setElsaVisit(bool visit) {
	this->elsaVisit = visit;
}

bool Cyan::getElsaVisit() {
	return elsaVisit;
}

void Cyan::setElsaFood(bool naviFood) {
	this->elsaFood = naviFood;
}

bool Cyan::getElsaFood() {
	return elsaFood;
}

void Cyan::setElsaDrink(bool naviDrink) {
	this->elsaDrink = naviDrink;
}

bool Cyan::getElsaDrink() {
	return elsaDrink;
}


void Cyan::setHuckleBerryHoundVisit(bool visit) {
	this->huckleBerryHoundVisit = visit;
}

bool Cyan::getHuckleBerryHoundVisit() {
	return huckleBerryHoundVisit;
}

void Cyan::setHuckleBerryHoundFood(bool cookieMonsterFood) {
	this->huckleBerryHoundFood = cookieMonsterFood;
}

bool Cyan::getHuckleBerryHoundFood() {
	return huckleBerryHoundFood;
}

void Cyan::setHuckleBerryHoundDrink(bool cookieMonsterDrink) {
	this->huckleBerryHoundDrink = cookieMonsterDrink;
}

bool Cyan::getHuckleBerryHoundDrink() {
	return huckleBerryHoundDrink;
}


void Cyan::setBettyRubbleVisit(bool visit) {
	this->bettyRubbleVisit = visit;
}

bool Cyan::getBettyRubbleVisit() {
	return bettyRubbleVisit;
}

void Cyan::setBettyRubbleFood(bool bobBlobFood) {
	this->bettyRubbleFood = bobBlobFood;
}

bool Cyan::getBettyRubbleFood() {
	return bettyRubbleFood;
}

void Cyan::setBettyRubbleDrink(bool bobBlobDrink) {
	this->bettyRubbleDrink = bobBlobDrink;
}

bool Cyan::getBettyRubbleDrink() {
	return bettyRubbleDrink;
}


/*******************************************************************************
**						function set Color() 6 each
** Setters for the 6 rooms other than this one.  This is how a player can
** travel between rooms. Called and used by ThrowBack.cpp
** Input: Space* for each individual room.
** Output: void.
******************************************************************************/
void Cyan::setBlue(Space *ptr) {
	C_Blue = ptr;
}

void Cyan::setYellow(Space *ptr) {
	C_Yellow = ptr;
}

void Cyan::setGreen(Space *ptr) {
	C_Green = ptr;
}

void Cyan::setRed(Space *ptr) {
	C_Red = ptr;
}

void Cyan::setMagenta(Space *ptr) {
	C_Magenta = ptr;
}

void Cyan::setWhite(Space *ptr) {
	C_White = ptr;
}