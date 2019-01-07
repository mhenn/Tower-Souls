#pragma once
#include "Stairs.h"

void GameLogic::Stairs::run(Player* player, bool& remove) {
	player->incStage();
	remove = false;
}