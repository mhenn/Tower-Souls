#pragma once
#include "Action.h"
#include "Player.h"
namespace GameLogic {

	/*
		Die Klasse fuer das Itemevent
	*/
	
	class Item : public Action {
		private:
			std::string name;
			int health;
			int strength;
			int maxHealth;
		public:
			Item (std::string name, int health, int strength)
				:  name{ name }, health{ health }, strength{ strength } { type = "item"; };
			Item(std::string name, int health, int strength, int maxHealth)
				:  name{ name }, health{ health }, strength{ strength }, maxHealth{ maxHealth } { type = "item"; };

			void run(Player* player, bool& remove) override;
			int getHealth() { return health; }
			std::string getName() { return name; }
			int getStrength() { return strength; }
			int getMaxHealth() { return maxHealth; }
	};
}
