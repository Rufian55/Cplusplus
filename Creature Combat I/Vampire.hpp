/****************************************************************************************
** Program Filename: Vampire.hpp
** Author: Chris Kearns
** Date: 2/14/2016
** Description: Vampire child class declaration file.
** Input:
** Output:
*****************************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Creature.hpp"
#include<string>
using std::string;

class Vampire : public Creature {
private:

protected:
	int strength;	// 18
	int numDie;	//  1
	int dieSides_A;	// 12
	int dieSides_D;	//  6
	int armor;	//  1
	bool charm;

public:
	Vampire();
	~Vampire();
	void setStrength(int);
	int getStrength();
	void setDieSides_A(int);
	int getDieSides_A();
	void setDieSides_D(int);
	int getDieSides_D();
	int getNumDie();
	void setNumDie(int);
	void setArmor(int);
	int getArmor();
	void charmer();
	void setCharm(bool);
	bool getCharm();
	int roll(string);
	int attack();
	void defend(int);
	bool checkPulse();

};
#endif
