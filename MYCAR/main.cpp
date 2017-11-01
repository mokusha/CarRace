#include <iostream>

#include "game.h"
#include "game_object.h"
#include "car.h"
#include "block.h"
#include "screen.h"

using namespace std;

int main(int argc, char** argv) {
	Game test;
	test.GameBegin();
	/*Screen test(20,20);
	Car testCar(0,0);
	test.InscribeObject(testCar);
	Block testBlock(3,3);
	test.InscribeObject(testBlock);
	test.Draw();*/
	//system("pause");
	return 0;
}