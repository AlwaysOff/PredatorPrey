/*
 * LadyBug.h
 *
 *  Created on: May 8, 2019
 *      Author: silvettimj
 */

#ifndef LADYBUG_H_
#define LADYBUG_H_

#include <iostream>

#include "Grid.h"
#include "Bug.h"

using namespace std;

class Bug;
class Grid;
class LadyBug : public Bug {
public:
	LadyBug();
	LadyBug(Grid *thisGrid, int x, int y, int bc);
	virtual ~LadyBug();
	void move();	     // Moves an Aphid to somewhere on the grid
	void breed();        // Makes a new Aphid
	char character();    // Returns 'o' for Aphid
	bool starveCheck();  // checks if ladybug is starved
	void setLbBreed(int brd);

private:
	int lbBreed;
	int starveCount;
	void birth(int posx, int posy);
};

#endif /* LADYBUG_H_ */
