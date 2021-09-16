/*
 * Grid.cpp
 *
 *  Created on: May 11, gridSize19
 *      Author: silvettimj
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>


#include "Grid.h"
#include "Aphid.h"
#include "LadyBug.h"

using namespace std;

Grid::Grid() {
	stepCount = 0;
	aNum = 0;
	lbNum = 0;
	srand(time(0));
	for(int xCount = 0; xCount < gridSize; xCount++){  // Make grid with empty cells (NULL)
		for(int yCount = 0; yCount < gridSize; yCount++){
			grid[xCount][yCount] = NULL; // Fills each cell with nothing
		}
	}
	cout << "Enter the number of Aphids you would like to make: ";
	cin >> aphidNum;
	cout << "Enter the number of LadyBugs you would like to make (make sure this is less than aphids): ";
	cin >> ladyBugNum;
	createAphids(aphidNum);
	createLadyBugs(ladyBugNum);
}

Grid::~Grid() {
	for(int xCount = 0; xCount < gridSize; xCount++){
		for(int yCount = 0; yCount < gridSize; yCount++){
			if(grid[xCount][yCount] != NULL){
				delete grid[xCount][yCount];
			}
		}
	}
}

Bug* Grid::getBugAt(int a, int b) const{
	if((a >= 0) && (b >= 0) && (a < gridSize) && (b < gridSize)){  // Makes sure input coordinates are good
		return grid[a][b];  // Returns pointer to bug at (a, b)
	}
	else{
		return NULL;  // returns nothing, bad coordinates
	}
}

void Grid::setBugAt(Bug* bug, int a, int b){
	if((a >= 0) && (b >= 0) && (a < gridSize) && (b < gridSize)){  // Makes sure input coordinates are good
		grid[a][b] = bug; // input bug gets set at (a, b) on the grid
	}
}

int Grid::randomPos(){  // Random number will be used for direction for aphids
	int retVal;
	retVal = rand() % 4;  // 0: up, 1: right, 2: down, 3: right
	return retVal;
}

void Grid::kill(){  // Check each grid cell for bugs who have starved, then delete them
	for(int xCount = 0;  xCount < gridSize;  xCount++){  // Cycle through each a value
		for(int yCount = 0; yCount < gridSize; yCount++){  // Cycle through each b value
			if((grid[ xCount][yCount] != NULL) && (grid[xCount][yCount]->starveCheck())){  // Make sure there is a bug at (a, b)
																                           // and it has starved
				delete grid[xCount][yCount];  // delete bug at this spot
				grid[xCount][yCount] = NULL;
			}
		}
	}
}

void Grid::resetMove(){  // On each new time step, move state for all bugs is set to 0
	for(int a = 0; a < gridSize; a++){  // Cycle through each a value
		for(int b = 0; b < gridSize; b++){  // Cycle through each b value
			if(grid[a][b] != NULL){  // Make sure there is a bug at (a, b)
				grid[a][b]->setMove(0);  // Set move state to not moved for bug being pointed to int grid arrab at (a, b)

			}
		}
	}
}

void Grid::createAphids(int n){  // Puts n number of initial LadyBugs on grid

	int aCount = 0;
	bool coordSel;
	int a;
	int b;
	int bc;
	cout << "Enter # of steps for Aphids to breed: ";
	cin >> bc;
	cout << "For Aphid coordinates, Enter 0 for random coordinates or 1 for manual entry: ";
	cin >> coordSel;
	while(aCount < n){
		switch(coordSel){
		case 0:
			a = rand() % gridSize;
			b = rand() % gridSize;
			break;
		case 1:
			aNum++;
			cout << "Enter x value for Aphid #" << aNum << ": ";
			cin >> a;
			cout << "Enter y value for Aphid #" << aNum << ": ";
			cin >> b;
			break;
		}
		if(grid[a][b] == NULL){
			aCount++;
			new Aphid(this, a, b, bc);
		}
	}
}

void Grid::createLadyBugs(int n){  // Puts initial Aphids on grid
	int lCount = 0;
	bool coordSel;
	int a;
	int b;
	int bc;
	cout << "Enter # of steps for LadyBugs to breed: ";
	cin >> bc;
	cout << "For LadyBug coordinates, enter 0 for random coordinates or 1 for manual entry: ";
	cin >> coordSel;
	while(lCount < n){
		switch(coordSel){
		case 0:
			a = rand() % gridSize;
			b = rand() % gridSize;
			break;
		case 1:
			lbNum++;
			cout << "Enter x value for LadyBug #" << lbNum << ": ";
			cin >> a;
			cout << "Enter y value for LadyBug #" << lbNum << ": ";
			cin >> b;
			break;
		}
		if(grid[a][b] == NULL){
			lCount++;
			new LadyBug(this, a, b, bc);
		}
	}
}

void Grid::displayGrid(){  // Goes left to right, top to bottom, prints out Grid with Bugs and grid lines
	for(int yCount = 0; yCount < gridSize; yCount++){
		if(yCount == 0){
			cout << "__|_0|_1|_2|_3|_4|_5|_6|_7|_8|_9|10|11|12|13|14|15|16|17|18|19|" << endl;
		}
		for(int xCount = 0; xCount < gridSize; xCount++){
			if(xCount == 0){
				if(yCount < 10){
					cout << ' ';
				}
				cout << yCount << '|';
			}
			if(grid[xCount][yCount] == NULL){
				cout << "__|";
			}
			else{
				cout << (grid[xCount][yCount]->character()) << "_|";
			}
		}
		cout << endl;
	}
}

void Grid::displayGridSfml(){
	ostringstream p;
	p << "Aphids Vs. Lady Bugs (Step: " <<  stepCount << ')';
	sf::RenderWindow window(sf::VideoMode(535,535), p.str());
	sf::CircleShape c[gridSize][gridSize];
	for(int yCount = 0; yCount < gridSize; yCount++){
		for(int xCount = 0; xCount < gridSize; xCount++){
			if(grid[xCount][yCount] == NULL){
				c[xCount][yCount] = sf::CircleShape(5.f, 4);
				c[xCount][yCount].setFillColor(sf::Color::Blue);
			}
			else{
				if(grid[xCount][yCount]->character() == 'x'){
					c[xCount][yCount] = sf::CircleShape(5.f);  //LadyBugs are red squares
					c[xCount][yCount].setFillColor(sf::Color::Red);
				}
				else if(grid[xCount][yCount]->character() == 'o'){
					c[xCount][yCount] = sf::CircleShape(5.f);  //Aphids are green circles
					c[xCount][yCount].setFillColor(sf::Color::Green);
				}
			}
			c[xCount][yCount].setPosition(xCount*25 + 25, yCount*25 + 25);
		}
	}

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}
		window.clear();
		for(int yCount = 0; yCount < gridSize; yCount++){
			for(int xCount = 0; xCount < gridSize; xCount++){
				window.draw(c[xCount][yCount]);
			}
		}
		window.display();
	}
}

void Grid::stepForward(int n){
	for(int m = 0; m < n; m++){
		stepCount++;
		for(int xCount = 0; xCount < gridSize; xCount++){  // Move all Bugs that haven't already moved
			for(int yCount = 0; yCount < gridSize; yCount++){
				if(grid[xCount][yCount] != NULL){
					grid[xCount][yCount]->setMove(0);
				}
			}
		}

		for(int xCount = 0; xCount < gridSize; xCount++){  // Move all Bugs that haven't already moved
			for(int yCount = 0; yCount < gridSize; yCount++){
				if((grid[xCount][yCount] != NULL) && !(grid[xCount][yCount]->moveCheck())){
					grid[xCount][yCount]->move();
				}
			}
		}

		kill();

		for(int xCount = 0; xCount < gridSize; xCount++){  // Each Bug breeds
			for(int yCount = 0; yCount < gridSize; yCount++){
				if(grid[xCount][yCount] != NULL){
					grid[xCount][yCount]->breed();
				}
			}
		}
	}
}

int Grid::getStepCount(){
	return stepCount;
}

void Grid::setStepCount(int a){
	stepCount = a;
}

Bug* Grid::getGrid(int x, int y){
	Bug *p;
	p = grid[x][y];
	return p;
}

