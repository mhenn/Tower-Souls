#include "SavePoint.h"

void GameLogic::SavePoint::run(GameLogic::Player* player, bool& remove) {
	player->setSaveAble(true);
	remove = false;
	player->getLog()->addEvent("Du siehst ein Terminal.");
	player->getLog()->addEvent("Zum speichern 'e' betaetigen");


}