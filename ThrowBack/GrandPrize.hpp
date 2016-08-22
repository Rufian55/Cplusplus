/****************************************************************************************
** Program Filename: GrandPrize.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/13/2016
** Description: Header file for Oscillator.cpp.
****************************************************************************************/
#ifndef GRANDPRIZE_HPP
#define GRANDPRIZE_HPP
#include "Space.hpp"

class GrandPrize : Space {
private:
protected:
public:
	void grandPrize();
	virtual void boostStrength() {}	// "Special" virtual function!
};
#endif