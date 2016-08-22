/****************************************************************************************
** Program Filename: GosperGun.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 1/17/2016
** Description: Contains the gosperGun() function.
** Input: array "collector"
** Output: Used by Main.cpp to generate Gosper Gun animation.
*****************************************************************************************/
#include "GosperGun.hpp"
#include <iomanip>
using std::setw;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


/***************************************************************************************
** Function: gosperGun()
** Description: animation function that generates Gosper Gun images.
** Parameters: array "collector" contains 5 user inputted animation control variables. 
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: None.
****************************************************************************************/
void gosperGun(int anArray[]) {
	int univRows, winRows, univCols, winCols;
	univRows = 60;									// Row bounds of our Universe.
	winRows = 40;									// Row bounds of our Window.
	univCols = 40;									// Column bounds of our Universe.
	winCols = 20;									// Column bounds of our Window.
	int iter = 0;									// Counter - each matrix outputed is 1 iteration.
	int time = 50000 * anArray[0];					// Time between iterations.
	int iterations = anArray[1];					// Iterations desired by user.
	int aliveCount = 0;								// Counter to determine cell state.
	int xOffset = anArray[2] + 18;			// x axis offset for initial image. (collector[2] ignored). (20)
	int yOffset = 31 - anArray[3];			// y-axis offset for initial image. (collector[3]) ignored). (30)

	// Our initial Universe array matrix_0 - all cells dead.
	std::string matrix_0[univRows][univCols];

	// Fill matrix_0 with "."
	for (int i = 0; i < univRows; i++) {
		for (int j = 0; j < univCols; j++) {
			matrix_0[i][j] = ".";
		}
	}

	// "Inject" initial image into matrix_0. See footnote (4) in Main.cpp
	int i, j;
	i = j = 0;
	
	matrix_0[i - 16 + yOffset][j - 7 + xOffset] = "X";
	matrix_0[i - 16 + yOffset][j - 6 + xOffset] = "X";
	matrix_0[i - 15 + yOffset][j - 7 + xOffset] = "X";
	matrix_0[i - 15 + yOffset][j - 6 + xOffset] = "X";
	matrix_0[i - 5 + yOffset][j - 9 + xOffset] = "X";
	matrix_0[i - 5 + yOffset][j - 8 + xOffset] = "X";
	matrix_0[i - 5 + yOffset][j - 4 + xOffset] = "X";
	matrix_0[i - 5 + yOffset][j - 3 + xOffset] = "X";
	matrix_0[i - 3 + yOffset][j - 8 + xOffset] = "X";
	matrix_0[i - 3 + yOffset][j - 4 + xOffset] = "X";
	matrix_0[i - 2 + yOffset][j - 7 + xOffset] = "X";
	matrix_0[i - 2 + yOffset][j - 6 + xOffset] = "X";
	matrix_0[i - 2 + yOffset][j - 5 + xOffset] = "X";
	matrix_0[i - 1 + yOffset][j - 7 + xOffset] = "X";
	matrix_0[i - 1 + yOffset][j - 6 + xOffset] = "X";
	matrix_0[i - 1 + yOffset][j - 5 + xOffset] = "X";
	matrix_0[i + 2 + yOffset][j - 4 + xOffset] = "X";
	matrix_0[i + 3 + yOffset][j - 5 + xOffset] = "X";
	matrix_0[i + 3 + yOffset][j - 4 + xOffset] = "X";
	matrix_0[i + 3 + yOffset][j - 3 + xOffset] = "X";
	matrix_0[i + 4 + yOffset][j - 6 + xOffset] = "X";
	matrix_0[i + 4 + yOffset][j - 2 + xOffset] = "X";
	matrix_0[i + 5 + yOffset][j - 4 + xOffset] = "X";
	matrix_0[i + 6 + yOffset][j - 7 + xOffset] = "X";
	matrix_0[i + 6 + yOffset][j - 1 + xOffset] = "X";
	matrix_0[i + 7 + yOffset][j - 7 + xOffset] = "X";
	matrix_0[i + 7 + yOffset][j -1 + xOffset] = "X";
	matrix_0[i + 8 + yOffset][j - 6 + xOffset] = "X";
	matrix_0[i + 8 + yOffset][j - 2 + xOffset] = "X";
	matrix_0[i + 9 + yOffset][j - 5 + xOffset] = "X";
	matrix_0[i + 9 + yOffset][j - 4 + xOffset] = "X";
	matrix_0[i + 9 + yOffset][j - 3 + xOffset] = "X";
	matrix_0[i + 18 + yOffset][j - 5 + xOffset] = "X";
	matrix_0[i + 18 + yOffset][j - 4 + xOffset] = "X";
	matrix_0[i + 19 + yOffset][j - 5 + xOffset] = "X";
	matrix_0[i + 19 + yOffset][j - 4 + xOffset] = "X";

	// Our initial Universe array matrix_1 - all cells dead.
	std::string matrix_1[univRows][univCols];

	// Fill matrix_1 with "."
	for (int i = 0; i < univRows; i++) {
		for (int j = 0; j < univCols; j++) {
			matrix_1[i][j] = ".";
		}
	}


	//Animation loop.
	for (int i = 0; i < iterations; i++) {

		// Output/display matrix_0.
		for (int i = 10; i < winRows + 10; i++) {
			for (int j = 10; j < winCols + 10; j++) {
				cout << setw(4) << matrix_0[i][j];
			}
			cout << endl;
		}

		// Sleep. See footnote(3) in Main.cpp.
		usleep(time); 

		// Move cursor up above matrix_1 rendering. See footnote (1) in Main.cpp
		cout << "\033[41A" << "Gosper Glider Gun is running from point: (" << anArray[2]
			<< "," << anArray[3] << "). " << "Iteration count = " << iter << endl;

		//Build matrix_1 *********************************************************
		// Determine change in state events.
		for (int i = 1; i < 59; i++) {
			for (int j = 1; j < 39; j++) {

				aliveCount = 0;						// Count occupied cells.

				if (matrix_0[i - 1][j - 1] == "X")	// Top left.
					aliveCount++;
				if (matrix_0[i - 1][j] == "X")		// Top center.
					aliveCount++;
				if (matrix_0[i - 1][j + 1] == "X")	// Top right.
					aliveCount++;
				if (matrix_0[i][j + 1] == "X")		// Center right.
					aliveCount++;
				if (matrix_0[i][j - 1] == "X")		// Bottom right.
					aliveCount++;
				if (matrix_0[i + 1][j + 1] == "X")	// Bottom center.
					aliveCount++;
				if (matrix_0[i + 1][j] == "X")		// Bottom left.
					aliveCount++;
				if (matrix_0[i + 1][j - 1] == "X")	// Center left.
					aliveCount++;

				// Rule #1: If occupied cell has 0, 1, or > 3 neighbors it dies!
				if ((matrix_0[i][j] == "X") && ((aliveCount < 2) || (aliveCount > 3))) {
					matrix_1[i][j] = ".";
				}
				else {//Rule #2: If occupied cell has 2 or 3 neighbors it lives!
					if ((matrix_0[i][j] == "X") && ((aliveCount > 1 ) && (aliveCount < 4))) {
						matrix_1[i][j] = "X";
					}
				}
								
				// Rule #3: If unoccupied cell has 3 neighbors, a 'X' is "born"!
				if ((matrix_0[i][j] == ".") && (aliveCount == 3)) {
					matrix_1[i][j] = "X";
				}
				else {
					if ((matrix_1[i][j] == ".") && (aliveCount != 3)) {
						matrix_1[i][j] = ".";
					}
				}
			}
		}
		// End matrix_1 build****************************************************

		// Reset Matrix_0
		for (int i = 0; i < univRows; i++) {
			for (int j = 0; j < univCols; j++) {
				matrix_0[i][j] = ".";
			}
		}

		// Output/display matrix_1
		for (int i = 10; i < winRows + 10; i++) {
			for (int j = 10; j < winCols + 10; j++) {
				cout << setw(4) << matrix_1[i][j];
			}
			cout << endl;
		}

		// Build matrix_0 *********************************************************
		// Determine change in state events.
		for (int i = 1; i < 59; i++) {
			for (int j = 1; j < 39; j++) {

				aliveCount = 0;						// Count occupied cells.

				if (matrix_1[i - 1][j - 1] == "X")	// Top left.
					aliveCount++;
				if (matrix_1[i - 1][j] == "X")		// Top center.
					aliveCount++;
				if (matrix_1[i - 1][j + 1] == "X")	// Top right.
					aliveCount++;
				if (matrix_1[i][j + 1] == "X")		// Center right.
					aliveCount++;
				if (matrix_1[i][j - 1] == "X")		// Bottom right.
					aliveCount++;
				if (matrix_1[i + 1][j + 1] == "X")	// Bottom center.
					aliveCount++;
				if (matrix_1[i + 1][j] == "X")		// Bottom left.
					aliveCount++;
				if (matrix_1[i + 1][j - 1] == "X")	// Center left.
					aliveCount++;

				// Rule #1: Occupied cell has 0, 1, or > 3 neighbors it dies!
				if ((matrix_1[i][j] == "X") && ((aliveCount < 2) || (aliveCount > 3))) {
					matrix_0[i][j] = ".";
				}
				else {//Rule #2: Occupied cell has 2 or 3 neighbors it lives!
					if ((matrix_1[i][j] == "X") && ((aliveCount > 1) && (aliveCount < 4))) {
						matrix_0[i][j] = "X";
					}
				}

				// Rule #3: Unoccupied cell has 3 neighbors, an 'X' is "born"!
				if ((matrix_1[i][j] == ".") && (aliveCount == 3)) {
					matrix_0[i][j] = "X";
				}
				else {
					if ((matrix_1[i][j] == ".") && (aliveCount != 3)) {
						matrix_0[i][j] = ".";
					}
				}
			}
		}
		// End matrix_0 build****************************************************

		// Reset matrix_1
		for (int i = 0; i < univRows; i++) {
			for (int j = 0; j < univCols; j++) {
				matrix_1[i][j] = ".";
			}
		}

		// Sleep. See footnote(3) in Main.cpp.
		usleep(time);
		
		iter++;
		
		// Move cursor up above matrix_1 rendering, clear console, user message!
		// See footnote (1) in Main.cpp
		cout << "\033[41A" << "Gosper Glider Gun is running from point: (" << anArray[2]
			<< "," << anArray[3] << "). " << "Iteration count = " << iter << endl;

	} // End animation loop.

};