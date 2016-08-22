/****************************************************************************************
** Program Filename: Space.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/17/2016
** Description: Contains the Space class definition file.
** Input: exitGame() takes 8 Space pointers for memory deallocation.
** Output: Base class for all ThrowBack derived classes.
*****************************************************************************************/
#include "Space.hpp"
#include<iostream>
using std::cout;
using std::cin;
#include<cstdlib>

/***************************************************************************************************************
**											function welcome()
** Initial game play welcome screen utilizing palette for text color decoration. Returns an int to the call
** based upon user input for play game or quit.
** Input: void.
** Output: returns appropriate user choice int.
***************************************************************************************************************/
int Space::welcome() {
	int choice = -1;
	int solve = -1;
	cout << palette(24) << "\n*****************************************************************************\n"
		<< palette(19) << "\t\t\t  Welcome to Throwback!\n"
		<< palette(24) << "*****************************************************************************\n"
		<< palette(1) << "This is the text based game that includes your favorite and not so favorite\n"
		<< "characters from various vintage games, television, and the cinema. Your goal\n" << "is to collect"
		<< " the puzzle pieces from each of 7 rooms colored: " << palette(24) << "Blue, " << palette(19)
		<< "Yellow, \n" << palette(34) << "Cyan, " << palette(14) << "Green, " << palette(9) << "Red, "
		<< palette(29) << "Magenta, " << palette(1) << "and " << palette(4) << "White " << palette(1)
		<< "whereupon, you will win the Grand Prize! \nHave faith, you will always know which room you are in!\n"
		<< "You must collect all seven puzzle pieces by conversing with the 5 color \ncoordinated characters in"
		<< " each room. For instance, " << palette(12) << "Shrek" << palette(1) << " is in the" << palette(14)
		<< " Green " << palette(1) << "room. \nOnce you have all seven pieces, you will be declared the "
		<< "winner and the Grand\nPrize will be revealed. Your backpack contents are validated each time\n"
		<< "you change rooms. \nEasy enough?  Not really! Some Characters are helpful, others, less so...\n"
		<< "Only one Character in each room has the puzzle piece. Some have food and drink,\n"
		<< "which you need to take. If your strength is sapped to 0, you will lose \nand your console text "
		<< "color will remain the color of the room you expired in!\nJust kidding!\n"
		<< "Beware, some characters will trick you and further sap your strength.\n"
		<< "There is a time limit, that you will be asked to set, maximum 15 minutes.\nYou will be kept "
		<< "apprised of your remaining time every time you change rooms.\n"
		<< "You are given choices at all times, including the ability to immediately \ntransport yourself "
		<< "to another room, which you will need to do anyway once \nyou have the room's puzzle piece.\n"
		<< "You are equipped with a backpack to store the pieces in. Each time you change \nrooms or make "
		<< "a choice in a room when dealing with a character, it costs \nyou strength points. Good Luck!\n\n"
		<< palette(19) << "Choose 1 to play, 0 to quit!" << palette(1) << "\n";
	while (!(cin >> choice) || choice < 0 || choice > 1) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error, Choose 1 to play, 0 to quit!\n" << palette(1);
	}
	if (choice == 1) {
		cout << palette(19) << "Would you like to see a helpful hint and the solution?" << palette(1) << "\n"
			<< "Enter 0 for no, I'll slay this game the old fasioned way!.\n"
			<< "Enter 1 for \"I'm a TA/Instructor!\" Of course!\n";
		while (!(cin >> solve) || solve < 0 || solve > 1) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << palette(9) << "\nYou've chosen poorly!\n" << palette(1)
				<< "Enter " << palette(4) << "0" << palette(1) << " for no, I'll slay this game the old fashioned way!\n"
				<< "Enter " << palette(4) << "1" << palette(1) << " for \"I'm a TA/Instructor! Of course!\"\n";
		}
	}
	if (solve == 1) {
		cout << palette(4) << "Helpful Hint:\n"
			<< "Keep an eye on your strength! If it is reduced below 25, change rooms and\n"
			<< "assuming you are special, pure, and virtuous, you will be offered an\n"
			<< "opportunity to boost your Strength. Each room offers a different amount.\n"
			<< "DO NOT let your Strength dwindle to zero or lower because with less than\n"
			<< "one Strength point, when you change rooms, the game will end and the Grand\n"
			<< "Prize will not be revealed to you!\n\n"
			<< "Solution:\n"
			<< palette(24) << "Blue Room: Na'vi" << palette(1) << " option 4.\n"
			<< palette(19) << "Yellow Room: Garfield" << palette(1) << " option 4.\n"
			<< palette(34) << "Cyan Room: Elsa" << palette(1) << " option 4.\n"
			<< palette(9) << "Red Room: Red Elmo" << palette(1) << " option 4.\n"
			<< palette(14) << "Green Room: Yoda" << palette(1) << " option 4.\n"
			<< palette(29) << "Magenta Room: Pink Panther" << palette(1) << " option 4.\n"
			<< palette(4) << "White Room: Brian" << palette(1) << " option 4.\n\n";
	}
	return choice;
}


