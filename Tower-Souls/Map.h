#pragma once
#include <vector>
#include "Room.h"
#include <windows.h>

class Map {
private:

	std::vector<std::vector<Room*>> grid;
	std::string spacer = "                           ";

	void drawTopCorners(int x, int y) {
		if (y == 0) {
			if (x == 0)
				std::cout << "-";
			grid[y][x]->drawTop();
			std::cout << "-";
		}
	}

	void drawMidDoors(int x, int y) {
		Room *current = grid[y][x];
		bool lastInRow = x == grid[0].size() - 1;
		if (x == 0)
			std::cout << "|";

		current->drawMid();

		if (lastInRow) {
			std::cout << "|";
			return;
		}

		if (!lastInRow && !grid[y][x ]->getFog()) {
			if (!current->getEast())
				std::cout << "|";
			else
				std::cout << " ";
		}
		else
			std::cout << " ";


	}

	void drawBottomCorners(int x, int y) {
		Room *current = grid[y][x];
		bool lastInCol = y == grid.size() - 1;
		bool lastInRow = x == grid[0].size() - 1;
		bool belowRight = !lastInCol && !lastInRow;

		if (x == 0)
			std::cout << "|";

		if (y < grid.size() - 1)
			current->drawBottom(lastInCol, grid[y + 1][x]);
		else
			current->drawBottom(lastInCol, nullptr);


		if (lastInRow) {
			std::cout << "|";
			return;
		}


		bool fogBelow = !lastInCol && !grid[y + 1][x]->getFog();
		bool fogNext = !lastInRow && !grid[y][x + 1]->getFog();
		bool fogBelowRight = belowRight && !grid[y + 1][x + 1]->getFog();

		if (lastInCol)
			std::cout << "-";
		else if (!current->getFog() || fogBelow || fogNext || fogBelowRight) {
			std::cout << "+";
		}
		else
			std::cout << " ";

	}


	void drawMap() {
		int start = 0;
		for (int y = 0; y < grid.size(); y++) {
			for (int i = start; i < 3; i++) {
				if (y == 0 || i > 0) {
					std::cout << std::endl;
					std::cout << spacer;
				}
				for (int x = 0; x < grid[0].size(); x++) {
					switch (i) {
					case 0:
						drawTopCorners(x, y);
						break;
					case 1:
						drawMidDoors(x, y);
						break;
					case 2:
						drawBottomCorners(x, y);
						break;
					}
				}

				start = 1;
			}
		}
	}

public:

	Map(std::vector<std::vector<Room*>> newGrid) : grid(newGrid) { }


	void draw() {				
		drawMap();
	}
};