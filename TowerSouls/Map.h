#pragma once
#include <vector>
#include <windows.h>
#include "Room.h"
#include "Player.h"
#include "Point.h"
#include "Stage.h"

namespace GameView {

	extern class Point;
	/*
		Rendert die Map (Darstellung der aktuellen Ebene)
	*/
	class Map {
	private:
		GameLogic::Stage* stage;
		GameLogic::Player* player;
		unsigned int spacer;

		// draw the room elemente in dependence to the surrounding ones
		void drawTopCorners(int x, int y);
		void drawMidDoors(int x, int y);
		void drawBottomCorners(int x, int y);	
		void drawBottom(bool bottom, GameLogic::Room *below, GameLogic::Room *current);
		std::string getRoomContent(GameLogic::Room* room, GameLogic::Point p);
	public:
		//Contructor shoudl contain the current stage as vector grid
		Map(GameLogic::Stage* newStage, GameLogic::Player* p ,int nSpacer) : spacer(nSpacer),stage(newStage), player(p) {}
		void setStage(GameLogic::Stage* stage) { this->stage = stage; }
		// draw the map
		void draw();
	};
}