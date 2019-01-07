#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ViewUtils.h"
namespace GameView {
	/*
		Rendert den Deathscreen in der Konsole
	*/


	class DeathScreen {
	private:
		std::vector<std::string> text{ "Du bist gestorben!" };
		/*{
		"__     __               _ _          _ _",
		"\ \   / /              | (_)        | | |",
		" \ \_/ /__  _   _    __| |_  ___  __| | |",
		"  \   / _ \| | | |  / _` | |/ _ \/ _` | |", 
		"   | | (_) | |_| | | (_| | |  __/ (_| |_|",
		"   |_|\___/ \__,_|  \__,_|_|\___|\__,_(_)" };
		*/

	public:
		// Erzeugt eine leere Instanz der Klasse
		DeathScreen() {}
		// Zeichnet das Fenster in der Konsole
		void draw();
	};
}