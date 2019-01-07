#pragma once
#include "Action.h"

namespace GameLogic {

	extern class Player;	
	// Die Aufzaehlung der moeglichen Richtungen
	enum direction { North, East, West, South, None };
	enum wnw { Wall = true, noWall = false };


	class Room {
		private:
			Action* action;
			bool north;
			bool west;
			bool east;
			bool south;
			bool hidden;
			bool isStart;
		public:
			Room(wnw North, wnw East, wnw West, wnw South, Action* action): 
				north(North), east(East),west(West),south(South), action(action) {}
			Room(bool North, bool East, bool West, bool South, bool Hidden):
				north(North), east(East), west(West), south(South),hidden(Hidden) {}
			void setAction(Action* action) { this->action = action; }
			// prft ob dort eine Wand ist und gibt true oder false zurck
			bool canPass(direction d);
			// Gibt das Event zurueck, das sich in dem Raum befindet
			Action* getEvent() { return action; }
			// gibt zuck ob der Raum enthllt ist
			bool isHidden() { return hidden; };
			// enthllt den Raum
			void reveal() { hidden = false; };
			// triggert Run des Action-Objects
			void triggerEvent(Player* p);
			// entfernt die Action aus dem Raum nach Nutzen des Items oder Gewinnen gegen das Monster um wieder nutzung oder erneuter Kampf zu vermeiden
			void Used_Won();
			void setStart(bool start) { this->isStart = start; }
			bool getStart() { return isStart; }
	};
}