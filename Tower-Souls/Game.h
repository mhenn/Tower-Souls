#pragma once

#include "Player.h"
#include "Tower.h"
#include "Map.h"
#include "Logic.h"

class Game {
private:
	Player * player;
	Tower *tower;
	Stage *currentStage;
	Map *map;

	void drawGrid() {
		map->draw();
	}

public:
	Game(Player *p, Tower *t) :player(p), tower(t) {
		this->currentStage = t->getStage(t->getCurrentStage());
		this->map = new Map(currentStage->getGrid());
	}

	void play() {
		boolean draw = true;
		Point start = currentStage->getStartPosition();
		Logic *l = new Logic(start, currentStage);

		while (!l->getGameOver())
		{
			if (draw)
				drawGrid();

			draw = l->input();
			l->move();
		}
	}




};