/****************************************************************************************
** Program Filename: Ant.hpp
** Author: Chris Kearns
** Date: 2/7/2016
** Description: Ant class declaration file.
*****************************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"

class Ant : public Critter {
protected:
	char name;
	int steps;
	int xLoc;
	int yLoc;
public:
	Ant() {
		setName('a');
		setSteps();
		setxLoc(0);
		setyLoc(0);
	};
	void move(int, int, int, int);
	void setName(char);
	char getName();
	void setSteps();
	void setSteps(int);				//overload
	int getSteps();
	void setxLoc(int);
	void setyLoc(int);
	int getxLoc();
	int getyLoc();
};
#endif
