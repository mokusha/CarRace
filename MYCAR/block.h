#pragma once
#include "game_object.h"

const int BLOCK = 178;
const int BLOCK_WIDTH = 2;
const int BLOCK_HEIGHT = 1;
//const int BLOCK_COUNT = 20;
const int arrBLOCK[BLOCK_HEIGHT*BLOCK_WIDTH] = { BLOCK,BLOCK };

class Block : public GameObject {
public:
	Block(const int x, const int y);
	~Block();
};
