/*
 * Aphid.cpp
 *
 *  Created on: May 8, 2019
 *      Author: silvettimj
 */

#include "Aphid.h"
#include <iostream>

using namespace std;

Aphid::Aphid() {
	// TODO Auto-generated constructor stub
}

Aphid::Aphid(Grid *thisGrid, int x, int y, int bc) : Bug(thisGrid, x, y){
	aBreed = bc;
}

Aphid::~Aphid() {
	// TODO Auto-generated destructor stub
}

void Aphid::move(){
	breedCount++;
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

void Aphid::birth(int posx, int posy){
	new Aphid(this->grid, posx, posy, aBreed);
	breedCount = 0;
}

void Aphid::breed(){
	if(breedCount >= aBreed){
		breedAdjacent();
	}
}

char Aphid::character(){
	return 'o';
}

