/****************************************************************************************
** Program Filename: Doodlebug.hpp
** Author: Chris Kearns
** Date: 2/7/2016
** Description: Doodlbug class declaration file.
*****************************************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug : public Critter {
protected:
	char name;
	int steps;
	int starveSteps;
	int xLoc;
	int yLoc;
public:
	Doodlebug() {
		setName('D');
		setSteps();
		setStarve();
		setxLoc(0);
		setyLoc(0);
	};
	void move(int, int, int, int);
	void setStarve(int);
	void setStarve();				//Overload.
	int getStarve();
	void setName(char);
	char getName();
	void setSteps(int);
	void setSteps();				//OVerload.
	int getSteps();
	void setxLoc(int);
	void setyLoc(int);
	int getxLoc();
	int getyLoc();
};
#endif
