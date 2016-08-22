/****************************************************************************************
** Program Filename: Magenta.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/13/2016
** Description: Magenta abstract class declaration file.
*****************************************************************************************/
#ifndef  MAGENTA_HPP
#define MAGENTA_HPP
#include "Space.hpp"
#include <string>
using std::string;

class Magenta : public Space {
private:
	bool randallBoggsVisit;
	bool randallBoggsFood;
	bool randallBoggsDrink;
	bool pinkyVisit;
	bool pinkyFood;
	bool pinkyDrink;
	bool thePinkPantherVisit;
	bool thePinkPantherFood;
	bool thePinkPantherDrink;
	bool jokerVisit;
	bool jokerFood;
	bool jokerDrink;
	bool ursulaVisit;
	bool ursulaFood;
	bool ursulaDrink;

protected:
	Space *M_Blue;
	Space *M_Yellow;
	Space *M_Cyan;
	Space *M_Green;
	Space *M_Red;
	Space *M_White;
	bool pPiece;
	int strength;

public:
	void setMagentaPtrs(Space*, Space*, Space*, Space*, Space*, Space*);
	~Magenta();
	void setStrength();
	virtual void setStrength(int);		// Local Overload.
	virtual int getStrength();			// Local strength.
	virtual int acceptStrength(int);	// From Throwback strength.

	void setPPMagenta(bool);
	void setPPMagenta();						//Overload.
	virtual bool getPPMagenta();
	void initCharBools();

	virtual int runRoom();
	virtual void boostStrength();		// Special Pure Virtual Function! 
	int runCharacters();
	int runController(int);
	int playerAI();

	int runRandallBoggs(int);
	int runPinky(int);
	int runThePinkPanther(int);
	int runJoker(int);
	int runUrsula(int);

	// Magenta Room Characters
	void setRandallBoggsVisit(bool);
	bool getRandallBoggsVisit();
	void setRandallBoggsFood(bool);
	bool getRandallBoggsFood();
	void setRandallBoggsDrink(bool);
	bool getRandallBoggsDrink();

	void setPinkyVisit(bool);
	bool getPinkyVisit();
	void setPinkyFood(bool);
	bool getPinkyFood();
	void setPinkyDrink(bool);
	bool getPinkyDrink();

	void setThePinkPantherVisit(bool);
	bool getThePinkPantherVisit();
	void setThePinkPantherFood(bool);
	bool getThePinkPantherFood();
	void setThePinkPantherDrink(bool);
	bool getThePinkPantherDrink();

	void setJokerVisit(bool);
	bool getJokerVisit();
	void setJokerFood(bool);
	bool getJokerFood();
	void setJokerDrink(bool);
	bool getJokerDrink();

	void setUrsulaVisit(bool);
	bool getUrsulaVisit();
	void setUrsulaFood(bool);
	bool getUrsulaFood();
	void setUrsulaDrink(bool);
	bool getUrsulaDrink();

	void setBlue(Space*);
	void setYellow(Space*);
	void setCyan(Space*);
	void setGreen(Space*);
	void setRed(Space*);
	void setWhite(Space*);
};
#endif