//============================================================================
// Name        : PredatorPrey.cpp
// Author      : Michael Silvetti
// Version     :
// Copyright   : Your copyright notice
// Description : Predator-prey simulation
//============================================================================

#include <iostream>
#include <ctime>
#include "Grid.h"
#include "LadyBug.h"
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
	int sc = 0;
	Grid myGrid;  // User defined input from console is initiated from the creation of this (actual input is in methods)
	ostringstream p;

	cout << "\nPress 1-9 while clicked on the SFML window to advance that many steps" << endl;
	cout << "Click the exit icon in the top right to exit the simulation." << endl;
	cout << "(Current step count is displayed in the console)" << endl;

	p << "Aphids Vs. Lady Bugs";
	sf::RenderWindow window(sf::VideoMode(535,535), p.str());
	sf::CircleShape c[gridSize][gridSize];

	while(window.isOpen()){
		for(int yCount = 0; yCount < gridSize; yCount++){
			for(int xCount = 0; xCount < gridSize; xCount++){
				if(myGrid.getGrid(xCount, yCount) == NULL){
					c[xCount][yCount] = sf::CircleShape(5.f, 4);
					c[xCount][yCount].setFillColor(sf::Color::Blue);
				}
				else{
					if(myGrid.getGrid(xCount, yCount)->character() == 'x'){
						c[xCount][yCount] = sf::CircleShape(5.f);  //LadyBugs are red squares
						c[xCount][yCount].setFillColor(sf::Color::Red);
					}
					else if(myGrid.getGrid(xCount, yCount)->character() == 'o'){
						c[xCount][yCount] = sf::CircleShape(5.f);  //Aphids are green circles
						c[xCount][yCount].setFillColor(sf::Color::Green);
					}
				}
				c[xCount][yCount].setPosition(xCount*25 + 25, yCount*25 + 25);
			}
		}
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
			if(event.type == sf::Event::KeyPressed){ // 1 step if 1 pressed
				for(int yCount = 0; yCount < gridSize; yCount++){
					for(int xCount = 0; xCount < gridSize; xCount++){
						if(myGrid.getGrid(xCount, yCount) == NULL){
							c[xCount][yCount] = sf::CircleShape(5.f, 4);
							c[xCount][yCount].setFillColor(sf::Color::Blue);
						}
						else{
							if(myGrid.getGrid(xCount, yCount)->character() == 'x'){
								c[xCount][yCount] = sf::CircleShape(5.f);  //LadyBugs are red squares
								c[xCount][yCount].setFillColor(sf::Color::Red);
							}
							else if(myGrid.getGrid(xCount, yCount)->character() == 'o'){
								c[xCount][yCount] = sf::CircleShape(5.f);  //Aphids are green circles
								c[xCount][yCount].setFillColor(sf::Color::Green);
							}
						}
						c[xCount][yCount].setPosition(xCount*25 + 25, yCount*25 + 25);
					}
				}
				switch(event.key.code){
				case (sf::Keyboard::Num1):
						sc++;
					cout << "Step " << sc << endl;
					myGrid.stepForward(1);
					window.clear();
					for(int yCount = 0; yCount < gridSize; yCount++){
						for(int xCount = 0; xCount < gridSize; xCount++){
							window.draw(c[xCount][yCount]);
						}
					}
					window.display();
					break;
				case (sf::Keyboard::Num2):
					sc += 2;
					cout << "Step " << sc << endl;
					myGrid.stepForward(2);
					window.clear();
					for(int yCount = 0; yCount < gridSize; yCount++){
						for(int xCount = 0; xCount < gridSize; xCount++){
							window.draw(c[xCount][yCount]);
						}
					}
					window.display();
					break;
				case (sf::Keyboard::Num3):
					sc += 3;
					cout << "Step " << sc << endl;
					myGrid.stepForward(3);
					window.clear();
					for(int yCount = 0; yCount < gridSize; yCount++){
						for(int xCount = 0; xCount < gridSize; xCount++){
							window.draw(c[xCount][yCount]);
						}
					}
					window.display();
					break;
				case (sf::Keyboard::Num4):
					sc += 4;
					cout << "Step " << sc << endl;
					myGrid.stepForward(4);
					window.clear();
					for(int yCount = 0; yCount < gridSize; yCount++){
						for(int xCount = 0; xCount < gridSize; xCount++){
							window.draw(c[xCount][yCount]);
						}
					}
					window.display();
					break;
				case (sf::Keyboard::Num5):
					sc += 5;
					cout << "Step " << sc << endl;
					myGrid.stepForward(5);
					window.clear();
					for(int yCount = 0; yCount < gridSize; yCount++){
						for(int xCount = 0; xCount < gridSize; xCount++){
							window.draw(c[xCount][yCount]);
						}
					}
					window.display();
					break;
				case (sf::Keyboard::Num6):
					sc += 6;
					cout << "Step " << sc << endl;
					myGrid.stepForward(6);
					window.clear();
					for(int yCount = 0; yCount < gridSize; yCount++){
						for(int xCount = 0; xCount < gridSize; xCount++){
							window.draw(c[xCount][yCount]);
						}
					}
					window.display();
					break;
				case (sf::Keyboard::Num7):
					sc += 7;
					cout << "Step " << sc << endl;
					myGrid.stepForward(7);
					window.clear();
					for(int yCount = 0; yCount < gridSize; yCount++){
						for(int xCount = 0; xCount < gridSize; xCount++){
							window.draw(c[xCount][yCount]);
						}
					}
					window.display();
					break;
				case (sf::Keyboard::Num8):
					sc += 8;
					cout << "Step " << sc << endl;
					myGrid.stepForward(8);
					window.clear();
					for(int yCount = 0; yCount < gridSize; yCount++){
						for(int xCount = 0; xCount < gridSize; xCount++){
							window.draw(c[xCount][yCount]);
						}
					}
					window.display();
					break;
				case (sf::Keyboard::Num9):
					sc += 9;
					cout << "Step " << sc << endl;
					myGrid.stepForward(9);
					window.clear();
					for(int yCount = 0; yCount < gridSize; yCount++){
						for(int xCount = 0; xCount < gridSize; xCount++){
							window.draw(c[xCount][yCount]);
						}
					}
					window.display();
					break;
				default:
					break;
				}
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
	return 0;
}
