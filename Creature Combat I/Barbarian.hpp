/****************************************************************************************
** Program Filename: Barbarian.hpp
** Author: Chris Kearns
** Date: 2/14/2016
** Description: Barbarian child class declaration file.
** Input:
** Output:
*****************************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Creature.hpp"
#include<string>
using std::string;

class Barbarian : public Creature {
private:

protected:
	int strength;	// 12
	int numDie;	//  2
	int dieSides;	//  6
	int armor;	//  0

public:
	Barbarian();
	~Barbarian();
	void setStrength(int);
	int getStrength();
	void setDieSides(int);
	int getDieSides();
	void setNumDie(int);
	int getNumDie();
	void setArmor(int);
	int getArmor();
	int roll(string);
	int attack();
	void defend(int);
	bool checkPulse();

};
#endif
