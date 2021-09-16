/*
 * LadyBug.cpp
 *
 *  Created on: May 8, 2019
 *      Author: silvettimj
 */

#include <iostream>

#include "LadyBug.h"
#include "Grid.h"
#include "Bug.h"

using namespace std;

LadyBug::LadyBug() {
	// TODO Auto-generated constructor stub
}

LadyBug::LadyBug(Grid *thisGrid, int x, int y, int bc) : Bug(thisGrid, x, y){
	starveCount = 0;
	breedCount = 0;
	lbBreed = bc;
}

LadyBug::~LadyBug() {
	// TODO Auto-generated destructor stub
}

void LadyBug::move(){
	starveCount++;
	breedCount++;

	// If on edge of grid, try wrapping around the grid and check if there is an Aphid there they can eat
	if(y == 0){
		if(grid->getBugAt(x, (gridSize - 1)) != NULL){  // If there is a Bug at (x, y - 1)
			if(grid->getBugAt(x, y - 1)->character() == 'o'){  // If this Bug is an Aphid, eat it
				delete grid->getBugAt(x, y - 1);
				starveCount = 0;
				basicMove(x, y - 1);
				return;
			}
		}
	}

	if(x == 0){
		if(grid->getBugAt((gridSize - 1), y) != NULL){  // If there is a Bug at (x, y - 1)
			if(grid->getBugAt((gridSize - 1), y)->character() == 'o'){  // If this Bug is an Aphid, eat it
				delete grid->getBugAt((gridSize - 1), y);
				starveCount = 0;
				basicMove((gridSize - 1), y);
				return;
			}
		}
	}

	if(y == (gridSize - 1)){
		if(grid->getBugAt(x, 0) != NULL){  // If there is a Bug at (x, y - 1)
			if(grid->getBugAt(x, 0)->character() == 'o'){  // If this Bug is an Aphid, eat it
				delete grid->getBugAt(x, 0);
				starveCount = 0;
				basicMove(x, 0);
				return;
			}
		}
	}

	if(x == (gridSize - 1)){
		if(grid->getBugAt(0, y) != NULL){  // If there is a Bug at (x, y - 1)
			if(grid->getBugAt(0, y)->character() == 'o'){  // If this Bug is an Aphid, eat it
				delete grid->getBugAt(0, y);
				starveCount = 0;
				basicMove(0, y);
				return;
			}
		}
	}

	// Adjacent eating
	if(grid->getBugAt(x + 1, y) != NULL){  // If there is a Bug at (x + 1, y)
		if(grid->getBugAt(x + 1, y)->character() == 'o'){  // If this Bug is an Aphid, eat it
			delete grid->getBugAt(x + 1, y);
			starveCount = 0;
			basicMove(x + 1, y);
			return;
		}
	}

	if(grid->getBugAt(x - 1, y) != NULL){  // If there is a Bug at (x - 1, y)
		if(grid->getBugAt(x - 1, y)->character() == 'o'){  // If this Bug is an Aphid, eat it
			delete grid->getBugAt(x - 1, y);
			starveCount = 0;
			basicMove(x - 1, y);
			return;
		}
	}

	if(grid->getBugAt(x, y + 1) != NULL){  // If there is a Bug at (x, y + 1)
		if(grid->getBugAt(x, y + 1)->character() == 'o'){  // If this Bug is an Aphid, eat it
			delete grid->getBugAt(x, y + 1);
			starveCount = 0;
			basicMove(x, y + 1);
			return;
		}
	}

	if(grid->getBugAt(x, y - 1) != NULL){  // If there is a Bug at (x, y - 1)
		if(grid->getBugAt(x, y - 1)->character() == 'o'){  // If this Bug is an Aphid, eat it
			delete grid->getBugAt(x, y - 1);
			starveCount = 0;
			basicMove(x, y - 1);
			return;
		}
	}

	//Random moving if no adjacent Aphids
	if((y == 0) && !(x == 0) && !(x == (gridSize - 1))){  // If LadyBug is on the edge of the grid
		switch(grid->randomPos()){
		case 0:  // up
			if((grid->getBugAt(x, (gridSize - 1)) == NULL) && (inBounds(x, (gridSize - 1)))){
				basicMove(x, (gridSize - 1));
			}
			break;
		case 1:  // right
			if((grid->getBugAt(x + 1, y) == NULL) && (inBounds(x + 1, y))){
				basicMove(x + 1, y);
			}
			break;
		case 2:  // down
			if((grid->getBugAt(x, y - 1) == NULL) && (inBounds(x, y - 1))){
				basicMove(x, y - 1);
			}
			break;
		case 3:  // left
			if((grid->getBugAt(x - 1, y) == NULL) && (inBounds(x - 1, y))){
				basicMove(x - 1, y);
			}
			break;
		}
	}
	else if((x == 0) && !(y == 0) && !(y == (gridSize - 1))){
		switch(grid->randomPos()){
		case 0:  // up
			if((grid->getBugAt(x, y + 1) == NULL) && (inBounds(x, y + 1))){
				basicMove(x, y + 1);
			}
			break;
		case 1:  // right
			if((grid->getBugAt(x + 1, y) == NULL) && (inBounds(x + 1, y))){
				basicMove(x + 1, y);
			}
			break;
		case 2:  // down
			if((grid->getBugAt(x, y - 1) == NULL) && (inBounds(x, y - 1))){
				basicMove(x, y - 1);
			}
			break;
		case 3:  // left
			if((grid->getBugAt((gridSize - 1), y) == NULL) && (inBounds((gridSize - 1), y))){
				basicMove((gridSize - 1), y);
			}
			break;
		}
	}
	else if((y == (gridSize - 1)) && !(x == 0) && !(x == (gridSize - 1))){
		switch(grid->randomPos()){
		case 0:  // up
			if((grid->getBugAt(x, y + 1) == NULL) && (inBounds(x, y + 1))){
				basicMove(x, y + 1);
			}
			break;
		case 1:  // right
			if((grid->getBugAt(x + 1, y) == NULL) && (inBounds(x + 1, y))){
				basicMove(x + 1, y);
			}
			break;
		case 2:  // down
			if((grid->getBugAt(x, 0) == NULL) && (inBounds(x, 0))){
				basicMove(x, 0);
			}
			break;
		case 3:  // left
			if((grid->getBugAt(x - 1, y) == NULL) && (inBounds(x - 1, y))){
				basicMove(x - 1, y);
			}
			break;
		}
	}
	else if((x == (gridSize - 1))  && !(y == 0) && !(y == (gridSize - 1))){
		switch(grid->randomPos()){
		case 0:  // up
			if((grid->getBugAt(x, y + 1) == NULL) && (inBounds(x, y + 1))){
				basicMove(x, y + 1);
			}
			break;
		case 1:  // right
			if((grid->getBugAt(0, y) == NULL) && (inBounds(0, y))){
				basicMove(0, y);
			}
			break;
		case 2:  // down
			if((grid->getBugAt(x, y - 1) == NULL) && (inBounds(x, y - 1))){
				basicMove(x, y - 1);
			}
			break;
		case 3:  // left
			if((grid->getBugAt(x - 1, y) == NULL) && (inBounds(x - 1, y))){
				basicMove(x - 1, y);
			}
			break;
		}
	}
	else if((x == 0) && (y == 0)){  // Top left corner
		switch(grid->randomPos()){
		case 0:  // up
			if((grid->getBugAt(x, (gridSize - 1)) == NULL) && (inBounds(x, (gridSize - 1)))){
				basicMove(x, (gridSize - 1));
			}
			break;
		case 1:  // right
			if((grid->getBugAt(x + 1, y) == NULL) && (inBounds(x + 1, y))){
				basicMove(x + 1, y);
			}
			break;
		case 2:  // down
			if((grid->getBugAt(x, y - 1) == NULL) && (inBounds(x, y - 1))){
				basicMove(x, y - 1);
			}
			break;
		case 3:  // left
			if((grid->getBugAt((gridSize - 1), y) == NULL) && (inBounds((gridSize - 1), y))){
				basicMove((gridSize - 1), y);
			}
			break;
		}
	}
	else if((x == (gridSize - 1)) && (y == 0)){  // Top right corner
		switch(grid->randomPos()){
		case 0:  // up
			if((grid->getBugAt(x, (gridSize - 1)) == NULL) && (inBounds(x, (gridSize - 1)))){
				basicMove(x, (gridSize - 1));
			}
			break;
		case 1:  // right
			if((grid->getBugAt(0, y) == NULL) && (inBounds(0, y))){
				basicMove(0, y);
			}
			break;
		case 2:  // down
			if((grid->getBugAt(x, y - 1) == NULL) && (inBounds(x, y - 1))){
				basicMove(x, y - 1);
			}
			break;
		case 3:  // left
			if((grid->getBugAt(x - 1, y) == NULL) && (inBounds(x - 1, y))){
				basicMove(x - 1, y);
			}
			break;
		}
	}
	else if((x == 0) && (y == (gridSize - 1))){  // Bottom left corner
		switch(grid->randomPos()){
		case 0:  // up
			if((grid->getBugAt(x, y + 1) == NULL) && (inBounds(x, y + 1))){
				basicMove(x, y + 1);
			}
			break;
		case 1:  // right
			if((grid->getBugAt(x + 1, y) == NULL) && (inBounds(x + 1, y))){
				basicMove(x + 1, y);
			}
			break;
		case 2:  // down
			if((grid->getBugAt(x, 0) == NULL) && (inBounds(x, 0))){
				basicMove(x, 0);
			}
			break;
		case 3:  // left
			if((grid->getBugAt((gridSize - 1), y) == NULL) && (inBounds((gridSize - 1), y))){
				basicMove((gridSize - 1), y);
			}
			break;
		}
	}
	else if((x == (gridSize - 1)) && (y == (gridSize - 1))){  // Bottom right corner
		switch(grid->randomPos()){
		case 0:  // up
			if((grid->getBugAt(x, y + 1) == NULL) && (inBounds(x, y + 1))){
				basicMove(x, y + 1);
			}
			break;
		case 1:  // right
			if((grid->getBugAt(0, y) == NULL) && (inBounds(0, y))){
				basicMove(0, y);
			}
			break;
		case 2:  // down
			if((grid->getBugAt(x, 0) == NULL) && (inBounds(x, 0))){
				basicMove(x, 0);
			}
			break;
		case 3:  // left
			if((grid->getBugAt(x - 1, y) == NULL) && (inBounds(x - 1, y))){
				basicMove(x - 1, y);
			}
			break;
		}
	}
	else{
		switch(grid->randomPos()){
		case 0:  // up
			if((grid->getBugAt(x, y + 1) == NULL) && (inBounds(x, y + 1))){
				basicMove(x, y + 1);
			}
			break;
		case 1:  // right
			if((grid->getBugAt(x + 1, y) == NULL) && (inBounds(x + 1, y))){
				basicMove(x + 1, y);
			}
			break;
		case 2:  // down
			if((grid->getBugAt(x, y - 1) == NULL) && (inBounds(x, y - 1))){
				basicMove(x, y - 1);
			}
			break;
		case 3:  // left
			if((grid->getBugAt(x - 1, y) == NULL) && (inBounds(x - 1, y))){
				basicMove(x - 1, y);
			}
			break;
		}
	}
}

void LadyBug::birth(int posx, int posy){
	new LadyBug(this->grid, posx, posy, lbBreed);
	breedCount = 0;
}

void LadyBug::breed(){
	if(breedCount >= lbBreed){
		breedAdjacent();
	}

}

char LadyBug::character(){
	return 'x';
}

bool LadyBug::starveCheck(){  // Returns 1 if bug is dead, 0 if still alive (used in kill() in Grid)
	if(starveCount >= 3){
		return 1;
	}
	else{
		return 0;
	}
}

