#include "Snake.h"

Snake::Snake() {
	this->x = 0;
	this->y = 0;
	this->lenght = 0;
	this->move_dir = UP;
};

bool Snake::Move() {
	switch (move_dir)
	{
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
	};
	return false;
};