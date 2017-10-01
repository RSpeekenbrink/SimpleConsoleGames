#ifndef SNAKE_H_
#define SNAKE_H_

	#include <iostream>

	class Snake
	{
	public:
		enum MOVE_DIR { UP, DOWN, LEFT, RIGHT };
		int lenght, x, y;
		int tailY[100], tailX[100];
		Snake();
		MOVE_DIR move_dir;
		bool Move();
	};

#endif