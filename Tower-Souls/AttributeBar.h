#pragma once
#include <iostream>
#include "Player.h"
#include "Tower.h"


class AttributeBar {
private:
	Player * p;
	int stage;
	std::string spacer;
public:
	AttributeBar() : p(nullptr), stage(0) {}
	AttributeBar(Player* nP, int currentStage, std::string nSpacer): p(nP), stage(currentStage), spacer(nSpacer) {}

	void draw() {
		int health = p->getHealth();
		int strength = p->getStrength();
		std::string text = "Leben: " + std::to_string(health) + "   Staerke: " +  std::to_string(strength) + "   Ebene: " + std::to_string(stage);
		std::cout << std::endl;
		std::cout << this->spacer << text << std::endl;
		std::cout << std::endl;
	}
};