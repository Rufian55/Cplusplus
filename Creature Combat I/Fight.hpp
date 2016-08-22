/****************************************************************************************
** Program Filename: Fight.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/14/2016
** Description: Fight class declaration file.
** Input:
** Output:
*****************************************************************************************/
#ifndef FIGHT_HPP
#define FIGHT_HPP
#include "Creature.hpp"
#include<string>
using std::string;

class Fight : public Creature {
private:
protected:
public:
	Fight() {};
	~Fight() {};

	// Virtual function placeholders.
	int roll(string) {};
	int attack() {};
	void defend(int) {};
	bool checkPulse() {};
	int getStrength() {};

};
#endif