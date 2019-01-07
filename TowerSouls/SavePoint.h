#pragma once
#include "Action.h"
#include "Game.h"

namespace GameLogic {

	/*
		Die Klasse fuer das Event "Speicherpunkt"
	*/
	class SavePoint : public Action {
		
	public:
		SavePoint() { type = "save"; }
		void run(Player* player,bool& remove) override;
	};
}