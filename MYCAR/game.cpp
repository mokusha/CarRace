#include <iostream>
#include <conio.h>
#include <time.h>
#include "game.h"
#include "game_object.h"
#include "car.h"
#include "block.h"
#include "screen.h"

using namespace std;

Game::Game():car(0, 0), screen(20, 20) {
	gameOver = false;
	timeBegin=0;
	timeEnd=0;
	timeDuration=0;
	periodMovement=200;
	int yCarInitial = screen.getHeightDisplay()  - car.getHeight();
	int xCarInitial = screen.getWidthDisplay() - car.getWidth();
	car.setY(yCarInitial);
	car.setX(xCarInitial);
};

Game::~Game() {
	
};

void Game::GameBegin() {
	Game::randomize();
	screen.InscribeObject(car);
	timeBegin = clock();
	while (!gameOver) {
		timeEnd = clock();
		timeDuration = timeEnd - timeBegin;
		Game::CreateBlock();
		if (_kbhit() || timeDuration >= periodMovement) {
			//Game::MoveBlock();
			Input();

			screen.Reset();
			screen.InscribeObject(car);
			//screen.InscribeObject(block);
			screen.Draw();
			timeBegin = timeEnd;

		}
	}
	
	
};

void Game::Input() {
	if (_kbhit()) {
		int direction = _getch();
		switch (direction) {
		case KEY_LEFT:
			if (car.getX() > 0) {
				car.setX(car.getX() - 1);
			}
			break;
		case KEY_RIGHT:
			if ((car.getX()+ car.getWidth()) < screen.getWidthDisplay()) {
				car.setX(car.getX()+1);
			}
			break;
		case KEY_UP:
			if (periodMovement >= MIN_PERIOD_MOVEMENT) {
				periodMovement = periodMovement - SHIFT_PERIOD_MOVEMENT;
			}
			break;
		case KEY_DOWN:
			if (periodMovement <= MAX_PERIOD_MOVEMENT) {
				periodMovement = periodMovement + SHIFT_PERIOD_MOVEMENT;
			}
			break;
		case KEY_ENTER:
			system("pause");
			break;
		case KEY_ESC:
			Game::GameOver();
			break;
		default:
			break;
		}
	}
};

void Game::randomize() {
	srand((unsigned)time(NULL));
};

void Game::CreateBlock() {

};

//void Game::MoveBlock() {
//	block.setY = block.getY + 1;
//};

bool Game::ChekCollision() {
	bool res = false;
	//if () {
	//	res = true;
	//}
	return res;
};

void Game::GameOver() {
	system("cls");
	cout << endl << endl << endl << endl
		<< endl << endl << endl << endl
		<< endl << endl << endl << endl
		<< "\t\t\tGame Over"
		<< endl << endl << endl << endl
		<< endl << endl << endl << endl
		<< endl << endl << endl << endl;
	gameOver = true;
	system("pause");
};
