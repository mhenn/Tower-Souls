#include "AttributeBar.h"

	// Zeichnet die Attributzeile in der Konsole
void GameView::AttributeBar::draw() {
	int health = p->getHealth();
	int strength = p->getStrength();
	int stage = p->getCurrentStage();	
	std::string text = "Leben: " + std::to_string(health) + "   Staerke: " + std::to_string(strength) + "   Ebene: " + std::to_string(++stage);
	std::cout << std::endl;
	for(int i = 0; i < this->spacer; i++)
	std::cout << " ";
	std::cout << text << std::endl;
	std::cout << std::endl;
}