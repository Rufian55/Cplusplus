/****************************************************************************************
** Program Filename: HarryPotter.hpp
** Author: Chris Kearns
** Date: 2/14/2016
** Description: HarryPotter child class declaration file.
** Input:
** Output:
*****************************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Creature.hpp"
#include<string>
using std::string;

class HarryPotter : public Creature {
private:

protected:
	int strength;		// 10
	int numDie;		//  2
	int dieSides;		//  6
	int armor;		//  0
	int deadOnce;		//  0

public:
	HarryPotter();
	~HarryPotter();
	void setStrength(int);
	int getStrength();
	void setDieSides(int);
	int getDieSides();
	void setNumDie(int);
	int getNumDie();
	void setArmor(int);
	int getArmor();
	void setDeadOnce(int);
	int getDeadOnce();
	void hogWarts();
	int roll(string);
	int attack();
	void defend(int);
	bool checkPulse();

};
#endif
