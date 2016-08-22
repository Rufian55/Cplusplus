/****************************************************************************************
** Program Filename: Space.hpp
** Author: Chris Kearns
** Date: 3/13/2016
** Description: Space abstract class declaration file.
*****************************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include<string>
using std::string;
#include<iostream>
using std::cout;

class Space {
private:

protected:

public:
	~Space() {} // Cannot accept parameters, so exitGame() handles cleanup.
	void exitGame(Space*, Space*, Space*, Space*, Space*, Space*, Space*, Space*);
	int welcome();
	int go2Room();
	string palette(int);

	virtual bool getPPBlue() {};
	virtual bool getPPYellow() {};
	virtual bool getPPCyan() {};
	virtual bool getPPGreen() {};
	virtual bool getPPRed() {};
	virtual bool getPPMagenta() {};
	virtual bool getPPWhite() {};

	virtual void setStrength(int) {};		// Local Room
	virtual int getStrength() {};			// Local Room
	virtual int acceptStrength(int) {};		// From Throwback strength.

	virtual int runRoom() {};
	virtual void boostStrength() = 0;		// "Special" virtual function!
};
#endif
