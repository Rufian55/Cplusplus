/****************************************************************************************
** Program Filename: Yellow.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/13/2016
** Description: Yellow abstract class declaration file.
*****************************************************************************************/
#ifndef YELLOW_HPP
#define YELLOW_HPP
#include "Space.hpp"
#include <string>
using std::string;

class Yellow : public Space {
private:
	bool bartSimpsonVisit;
	bool bartSimpsonFood;
	bool bartSimpsonDrink;
	bool bigBirdVisit;
	bool bigBirdFood;
	bool bigBirdDrink;
	bool garfieldVisit;
	bool garfieldFood;
	bool garfieldDrink;
	bool pokemonVisit;
	bool pokemonFood;
	bool pokemonDrink;
	bool spongeBobSquarePantsVisit;
	bool spongeBobSquarePantsFood;
	bool spongeBobSquarePantsDrink;
protected:
	Space *Y_Blue;
	Space *Y_Cyan;
	Space *Y_Green;
	Space *Y_Red;
	Space *Y_Magenta;
	Space *Y_White;
	bool pPiece;
	int strength;
public:
	void setYellowPtrs(Space*, Space*, Space*, Space*, Space*, Space*);
	~Yellow();
	void setStrength();
	virtual void setStrength(int);		// Local Overload.
	virtual int getStrength();			// Local strength.
	virtual int acceptStrength(int);	// From Throwback strength.

	void setPPYellow(bool);
	void setPPYellow();//Overload.
	virtual bool getPPYellow();
	void initCharBools();

	virtual int runRoom();
	virtual void boostStrength(); // Special Pure Virtual Function! 
	int runCharacters();
	int runController(int);
	int playerAI();

	// Yellow Room Characters
	int runBartSimpson(int);
	int runBigBird(int);
	int runGarfield(int);
	int runPokemon(int);
	int runSpongeBobSquarePants(int);

	void setBartSimpsonVisit(bool);
	bool getBartSimpsonVisit();
	void setBartSimpsonFood(bool);
	bool getBartSimpsonFood();
	void setBartSimpsonDrink(bool);
	bool getBartSimpsonDrink();

	void setBigBirdVisit(bool);
	bool getBigBirdVisit();
	void setBigBirdFood(bool);
	bool getBigBirdFood();
	void setBigBirdDrink(bool);
	bool getBigBirdDrink();

	void setGarfieldVisit(bool);
	bool getGarfieldVisit();
	void setGarfieldFood(bool);
	bool getGarfieldFood();
	void setGarfieldDrink(bool);
	bool getGarfieldDrink();

	void setPokemonVisit(bool);
	bool getPokemonVisit();
	void setPokemonFood(bool);
	bool getPokemonFood();
	void setPokemonDrink(bool);
	bool getPokemonDrink();

	void setSpongeBobSquarePantsVisit(bool);
	bool getSpongeBobSquarePantsVisit();
	void setSpongeBobSquarePantsFood(bool);
	bool getSpongeBobSquarePantsFood();
	void setSpongeBobSquarePantsDrink(bool);
	bool getSpongeBobSquarePantsDrink();

	void setBlue(Space*);
	void setCyan(Space*);
	void setGreen(Space*);
	void setRed(Space*);
	void setMagenta(Space*);
	void setWhite(Space*);
};
#endif