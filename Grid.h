/*
 * Grid.h
 *
 *  Created on: May 11, 2019
 *      Author: silvettimj
 */

#ifndef GRID_H_
#define GRID_H_
#include <iostream>
#include "Bug.h"
#include <vector>

using namespace std;

const int gridSize = 20;

class Bug;  //forward declaration for composition (Grid "has a" bug)
class Grid {
public:
	Grid();
	virtual ~Grid();
	Bug* getBugAt(int x, int y) const;
	void setBugAt(Bug* bug, int x, int y);
	void stepForward(int n);
	void displayGrid();
	void displayGridSfml();
	void resetMove();
	int randomPos();
	bool deadCheck();
	void setGridSize(int n);
	int getStepCount();
	Bug* getGrid(int x, int y);
	void setStepCount(int a);

private:
	int stepCount;
	int aphidNum;
	int ladyBugNum;
	int aNum;
	int lbNum;
	bool movedCheck;
	void kill();
	void createAphids(int n);
	void createLadyBugs(int n);
	Bug* grid[gridSize][gridSize];  // Multidimensional array of type Bug pointers of size 20.
						            // Will be used to keep track of bugs coordinates.
};

#endif /* GRID_H_ */
