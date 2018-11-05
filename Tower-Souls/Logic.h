#pragma once
#include <conio.h>
#include <windows.h>
#include "Stage.h"

class Logic {
private:
	int x;
	int y;
	bool gameOver;
	enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirecton dir;
	Stage *s;
public:

	Logic() : x(0), y(0), gameOver(false), dir(STOP), s(nullptr) {}
	Logic(int nX, int nY, Stage *nS) : x(nX), y(nY), gameOver(false), dir(STOP), s(nS) {}
	Logic(Point p, Stage *nS) : x(p.x), y(p.y), gameOver(false), dir(STOP), s(nS) {}

	bool getGameOver() { return this->gameOver; }

	boolean input()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				dir = LEFT;
				return true;
			case 'd':
				dir = RIGHT;
				return true;
			case 'w':
				dir = UP;
				return true;
			case 's':
				dir = DOWN;
				return true;
			case 'x':
				gameOver = true;
				return true;
			}
		}
		return false;
	}


	void move()
	{
		std::vector<std::vector<Room*>> grid = s->getGrid();

		switch (dir)
		{
		case LEFT:
			if (s->getXYGrid(x, y)->getWest()) {
				if (x - 1 >= 0) {
					s->getXYGrid(x--, y)->removePlayer();
					s->getXYGrid(x, y)->setPlayerPosition();

				}
			}

			break;
		case RIGHT:
			if (s->getXYGrid(x, y)->getEast()) {
				if (x + 1 < grid[0].size()) {
					s->getXYGrid(x++, y)->removePlayer();
					s->getXYGrid(x, y)->setPlayerPosition();
				}
			}
			break;
		case UP:
			if (s->getXYGrid(x, y)->getNorth()) {
				if (y - 1 >= 0) {
					s->getXYGrid(x, y--)->removePlayer();
					s->getXYGrid(x, y)->setPlayerPosition();
				}
			}
			break;
		case DOWN:
			if (s->getXYGrid(x, y)->getSouth()) {
				if (y + 1 < grid.size()) {
					s->getXYGrid(x, y++)->removePlayer();
					s->getXYGrid(x, y)->setPlayerPosition();
				}
			}
			break;
		default:
			break;
		}
		dir = STOP;

	}

};