/****************************************************************************************
** Program Filename: Creature.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/28/2016
** Description: Creature abstract class declaration file.
** Input:
** Output:
*****************************************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP
#include<string>
using std::string;

class Creature {
private:

protected:

public:
	virtual int roll(string) = 0;
	virtual int attack() = 0;
	virtual void defend(int) = 0;
	virtual bool checkPulse() = 0;
	virtual int getStrength() = 0;
	virtual int getPlayer() = 0;
	virtual string getName() = 0;
	virtual string getType() = 0;
	virtual void healer() = 0;
	virtual void setcScore(int) = 0;
	virtual int getcScore() = 0;
};
#endif