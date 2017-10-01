#ifdef _WIN32
	#include <Windows.h>	
#else
	#include <unidef.h>
#endif

#include <conio.h>
#include <iostream>
#include "Fruit.h"
#include "Map.h"
#include "Snake.h"

bool gameOver, won;
unsigned int delMil(100);
int score;
Snake player;
Fruit fruit;
Map map(30, 20, &player, &fruit);

void Setup();
void Input();

int main() {
	Setup();
	while (!gameOver) {
		Input();
		player.Move();

		map.Draw();
		std::cout << "Score: " << score;

		if (player.x == fruit.x && player.y == fruit.y) {
			fruit.resetLoc((map.width - 1), (map.height - 1));
			player.lenght++;
			score++;
			if (score == 100)
			{
				won = true;
				gameOver = true;
			}
		}

		if (player.x == 0 || player.x == map.width || player.y == 0 || player.y == map.height) 
		{
			gameOver = true;
		}

		for (short int i = 0; i < player.lenght; i++)
		{
			if (player.x == player.tailX[i] && player.y == player.tailY[i])
			{
				gameOver = true;
				break;
			}
		}

		#ifdef _WIN32 //Control Speedy CPU's
				Sleep(delMil);
		#else
				usleep(delMil * 1000);
		#endif
	}
	if(won)
		std::cout << std::endl << "You Won! Score: " << score << std::endl;
	else
		std::cout << std::endl << "Game Over! Score: " << score << std::endl;
	std::system("pause");

	return 0;
}

void Setup() {
	gameOver = false;
	won = false;
	player = Snake();
	player.x = map.width / 2;
	player.y = map.height / 2;
	fruit.resetLoc((map.width - 1), (map.height - 1));
}

void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			player.move_dir = Snake::LEFT;
			break;
		case 'w':
			player.move_dir = Snake::UP;
			break;
		case 'd':
			player.move_dir = Snake::RIGHT;
			break;
		case 's':
			player.move_dir = Snake::DOWN;
			break;
		default:
				break;
		}
	}
}