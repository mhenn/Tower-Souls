#pragma once
#include <iostream>
#include "Player.h"
#include <iomanip>

namespace GameView {
	/*
		Rendert die Attributzeile ueber der Map
	*/
	class AttributeBar {
	private:
		GameLogic::Player* p;
		unsigned int spacer;
	public:
		// Erstellt eine leere Instanz der Klasse
		AttributeBar(int nSpacer) : spacer(nSpacer), p(nullptr) {}
		// Erstellt eine neue Instanz der Klasse mit Spieler und Spacer
		AttributeBar(GameLogic::Player* nP, int nSpacer):p(nP), spacer(nSpacer) {}
		// Zeichnet die Attributzeile in der Konsole
		void draw();
	};
}