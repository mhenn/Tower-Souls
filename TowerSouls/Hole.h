#pragma once
#include "Action.h"
#include "Player.h"

namespace GameLogic {
	/*
		Die Klasse fuer das Lochevent
	*/
	class Hole : public Action {
	public:
		// Legt ein neues Loch an
		Hole() { type = "loch"; }
		void run(Player* player, bool& remove) override;
	};
}