#pragma once
#include "game_object.h"
#include "car.h"
#include "block.h"
#include "screen.h"


const int KEY_LEFT = 75, KEY_RIGHT = 77, KEY_UP = 72, KEY_DOWN = 80, KEY_ENTER = 13, KEY_ESC = 27;
//const int X_CAR_INITIAL = 16, Y_CAR_INITIAL = 15;
const int SHIFT_PERIOD_MOVEMENT = 10, MAX_PERIOD_MOVEMENT=400, MIN_PERIOD_MOVEMENT=10;

class Game {

public:
	Game();
	~Game();

	void GameBegin();
	void Input();
	void randomize();

	void CreateBlock();
	//void MoveBlock();
	void GameOver();
	bool ChekCollision();

private:
	bool gameOver;
	unsigned long int timeBegin;
	unsigned long int timeEnd;
	unsigned long int timeDuration;
	int periodMovement;
	Car car;
	Screen screen;
};
