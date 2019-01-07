#pragma once
#include "Map.h"
#include <iostream>
#include "Game.h"

		void GameView::Map::drawTopCorners(int x, int y) {
			if (y == 0) {
				if (x == 0)
					std::cout << "-";
				std::cout << "---";
				std::cout << "-";
			}
		}


		std::string GameView::Map::getRoomContent(GameLogic::Room* room, GameLogic::Point p) {
			std::string type = "";
			if (room->getEvent())
				type = room->getEvent()->getType();
			
			if (p == this->player->getRoom())
				return "P";
			else if (type == "loch")
				return "L";
			else if (type == "save")
				return "S";
			else if (type == "monster")
				return "M";
			else if(type == "treppe")
				return "A";
			return " ";
		}


		void GameView::Map::drawMidDoors(int x, int y) {
			GameLogic::Room *current = stage->getRoom(x,y);
			bool lastInRow = x == stage->getLength() - 1;
			if (x == 0)
				std::cout << "|";

			if (!current->isHidden())
				std::cout << " " + getRoomContent(stage->getRoom(x, y), GameLogic::Point(x,y)) + " ";
			else
				std::cout << "   ";

			if (lastInRow) {
				std::cout << "|";
				return;
			}

			if (!stage->getRoom(x, y)->isHidden() || !lastInRow && !stage->getRoom(x+1, y)->isHidden()) {
				if (!current->canPass(GameLogic::East))
					std::cout << "|";
				else
					std::cout << " ";
			}
			else
				std::cout << " ";
		}

		void GameView::Map::drawBottom(bool bottom, GameLogic::Room *below, GameLogic::Room *current) {
			if (bottom || !current->isHidden() && !current->canPass(GameLogic::South) || below && !below->isHidden() && !below->canPass(GameLogic::North))
				std::cout << "---";
			else
				std::cout << "   ";
		}

		void GameView::Map::drawBottomCorners(int x, int y) {
			GameLogic::Room *current = stage->getRoom(x, y);
			bool lastInCol = y == stage->getHeight() - 1;
			bool lastInRow = x == stage->getLength() - 1;
			bool belowRight = !lastInCol && !lastInRow;

			if (x == 0)
				std::cout << "|";

			if (y < stage->getHeight() - 1)
				drawBottom(lastInCol, stage->getRoom(x, y + 1), stage->getRoom(x, y));
			else
				drawBottom(lastInCol, nullptr, stage->getRoom(x, y));


			if (lastInRow) {
				std::cout << "|";
				return;
			}


			bool fogBelow = !lastInCol && !stage->getRoom(x, y+1)->isHidden();
			bool fogNext = !lastInRow && !stage->getRoom(x +1, y)->isHidden();
			bool fogBelowRight = belowRight && !stage->getRoom(x+1, y+1)->isHidden();

			if (lastInCol)
				std::cout << "-";
			else if (!current->isHidden() || fogBelow || fogNext || fogBelowRight) {
				std::cout << "+";
			}
			else
				std::cout << " ";
		}
	
		
		
		// draw the map
		void GameView::Map::draw() {
			int start = 0;
			for (int y = 0; y < stage->getHeight(); y++) {
				for (int i = start; i < 3; i++) {
					if (y == 0 || i > 0) {
						std::cout << std::endl;
						cout << setw(this->spacer);
					}
					for (int x = 0; x < stage->getLength(); x++) {
						switch (i) {
						case 0:
							drawTopCorners(x, y);
							break;
						case 1:
							drawMidDoors(x, y);
							break;
						case 2:
							drawBottomCorners(x, y);
							break;
						}
					}
					start = 1;
				}
			}
		}