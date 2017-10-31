#pragma once
#include "game_object.h"

const int SPACE = 32, CAR = 219;
const int CAR_WIDTH = 3, CAR_HEIGHT = 4;
const int arrMyCar[CAR_HEIGHT * CAR_WIDTH] = { SPACE, CAR, SPACE , CAR, CAR, CAR , SPACE, CAR, SPACE , CAR, CAR, CAR };

class Car: public GameObject{

public:
	Car(const int x, const int y);
	~Car();
};