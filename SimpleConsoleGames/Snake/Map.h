#ifndef MAP_H_
#define MAP_H_
	#include <iostream>
	#include "Snake.h"
	#include "Fruit.h"

	class Map {
		private:
			Snake* player;
			Fruit* fruit;
		public:
			int width, height;
			Map(int width, int height, Snake* snake, Fruit* fruit);
			bool Draw();
	};
#endif