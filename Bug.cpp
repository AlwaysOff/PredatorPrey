/*
 * Bug.cpp
 *
 *  Created on: May 8, 2019
 *      Author: silvettimj
 */

#include <iostream>

#include "Bug.h"
#include "Grid.h"


using namespace std;

Bug::Bug() {
	// TODO Auto-generated constructor stub
}

Bug::Bug(Grid *thisGrid, int posx, int posy){
	grid = thisGrid;
	grid->setBugAt(this, posx, posy);
	x = posx;
	y = posy;
	movedCheck = 0;
	breedCount = 0;
}

Bug::~Bug() {
	// TODO Auto-generated destructor stub
}

void Bug::breedAdjacent(){
	if((grid->getBugAt(x + 1, y) == NULL)  && (inBounds(x - 1, y))){
		birth(x - 1, y);
	}
	else if((grid->getBugAt(x - 1, y) == NULL)  && (inBounds(x + 1, y))){
		birth(x + 1, y);
	}
	else if((grid->getBugAt(x, y + 1) == NULL) && (inBounds(x, y + 1))){
		birth(x, y + 1);
	}
	else if((grid->getBugAt(x, y - 1) == NULL) && (inBounds(x, y - 1))){
		birth(x, y - 1);
	}
}

bool Bug::inBounds(int i, int j){  // sees if bug is between 0 and 20 for x and y
	bool check;
	check = ((i >= 0) && (i < 20) && (j >= 0) && (j < 20));  //
	return check;
}

void Bug::basicMove(int i, int j){
	Bug* bugToMove;
	Bug* empty;
	bugToMove = grid->getBugAt(x, y);  // Bug to move set to bug at (x, y)
	empty = NULL;
	grid->setBugAt(bugToMove, i, j);  // bring bug to new place
	grid->setBugAt(empty, x, y); // set previous place to empty
	x = i;
	y = j;
	grid->getBugAt(x, y)->setMove(1);
}

void Bug::setMove(bool m){  // To set move state of
	movedCheck = m;
}

bool Bug::moveCheck(){
	return movedCheck;
}

bool Bug::starveCheck(){
	return 0;
}
