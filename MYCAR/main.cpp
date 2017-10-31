#include <iostream>
#include <conio.h>
#include <time.h>

#include "game.h"
#include "game_object.h"
#include "car.h"
#include "block.h"
#include "screen.h"

using namespace std;

int main(int argc, char** argv) {
	Screen test(15,15);
	Car testCar(10,10);
	test.InscribeObject(testCar);
	Block testBlock(18,18);
	test.InscribeObject(testBlock);
	test.Draw();
	system("pause");
	return 0;
}