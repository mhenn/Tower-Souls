#pragma once
#include "Game.h"
#include <conio.h>
#include <windows.h>
#include "XML.h"
#include "windows.h"

namespace GameLogic {
	/*
		Enthaelt die elementaren Funktionen des Spiels.
		Die Methode runGame() muss in der main Funktion aufgerufen werden.
	*/
	class Main {
	private:
		// Das Game Objekt, das das aktuelle Spiel enthaelt
		Game* game;		
		// Speichert den aktuellen Spielstand
		bool save();
		playerInput input();		
	public:
		// Erstellt eine neue Instanz der Klasse und erstellt ein neues Game Objekt
		Main(): game(new Game()) { 
			system("mode con COLS=700");
			ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
		}
		// Fuehrt das Spiel aus
		void runGame();
	};
}


