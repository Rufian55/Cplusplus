/****************************************************************************************
** Program Filename: GrandPrize.cpp
** Author: Chris Kearns
** Date: 3/17/2016
** Description: Contains the grandPrize() function.
** Input: array "collector"
** Output: Used by Main.cpp to generate Jan Kok's Galaxy oscillator animation.
*****************************************************************************************/
#include "GrandPrize.hpp"
#include <iomanip>
using std::setw;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>

/***************************************************************************************
** Function: grandPrize()
** Description:Description: animation function that generates Jan Kok's Galaxy images.
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: None.
****************************************************************************************/
void GrandPrize::grandPrize() {
	int univRows, winRows, univCols, winCols;
	univRows = 60;					// Row bounds of our Universe.
	winRows = 40;					// Row bounds of our Window.
	univCols = 40;					// Column bounds of our Universe.
	winCols = 20;					// Column bounds of our Window.
	int time = 50000 * 2;				// Time between iterations.
	int iterations = 19;				// Iterations desired by user.
	int aliveCount = 0;				// Counter to determine cell state.
	int xOffset = 20;				// x axis offset for initial image.
	int yOffset = 20;				// y-axis offset for inital image.
	std::string matrix_0[univRows][univCols];	// Our initial Universe array matrix_0 - all cells dead.

	// Fill matrix_0 with " "
	for (int i = 0; i < univRows; i++) {
		for (int j = 0; j < univCols; j++) {
			matrix_0[i][j] = " ";
		}
	}
	
	// "Inject" initial Galaxy image.
	int i, j;
	i = j = 0;

	matrix_0[i - 4 + yOffset][j - 2 + xOffset] = "*";
	matrix_0[i - 4 + yOffset][j + 1 + xOffset] = "*";
	matrix_0[i - 4 + yOffset][j + 3 + xOffset] = "*";
	matrix_0[i - 3 + yOffset][j - 4 + xOffset] = "*";
	matrix_0[i - 3 + yOffset][j - 3 + xOffset] = "*";
	matrix_0[i - 3 + yOffset][j - 1 + xOffset] = "*";
	matrix_0[i - 3 + yOffset][j + 1 + xOffset] = "*";
	matrix_0[i - 3 + yOffset][j + 2 + xOffset] = "*";
	matrix_0[i - 3 + yOffset][j + 3 + xOffset] = "*";
	matrix_0[i - 2 + yOffset][j - 3 + xOffset] = "*";
	matrix_0[i - 2 + yOffset][j + 4 + xOffset] = "*";
	matrix_0[i - 1 + yOffset][j - 4 + xOffset] = "*";
	matrix_0[i - 1 + yOffset][j - 3 + xOffset] = "*";
	matrix_0[i - 1 + yOffset][j + 3 + xOffset] = "*";
	matrix_0[i + 1 + yOffset][j - 3 + xOffset] = "*";
	matrix_0[i + 1 + yOffset][j + 3 + xOffset] = "*";
	matrix_0[i + 1 + yOffset][j + 4 + xOffset] = "*";
	matrix_0[i + 2 + yOffset][j - 4 + xOffset] = "*";
	matrix_0[i + 2 + yOffset][j + 3 + xOffset] = "*";
	matrix_0[i + 3 + yOffset][j - 3 + xOffset] = "*";
	matrix_0[i + 3 + yOffset][j - 2 + xOffset] = "*";
	matrix_0[i + 3 + yOffset][j - 1 + xOffset] = "*";
	matrix_0[i + 3 + yOffset][j + 1 + xOffset] = "*";
	matrix_0[i + 3 + yOffset][j + 3 + xOffset] = "*";
	matrix_0[i + 3 + yOffset][j + 4 + xOffset] = "*";
	matrix_0[i + 4 + yOffset][j - 3 + xOffset] = "*";
	matrix_0[i + 4 + yOffset][j - 1 + xOffset] = "*";
	matrix_0[i + 4 + yOffset][j + 2 + xOffset] = "*";

	// Our initial Universe array matrix_1 - all cells dead.
	std::string matrix_1[univRows][univCols];

	// Fill matrix_1 with " "
	for (int i = 0; i < univRows; i++) {
		for (int j = 0; j < univCols; j++) {
			matrix_1[i][j] = " ";
		}
	}

	//Animation loop.
	for (int i = 0; i < iterations; i++) {
		// Output/display matrix_0.
		cout << palette(24) << "";
		for (int i = 10; i < winRows + 10; i++) {
			for (int j = 10; j < winCols + 10; j++) {
				cout << setw(4) << matrix_0[i][j];
			}
			cout << endl;
		}
		cout << palette(1) << "";
		usleep(time);

		// Move cursor up above matrix_1 rendering.
		cout << "\033[41A" << palette(24) << "\tYou are the winner!! For Two Full Weeks, YOU"
			<< " are Ruler of the Galaxy!" << palette(1) << "\n";

		//Build matrix_1 *********************************************************
		// Determine change in state events.
		for (int i = 1; i < 59; i++) {
			for (int j = 1; j < 39; j++) {

				aliveCount = 0;				// Count occupied cells.

				if (matrix_0[i - 1][j - 1] == "*")	// Top left.
					aliveCount++;
				if (matrix_0[i - 1][j] == "*")		// Top center.
					aliveCount++;
				if (matrix_0[i - 1][j + 1] == "*")	// Top right.
					aliveCount++;
				if (matrix_0[i][j + 1] == "*")		// Center right.
					aliveCount++;
				if (matrix_0[i][j - 1] == "*")		// Bottom right.
					aliveCount++;
				if (matrix_0[i + 1][j + 1] == "*")	// Bottom center.
					aliveCount++;
				if (matrix_0[i + 1][j] == "*")		// Bottom left.
					aliveCount++;
				if (matrix_0[i + 1][j - 1] == "*")	// Center left.
					aliveCount++;

				// Rule #1: If occupied cell has 0, 1, or > 3 neighbors it dies!
				if ((matrix_0[i][j] == "*") && ((aliveCount < 2) || (aliveCount > 3))) {
					matrix_1[i][j] = " ";
				}
				else {//Rule #2: If occupied cell has 2 or 3 neighbors it lives!
					if ((matrix_0[i][j] == "*") && ((aliveCount > 1) && (aliveCount < 4))) {
						matrix_1[i][j] = "*";
					}
				}

				// Rule #3: If unoccupied cell has 3 neighbors, an '*' is "born"!
				if ((matrix_0[i][j] == " ") && (aliveCount == 3)) {
					matrix_1[i][j] = "*";
				}
				else {
					if ((matrix_1[i][j] == " ") && (aliveCount != 3)) {
						matrix_1[i][j] = " ";
					}
				}
			}
		}
		// End matrix_1 build****************************************************

		// Reset Matrix_0
		for (int i = 0; i < univRows; i++) {
			for (int j = 0; j < univCols; j++) {
				matrix_0[i][j] = " ";
			}
		}

		// Output/display matrix_1
		cout << palette(19) << "";
		for (int i = 10; i < winRows + 10; i++) {
			for (int j = 10; j < winCols + 10; j++) {
				cout << setw(4) << matrix_1[i][j];
			}
			cout << endl;
		}
		cout << palette(1) << "";
		// Build matrix_0 *********************************************************
		// Determine change in state events.
		for (int i = 1; i < 59; i++) {
			for (int j = 1; j < 39; j++) {

				aliveCount = 0;				// Count occupied cells.

				if (matrix_1[i - 1][j - 1] == "*")	// Top left.
					aliveCount++;
				if (matrix_1[i - 1][j] == "*")		// Top center.
					aliveCount++;
				if (matrix_1[i - 1][j + 1] == "*")	// Top right.
					aliveCount++;
				if (matrix_1[i][j + 1] == "*")		// Center right.
					aliveCount++;
				if (matrix_1[i][j - 1] == "*")		// Bottom right.
					aliveCount++;
				if (matrix_1[i + 1][j + 1] == "*")	// Bottom center.
					aliveCount++;
				if (matrix_1[i + 1][j] == "*")		// Bottom left.
					aliveCount++;
				if (matrix_1[i + 1][j - 1] == "*")	// Center left.
					aliveCount++;

				// Rule #1: Occupied cell has 0, 1, or > 3 neighbors it dies!
				if ((matrix_1[i][j] == "*") && ((aliveCount < 2) || (aliveCount > 3))) {
					matrix_0[i][j] = " ";
				}
				else {//Rule #2: Occupied cell has 2 or 3 neighbors it lives!
					if ((matrix_1[i][j] == "*") && ((aliveCount > 1) && (aliveCount < 4))) {
						matrix_0[i][j] = "*";
					}
				}

				// Rule #3: Unoccupied cell has 3 neighbors, an '*' is "born"!
				if ((matrix_1[i][j] == " ") && (aliveCount == 3)) {
					matrix_0[i][j] = "*";
				}
				else {
					if ((matrix_1[i][j] == " ") && (aliveCount != 3)) {
						matrix_0[i][j] = " ";
					}
				}
			}
		}
		// End matrix_0 build****************************************************

		// Reset matrix_1
		for (int i = 0; i < univRows; i++) {
			for (int j = 0; j < univCols; j++) {
				matrix_1[i][j] = " ";
			}
		}
		usleep(time);

		// Move cursor up above matrix_1 rendering, clear console, user message!
		cout << "\033[41A" << palette(19) << "\tYou are the winner!! For Two Full Weeks, YOU"
			<< " are Ruler of the Galaxy!" << palette(1) << "\n";
	} // End animation loop.
	cout << palette(1) << "\033[60B";
}
