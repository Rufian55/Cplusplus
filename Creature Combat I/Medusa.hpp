/****************************************************************************************
** Program Filename: Medussa.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/14/2016
** Description: Medussa child class declaration file.
** Input:
** Output:
*****************************************************************************************/
#ifndef MEDUSSA_HPP
#define MEDUSA_HPP
#include "Creature.hpp"
#include<string>
using std::string;

class Medusa : public Creature {
private:
	
protected:
	int strength;	// 8
	int numDie_A;	// 2
	int dieSides_A;	// 6
	int numDie_D;	// 1
	int dieSides_D;	// 6
	int armor;		// 3

public:
	Medusa();
	~Medusa();
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
	int roll(string);
	int attack();
	void defend(int);
	bool checkPulse();

};
#endif