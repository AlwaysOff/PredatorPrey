/*
 * Aphid.h
 *
 *  Created on: May 8, 2019
 *      Author: silvettimj
 */

#ifndef APHID_H_
#define APHID_H_

#include <iostream>

#include "Grid.h"
#include "Bug.h"

using namespace std;

class Grid;
class Aphid : public Bug {
public:
	Aphid();
	Aphid(Grid *thisGrid, int x, int y, int bc);
	virtual ~Aphid();
	void move();	   // Moves an Aphid to somewhere on the grid
	void breed();      // Makes a new Aphid
	char character();  // Returns 'o' for Aphid
	void setABreed(int brd);

private:
	int aBreed;
	void birth(int posx, int posy);
};

#endif /* APHID_H_ */
