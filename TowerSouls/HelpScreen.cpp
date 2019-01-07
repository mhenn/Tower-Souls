#include "HelpScreen.h"

void GameView::HelpScreen::draw() {

	Utils::multEndl(1);
	Utils::printCentered("Help");
	Utils::multEndl(2);
	Utils::printCentered("'w','a','s','d' zur Navigation in die entsprechende Richtung");
	Utils::multEndl(1);
	Utils::printCentered("'h' um die Hilfe zu oeffnen und zu schliessen");
	Utils::multEndl(1);
	Utils::printCentered("'n' um ein Neues Spiel zu starten");
	Utils::multEndl(1);
	Utils::printCentered("'l' um ein zuvor gespeichertes Spiel zu laden");
}