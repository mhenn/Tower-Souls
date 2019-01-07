#include "Intro.h"




void GameView::Intro::draw() {
	Utils::multEndl(1);	
	Utils::printSingleCentered("Intro");
	Utils::multEndl(2);	
	Utils::printCentered(this->text);
}