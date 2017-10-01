#include "Snake.h"

Snake::Snake() {
	this->x = 0;
	this->y = 0;
	this->lenght = 0;
	this->move_dir = UP;
};

bool Snake::Move() {
	short int prevLoc[2];
	short int newLoc[2];

	for (short int i = 0; i < lenght; i++) {
		if (i == 0)
		{
			prevLoc[0] = tailX[0];
			prevLoc[1] = tailY[0];
			tailX[0] = x;
			tailY[0] = y;
		}
		else
		{
			newLoc[0] = prevLoc[0];
			newLoc[1] = prevLoc[1];
			prevLoc[0] = tailX[i];
			prevLoc[1] = tailY[i];
			tailX[i] = newLoc[0];
			tailY[i] = newLoc[1];
		}
	}

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
	default:
		return false;
		break;
	};

	return true;
};