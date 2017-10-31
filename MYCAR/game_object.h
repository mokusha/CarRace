#pragma once

class GameObject {

public:
	GameObject(const int x, const int y, const int width, const int height, const int arrO[]);
	virtual ~GameObject();

	//bool isAlive() const;
	//bool checkCollision(GameObject& go) const;

	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	int getSymbol(int y, int x) const;

	//void setX(int x);
	//void setY(int y);

private:
	int x, y;
	int width, height;
	int** arrObject;

};