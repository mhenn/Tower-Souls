#pragma once
#include <string>
#include "Action.h"
#include "Player.h"
#include "Item.h"

namespace GameLogic {

	extern class Player;
	class Monster : public Action {//Extends Action

	private:
		unsigned int strength;
		std::string name;
		Item* item;

	public:
		Monster(std::string name, unsigned int strength, Item* item = nullptr):name(name),strength(strength),item(item) {type = "monster"; }		
		void run(Player* player, bool& remove) override;
		unsigned int getStrength() { return strength; }
		std::string getName() { return this->name; }
		Item* getItem() { return this->item; }
	};

}