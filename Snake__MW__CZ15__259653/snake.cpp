#include "snake.h"
#include<time.h>
#include<iostream>

Snake::Snake(menu &m) : m(m)
{
	gameOver = false;
	direction = UP;
	this->m = m;
	


}

void Snake::debug_display() const
{
	std::cout << "Snake:" << std::endl;
	for (size_t i=0; i<snake.size(); ++i)
	{
		std::cout << snake[i].first << ", " << snake[i].second << std::endl;
	}

	std::cout << "Fruit:" << fruit.first << ", " << fruit.second << std::endl;
}

void Snake::update()
{
	srand(time(0));
	if (direction == UP)
	{
		snake.insert(snake.begin(),(std::pair<int, int>(snake.front().first, snake.front().second-1)));
		snake.pop_back();
	}
	if (direction == DOWN)
	{
		snake.insert(snake.begin(),(std::pair<int, int>(snake.front().first, snake.front().second+1)));
		snake.pop_back();
	}
	if (direction == LEFT)
	{
		snake.insert(snake.begin(),(std::pair<int, int>(snake.front().first -1, snake.front().second)));
		snake.pop_back();
	}
	if (direction == RIGHT)
	{
		snake.insert(snake.begin(), (std::pair<int, int>(snake.front().first +1, snake.front().second)));
		snake.pop_back();
	}
	if (direction == STOP) {  }
	
	if (snake.front().first == fruit.first && snake.front().second == fruit.second)
	{

		snake.push_back(std::pair<int, int>(snake.end()[-1].first, snake.end()[-1].second));
		int randx = rand() % (width - 3) + 2;
		int randy = rand() % (height - 3) + 5;
		bool isFree;
		if (m.getMode() == CLASSIC)
		{
			fruit.first = randx;
			fruit.second = randy;

		}
		if (m.getMode() == RIVER)
		{
			
			if (randx > width/2 - 3 && randx < width/2 + 3)
			{
				
				fruit.first = 12;
				fruit.second = randy;
			}
			else
			{
				
				fruit.first = randx;
				fruit.second = randy;
			}
			
		}

			
		
		score += 10;
		std::cout << "Score: "<<score << std::endl;
		std::cout << "mode: " << m.getMode() << "\n";
	}


	if ( snake.front().first == 0 || snake.front().first == width-1 || snake.front().second == 0 || snake.front().second == 1 || snake.front().second == 2|| snake.front().second == 3||snake.front().second == height+2)
	{
		direction = STOP;
		gameOver = true;
		std::cout << "GAME OVER" << std::endl;
		
	}
	
	for (size_t i = 4; i < snake.size(); ++i)
	{
		if (snake.front().first == snake[i].first && snake.front().second == snake[i].second)
		{
			direction = STOP;
			gameOver = true;
			std::cout << "GAME OVER" << std::endl;
		}
	}

	for (size_t i = 0; i < water.size(); ++i)
	{
		if (snake.front().first == water[i].first && snake.front().second == water[i].second && snake.front().first != bridge[i].first && snake.front().second != bridge[i].second)
		{
			direction = STOP;
			gameOver = true;
			std::cout << "GAME OVER" << std::endl;
		}
	}

	
	
}

void Snake::turn(Direction new_dir)
{
	direction = new_dir;
	if (new_dir == UP)
		std::cout << "Turn Up" << std::endl;
	if (new_dir == DOWN)
		std::cout << "Turn Down" << std::endl;
	if (new_dir == LEFT)
		std::cout << "Turn Left" << std::endl;
	if (new_dir == RIGHT)
		std::cout << "Turn Right" << std::endl;
}

bool Snake::isGameOver()
{
	if (gameOver == true)
		return true;
	if(gameOver == false)
	return false;
}

Direction Snake::getDirection()
{
	if (direction == UP)
	{
		return UP;
	}
	if (direction == DOWN)
	{
		return DOWN;
	}
	if (direction == LEFT)
	{
		return LEFT;
	}
	if (direction == RIGHT)
	{
		return RIGHT;
	}
}

int Snake::getSnakeSize()
{
	return snake.size();
}

int Snake::getSnakePosX(int no)
{
	return snake[no].first;
}

int Snake::getWaterSize()
{
	return water.size();
}

int Snake::getSnakePosY(int no)
{
	return snake[no].second;
}

int Snake::getWaterPosX(int no)
{
	return water[no].first;
}

int Snake::getWaterPosY(int no)
{
	return water[no].second;
}

int Snake::getBridgeSize()
{
	return bridge.size();
}

int Snake::getBridgePosX(int no)
{
	return bridge[no].first;
}

int Snake::getBridgePosY(int no)
{
	return bridge[no].second;
}



int Snake::getFruitPosX()
{
	return fruit.first;
}

int Snake::getFruitPosY()
{
	return fruit.second;
}

int Snake::getBoardHeight()
{
	return height;
}

int Snake::getBoardWidth()
{
	return width;
}

int Snake::getScore()
{
	return score;
}

void Snake::restart()
{

	snake.clear();
	score = 0;
	gameOver = false;
	direction = UP;
	snake.insert(snake.begin(), (std::pair<int, int>(width / 2, height / 2)));
	fruit.first = 9; fruit.second = 9;
	

}

void Snake::choose_gamemode()
{
	if (m.getMode() == CLASSIC)
	{
		snake.insert(snake.begin(), (std::pair<int, int>(width / 2, height / 2)));
		fruit.first = 9; fruit.second = 9;
	}
	if (m.getMode() == RIVER)
	{

		snake.insert(snake.begin(), (std::pair<int, int>(width / 1.5, height / 1.5)));
		fruit.first = 6; fruit.second = 6;
		for (int i = 1; i < width; ++i)
			for (int j = 4; j < height + 2; ++j)
			{
				if (i > width / 2 - 3 && i < width / 2 + 3)
				{
					if ((j > 7 && j < 11) || (j < height - 2 && j > height - 6))
					{
						bridge.push_back(std::pair<int, int>(i, j));
					}
					else
						water.push_back(std::pair<int, int>(i, j));
				}

			}
	}
}

//Mode Snake::getMode()
//{
//	return mode;
//}
