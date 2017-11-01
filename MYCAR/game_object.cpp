#include "game_object.h"


GameObject::GameObject(const int x, const int y, const int width, const int height, const int arrO[])
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	//ob'ablenie dinamicheskogo massiva
	int** arr = new int*[this->height];
	for (int i = 0; i < this->height; i++) {
		arr[i] = new int[this->width];
	}
	//заполнение массива
	for (int i = 0; i < this->height; i++) {
	for (int j = 0; j < this->width; j++) {
		arr[i][j] = arrO[i*this->width+j];
		}
	}
	this->arrObject = arr;
}
GameObject::~GameObject() {
	for (int i = 0; i < this->height; i++) {
		delete[] this->arrObject[i];
	}
	delete[] this->arrObject;
}

//bool GameObject::isAlive() const{}
//bool GameObject::checkCollision(GameObject& go) const {}
//
int GameObject::getX() const {
	return this->x;
}
int GameObject::getY() const {
	return this->y;}
int GameObject::getWidth() const {
	return this->width;
}
int GameObject::getHeight() const {
	return this->height;
}
int GameObject::getSymbol(int y, int x) const {
	return this->arrObject[y][x];
};

void GameObject::setX(int x) {
	this->x =x;
};
void GameObject::setY(int y) {
	this->y = y;
};

