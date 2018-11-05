#pragma once
#include <vector>
#include "Room.h"
#include "Point.h"

class Stage {
private:


	struct RoomList {
		std::vector<Room*> list;
		RoomList(std::vector<Room*> l) : list(l) {}
		Room* operator [](int i) {
			return list[i];
		}

	};

	std::string story;
	std::vector<std::vector<Room*>> grid;
public:
	void setStory(std::string s) { this->story = s; }
	std::string getStory() { return this->story; }
	std::vector<std::vector<Room*>> getGrid() {
		return this->grid;
	}

	void pushRow(std::vector<Room*> row) {
		this->grid.push_back(row);
	}


	RoomList operator[](int i) {
		return RoomList(grid[i]);
	}

	Point getStartPosition() {
		for (int y = 0; y < grid.size(); y++) {
			for (int x = 0; x < grid[0].size(); x++) {
				if (grid[y][x]->getContainsPlayer())
					return Point(x, y);
			}
		}
		return Point(0, 0);
	}
	Room* getXYGrid(int x, int y) {
		return this->grid[y][x];
	}

};
