#include "Hole.h"

void GameLogic::Hole::run(GameLogic::Player* player,  bool& remove) {

	
	player->decStage();
	player->getLog()->addEvent("Du faellst durch ein Loch im Boden eine Etage nach unten.");
	remove = false;

}