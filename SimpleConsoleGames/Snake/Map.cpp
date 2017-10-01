#include "Map.h";


Map::Map(int width, int height, Snake* snake, Fruit* fruit) {
	this->width = width;
	this->height = height;
	this->player = snake;
	this->fruit = fruit;
};

bool Map::Draw()
{
	#ifdef _WIN32 //cls in windows = clear in Lunix
		std::system("cls");
	#else
		std::system("clear");
	#endif
		

		for (int i(0); i < this->height; i++) {
			for (int j(0); j < this->width; j++) {
				if (i == 0 || i == (this->height - 1))
					std::cout << "-";
				else if (j == 0 || j == (this->width - 1))
					std::cout << "|";
				else if (j == player->x && i == player->y)
					std::cout << "0";
				else if (j == fruit->x && i == fruit->y)
					std::cout << "@";
				else
				{ 
					bool handled = false;
					for(short int k(0); k < player->lenght; k++)
					{
						if (j == player->tailX[k] && i == player->tailY[k])
						{
							std::cout << "o";
							handled = true;
							break;
						}
					};
					if(!handled)
					std::cout << " ";
				}

				if (j == (this->width - 1))
					std::cout << std::endl;
			}
		}

	return true;
};