/****************************************************************************************
** Program Filename: BlueMen.hpp
** Author: Chris Kearns
** Date: 2/14/2016
** Description: BlueMen child class declaration file.
** Input:
** Output:
*****************************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Creature.hpp"
#include<string>
using std::string;

class BlueMen : public Creature {
private:

protected:
	int strength;	// 12
	int numDie_A;	//  2
	int dieSides_A;	// 10
	int numDie_D;	//  3/2/1
	int dieSides_D;	//  6
	int armor;	//  3

public:
	BlueMen();
	~BlueMen();
	void setStrength(int);
	int getStrength();
	void setDieSides_A(int);
	int getDieSides_A();
	void setNumDie_A(int);
	int getNumDie_A();
	void setDieSides_D(int);
	int getDieSides_D();
	void setNumDie_D(int);
	int getNumDie_D();
	void setArmor(int);
	int getArmor();
	void mob();
	int roll(string);
	int attack();
	void defend(int);
	bool checkPulse();
};
#endif
