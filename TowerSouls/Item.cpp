#include "Item.h"

void GameLogic::Item::run(GameLogic::Player* player,bool& remove) {

	std::string message = "Du findest: " + this->name;
	player->getLog()->addEvent(message);

	player->incHealth(this->health);
	player->incStrength(this->strength);

	message = "Du erhaelst einen Bonus von, Leben: " + std::to_string(this->health);
	message += " Staerke: " + std::to_string(this->strength);
	player->getLog()->addEvent(message);	
}