/****************************************************************************************
** Program Filename: Yellow.cpp
** Author: Chris Kearns
** Date: 3/17/2016
** Description: Contains the Yellow class definition file.
** Input: exitGame() takes 6 Space pointers for linking rooms.
** Output: Linked to all ThrowBack derived classes.
*****************************************************************************************/
#include "Yellow.hpp"
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
void Yellow::setYellowPtrs(Space* blue, Space* cyan, Space* green, Space* red, Space* magenta, Space* white) {
	setBlue(blue);
	setCyan(cyan);
	setGreen(green);
	setRed(red);
	setMagenta(magenta);
	setWhite(white);
	setPPYellow(false);
	setStrength();
	initCharBools();
}

// Destructor.
Yellow::~Yellow() {
	Y_Blue = NULL;
	Y_Cyan = NULL;
	Y_Green = NULL;
	Y_Red = NULL;
	Y_Magenta = NULL;
	Y_White = NULL;
}


/*******************************************************************************
**			function setstrength() 3 each.
** Setters for stregth. setStrength() for initialization, setSTregth(int) for
** updating local room strength changes. getStrength for logic control, and
** acceptStrength() sets overall current Player strength upon Player entry to
** this room.  acceptSTrength() also returns current Player to ThrowBack.cpp for
** use as Player enters other rooms or re-enters this room.
** Input: acceptStregnth() current strength int from Throwback.cpp
** Output: sets local stregth int.
******************************************************************************/
void Yellow::setStrength() {
	this->strength = 0;
}

void Yellow::setStrength(int strength) {
	this->strength = getStrength() + strength;
}

int Yellow::getStrength() {
	return strength;
}

// Throwback passes overall Player strength for update here.
int Yellow::acceptStrength(int strength) {
	this->strength = strength;
}


/*******************************************************************************
**			function setPPColor() 3 each.
** Initializes Player color puzzle piece, logic control locally to ths room, and
** getPPBlue used by ThrowBack.cpp for logic control and displayBP()
** Input: bool to initialize and set when Player finds color puzzle piece.
** Output:
******************************************************************************/
void Yellow::setPPYellow(bool f) {
	this->pPiece = f;
}

void Yellow::setPPYellow() {
	this->pPiece = true;
}

bool Yellow::getPPYellow() {
	return pPiece;
}


