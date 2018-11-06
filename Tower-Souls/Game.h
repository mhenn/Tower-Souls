#pragma once
#include "Player.h"
#include "Tower.h"

#include "Logic.h"
#include "View.h"

class Game {
private:
	Player * player;
	Tower tower;
	Stage *currentStage;
	View *view;

	void drawGrid() {
		view->draw();
	}

public:
	Game(Player *p, Tower t) :player(p), tower(t) {
		this->currentStage = t.getStage(t.getCurrentStage());
		this->view = new View(currentStage->getGrid(), player, t.getCurrentStage());
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