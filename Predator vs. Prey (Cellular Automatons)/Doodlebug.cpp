/****************************************************************************************
** Program Filename: Doodlebug.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/7/2016
** Description: Doodlebug class implementation file.
*****************************************************************************************/
#include "Doodlebug.hpp"


/***************************************************************************************
** Function: move()
** Description:	Object movement, randomly selects movement direction via call to getRand()
** and checks up, down, left, and right for out of bounds.
** Parameters: Int i,j, rows, cols.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Should ultimately reset objects x and y coordinates on the grid.
****************************************************************************************/
void Doodlebug::move(int i, int j, int rows, int cols) {	// i is current x-axis location, j is y-axis location.
															// rows and cols is grid size as per user.
	int dir = getRand();									// getRand() returns random 1, 2, 3, or 4.
	int x = getxLoc();										// x-axis location var currently stored in object.
	int y = getyLoc();										// y-axis location var currently stored in object.

	//UP
	if (dir == 1 && (i != 0)) {
		x -= 1;
		setxLoc(x);
	}
	else {
		setxLoc(x);
	}

	//RIGHT
	if (dir == 2 && (j != cols - 1)) {
		y += 1;
		setyLoc(y);
	}
	else {
		setyLoc(y);
	}

	//DOWN
	if (dir == 3 && (i != rows - 1)) {
		x += 1;
		setxLoc(x);
	}
	else {
		setxLoc(x);
	}

	//LEFT
	if (dir == 4 && (j != 0)) {
		y -= 1;
		setyLoc(y);
	}
	else {
		setyLoc(y);
	}
}

void Doodlebug::setStarve(int steps) {
	this->starveSteps = getStarve() + steps;
}

void Doodlebug::setStarve() {
	this->starveSteps = 0;
}

int Doodlebug::getStarve() {
	return starveSteps;
}

void Doodlebug::setName(char name) {
	this->name = name;
}

char Doodlebug::getName() {
	return name;
}

void Doodlebug::setSteps() {
	this->steps = 0;
}

void Doodlebug::setSteps(int steps) {
	this->steps = getSteps() + steps;
}

int Doodlebug::getSteps() {
	return steps;
}

void Doodlebug::setxLoc(int xLoc) {
	this->xLoc = xLoc;
}

void Doodlebug::setyLoc(int yLoc) {
	this->yLoc = yLoc;
}

int Doodlebug::getxLoc() {
	return xLoc;
}

int Doodlebug::getyLoc() {
	return yLoc;
}