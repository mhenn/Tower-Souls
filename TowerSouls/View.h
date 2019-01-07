#pragma once
#include "Map.h"
#include "AttributeBar.h"
#include "EventWindow.h"
#include "Room.h"
#include "Death.h"
#include "Player.h"
#include "Titel.h"
#include "HelpScreen.h"
#include "StageSwitchScreen.h"
#include "Intro.h"
#include "Outro.h"
#include "ViewUtils.h"

namespace GameView {

	enum draw {Title, Game, Begin, End, Death, Help, StageSwitch};

	class View {
	private:
		AttributeBar * bar;
		Map *map;
		EventWindow *eventWin;
		Titel* title;
		Intro* intro;
		Outro* outro;
		std::string spacer;
		std::string additionalSpacer;
		GameLogic::Stage* grid;
		GameLogic::Player* player;
		// hide the cursor 
		void hideConsoleCursor();

	public:
		View() {
			this->title = new Titel(42);

		}
		//View should contain the current stage as vector grid
		View(GameLogic::Stage* stage, GameLogic::Player *pL, GameLogic::EventLog* log, std::string begin) :			
			grid(stage), player(pL) {
			double maxScreen = 242;
			double screenWidth = Utils::getScreenWidth();
			double additional = screenWidth > 200 ? 1 : 2;
			double fak = screenWidth  / maxScreen /additional;
			this->title = new Titel(fak * 42);
			this->map = new Map(stage, pL, fak * 42);
			this->bar = new AttributeBar(pL, fak * 42);
			this->eventWin = new EventWindow(fak * 37, log);
			this->intro = new Intro(begin);
		}
		View(std::string endStory) :outro(new Outro(endStory)){}
		

		void setStage(GameLogic::Stage* stage) { 
			this->grid = stage;
			map->setStage(stage);
		}
		void setPlayer(GameLogic::Player* player) { this->player = player;}

		EventWindow* getEventWin() { return this->eventWin; }
		void draw(draw d);
	};
}