#include "Fruit.h"

void Fruit::resetLoc(int maxX, int maxY) {
	x = (rand() % (maxX - 1) )+ 1;
	y = (rand() % (maxY - 1) )+ 1;
}