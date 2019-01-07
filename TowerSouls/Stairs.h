#pragma once
#include "Action.h"
#include "Player.h"

namespace GameLogic {
	/*
	Die Klasse fuer das Lochevent
	*/
	class Stairs : public Action {
	public:
		// Legt ein neues Loch an
		Stairs() { type = "treppe"; }
		void run(Player* player, bool& remove) override;
	};
}