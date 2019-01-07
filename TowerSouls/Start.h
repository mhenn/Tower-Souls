#pragma once
#include "Action.h"
#include "Player.h"

namespace GameLogic {
	/*
	Die Klasse fuer das Lochevent
	*/
	class Start : public Action {
	private:
		std::string story;
	public:
		// Legt ein neues Loch an
		Start(std::string Story): story(Story) { type = "start"; }
		void run(Player* player, bool& remove) override;
	};
}