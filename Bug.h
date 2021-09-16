/*
 * Bug.h
 *
 *  Created on: May 8, 2019
 *      Author: silvettimj
 */

#ifndef BUG_H_
#define BUG_H_

#include <iostream>

using namespace std;

class Grid;  //forward declaration for composition
class Bug {
public:
	Bug();
	Bug(Grid *thisGrid, int posx, int posy);  // Bug "has a" grid
	virtual ~Bug();
	virtual void move() = 0;	   // Moves the bug to a location on the grid
	virtual void breed() = 0;      // Makes a new bug of this type of bug
	virtual char character() = 0;  // Returns character of this bug
	bool inBounds(int x, int y);
	virtual bool starveCheck();
	void setMove(bool m);
	bool moveCheck();

protected:
	virtual void birth(int posx, int posy) = 0;
	void breedAdjacent();
	int x;  // Current x coordinate of Bug
	int y;  // Current y coordinate
	Grid* grid;  // Grid pointer that points to grid that the Bug lives in
	bool movedCheck;
	int breedCount;
	int lbNum;
	void basicMove(int x, int y);
};

#endif /* BUG_H_ */
