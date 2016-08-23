/****************************************************************************************
** Program Filename: Main.cpp
** Author: Chris Kearns
** Date: 1/17/2016
** Description: Main Program file - menu logic and function calls.
** Input: User input mandatory.
** Output: Displays several 40x20 user controlled image animations via call to 
** respective function with user defined collector array as sole paramter.
****************************************************************************************/
#include "BlankGrid.hpp"
#include "Oscillator.hpp"
#include "Stable.hpp"
#include "SimpOsc.hpp"
#include "Glider.hpp"
#include "GosperGun.hpp"
#include <iomanip>
using std::setw;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main() {
	// Initial user prompt for desired matrix size.
	int whichOne = -1;	 // Choice for which simulator to run.
	int howFast = -1;	 // Choice for speed of simulator.
	int numIters = -1;	 // Choice for # of iterations to run.
	int xOff = -100;	 // Chioce for x-axis offset.
	int yOff = -100;	 // Choice for y-axis offset.
	int collector[4];	 // Array to keep parameter passing simpler.
	int transpose[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // Speed control transpose utility array.

	// User Input frame 1, which one?
	cout << endl << "Welcome to Conway's Game of Life simulator." << endl << endl
		 << "Enter 1 for a basic stable grid pattern." << endl
		 << "Enter 2 for a Stable Box image" << endl
		 << "Enter 3 for a Simple oscillator" << endl
		 << "Enter 4 for Jan Kok's Galaxy oscillator." << endl
		 << "Enter 5 for a Glider." << endl
		 << "Enter 6 for a Gosper Glider Gun." << endl
		 << "or Enter 0 to quit." << endl << endl;

	cin >> whichOne;

	// User input validation.
	while ((whichOne < 0) || (whichOne > 6)) {
		cout << "Error! Please enter an integer from 1 to 6 as follows or 0 to quit." << endl << endl
			 << "Enter 1 for a basic stable grid pattern." << endl
			 << "Enter 2 for a Stable Box image" << endl
			 << "Enter 3 for a Simple oscillator" << endl
			 << "Enter 4 for Kok's Galaxy oscillator." << endl
			 << "Enter 5 for a Glider." << endl
			 << "Enter 6 for a Gosper Gun." << endl
			 << "or Enter 0 to quit." << endl << endl;
				
		cin >> whichOne;
		
		// Exit while loop if user inputs 0 for quit.
		if (whichOne == 0)
			return 0;
	}

	// Program exit if user has input 0 for quit.
	if (whichOne == 0)
		return 0;


	// User Input frame 2, how fast?
	cout << "How fast do you want the animation to run?" << endl
		 << "Enter a number from 1 to 9 or 0 to quit." << endl
		 << "1 is approximately 1 second per frame, 9 is approximately 0.1 seconds per frame." << endl;

	cin >> howFast;

	// User input validation.
	while ((howFast < 0) || (howFast > 9)) {
		cout << "Error! Please enter an integer from 1 to 9 or 0 to quit." << endl
			<< "1 is approximately 1 second and 9 is approximately 0.1 seconds." << endl;

		cin >> howFast;

		// Exit while loop if user inputs 0 for quit.
		if (howFast == 0)
			return 0;
	}

	// Program exit if user has input 0 for quit.
	if (howFast == 0)
		return 0;
	
	// Transpose howFast variable so it works as user would typically expect.
	howFast = transpose[howFast];

	// User Input for frame 3, # of iterations?
	cout << "How many iterations would you like to see?" << endl
		 << "Keeping in mind how fast you are running the animation," << endl
		 << "enter a number between 1 and 1000 or 0 to quit." << endl;

	cin >> numIters;

	// User input validation.
	while ((numIters < 0) || (numIters > 1000)) {
		cout << "Error! Please enter an integer from 1 to 1000 or 0 to quit." << endl;

		cin >> numIters;

		// Exit while loop if user inputs 0 for quit.
		if (numIters == 0)
			return 0;
	}

	// Program exit if user has input 0 for quit.
	if (numIters == 0)
		return 0;


	// Logic for calling user selected animation functions
	// with x-axis / y-axis offset variable collection.
	
	// Blank Grid
	if (whichOne == 1) {
	
		// Build collector array to pass to animation functions.
		collector[0] = howFast;
		collector[1] = numIters;
		collector[2] = 0;				// There's no x-axis Offset in Basic Grid.
		collector[3] = 0;				// There's no y-axis Offset in Basic Grid.

		blankGrid(collector);
	
	}


	//Stable Grid
	if (whichOne == 2) {
	
		// User input for frame 4, x-axis offset.
		cout << "Where do you want to position the inital Box image vertically when" << endl
			 << "the animation starts?  Partial off grid locations are allowed." << endl
			 << "The animation image is presented on a 40x20 grid so, from the top left corner," << endl
			 << "select an x-axis starting point by entering an integer from 1 to 20" << endl
			 << "or 0 to quit." << endl;

		cin >> xOff;

		// User input validation.
		while ((xOff < 0) || (xOff > 20)) {
			cout << "Error! Please enter an integer from 1 to 20 or 0 to quit." << endl;
			cin >> xOff;

			// Exit while loop if user inputs 0 for quit.
			if (xOff == 0)
				return 0;
		
		}

		// Exit Program if user inputs 0 for quit.
		if (xOff == 0)
			return 0;

		// User input for frame 5, y-axis offsets.
		cout << "Finally, where do you want to position the initial image horizonatally when" << endl
			 << "the animation starts?  Partial off grid locations are allowed." << endl
			 << "The animation image is presented on a 40x20 grid so, from the top left corner," << endl
			 << "select the y-axis starting point by entering an integer fromn 1 to 40" << endl
			 << "or 0 to quit." << endl;

		cin >> yOff;
		cout << endl;

		// User input validation.
		while ((yOff < 0) || (yOff > 40)) {
			cout << "Error! Please enter an integer from 1 to 40 or 0 to quit." << endl;
			cin >> yOff;
			cout << endl;
		
			// Exit while loop if user inputs 0 for quit.
			if (yOff == 0)
				return 0;

		}

		// Exit Program if user inputs 0 for quit.
		if (yOff == 0)
			return 0;

		// Build collector array and pass to animation function.
		collector[0] = howFast;
		collector[1] = numIters;
		collector[2] = xOff;
		collector[3] = yOff;

		stable(collector);
	}


	// Simple Oscillator
	if (whichOne == 3) {

		// User input for frame 4, x-axis offset.
		cout << "Where do you want to position the image center vertically when" << endl
			<< "the animation starts?  Partial off grid locations are allowed." << endl
			<< "The animation image is presented on a 40x20 grid so, from the top left corner," << endl
			<< "select an x-axis starting point by entering an integer from 1 to 20" << endl
			<< "or 0 to quit." << endl;

		cin >> xOff;

		// User input validation.
		while ((xOff < 0) || (xOff > 20)) {
			cout << "Error! Please enter an integer from 1 to 20 or 0 to quit." << endl;
			cin >> xOff;

			// Exit while loop if user inputs 0 for quit.
			if (xOff == 0)
				return 0;

		}

		// Exit Program if user inputs 0 for quit.
		if (xOff == 0)
			return 0;

		// User input for frame 5, y-axis offsets.
		cout << "Finally, where do you want to position the image center horizonatally when" << endl
			 << "the animation starts?  Partial off grid locations are allowed." << endl
			 << "The animation image is presented on a 40x20 grid so, from the top left corner," << endl
			 << "select the y-axis starting point by entering an integer fromn 1 to 40" << endl
			 << "or 0 to quit." << endl;

		cin >> yOff;
		cout << endl;

		// User input validation.
		while ((yOff < 0) || (yOff > 40)) {
			cout << "Error! Please enter an integer from 1 to 40 or 0 to quit." << endl;
			cin >> yOff;
			cout << endl;

			// Exit while loop if user inputs 0 for quit.
			if (yOff == 0)
				return 0;

		}

		// Exit Program if user inputs 0 for quit.
		if (yOff == 0)
			return 0;

		// Build collector array and pass to animation function.
		collector[0] = howFast;
		collector[1] = numIters;
		collector[2] = xOff;
		collector[3] = yOff;

		simpOsc(collector);
	}


	// Jan Kok's Galaxy Oscillator
	if (whichOne == 4) {

		// User input for frame 4, x-axis offset.
		cout << "Where do you want to position the image center vertically when" << endl
			<< "the animation starts?  Partial off grid locations are allowed." << endl
			<< "The animation image is presented on a 40x20 grid so, from the top left corner," << endl
			<< "select an x-axis starting point by entering an integer from 1 to 20" << endl
			<< "or 0 to quit." << endl;

		cin >> xOff;

		// User input validation.
		while ((xOff < 0) || (xOff > 20)) {
			cout << "Error! Please enter an integer from 1 to 20 or 0 to quit." << endl;
			cin >> xOff;

			// Exit while loop if user inputs 0 for quit.
			if (xOff == 0)
				return 0;

		}

		// Exit Program if user inputs 0 for quit.
		if (xOff == 0)
			return 0;

		// User input for frame 5, y-axis offsets.
		cout << "Finally, where do you want to position the image center horizonatally when" << endl
			<< "the animation starts?  Partial off grid locations are allowed." << endl
			<< "The animation image is presented on a 40x20 grid so, from the top left corner," << endl
			<< "select the y-axis starting point by entering an integer fromn 1 to 40" << endl
			<< "or 0 to quit." << endl;

		cin >> yOff;
		cout << endl;

		// User input validation.
		while ((yOff < 0) || (yOff > 40)) {
			cout << "Error! Please enter an integer from 1 to 40 or 0 to quit." << endl;
			cin >> yOff;
			cout << endl;

			// Exit while loop if user inputs 0 for quit.
			if (yOff == 0)
				return 0;

		}

		// Exit Program if user inputs 0 for quit.
		if (yOff == 0)
			return 0;

		// Build collector array and pass to animation function.
		collector[0] = howFast;
		collector[1] = numIters;
		collector[2] = xOff;
		collector[3] = yOff;

		oscillator(collector);
	}


	// Gosper Glider
	if (whichOne == 5) {

		// User input for frame 4, x-axis offset.
		cout << "Where do you want to position the image center vertically when" << endl
			<< "the animation starts?  Start locatons are limited in Quadrant IV." << endl
			<< "The animation image is presented on a 40x20 grid so, from the top left corner," << endl
			<< "select an x-axis starting point by entering an integer from 1 to 15" << endl
			<< "or 0 to quit." << endl;

		cin >> xOff;

		// User input validation.
		while ((xOff < 0) || (xOff > 15)) {
			cout << "Error! Please enter an integer from 1 to 15 or 0 to quit." << endl;
			cin >> xOff;

			// Exit while loop if user inputs 0 for quit.
			if (xOff == 0)
				return 0;

		}

		// Exit Program if user inputs 0 for quit.
		if (xOff == 0)
			return 0;

		// User input for frame 5, y-axis offsets.
		cout << "Finally, where do you want to position the image center horizonatally when" << endl
			<< "the animation starts?   Start locatons are limited in Quadrant IV." << endl
			<< "The animation image is presented on a 40x20 grid so, from the top left corner," << endl
			<< "select the y-axis starting point by entering an integer fromn 1 to 30" << endl
			<< "or 0 to quit." << endl;

		cin >> yOff;
		cout << endl;

		// User input validation.
		while ((yOff < 0) || (yOff > 30)) {
			cout << "Error! Please enter an integer from 1 to 30 or 0 to quit." << endl;
			cin >> yOff;
			cout << endl;

			// Exit while loop if user inputs 0 for quit.
			if (yOff == 0)
				return 0;

		}

		// Exit Program if user inputs 0 for quit.
		if (yOff == 0)
			return 0;

		// Build collector array and pass to animation function.
		collector[0] = howFast;
		collector[1] = numIters;
		collector[2] = xOff;
		collector[3] = yOff;

		glider(collector);
	}


	// Gosper Glider Gun
	if (whichOne == 6) {

		// User input for frame 4, x-axis offset.
		cout << "Where do you want to position the image center vertically when" << endl
			<< "the animation starts?  Since the Gosper Gun is large, we limit positioning." << endl
			<< "The animation image is presented on a 40x20 grid so, from the top left corner," << endl
			<< "select an x-axis starting point by entering an integer from 1 to 10" << endl
			<< "or 0 to quit." << endl;

		cin >> xOff;

		// User input validation.
		while ((xOff < 0) || (xOff > 10)) {
			cout << "Error! Please enter an integer from 1 to 10 or 0 to quit." << endl;
			cin >> xOff;

			// Exit while loop if user inputs 0 for quit.
			if (xOff == 0)
				return 0;

		}

		// Exit Program if user inputs 0 for quit.
		if (xOff == 0)
			return 0;

		// User input for frame 5, y-axis offsets.
		cout << "Finally, where do you want to position the image center horizonatally when" << endl
			<< "the animation starts?  Since the Gosper Gun is large, we limit positioning." << endl
			<< "The animation image is presented on a 40x20 grid so, from the top left corner," << endl
			<< "select the y-axis starting point by entering an integer fromn 1 to 5" << endl
			<< "or 0 to quit." << endl;

		cin >> yOff;
		cout << endl;

		// User input validation.
		while ((yOff < 0) || (yOff > 5)) {
			cout << "Error! Please enter an integer from 1 to 5 or 0 to quit." << endl;
			cin >> yOff;
			cout << endl;

			// Exit while loop if user inputs 0 for quit.
			if (yOff == 0)
				return 0;

		}

		// Exit Program if user inputs 0 for quit.
		if (yOff == 0)
			return 0;

		// Build collector array and pass to animation function.
		collector[0] = howFast;
		collector[1] = numIters;
		collector[2] = xOff;
		collector[3] = yOff;

		gosperGun(collector);
	}
	

	// Finally, clear console and output message.
	cout << "\033[40A"
		 << "\033[2J"
		 << "\033[1; 1H"
		 << "Thank you for playing Chris' version of Conway's Game of Life." << endl;

}
