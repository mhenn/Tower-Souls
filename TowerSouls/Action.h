#pragma once
#include <string>
#include "EventLog.h"


namespace GameLogic {

	extern class Player;
	/*
		Die Klasse Action ist die abstrakte Oberklasse fuer alle Events
	*/
	class Action {
	protected:
		std::string type;
	public:
		// Wird aufgerufen, wenn das Event ausgeloest wird
		virtual void run(Player* player, bool& remove) = 0;
		// Gibt den Typ des Events zurueck
		std::string getType() { return type; }
	};
}

