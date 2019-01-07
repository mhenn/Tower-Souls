#include "Outro.h"

void GameView::Outro::draw() {
	Utils::multEndl(1);
	Utils::printSingleCentered("Ende");
	Utils::multEndl(2);
	Utils::printCentered(this->text);
}