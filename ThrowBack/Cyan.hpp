/****************************************************************************************
** Program Filename: Cyan.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/13/2016
** Description: Cyan abstract class declaration file.
*****************************************************************************************/
#ifndef CYAN_HPP
#define CYAN_HPP
#include "Space.hpp"
#include <string>
using std::string;

class Cyan : public Space {
private:
	bool inkyVisit;
	bool inkyFood;
	bool inkyDrink;
	bool bruceVisit;
	bool bruceFood;
	bool bruceDrink;
	bool elsaVisit;
	bool elsaFood;
	bool elsaDrink;
	bool huckleBerryHoundVisit;
	bool huckleBerryHoundFood;
	bool huckleBerryHoundDrink;
	bool bettyRubbleVisit;
	bool bettyRubbleFood;
	bool bettyRubbleDrink;

protected:
	Space *C_Blue;
	Space *C_Yellow;
	Space *C_Green;
	Space *C_Red;
	Space *C_Magenta;
	Space *C_White;
	bool pPiece;
	int strength;

public:
	void setCyanPtrs(Space*, Space*, Space*, Space*, Space*, Space*);
	~Cyan();
	void setStrength();
	virtual void setStrength(int);		// Local Overload.
	virtual int getStrength();			// Local strength.
	virtual int acceptStrength(int);	// From Throwback strength.

	void setPPCyan(bool);
	void setPPCyan();					//Overload.
	virtual bool getPPCyan();
	void initCharBools();

	virtual int runRoom();
	virtual void boostStrength();		// Special Pure Virtual Function! 
	int runCharacters();
	int runController(int);
	int playerAI();

	int runInky (int);
	int runBruce (int);
	int runElsa (int);
	int runHuckleBerryHound (int);
	int runBettyRubble (int);

	// Cyan Room Characters
	void setInkyVisit(bool);
	bool getInkyVisit();
	void setInkyFood(bool);
	bool getInkyFood();
	void setInkyDrink(bool);
	bool getInkyDrink();

	void setBruceVisit(bool);
	bool getBruceVisit();
	void setBruceFood(bool);
	bool getBruceFood();
	void setBruceDrink(bool);
	bool getBruceDrink();

	void setElsaVisit(bool);
	bool getElsaVisit();
	void setElsaFood(bool);
	bool getElsaFood();
	void setElsaDrink(bool);
	bool getElsaDrink();

	void setHuckleBerryHoundVisit(bool);
	bool getHuckleBerryHoundVisit();
	void setHuckleBerryHoundFood(bool);
	bool getHuckleBerryHoundFood();
	void setHuckleBerryHoundDrink(bool);
	bool getHuckleBerryHoundDrink();

	void setBettyRubbleVisit(bool);
	bool getBettyRubbleVisit();
	void setBettyRubbleFood(bool);
	bool getBettyRubbleFood();
	void setBettyRubbleDrink(bool);
	bool getBettyRubbleDrink();

	void setBlue(Space*);
	void setYellow(Space*);
	void setGreen(Space*);
	void setRed(Space*);
	void setMagenta(Space*);
	void setWhite(Space*);
};
#endif