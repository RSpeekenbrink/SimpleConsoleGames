#ifndef SNAKE_H_
#define SNAKE_H_

	#include <iostream>

	class Snake
	{
	public:
		enum MOVE_DIR { UP, DOWN, LEFT, RIGHT };
		int lenght, x, y;
		Snake();
		MOVE_DIR move_dir;
		bool Move();
	};

#endif