#include <iostream>

#include "game.h"
#include "game_object.h"
#include "car.h"
#include "block.h"
#include "screen.h"

using namespace std;

Screen::Screen(int heightDisplay, int widthDisplay)
{
	//arrDisplay = CreateDisplay();
	this->arrDisplay = new int*[heightDisplay];
	for (int i = 0; i < heightDisplay; i++) {
		arrDisplay[i] = new int[widthDisplay];
	}
	
	for (int i = 0; i < heightDisplay; i++) {
		for (int j = 0; j < widthDisplay; j++)
		{
			if (i == 0 || i == (heightDisplay - 1)) {
				arrDisplay[i][j] = BORDER_H;
			}
			else
			{
				if (j == 0 || j == (widthDisplay - 1)) {
					arrDisplay[i][j] = BORDER_V;
				}
				else {
					arrDisplay[i][j] = SPACE;
				}
			}
			
		}
	}
	arrDisplay[0][0] = BORDER_1;
	arrDisplay[0][widthDisplay - 1] = BORDER_2;
	arrDisplay[heightDisplay - 1][0] = BORDER_3;
	arrDisplay[heightDisplay - 1][widthDisplay - 1] = BORDER_4;


	//Draw( arrDisplay);
};

Screen::~Screen()
{
	for (int i = 0; i < heightDisplay; i++) {
		delete[] this->arrDisplay[i];
	}
	delete[] this->arrDisplay;
}

void Screen::InscribeObject(GameObject& go) {
	for (int i = 0; i<go.getHeight(); i++) {
		for (int j = 0; j<go.getWidth(); j++) {
			arrDisplay[i+go.getY()][j+go.getX()]=go.getSymbol(i, j);
		}
	}
};

void Screen::Draw() {
	system("cls");
	for (int i = 0; i < heightDisplay; i++)
	{
		for (int j = 0; j < widthDisplay; j++)
			cout << char(arrDisplay[i][j]);
		cout << endl;
	}
};

void Screen::Reset() {
	for (int i = 1; i < heightDisplay - 1; i++) {
		for (int j = 1; j < widthDisplay - 1; j++) {
			arrDisplay[i][j] = SPACE;
		}
	}
};
