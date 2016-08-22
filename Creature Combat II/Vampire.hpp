/****************************************************************************************
** Program Filename: Vampire.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/28/2016
** Description: Vampire child class declaration file.
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
	int numDie;		//  1
	int dieSides_A;	// 12
	int dieSides_D;	//  6
	int armor;		//  1
	bool charm;
	int player;
	string name;
	string type;
	int cScore;

public:
	Vampire(string, string, int);
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
	void setPlayer(int);
	int getPlayer();
	void setName(string);
	string getName();
	void charmer();
	void setCharm(bool);
	bool getCharm();
	int roll(string);
	int attack();
	void defend(int);
	bool checkPulse();
	void healer();
	void setType(string);
	string getType();
	void setcScore(int);
	int getcScore();
};
#endif