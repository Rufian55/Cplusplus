/****************************************************************************************
** Program Filename: Ant.cpp
** Author: Chris Kearns
** Date: 2/7/2016
** Description: Ant class implementation file.
*****************************************************************************************/
#include "Ant.hpp"

/***************************************************************************************
** Function: move()
** Description:	Object movement, randomly selects movement direction via call to getRand()
** and checks up, down, left, and right for outofbounds.
** Parameters: Int i,j, rows, cols.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Should ultimately reset objects x and y coordiantes on the grid.
****************************************************************************************/
void Ant::move(int i, int j, int rows, int cols) {	// i is current x-axis location, j is y-axis location.
							// rows and cols is grid size as per user.
	int dir = getRand();				// getRand() returns random 1, 2, 3, or 4.
	int x = getxLoc();				// x-axis location var currently stored in object.
	int y = getyLoc();				// y-axis location var currently stored in object.

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


void Ant::setName(char name) {
	this->name = name;
}

char Ant::getName() {
	return name;
}

void Ant::setSteps() {
	this->steps = 0;
}

void Ant::setSteps(int steps) {
	this->steps = getSteps() + steps;
}

int Ant::getSteps() {
	return this->steps;
}

void Ant::setxLoc(int xLoc) {
	this->xLoc = xLoc;
}

void Ant::setyLoc(int yLoc){
	this->yLoc = yLoc;
}

int Ant::getxLoc() {
	return xLoc;
}

int Ant::getyLoc() {
	return yLoc;
}
