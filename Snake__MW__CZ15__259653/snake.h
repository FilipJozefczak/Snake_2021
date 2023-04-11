#pragma once
#include <vector>
#include "menu.h"
enum Direction {STOP=0, UP, DOWN, LEFT, RIGHT };
//enum Mode {CLASSIC, RIVER};

class Snake
{
	menu& m;
	int height = 40;
	int width = 40;

	int score = 0;
	bool gameOver;
	Direction direction;
	//Mode mode;
	std::vector<std::pair<int, int>> snake;

	std::pair<int, int> fruit;
	std::vector<std::pair<int, int>> water;
	std::vector<std::pair<int, int>> bridge;

public:
	Snake(menu& m);
	void debug_display() const;
	void update();
	void turn(Direction new_dir);
	bool isGameOver();
	Direction getDirection();
	int getSnakeSize();
	int getSnakePosX(int no);
	int getWaterSize();
	int getSnakePosY(int no);
	int getWaterPosX(int no);
	int getWaterPosY(int no);
	int getBridgeSize();
	int getBridgePosX(int no);
	int getBridgePosY(int no);
	int getFruitPosX();
	int getFruitPosY();
	int getBoardHeight();
	int getBoardWidth();
	int getScore();
	void restart();
	void choose_gamemode();
	//Mode getMode();
};