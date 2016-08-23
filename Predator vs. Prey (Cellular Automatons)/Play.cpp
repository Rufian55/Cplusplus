/****************************************************************************************
** Program Filename: Play.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/7/2016
** Description: Play class implementation file. Utilizes virtual class Critter, then Ant
** and Doodlbug classes.  
** Input:	user, various functions from Critter, Ant, and Doodlebug.
** Output:	to console.
*****************************************************************************************/
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "Play.hpp"
#include<iostream>
using std::cout;
using std::cin;
#include<iomanip>
using std::setw;
#include<cstdlib>
using std::srand;
using std::rand;
#include<sstream>
#include<string>
#include<unistd.h>

/***************************************************************************************
** Function: grid()
** Description: user menu system, initialization of Ant and Doodlbug objects, drives 
** simulation via a double array matriz utilizing move(), starve(), and breed() funtions.
** Parameters:
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: None.
****************************************************************************************/
void Play::grid() {

	int rows = 0;				// user input collection var for matrix rows.
	int cols = 0;				// user input collection var for martix columns.
	int numAnts = 0;			// input collection var.
	int numdBugs = 0;			// input colection var.
	int count_1 = 0;			// local accumulator var for adding Ants.
	int count_2 = 0;			// local accumulator var for adding dBugs.
	int timeSteps = 0;			// incementing time simulation var.
	int iters = 0;				// # of animations outputted.
	int timer = 1000000 / 10;	// Set frame refresh rate.

	cout << "Welcome to Predater Prey!\n";

	cout << "Enter the number of rows for the grid you would like to play on.\n"
		<< "Min is 1, max is 40\n";
	while (!(cin >> rows) || rows < 1 || rows > 40) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input Error!\n"
			<< "Enter the number of rows for the grid you would like to play on.\n"
			<< "Min is 1, max is 40\n";
	}
	setRow(rows);

	cout << "Enter the number of columns for the grid you would like to play on.\n"
		<< "Min is 1, max is 40\n";
	while (!(cin >> cols) || cols < 1 || cols > 40) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input Error!\n"
			<< "Enter the number of columns for the grid you would like to play on.\n"
			<< "Min is 1, max is 40\n";
	}
	setCol(cols);

	int antLimit = rows * cols * 0.75;

	cout << "Enter desired number of Ants from 0 to " << antLimit << ".\n";
	while (!(cin >> numAnts) || numAnts > antLimit || numAnts < 0) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input Error\n"
			<< "Enter desired number of Ants from 0 to " << antLimit << ".\n";
	}

	int dBugLimit = (rows * cols * 0.8) - antLimit;

	cout << "Enter desired number of Doodlebugs from 0 to " << dBugLimit << ".\n";
	while (!(cin >> numdBugs) || numdBugs > dBugLimit || numdBugs < 0) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input Error\n"
			<< "Enter desired number of DoodleBugs from 0 to " << dBugLimit << ".\n";
	}

	cout << "Enter desired number of iterations from 1 to 600,000 you'd like to run.\n";
	while (!(cin >> timeSteps) || timeSteps < 1 || timeSteps > 600000) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input Error!\n"
			<< "Enter desired number of iterations from 1 to 600,000 you'd like to run.\n";
	}
	timeSteps /= 2;
	cout << "\n";

	// Allocate memory for matrix_0 array of Critter pointers
	Critter*** matrix_0 = new Critter**[rows];
	for (int i = 0; i < rows; i++) {
		matrix_0[i] = new Critter*[cols];
	}

	// Null critter pointers.
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix_0[i][j] = NULL;
		}
	}

	//Add Ants to matrix_0
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			while (count_1 < numAnts) {
				int xLoc = getRandRow();
				int yLoc = getRandCol();
				if (matrix_0[xLoc][yLoc] == 0) {
					Ant *ant = new Ant;
					ant->setxLoc(xLoc);
					ant->setyLoc(yLoc);
					matrix_0[xLoc][yLoc] = ant;
					count_1++;
				}
			}
		}
	}

	//Add Doodlebugs to matrix_0 (placed after ants)
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			while (count_2 < numdBugs) {
				int xLoc = getRandRow();
				int yLoc = getRandCol();
				if (matrix_0[xLoc][yLoc] == 0) {
					Doodlebug *dBug = new Doodlebug;
					dBug->setxLoc(xLoc);
					dBug->setyLoc(yLoc);
					matrix_0[xLoc][yLoc] = dBug;
					count_2++;
				}
			}
		}
	}

	// Allocate memory for matrix_1 array of Critter pointers
	Critter*** matrix_1 = new Critter**[rows];
	for (int i = 0; i < rows; i++) {
		matrix_1[i] = new Critter*[cols];
	}

	// Set the matrix_1 array of Critter pointers to NULL.
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix_1[i][j] = NULL;
		}
	}

	//Animation loop +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	for (int timestep = 0; timestep < timeSteps; timestep++) {

		// Output/display matrix_0.
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix_0[i][j] == 0) {
					cout << setw(2) << ".";
				} else if(matrix_0[i][j]->getName() == 'a') {
						cout << palette(29) << setw(2) <<  matrix_0[i][j]->getName() << palette(1);
					}
					else if(matrix_0[i][j]->getName() == 'D') {
						cout << palette(14) << setw(2) << matrix_0[i][j]->getName() << palette(1);
					}
				}
			cout << "\n";
			}

		// Animation refresh rate.
		usleep(timer);
		iters++;

		// Move cursor up above matrix_0 rendering, clear console, user message!
		cout << cursorMover() << "Predator-Prey is running! " << "Time Steps = " << iters << "\n";
        
		//Build matrix_1 ****************************************************************************************************
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix_1[i][j] = matrix_0[i][j];
				matrix_0[i][j] = NULL;
				if (matrix_1[i][j] != 0) {
					if (matrix_1[i][j]->getStarve() == 3) {		// Hasn't eaten in 3 timeSteps so dbug dies!
						delete matrix_1[i][j];
						matrix_1[i][j] = NULL;
					}
				}
			}
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix_1[i][j] != 0) {									// matrix_0 array element is a Critter.
					if (matrix_1[i][j]->getName() == 'D') {					// Object is a dBug.
						matrix_1[i][j]->move(i, j, rows, cols);				// Determine proposed new coordinates.
						int anX = matrix_1[i][j]->getxLoc();				// Get dBug's proposed new x coordinate.
						int anY = matrix_1[i][j]->getyLoc();				// Get dBug's proposed new y coordinate.
						if (matrix_1[anX][anY] == 0) {						// Dont't call getName() on NULL Ptr!
							matrix_1[anX][anY] = matrix_1[i][j];
							matrix_1[i][j] = NULL;
							matrix_1[anX][anY]->setSteps(1);
							matrix_1[anX][anY]->setStarve(1);				// Didn't eat an Ant! Incur a starveStep!

							if (matrix_1[anX][anY]->getSteps() == 8) {		// Check for dBug Breeding
								matrix_1[anX][anY]->setSteps();
								if (anX != 0) {								// UP
									if (matrix_1[anX - 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX - 1);
										dBug->setyLoc(anY);
										matrix_1[anX - 1][anY] = dBug;
									}
								}
								else if (anY != (cols - 1)) {				// RIGHT
									if (matrix_1[anX][anY + 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY + 1);
										matrix_1[anX][anY + 1] = dBug;
									}
								}
								else if (anX != (rows - 1)) {				// DOWN
									if (matrix_1[anX + 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX + 1);
										dBug->setyLoc(anY);
										matrix_1[anX + 1][anY] = dBug;
									}
								}
								else if (anY != 0) {						// LEFT
									if (matrix_1[anX][anY - 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY - 1);
										matrix_1[anX][anY + 1] = dBug;
									}
								}
							}
						}
						else if (matrix_1[anX][anY]->getName() == 'a') {	// Eat the Ant!
							delete matrix_1[anX][anY];						// First delete the Ant.
							matrix_1[anX][anY] = NULL;						// Set the pointer to NULL.
							matrix_1[anX][anY] = matrix_1[i][j];			// Move the Doodlebug to the proposed location.
							matrix_1[i][j] = NULL;
							matrix_1[anX][anY]->setSteps(1);
							matrix_1[anX][anY]->setStarve();				// Reset this DoodleBug's starveSteps to 0.

							if (matrix_1[anX][anY]->getSteps() == 8) {		// Check for dBug Breeding
								matrix_1[anX][anY]->setSteps();
								if (anX != 0) {								// UP
									if (matrix_1[anX - 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX - 1);
										dBug->setyLoc(anY);
										matrix_1[anX - 1][anY] = dBug;
									}
								}
								else if (anY != (cols - 1)) {				// RIGHT
									if (matrix_1[anX][anY + 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY + 1);
										matrix_1[anX][anY + 1] = dBug;
									}
								}
								else if (anX != (rows - 1)) {				// DOWN
									if (matrix_1[anX + 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX + 1);
										dBug->setyLoc(anY);
										matrix_1[anX + 1][anY] = dBug;
									}
								}
								else if (anY != 0) {						// LEFT
									if (matrix_1[anX][anY - 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY - 1);
										matrix_1[anX][anY + 1] = dBug;
									}
								}
							}
						}
						else {												// New proposed location is another dBug,
							matrix_1[i][j]->setxLoc(i);						// so we don't move.
							matrix_1[i][j]->setyLoc(j);
							matrix_1[anX][anY]->setSteps(1);
							matrix_1[anX][anY]->setStarve(1);				// Didn't eat an ant! Incur a starveStep!

							if (matrix_1[anX][anY]->getSteps() == 8) {		// Check for dBug Breeding
								matrix_1[anX][anY]->setSteps();
								if (anX != 0) {								// UP
									if (matrix_1[anX - 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX - 1);
										dBug->setyLoc(anY);
										matrix_1[anX - 1][anY] = dBug;
									}
								}
								else if (anY != (cols - 1)) {				// RIGHT
									if (matrix_1[anX][anY + 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY + 1);
										matrix_1[anX][anY + 1] = dBug;
									}
								}
								else if (anX != (rows - 1)) {				// DOWN
									if (matrix_1[anX + 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX + 1);
										dBug->setyLoc(anY);
										matrix_1[anX + 1][anY] = dBug;
									}
								}
								else if (anY != 0) {						// LEFT
									if (matrix_1[anX][anY - 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY - 1);
										matrix_1[anX][anY + 1] = dBug;
									}
								}
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix_1[i][j] != 0) {									// matrix_0 array element is a Critter.
					if (matrix_1[i][j]->getName() == 'a') {					// Object is an Ant.
						matrix_1[i][j]->move(i, j, rows, cols);				// Determine proposed new coordinates.
						int anX = matrix_1[i][j]->getxLoc();				// Get Ant's proposed new x coordinate.
						int anY = matrix_1[i][j]->getyLoc();				// Get Ant's proposed new y coordinate.
						if (matrix_1[anX][anY] == 0) {						// Dont't call getName() on NULL Ptr!
							matrix_1[anX][anY] = matrix_1[i][j];
							matrix_1[i][j] = NULL;
							matrix_1[anX][anY]->setSteps(1);

							if (matrix_1[anX][anY]->getSteps() == 4) {		// Check for Ant Breeding
								matrix_1[anX][anY]->setSteps();
								if (anX != 0) {								// UP
									if (matrix_1[anX - 1][anY] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX - 1);
										ant->setyLoc(anY);
										matrix_1[anX - 1][anY] = ant;
									}
								} else if (anY != (cols - 1)) {				// RIGHT
									if (matrix_1[anX][anY + 1] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX);
										ant->setyLoc(anY + 1);
										matrix_1[anX][anY + 1] = ant;
									}
								} else if (anX != (rows - 1)) {				// DOWN
									if (matrix_1[anX + 1][anY] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX + 1);
										ant->setyLoc(anY);
										matrix_1[anX + 1][anY] = ant;
									}
								} else if (anY != 0) {						// LEFT
									if (matrix_1[anX][anY - 1] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX);
										ant->setyLoc(anY - 1);
										matrix_1[anX][anY + 1] = ant;
									}
								}
							}
						}
						else {												// New proposed location is another Critter,
							matrix_1[i][j]->setxLoc(i);						// so we don't move.
							matrix_1[i][j]->setyLoc(j);
							matrix_1[i][j]->setSteps(1);
							if (matrix_1[anX][anY]->getSteps() == 4) {		// Check for Ant Breeding
								matrix_1[anX][anY]->setSteps();
								if (anX != 0) {								// UP
									if (matrix_1[anX - 1][anY] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX - 1);
										ant->setyLoc(anY);
										matrix_1[anX - 1][anY] = ant;
									}
								} else if (anY != (cols - 1)) {				// RIGHT
									if (matrix_1[anX][anY + 1] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX);
										ant->setyLoc(anY + 1);
										matrix_1[anX][anY + 1] = ant;
									}
								} else if (anX != (rows - 1)) {				// DOWN
									if (matrix_1[anX + 1][anY] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX + 1);
										ant->setyLoc(anY);
										matrix_1[anX + 1][anY] = ant;
									}
								} else if (anY != 0) {						// LEFT
									if (matrix_1[anX][anY - 1] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX);
										ant->setyLoc(anY - 1);
										matrix_1[anX][anY + 1] = ant;
									}
								}
							}
						}
					}
				}
			}
		}
		// End matrix_1 build************************************************************************************************

		// Output/display matrix_1.
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix_1[i][j] == 0) {
					cout << setw(2) << ".";
				}
				else if (matrix_1[i][j]->getName() == 'a') {
					cout << palette(29) << setw(2) << matrix_1[i][j]->getName() << palette(1);
				}
				else if (matrix_1[i][j]->getName() == 'D') {
					cout << palette(14) << setw(2) << matrix_1[i][j]->getName() << palette(1);
				}
			}
			cout << "\n";
		}

		//Build matrix_0 *****************************************************************************************************
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix_0[i][j] = matrix_1[i][j];
				matrix_1[i][j] = NULL;
				if (matrix_0[i][j] != 0) {
					if (matrix_0[i][j]->getStarve() == 3) {					// Hasn't eaten in 3 timeSteps so dbug dies!
						delete matrix_0[i][j];
						matrix_0[i][j] = NULL;
					}
				}
			}
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix_0[i][j] != 0) {									// matrix_0 array element is a Critter.
					if (matrix_0[i][j]->getName() == 'D') {					// Object is a dBug.
						matrix_0[i][j]->move(i, j, rows, cols);				// Determine proposed new coordinates.
						int anX = matrix_0[i][j]->getxLoc();				// Get dBug's proposed new x coordinate.
						int anY = matrix_0[i][j]->getyLoc();				// Get dBug's proposed new y coordinate.
						if (matrix_0[anX][anY] == 0) {						// Dont't call getName() on NULL Ptr!
							matrix_0[anX][anY] = matrix_0[i][j];
							matrix_0[i][j] = NULL;
							matrix_0[anX][anY]->setSteps(1);
							matrix_0[anX][anY]->setStarve(1);				// Didn't eat an Ant! Incur a starveStep!

							if (matrix_0[anX][anY]->getSteps() == 8) {		// Check for Breeding
								matrix_0[anX][anY]->setSteps();
								if (anX != 0) {								// UP
									if (matrix_0[anX - 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX - 1);
										dBug->setyLoc(anY);
										matrix_0[anX - 1][anY] = dBug;
									}
								}
								else if (anY != (cols - 1)) {				// RIGHT
									if (matrix_0[anX][anY + 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY + 1);
										matrix_0[anX][anY + 1] = dBug;
									}
								}
								else if (anX != (rows - 1)) {				// DOWN
									if (matrix_0[anX + 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX + 1);
										dBug->setyLoc(anY);
										matrix_0[anX + 1][anY] = dBug;
									}
								}
								else if (anY != 0) {						// LEFT
									if (matrix_0[anX][anY - 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY - 1);
										matrix_0[anX][anY + 1] = dBug;
									}
								}
							}
						}
						else if (matrix_0[anX][anY]->getName() == 'a') {	// Eat the Ant!
							delete matrix_0[anX][anY];						// First delete the Ant.
							matrix_0[anX][anY] = NULL;						// Set the pointer to NULL.
							matrix_0[anX][anY] = matrix_0[i][j];			// Move the Doodlebug to the proposed location.
							matrix_0[i][j] = NULL;
							matrix_0[anX][anY]->setSteps(1);
							matrix_0[anX][anY]->setStarve();				// Reset this DoodleBug's starveSteps to 0.
							if (matrix_0[anX][anY]->getSteps() == 8) {		// Check for Breeding
								matrix_0[anX][anY]->setSteps();
								if (anX != 0) {								// UP
									if (matrix_0[anX - 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX - 1);
										dBug->setyLoc(anY);
										matrix_0[anX - 1][anY] = dBug;
									}
								}
								else if (anY != (cols - 1)) {				// RIGHT
									if (matrix_0[anX][anY + 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY + 1);
										matrix_0[anX][anY + 1] = dBug;
									}
								}
								else if (anX != (rows - 1)) {				// DOWN
									if (matrix_0[anX + 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX + 1);
										dBug->setyLoc(anY);
										matrix_0[anX + 1][anY] = dBug;
									}
								}
								else if (anY != 0) {						// LEFT
									if (matrix_0[anX][anY - 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY - 1);
										matrix_0[anX][anY + 1] = dBug;
									}
								}
							}
						}
						else {												// New proposed location is another dBug,
							matrix_0[i][j]->setxLoc(i);						// so we don't move.
							matrix_0[i][j]->setyLoc(j);
							matrix_0[anX][anY]->setSteps(1);
							matrix_0[anX][anY]->setStarve(1);				// Didn't eat an ant! Incur a starveStep!
							if (matrix_0[anX][anY]->getSteps() == 8) {		// Check for Breeding
								matrix_0[anX][anY]->setSteps();
								if (anX != 0) {								// UP
									if (matrix_0[anX - 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX - 1);
										dBug->setyLoc(anY);
										matrix_0[anX - 1][anY] = dBug;
									}
								}
								else if (anY != (cols - 1)) {				// RIGHT
									if (matrix_0[anX][anY + 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY + 1);
										matrix_0[anX][anY + 1] = dBug;
									}
								}
								else if (anX != (rows - 1)) {				// DOWN
									if (matrix_0[anX + 1][anY] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX + 1);
										dBug->setyLoc(anY);
										matrix_0[anX + 1][anY] = dBug;
									}
								}
								else if (anY != 0) {						// LEFT
									if (matrix_0[anX][anY - 1] == 0) {
										Doodlebug *dBug = new Doodlebug;
										dBug->setxLoc(anX);
										dBug->setyLoc(anY - 1);
										matrix_0[anX][anY + 1] = dBug;
									}
								}
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix_0[i][j] != 0) {									// matrix_0 array element is a Critter.
					if (matrix_0[i][j]->getName() == 'a') {					// Object is an Ant.
						matrix_0[i][j]->move(i, j, rows, cols);				// Determine proposed new coordinates.
						int anX = matrix_0[i][j]->getxLoc();				// Get Ant's proposed new x coordinate.
						int anY = matrix_0[i][j]->getyLoc();				// Get Ant's proposed new y coordinate.
						if (matrix_0[anX][anY] == 0) {						// Dont't call getName() on NULL Ptr!
							matrix_0[anX][anY] = matrix_0[i][j];
							matrix_0[i][j] = NULL;
							matrix_0[anX][anY]->setSteps(1);

							if (matrix_0[anX][anY]->getSteps() == 4) {		// Check for Breeding
								matrix_0[anX][anY]->setSteps();
								if (anX != 0) {								// UP
									if (matrix_0[anX - 1][anY] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX - 1);
										ant->setyLoc(anY);
										matrix_0[anX - 1][anY] = ant;
									}
								}
								else if (anY != (cols - 1)) {				// RIGHT
									if (matrix_0[anX][anY + 1] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX);
										ant->setyLoc(anY + 1);
										matrix_0[anX][anY + 1] = ant;
									}
								}
								else if (anX != (rows - 1)) {				// DOWN
									if (matrix_0[anX + 1][anY] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX + 1);
										ant->setyLoc(anY);
										matrix_0[anX + 1][anY] = ant;
									}
								}
								else if (anY != 0) {						// LEFT
									if (matrix_0[anX][anY - 1] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX);
										ant->setyLoc(anY - 1);
										matrix_0[anX][anY + 1] = ant;
									}
								}
							}
						}
						else {												// New proposed location is another Critter,
							matrix_0[i][j]->setxLoc(i);						// so we don't move.
							matrix_0[i][j]->setyLoc(j);
							matrix_0[i][j]->setSteps(1);
							if (matrix_0[anX][anY]->getSteps() == 4) {		// Check for Breeding
								matrix_0[anX][anY]->setSteps();
								if (anX != 0) {								// UP
									if (matrix_0[anX - 1][anY] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX - 1);
										ant->setyLoc(anY);
										matrix_0[anX - 1][anY] = ant;
									}
								}
								else if (anY != (cols - 1)) {				// RIGHT
									if (matrix_0[anX][anY + 1] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX);
										ant->setyLoc(anY + 1);
										matrix_0[anX][anY + 1] = ant;
									}
								}
								else if (anX != (rows - 1)) {				// DOWN
									if (matrix_0[anX + 1][anY] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX + 1);
										ant->setyLoc(anY);
										matrix_0[anX + 1][anY] = ant;
									}
								}
								else if (anY != 0) {						// LEFT
									if (matrix_0[anX][anY - 1] == 0) {
										Ant *ant = new Ant;
										ant->setxLoc(anX);
										ant->setyLoc(anY - 1);
										matrix_0[anX][anY + 1] = ant;
									}
								}
							}
						}
					}
				}
			}
		}
		// End matrix_0 build*************************************************************************************************

		// Animation refresh rate.
		usleep(timer);
		iters++;

		// Move cursor up above matrix_1 rendering, clear console, user message!
		cout << cursorMover() << "Predator-Prey is running! " << "Time Steps = " << iters << "\n";

	}//End Animation Loop +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	 // Manage memory for matrix_0
	 for (int i = 0; i < rows; i++) {
		 for (int j = 0; j < cols; j++) {
			 if (matrix_0[i][j] != 0) {
				 delete matrix_0[i][j];
				 matrix_0[i][j] = NULL;
				}
			 matrix_0[i][j] = NULL;
			}
		 delete[] matrix_0[i];
	 }
	 delete[] matrix_0;
	 matrix_0 = NULL;


	 // Manage memory for matrix_1
	 for (int i = 0; i < rows; i++) {
		 for (int j = 0; j < cols; j++) {
			 if (matrix_1[i][j] != 0) {
				 delete matrix_1[i][j];
				 matrix_1[i][j] = NULL;
			 }
			 matrix_1[i][j] = NULL;
		 }
		 delete[] matrix_1[i];
	 }
	 delete[] matrix_1;
	 matrix_1 = NULL;

}// End function grid()


