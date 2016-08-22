/****************************************************************************************
** Program Filename: Queue.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/06/2016
** Description: Queue class implementation file.
** Input:
** Output:
*****************************************************************************************/
#include "Queue.hpp"
#include <cstdlib>


/*******************************************************************************
**							function intGen()
** Returns a random var from 1 to 1000 on call. srand seed is in main().
******************************************************************************/
int Queue::intGen() {
	int var = rand() % 1000 + 1;
	return var;
}


/*******************************************************************************
**							function isTrue()
** Returns a bool based upon the probablity inputed. srand seed is in main().
** Works by comparing a randome number/RAND_MAX to user inputted probablity/100.
*******************************************************************************/
bool Queue::isTrue(double pctPutPop) {
	double rNum = rand();
	double rMax = RAND_MAX;
	if ((rNum / rMax) < (pctPutPop/100))
		return true;
	else
		return false;
}