/*******************************************************************************
**							function go2Roome()
** Virtual function called by Throwback.cpp when Player chooses a different room
** to visit.  Called via the tBack*.
** Input: Player cin 
** Output: Returns an int to calling runController()
******************************************************************************/
int Space::go2Room() {
	int choice;
	cout << "\nWhich room would you like to enter?\n"
		<< "1. " << palette(24) << "Blue Room." << palette(1) << "\n"
		<< "2. " << palette(19) << "Yellow Room." << palette(1) << "\n"
		<< "3. " << palette(34) << "Cyan Room." << palette(1) << "\n"
		<< "4. " << palette(14) << "Green Room." << palette(1) << "\n"
		<< "5. " << palette(9) << "Red Room." << palette(1) << "\n"
		<< "6. " << palette(29) << "Magenta Room." << palette(1) << "\n"
		<< "7. " << palette(4) << "White Room." << palette(1) << "\n"
		<< "or 0 to Quit.\n";
	while (!(cin >> choice) || choice < 0 || choice > 7) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << palette(9) << "\nInput Error!\n" << palette(1)
			<< "Which room would you like to enter?\n"
			<< "1. " << palette(24) << "Blue Room." << palette(1) << "\n"
			<< "2. " << palette(19) << "Yellow Room." << palette(1) << "\n"
			<< "3. " << palette(34) << "Cyan Room." << palette(1) << "\n"
			<< "4. " << palette(14) << "Green Room." << palette(1) << "\n"
			<< "5. " << palette(9) << "Red Room." << palette(1) << "\n"
			<< "6. " << palette(29) << "Magenta Room." << palette(1) << "\n"
			<< "7. " << palette(4) << "White Room." << palette(1) << "\n"
			<< "or 0 to Quit.\n";
	}
	return choice;
}

/*******************************************************************************
**							function exitGame()
** Exits game and utilizing palette(1) for text color decoration returns Player
** console to default white.  Valgrind checks good!
** Input: void.
** Output: void, cout error message.
******************************************************************************/
void Space::exitGame(Space* blue, Space* yellow, Space* cyan, Space* green,
					 Space* red, Space* magenta, Space* white, Space* Player) {
	delete blue;
	blue = NULL;
	delete yellow;
	yellow = NULL;
	delete cyan;
	cyan = NULL;
	delete green;
	green = NULL;
	delete red;
	red = NULL;
	delete magenta;
	magenta = NULL;
	delete white;
	white = NULL;
	Player = NULL;
	cout << palette(34) << "\nDon't like your console text color? Better call Saul!\n"
		<< palette(1) << "\nThanks for playing Throwback!\n\n";
	exit(EXIT_SUCCESS);
}