void Play::setRow(int row) {
	this->row = row;
}

int Play::getRow() {
	return row;
}

void Play::setCol(int col) {
	this->col = col;
}

int Play::getCol() {
	return col;
}

/***************************************************************************************
** Function: getRandRow()
** Description: returns a random row location for Ant and Doodlebug initialization and
** placement on the grid.
** Parameters: none
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: None.
****************************************************************************************/
int Play::getRandRow() {
	int *xLoc = new int[getRow()];
	for (int i = 0; i < getRow(); i++) {
		xLoc[i] = i;
	}
	for (int i = 1; i < getRow(); i++) {
		int j = rand() % i;
		int temp = xLoc[i];
		xLoc[i] = xLoc[j];
		xLoc[j] = temp;
	}
	int val = xLoc[1];

	delete [] xLoc;
	xLoc = NULL;

	return val;
}


/***************************************************************************************
** Function: getRandcol()
** Description: returns a random col location for Ant and Doodlebug initialization and
** placement on the grid.
** Parameters: none
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: None.
****************************************************************************************/
int Play::getRandCol() {
	int *yLoc = new int[getCol()];
	for (int i = 0; i < getCol(); i++) {
		yLoc[i] = i;
	}
	for (int i = 1; i < getRow(); i++) {
		int j = rand() % i;
		int temp = yLoc[i];
		yLoc[i] = yLoc[j];
		yLoc[j] = temp;
	}
	int val = yLoc[1];

	delete [] yLoc;
	yLoc = NULL;

	return val;
}


/***************************************************************************************
** Function: cursorMover()
** Description: Used to build string for returning cursor to top of console display
** for varaible length rows.
** Parameters: requires user input to establish desired row var for getRow() call.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: console display cursor movement.
****************************************************************************************/
string Play::cursorMover() {
	int anInt = getRow() + 1;
	string rows2move;
	std::ostringstream temp;
	temp << anInt;
	rows2move = temp.str();
	string cursor = "\033[" + rows2move + "A";
	return cursor;
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
string Play::palette(int color) {
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