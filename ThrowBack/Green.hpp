/****************************************************************************************
** Program Filename: Green.hpp
** Author: Chris Kearns
** Date: 3/13/2016
** Description: Green abstract class declaration file.
*****************************************************************************************/
#ifndef  GREEN_HPP
#define GREEN_HPP
#include "Space.hpp"
#include <string>
using std::string;

class Green : public Space {
private:
	bool shrekVisit;
	bool shrekFood;
	bool shrekDrink;
	bool kermitVisit;
	bool kermitFood;
	bool kermitDrink;
	bool yodaVisit;
	bool yodaFood;
	bool yodaDrink;
	bool theGrinchVisit;
	bool theGrinchFood;
	bool theGrinchDrink;
	bool theHulkVisit;
	bool theHulkFood;
	bool theHulkDrink;

protected:
	Space *G_Blue;
	Space *G_Yellow;
	Space *G_Cyan;
	Space *G_Red;
	Space *G_Magenta;
	Space *G_White;
	bool pPiece;
	int strength;

public:
	void setGreenPtrs(Space*, Space*, Space*, Space*, Space*, Space*);
	~Green();
	void setStrength();
	virtual void setStrength(int);		// Local Overload.
	virtual int getStrength();		// Local strength.
	virtual int acceptStrength(int);	// From Throwback strength.

	void setPPGreen(bool);
	void setPPGreen();			//Overload.
	virtual bool getPPGreen();
	void initCharBools();

	virtual int runRoom();
	virtual void boostStrength();		// Special Pure Virtual Function! 
	int runCharacters();
	int runController(int);
	int playerAI();

	int runShrek(int);
	int runKermit(int);
	int runYoda(int);
	int runTheGrinch(int);
	int runTheHulk(int);

	// Green Room Characters
	void setShrekVisit(bool);
	bool getShrekVisit();
	void setShrekFood(bool);
	bool getShrekFood();
	void setShrekDrink(bool);
	bool getShrekDrink();

	void setKermitVisit(bool);
	bool getKermitVisit();
	void setKermitFood(bool);
	bool getKermitFood();
	void setKermitDrink(bool);
	bool getKermitDrink();

	void setYodaVisit(bool);
	bool getYodaVisit();
	void setYodaFood(bool);
	bool getYodaFood();
	void setYodaDrink(bool);
	bool getYodaDrink();

	void setTheGrinchVisit(bool);
	bool getTheGrinchVisit();
	void setTheGrinchFood(bool);
	bool getTheGrinchFood();
	void setTheGrinchDrink(bool);
	bool getTheGrinchDrink();

	void setTheHulkVisit(bool);
	bool getTheHulkVisit();
	void setTheHulkFood(bool);
	bool getTheHulkFood();
	void setTheHulkDrink(bool);
	bool getTheHulkDrink();

	void setBlue(Space*);
	void setYellow(Space*);
	void setCyan(Space*);
	void setRed(Space*);
	void setMagenta(Space*);
	void setWhite(Space*);
};
#endif
