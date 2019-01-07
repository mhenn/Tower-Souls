#pragma once
#include "EventLog.h"
#include "View.h"
#include "Player.h"
#include "Tower.h"


namespace GameLogic {

	// Verfuegbare Eingaben
	enum playerInput { Left, Right, Up, Down, New, Load, Save, Help, Skip, Idle };
	/*
		Stellt das gesamte Spiel dar (ohne Tastatureingaben und Speichern-/ Ladenfunktion
	*/
	class Game {
	private:
		//EventLog * eventlog;
		GameView::View* view;
		std::string beginStory;
		std::string endStory;
		Tower* tower;
		Player* player;
		bool handleMove(direction d);
		GameView::draw perspecitve;
		EventLog* log;
		bool active = false;
		void handleStageSwitch(int stage);

	public:
		// Erzeugt ein neues Spiel mit neuem Spieler und neuem Tower
		//Game() :  log(new EventLog()), player(new Player()) {};
		Game() : log(new EventLog()){}
		// Wertet die Tastatureingabe des Benutzers aus und fuehrt die entsprechende Aktion durch.
		void run(playerInput input);
		GameView::View* getView() { return view; }
		void setTower(Tower* tower);
		void setPlayer(Player* player) { this->player = player; }
		void showTitle();
		void initNewGame();
		void initGameView(GameView::draw p);
		void setPerspective(GameView::draw p) { this->perspecitve = p; }
		bool isActive() { return active; }
		std::string GetEndStory() { return this->endStory; }
		Tower* getTower() { return tower; }
		Player* getCurrentPlayer() { return player; }
		EventLog* getLog() { return log; }
		
	};

}