#include "Monster.h"

void GameLogic::Monster::run(GameLogic::Player* player,bool& remove) {

	std::string message = "Du triffst auf: " + this->getName();
	player->getLog()->addEvent(message);

	if (player->getStrength() >= this->strength) {
		player->getLog()->addEvent("Du gewinnst!");
		if (this->item)
			this->item->run(player, remove);		
	}
	else {
		player->decHealth();
		
		if (player->getGameOver())
			return;

		player->getLog()->addEvent("Du verlierst und wirst zum Start zurueckgesetzt!");
		player->setRoom(player->getStart());
		remove = false;
		
	}
}