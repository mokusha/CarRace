#pragma once

const int ADDITIONAL_WIDTH = 2, ADDITIONAL_HEIGHT = 2, X_SHIFT = 1, Y_SHIFT = 1;
const int BORDER_H = 205, BORDER_V = 186,
BORDER_1 = 201, BORDER_2 = 187, BORDER_3 = 200, BORDER_4 = 188;

class Screen {
public:
	Screen(int heightDisplay, int widthDisplay);
	~Screen();

	void InscribeObject(GameObject& go);
	void Draw();
	void Reset();
	int getHeightDisplay();
	int getWidthDisplay();

private:
	int** arrDisplay;
	int x;
	int y;
	int heightDisplay;
	int widthDisplay;
};