/*******************************************************************************
**			function initCharBools()
** Initializes individual characters variables at room initializaton.
******************************************************************************/
void Yellow::initCharBools() {
	this->bartSimpsonFood = false;
	this->bartSimpsonDrink = false;
	this->bartSimpsonVisit = false;
	this->bigBirdFood = false;
	this->bigBirdDrink = false;
	this->bigBirdVisit = false;
	this->garfieldFood = false;
	this->garfieldDrink = false;
	this->garfieldVisit = false;
	this->pokemonFood = false;
	this->pokemonDrink = false;
	this->pokemonVisit = false;
	this->spongeBobSquarePantsFood = false;
	this->spongeBobSquarePantsDrink = false;
	this->spongeBobSquarePantsVisit = false;
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
int Yellow::runRoom() {
	int choice = 1;
	cout << palette(19) << "You are in the Yellow Room!" << palette(1) << "\n";
	if (getStrength() < 25) {
		cout << palette(19) << "You're looking jaundiced!" << palette(1) << "\n";
		boostStrength();
	}
	while (choice > 0 && choice <= 6) {
		choice = runCharacters();
		if (choice == 1) {
			choice = runController(1);	// Bart Simpson
		}
		else if (choice == 2) {
			choice = runController(2);	// Big Bird
		}
		else if (choice == 3) {
			choice = runController(3);	// Garfield
		}
		else if (choice == 4) {
			choice = runController(4);	// Pokemon
		}
		else if (choice == 5) {
			choice = runController(5);	// Sponge Bob
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
void Yellow::boostStrength() {
	int answer = 0;
	cout << palette(19) << "Would you like an 18 point strength boost to keep playing?\n" << palette(1)
		<< "1. Yes!\n"
		<< "2. What? Never! I'm a Computer Scientist!\n";
	while (!(cin >> answer) || answer < 1 || answer > 2) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(19)
			<< "Would you like a strength Boost to keep playing?\n" << palette(1)
			<< "1. Yes!\n"
			<< "2. No!\n";
	}
	if (answer == 1) {
		setStrength(18);
		cout << palette(19) << "New Strength = " << getStrength() << palette(1) << "\n";
	}
}


/*******************************************************************************
**			function runCharacters()
** Player chocie cout/cin input validation module. Returns an int for choice of
** character to visit to runController()
** Input: Player
** Output: int choice to local runController()
******************************************************************************/
int Yellow::runCharacters() {
	int utter = 0;
	cout << "Which" << palette(19) << " Yellow Room " << palette(1) << "character do you want to converse with?\n"
		<< "1. " << palette(19) << "Bart Simpson" << palette(1) << "\n"
		<< "2. " << palette(19) << "Big Bird (Sesame Street)" << palette(1) << "\n"
		<< "3. " << palette(19) << "Pokemon (Pikachu)" << palette(1) << "\n"
		<< "4. " << palette(19) << "Garfield" << palette(1) << "\n"
		<< "5. " << palette(19) << "Sponge Bob Square Pants" << palette(1) << "\n"
		<< "6. " << palette(9) << "Change Rooms now!" << palette(1) << "\n";
	while (!(cin >> utter) || utter < 1 || utter > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< "Which" << palette(19) << " Yellow Room " << palette(1) << "character do you want to converse with?\n"
			<< "1. " << palette(19) << "Bart Simpson" << palette(1) << "\n"
			<< "2. " << palette(19) << "Big Bird (Sesame Street)" << palette(1) << "\n"
			<< "3. " << palette(19) << "Pokemon (Pikachu)" << palette(1) << "\n"
			<< "4. " << palette(19) << "Garfield" << palette(1) << "\n"
			<< "5. " << palette(19) << "Sponge Bob Square Pants" << palette(1) << "\n"
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
int Yellow::runController(int in) {
	int arg = in;
	int choice1;
	int choice2;
	while (arg > 0 && arg < 7) {
		if (arg == 1) {				/**** Bart Simpson ****/
			while (arg == 1) {
				choice1 = playerAI();
				choice2 = runBartSimpson(choice1);
				if (choice2 == 1) { setStrength(-1); }
				else if (choice2 == 2) { setStrength(-1); setBartSimpsonFood(true); }
				else if (choice2 == 3) { setStrength(-1); setBartSimpsonDrink(true); }
				else if (choice2 == 4) { setStrength(-1); }
				else if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				else if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 2) {		/**** Big Bird ****/
			while (arg == 2) {
				choice1 = playerAI();
				choice2 = runBigBird(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setBigBirdFood(true); }
				if (choice2 == 3) {
					if (getBigBirdDrink() == false) {
						setStrength(2);
						setBigBirdDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 3) {		/**** Pokemon ****/
			while (arg == 3) {
				choice1 = playerAI();
				choice2 = runPokemon(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setPokemonFood(true); }
				if (choice2 == 3) {
					if (getPokemonDrink() == false) {
						setStrength(15);
						setPokemonDrink(true);
					}
				}
				if (choice2 == 4) { setStrength(-1); }
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 4) {		/**** Garfield ****/
			while (arg == 4) {
				choice1 = playerAI();
				choice2 = runGarfield(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) { setStrength(-5); setGarfieldFood(true); }
				if (choice2 == 3) { setStrength(-10); setGarfieldDrink(true); }
				if (choice2 == 4) {
					setStrength(-1);
					if (getPPYellow() == false) {
						setPPYellow(true);
						cout << "\nThe " << palette(17) << " Y " << palette(1) << palette(19)
							<< " Puzzle Piece " << palette(1) << "is in your Backpack!!\n\n";
					}
				}
				if (choice2 == 5) { setStrength(-1); arg = runCharacters(); }
				if (choice2 == 6) { setStrength(-1); arg = 0; }
			}
		}
		else if (arg == 5) {		/**** Sponge Bob Square Pants ****/
			while (arg == 5) {
				choice1 = playerAI();
				choice2 = runSpongeBobSquarePants(choice1);
				if (choice2 == 1) { setStrength(-1); }
				if (choice2 == 2) {
					if (getSpongeBobSquarePantsFood() == false) {
						setStrength(5);
						setSpongeBobSquarePantsFood(true);
					}
				}
				if (choice2 == 3) {
					if (getSpongeBobSquarePantsDrink() == false) {
						setStrength(15);
						setSpongeBobSquarePantsDrink(true);
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
int Yellow::playerAI() {
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
	cout << "There's a " << palette(19) << "Yellow" << palette(1) << " Character in front of you. Say:\n"
		<< "1. Greatings " << palette(19) << "Yellow Room" << palette(1) << " Character!\n"
		<< "2. Do you have anything to eat?\n"
		<< "3. Do you have anything to drink?\n"
		<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
		<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
		<< "5. I'm going to visit a different " << palette(19) << "Yellow Room" << palette(1) << " Character.\n"
		<< "6. " << palette(9) << "I'm changing rooms now!" << palette(1) << "\n";
	while (!(cin >> out) || out < 1 || out > 6) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< palette(3) << "You're going to upset it!" << palette(1) << " What do you want to say?\n"
			<< "1. Greatings " << palette(19) << "Yellow Room" << palette(1) << " Character!\n"
			<< "2. Do you have anything to eat?\n"
			<< "3. Do you have anything to drink?\n"
			<< "4. Do you have the " << palette(19) << "p" << palette(34) << "u" << palette(14) << "z" << palette(9)
			<< "z" << palette(29) << "l" << palette(4) << "e" << palette(1) << " piece I seek?\n"
			<< "5. I'm going to visit a different " << palette(19) << "Yellow Room" << palette(1) << " Character.\n"
			<< "6. " << palette(9) << "I'm changing rooms now!" << palette(1) << "\n";
	}
	return out;
}


/***************************************************************************************************************
**			function run Characters() 5 each.
** Indivdual character responses to PlayerAI query. Player is assesed and awarded points based upon query and
** characters call stack in runController()
** Input: PlayerAI query choice.
** Output: reutrns int response to runController()
***************************************************************************************************************/
int Yellow::runBartSimpson(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getBartSimpsonVisit() == false) {
			cout << palette(19) << "Bart: I am Bart Simpson. Who the heck are you?" << palette(1) << "\n";
			setBartSimpsonVisit(true);
			out = 1;
		}
		else {
			cout << palette(19) << "Bart: Don't have a cow, man!" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getBartSimpsonFood() == false) {
			cout << palette(19) << "Bart: Homer's eaten it all!" << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(19) << "Bart: They have some beer nuts down at Moe's Tavern! Beat it!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getBartSimpsonDrink() == false) {
			cout << palette(19) << "Bart: Some Duff's Beer? None for you!!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(19) << "Bart: Nope, and I've eaten the last Krusty Burger, sorry!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(19) << "Bart: I can't promise I'll try, but I'll try to try to find it." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(19) << "Bart: Ay Caramba!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(19) << "Bart: Eat my shorts!" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Yellow::runBigBird(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getBigBirdVisit() == false) {
			cout << palette(19) << "Big Bird: Hello boys and girls. Welcome to Sesame Street" << palette(1) << "\n";
			setBigBirdVisit(true);
			out = 1;
		}
		else {
			cout << palette(19) << "Big Bird: Never refer to me as an item. I'm a bird." << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getBigBirdFood() == false) {
			cout << palette(19) << "Big Bird: I only have pond water, sorry." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(19) << "Big Bird: You rode the short bus over here, didn't you?" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getBigBirdDrink() == false) {
			cout << palette(19) << "Big Bird: If you like chicken scratch?" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(19) << "Big Bird: Did you fail kindergarden?" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(19) << "Big Bird: No, but I hear Garfield might have it." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(19) << "Big Bird: Super. Duper. Flooper. Hooper: Hooper! Hooper!" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(19) << "Big Bird: Im gonna miss you, Mr. Looper." << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Yellow::runGarfield(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getGarfieldVisit() == false) {
			cout << palette(19) << "Garfield: Good Day! Never trust a smiling cat." << palette(1) << "\n";
			setGarfieldVisit(true);
			out = 1;
		}
		else {
			cout << palette(19) << "Garfield: Why don't you go talk to Brian the " << palette(4) << "Dog?" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getGarfieldFood() == false) {
			cout << palette(19) << "Garfield: Avoid fruits and nuts: after all, you are what you eat. -5 Strength." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(19) << "Garfield: Eat every meal as though it were your last. -5 again." << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getGarfieldDrink() == false) {
			cout << palette(19) << "Garfield: I don't share! -10 Strength!" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(19) << "Garfield: You're worse than that Big Bird character down the hall. -10 Strength." << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		if (getPPYellow() == false) {
			cout << palette(19) << "Garfield: Indeed I do! Let me climb up and put it in your backpack." << palette(1) << "\n";
			out = 4;
		}
		else {
			cout << palette(19) << "Garfield: If you are patient...and wait long enough...Nothing will happen!" << palette(1) << "\n";
		}
	}
	else if (inMessage == 5) {
		cout << palette(19) << "Garfield: Excellant, back to my nap." << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(19) << "Garfield: Bring some snacks next time." << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Yellow::runPokemon(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getPokemonVisit() == false) {
			cout << palette(19) << "Pikachu: Pika! (I'm easily the most annoying character in this place!)" << palette(1) << "\n";
			setPokemonVisit(true);
			out = 1;
		}
		else {
			cout << palette(19) << "Pikachu: Chu! (Shall we sing the Pikachu song together?)" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getPokemonFood() == false) {
			cout << palette(19) << "Pikachu: Pika... Pika! " << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(19) << "Pikachu: Chu!" << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getPokemonDrink() == false) {
			cout << palette(19) << "Pikachu: Pika, Pika?" << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(19) << "Pikachu: Chu! Pika!" << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(19) << "Pikachu: Pika! Chu! Pika!" << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(19) << "Pikachu: Pika! (Go on, laugh, I'm a multi-billion dollar industry!)" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(19) << "Pikachu: Pika! (I love you!)" << palette(1) << "\n";
		out = 6;
	}
	return out;
}


int Yellow::runSpongeBobSquarePants(int inMessage) {
	int out = 0;
	if (inMessage == 1) {
		if (getSpongeBobSquarePantsVisit() == false) {
			cout << palette(19) << "Sponge Bob: Hiya! I'm ugly and I'm proud!" << palette(1) << "\n";
			setSpongeBobSquarePantsVisit(true);
			out = 1;
		}
		else {
			cout << palette(19) << "Sponge Bob: Nosferatu!" << palette(1) << "\n";
			out = 1;
		}
	}
	else if (inMessage == 2) {
		if (getSpongeBobSquarePantsFood() == false) {
			cout << palette(19) << "Sponge Bob: Squidaward ate all the patties." << palette(1) << "\n";
			out = 2;
		}
		else {
			cout << palette(19) << "Sponge Bob: It'll just go straight to your thighs." << palette(1) << "\n";
			out = 2;
		}
	}
	else if (inMessage == 3) {
		if (getSpongeBobSquarePantsDrink() == false) {
			cout << palette(19) << "Sponge Bob: Remember, licking doorknobs is illegal in other rooms." << palette(1) << "\n";
			out = 3;
		}
		else {
			cout << palette(19) << "Sponge Bob: I know of a place." << palette(1) << "\n";
			out = 3;
		}
	}
	else if (inMessage == 4) {
		cout << palette(19) << "Sponge Bob: No, but that sloth like cat down the hall can helo you." << palette(1) << "\n";
		out = 4;
	}
	else if (inMessage == 5) {
		cout << palette(19) << "Sponge Bob: No, have you seen Patrick?" << palette(1) << "\n";
		out = 5;
	}
	else if (inMessage == 6) {
		cout << palette(19) << "Sponge Bob: Can I be excused for the rest of my life?" << palette(1) << "\n";
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
void Yellow::setBartSimpsonVisit(bool visit) {
	this->bartSimpsonVisit = visit;
}

bool Yellow::getBartSimpsonVisit() {
	return bartSimpsonVisit;
}

void Yellow::setBartSimpsonFood(bool food) {
	this->bartSimpsonFood = food;
}

bool Yellow::getBartSimpsonFood() {
	return bartSimpsonFood;
}

void Yellow::setBartSimpsonDrink(bool drink) {
	this->bartSimpsonDrink = drink;
}

bool Yellow::getBartSimpsonDrink() {
	return bartSimpsonDrink;
}


void Yellow::setBigBirdVisit(bool visit) {
	this->bigBirdVisit = visit;
}

bool Yellow::getBigBirdVisit() {
	return bigBirdVisit;
}

void Yellow::setBigBirdFood(bool food) {
	this->bigBirdFood = food;
}

bool Yellow::getBigBirdFood() {
	return bigBirdFood;;
}

void Yellow::setBigBirdDrink(bool drink) {
	this->bigBirdDrink = drink;
}

bool Yellow::getBigBirdDrink() {
	return bigBirdDrink;
}


void Yellow::setGarfieldVisit(bool visit) {
	this->garfieldVisit = visit;
}

bool Yellow::getGarfieldVisit() {
	return garfieldVisit;
}

void Yellow::setGarfieldFood(bool food) {
	this->garfieldFood = food;
}

bool Yellow::getGarfieldFood() {
	return garfieldFood;
}

void Yellow::setGarfieldDrink(bool drink) {
	this->garfieldDrink = drink;
}

bool Yellow::getGarfieldDrink() {
	return garfieldDrink;
}


void Yellow::setPokemonVisit(bool visit) {
	this->pokemonVisit = visit;
}

bool Yellow::getPokemonVisit() {
	return pokemonVisit;
}

void Yellow::setPokemonFood(bool food) {
	this->pokemonFood = food;
}

bool Yellow::getPokemonFood() {
	return pokemonFood;
}

void Yellow::setPokemonDrink(bool drink) {
	this->pokemonDrink = drink;
}

bool Yellow::getPokemonDrink() {
	return pokemonDrink;
}


void Yellow::setSpongeBobSquarePantsVisit(bool visit) {
	this->spongeBobSquarePantsVisit = visit;
}

bool Yellow::getSpongeBobSquarePantsVisit() {
	return spongeBobSquarePantsVisit;
}

void Yellow::setSpongeBobSquarePantsFood(bool food) {
	this->spongeBobSquarePantsFood = food;
}

bool Yellow::getSpongeBobSquarePantsFood() {
	return spongeBobSquarePantsFood;
}

void Yellow::setSpongeBobSquarePantsDrink(bool drink) {
	this->spongeBobSquarePantsDrink = drink;
}

bool Yellow::getSpongeBobSquarePantsDrink() {
	return spongeBobSquarePantsDrink;
}


/*******************************************************************************
**			function set Color() 6 each
** Setters for the 6 rooms other than this one.  This is how a player can
** travel between rooms. Called and used by ThrowBack.cpp
** Input: Space* for each individual room.
** Output: void.
******************************************************************************/
void Yellow::setBlue(Space *ptr) {
	Y_Blue = ptr;
}

void Yellow::setCyan(Space *ptr) {
	Y_Cyan = ptr;
}

void Yellow::setGreen(Space *ptr) {
	Y_Green = ptr;
}

void Yellow::setRed(Space *ptr) {
	Y_Red = ptr;
}

void Yellow::setMagenta(Space *ptr) {
	Y_Magenta = ptr;
}

void Yellow::setWhite(Space *ptr) {
	Y_White = ptr;
}
