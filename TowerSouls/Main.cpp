#include "Main.h"


// Speichert den aktuellen Spielstand
bool GameLogic::Main::save() {
	return true;
}

GameLogic::playerInput GameLogic::Main::input() {
	switch (_getch())
	{
	case 'a':
		return Left;
	case 'd':
		return Right;
	case 'w':
		return Up;
	case 's':
		return Down;
	case 'n':
		return New;
	case 'l':
		return Load;
	case 'h':
		return Help;
	case 'e':
		return Save;
	case ' ':
		return Skip;
	}
	return Idle;
}

void GameLogic::Main::runGame() {

	bool gameOver = false;
	this->game->showTitle();
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLError eResult;
	while (!gameOver) {
		playerInput in = input();
		switch (in) {
		case Load:			
			eResult = xmlDoc.LoadFile("SaveGame.xml");
			if (eResult)
				break;
			game = Utils::XML().loadSaveGame();
			game->initGameView(GameView::Game);

			break;
		case Save:
			if (game->getCurrentPlayer() && game->getCurrentPlayer()->getSaveAble()) {
				Utils::XML().save(this->game);
				this->game->getLog()->addEvent("Gespeichert");
				this->game->getView()->draw(GameView::draw::Game);
				this->game->getLog()->removeLast();
			}
			break;
		case New:
			game->setTower(Utils::XML().load());
			game->initNewGame();
			break;
		case Idle:
			break;
		default:
			game->run(in);
			break;
		}

		if (game && game->isActive()) {
			gameOver = this->game->getCurrentPlayer()->getGameOver();
			if (gameOver) {
				GameView::View().draw(GameView::draw::Death);
				Sleep(10000);				
			}
			if (game->getCurrentPlayer()->getWon()) {
				gameOver = true;
				GameView::View(this->game->GetEndStory()).draw(GameView::draw::End);
				Sleep(10000);
			}
		}


	}
}

int main() {
	bool gameRunning = true;
	while (gameRunning) {
		GameLogic::Main main = GameLogic::Main();
		main.runGame();
	}
	return 0;
}

bool load();
