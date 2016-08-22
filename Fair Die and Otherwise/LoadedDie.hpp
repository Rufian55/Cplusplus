/****************************************************************************************
** Program Filename: LoadedDie.hpp
** Author: Chris Kearns
** Date: 1/24/2016
** Description: LoadedDie class header file.
** Input:
** Output:
*****************************************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class LoadedDie : public Die {
private:
public:
	int reRoll(Die);		// for using a loaded die!
};
#endif