/*******************************************************************************
**							function pallete()
** Takes an int argument for selected color and returns a string containing the
** ASCII escape codes for color and/or text decoration.  Should be used cout and
** followed by a default color reset in the same cout line. Ints outside of
** expected range will return the default switch - the system default color.
** Input: int color.
** Output: returns appropriate ASCII excape string.
******************************************************************************/
string Space::palette(int color) {
	string col;
	switch (color) {
	case 1:
		col = "\033[0m";		// cout << "\033[0m" << "The default color.\n";
		break;
	case 2:
		col = "\033[7m";		// cout << "\033[7m" << "Background Default.\n";
		break;
	case 3:
		col = "\033[4m";		// cout << "\033[4m" << "Underlined default.\n";
		break;
	case 4:
		col = "\033[1;37m";		// cout << "\033[1;37m" << "Bold White.\n";
		break;
	case 5:
		col = "\033[1;4;37m";	// cout << "\033[4;37m" << "Underlined Bold White.\n";
		break;
	case 6:
		col = "\033[0;31m";		// cout << "\033[0;31m" << "Red.\n";
		break;
	case 7:
		col = "\033[7;31m";		// cout << "\033[7;31m" << "Background Red.\n";
		break;
	case 8:
		col = "\033[0;4;31m";	// cout << "\033[0;4;31m" << "Underlined Red.\n";
		break;
	case 9:
		col = "\033[1;31m";		// cout << "\033[1;31m" << "Bold Red.\n";
		break;
	case 10:
		col = "\033[4;1;31m";	// cout << "\033[4;31m" << "Underlined Bold Red.\n";
		break;
	case 11:
		col = "\033[0;32m";		// cout << "\033[0;32m" << "Green.\n";
		break;
	case 12:
		col = "\033[7;32m";		// cout << "\033[7;32m" << "Background Green.\n";
		break;
	case 13:
		col = "\033[0;4;32m";	// cout << "\033[0;4;32m" << "Underlined Green.\n";
		break;
	case 14:
		col = "\033[1;32m";		// cout << "\033[1;32m" << "Bold Green.\n";
		break;
	case 15:
		col = "\033[1;4;32m";	// cout << "\033[4;32m" << "Underlined Bold Green.\n";
		break;
	case 16:
		col = "\033[0;33m";		// cout << "\033[0;33m" << "Yellow.\n";
		break;
	case 17:
		col = "\033[7;33m";		// cout << "\033[7;33m" << "Background Yellow.\n";
		break;
	case 18:
		col = "\033[0;4;33m";	// cout << "\033[0;4;33m" << "Underlined Yellow.\n";
		break;
	case 19:
		col = "\033[1;33m";		// cout << "\033[1;33m" << "Bold Yellow.\n";
		break;
	case 20:
		col = "\033[1;4;33m";	// cout << "\033[4;33m" << "Underlined Bold Yellow.\n";
		break;
	case 21:
		col = "\033[0;34m";		// cout << "\033[0;34m" << "Blue.\n";
		break;
	case 22:
		col = "\033[7;34m";		// cout << "\033[7;34m" << "Background Blue.\n";
		break;
	case 23:
		col = "\033[0;4;34m";	// cout << "\033[0;4;34m" << "Underlined Blue.\n";
		break;
	case 24:
		col = "\033[1;34m";		// cout << "\033[1;34m" << "Bold Blue.\n";
		break;
	case 25:
		col = "\033[1;4;34m";	// cout << "\033[4;34m" << "Underlined Bold Blue.\n";
		break;
	case 26:
		col = "\033[0;35m";		// cout << "\033[0;35m" << "Magenta.\n";
		break;
	case 27:
		col = "\033[7;35m";		// cout << "\033[7;35m" << "Background Magenta.\n";
		break;
	case 28:
		col = "\033[0;4;35m";	// cout << "\033[0;4;35m" << "Underlined Magenta.\n";
		break;
	case 29:
		col = "\033[1;35m";		// cout << "\033[1;35m" << "Bold Magenta.\n";
		break;
	case 30:
		col = "\033[1;4;35m";	// cout << "\033[4;35m" << "Underlined Bold Magenta.\n";
		break;
	case 31:
		col = "\033[0;36m";		// cout << "\033[0;36m" << "Cyan.\n";
		break;
	case 32:
		col = "\033[7;36m";		// cout << "\033[7;36m" << "Background Cyan.\n";
		break;
	case 33:
		col = "\033[0;4;36m";	// cout << "\033[0;4;36m" << "Underlined Cyan.\n";
		break;
	case 34:
		col = "\033[1;36m";		// cout << "\033[1;36m" << "Bold Cyan.\n";
		break;
	case 35:
		col = "\033[1;4;36m";	// cout << "\033[4;36m" << "Underlined Bold Cyan.\n";
		break;
	default:
		col = "\033[0m";		// cout << "\033[0m" << "The default color.\n";
	}
	return col;
}