#pragma once

//const int SPACE = 32;
const int DISPLAY_WIDTH = 20, DISPLAY_HEIGHT = 20;
const int BORDER_H = 205, BORDER_V = 186,
BORDER_1 = 201, BORDER_2 = 187, BORDER_3 = 200, BORDER_4 = 188;


class Screen {
public:
	Screen(int heightDisplay, int widthDisplay);
	~Screen();

	void InscribeObject(GameObject& go);
	void Draw();
	void Reset();
	//int** CreateDisplay();

public:
	int** arrDisplay;
	int x;
	int y;
	int heightDisplay;
	int widthDisplay;
};

