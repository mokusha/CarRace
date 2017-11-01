#include <iostream>

#include "game.h"
#include "game_object.h"
#include "car.h"
#include "block.h"
#include "screen.h"

using namespace std;

Screen::Screen(int h, int w)
{
	this->heightDisplay = h + ADDITIONAL_HEIGHT;
	this->widthDisplay = w + ADDITIONAL_WIDTH;
	this->arrDisplay = new int*[this->heightDisplay];
	for (int i = 0; i < this->heightDisplay; i++) {
		this->arrDisplay[i] = new int[this->widthDisplay];
	}

	for (int i = 0; i < this->heightDisplay; i++) {
		for (int j = 0; j < this->widthDisplay; j++)
		{
			if (i == 0 || i == (this->heightDisplay - 1)) {
				this->arrDisplay[i][j] = BORDER_H;
			}
			else
			{
				if (j == 0 || j == (this->widthDisplay - 1)) {
					this->arrDisplay[i][j] = BORDER_V;
				}
				else {
					this->arrDisplay[i][j] = SPACE;
				}
			}
		}
	}
	this->arrDisplay[0][0] = BORDER_1;
	this->arrDisplay[0][this->widthDisplay - 1] = BORDER_2;
	this->arrDisplay[this->heightDisplay - 1][0] = BORDER_3;
	this->arrDisplay[this->heightDisplay - 1][this->widthDisplay - 1] = BORDER_4;
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
			arrDisplay[i+go.getY()+ Y_SHIFT][j+go.getX()+ X_SHIFT]=go.getSymbol(i, j);
		}
	}
};

void Screen::Draw() {
	system("cls");
	for (int i = 0; i < heightDisplay; i++) {
		for (int j = 0; j < widthDisplay; j++) {
			cout << char(arrDisplay[i][j]);
		}
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

int Screen::getHeightDisplay() {
	return this->heightDisplay-ADDITIONAL_HEIGHT;
};

int Screen::getWidthDisplay() {
	return this->widthDisplay- ADDITIONAL_WIDTH;
};