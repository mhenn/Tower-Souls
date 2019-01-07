#pragma once
#include "Player.h"
#include "Game.h"

void GameLogic::Player::incHealth(int amount ) {
	if (this->health + amount <= this->maxhealth)
		this->health += amount;
	else
		this->health = this->maxhealth;
}

void GameLogic::Player::decHealth(int amount ) {
	int newHealth = this->health - amount;
	if ( newHealth >= 0)
		this->health -= amount;
	else
		this->gameOver = true;
}

void GameLogic::Player::incStage() {
	int newStage = this->currentStage + 1;
	if (newStage < 10)
		this->currentStage += 1;
	else 
		this->wonTheGame = true;
}
void GameLogic::Player::decStage() {
	int newStage = this->currentStage + 1;
	if (newStage >= 0)
		this->currentStage -= 1;
}

bool GameLogic::Player::move(direction d, Stage *currentStage) {
	Room* currentRoom = currentStage->getRoom(room);
	switch (d) {
	case North:
		if (currentRoom->canPass(North)) {			
			if (room.getY() - 1 >= 0)
				room = Point(room.getX(), room.getY() -1);
			Room* newRoom = currentStage->getRoom(room);
			newRoom->reveal();
			return true;
		}		
		break;
	case East:
		if (currentRoom->canPass(East)) {
			if (room.getX() + 1 < currentStage->getLength())
				room = Point(room.getX() +1, room.getY() );
			Room* newRoom = currentStage->getRoom(room);
			newRoom->reveal();
			return true;
		}
		break;
	case South:
		if (currentRoom->canPass(South)) {
			if (room.getY() + 1 < currentStage->getHeight())
				room = Point(room.getX(), room.getY() + 1);
			Room* newRoom = currentStage->getRoom(room);
			newRoom->reveal();
			return true;
		}
		break;
	case West:
		if (currentRoom->canPass(West)) {
			if (room.getX() - 1 >= 0)
				room = Point(room.getX() - 1, room.getY());
			Room* newRoom = currentStage->getRoom(room);
			newRoom->reveal();
			return true;
		}
		break;
	}
	return false;
}
