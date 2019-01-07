#pragma once
#include "Room.h"

bool GameLogic::Room::canPass(direction d) {
	switch (d)
	{
	case GameLogic::North:
		return this->north;
	case GameLogic::East:
		return this->east;
	case GameLogic::West:
		return this->west;
	case GameLogic::South:
		return this->south;	
	}
	return false;
}

void GameLogic::Room::triggerEvent(GameLogic::Player* p) {
	
	bool remove = true;
	if (this->action)
		this->action->run(p, remove);
	if(remove)
		Used_Won();	
}

void GameLogic::Room::Used_Won() {
	this->action = nullptr;
}