/****************************************************************************************
** Program Filename: Critter.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/7/2016
** Description: Base class declaration file.
*****************************************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter {
public:
	Critter() {}
	virtual void move(int, int, int, int) {}
	virtual void setName(char) {}
	virtual char getName() { return 'C'; }
	virtual int getSteps() { return 0; }
	virtual void setSteps() {}
	virtual void setSteps(int) {}
	virtual void setStarve() {}
	virtual void setStarve(int) {}
	virtual int getStarve() { return 0; }
	virtual void setxLoc(int) {}
	virtual void setyLoc(int) {}
	virtual int getxLoc() { return 0; }
	virtual int getyLoc() { return 0; }
	int getRand();
};
#endif // !CRITTER_HPP