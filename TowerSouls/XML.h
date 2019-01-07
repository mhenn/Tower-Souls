#pragma once
#include <fstream>
#include "tinyxml2.h"
#include "Item.h"
#include "Hole.h"
#include "Monster.h"
#include "SavePoint.h"
#include "Stairs.h"
#include "Game.h"
#include "Start.h"

namespace Utils {
	class XML {
	private:
		tinyxml2::XMLDocument xmlDoc;
		bool textToBool(std::string text);
		 int textToInt(tinyxml2::XMLElement * el);
		GameLogic::Item* getItem(tinyxml2::XMLNode *node);
		GameLogic::Monster* getMonster(tinyxml2::XMLNode *node);
		GameLogic::Stage* loadStage(tinyxml2::XMLNode *stage);
		void add(tinyxml2::XMLElement * pParent, std::string name, std::string value = "");
		tinyxml2::XMLElement* addStory(std::string begin, std::string end);
		tinyxml2::XMLElement* addItem(GameLogic::Item* item);
		tinyxml2::XMLElement* addMonster(GameLogic::Monster* monster);
		tinyxml2::XMLElement* addRoom(GameLogic::Room* room);
		tinyxml2::XMLElement* addRow(std::vector<GameLogic::Room*> row);
		tinyxml2::XMLElement* addStage(GameLogic::Stage* stage);
		tinyxml2::XMLElement* addStages(vector<GameLogic::Stage*> stages);
		tinyxml2::XMLElement* addTower(GameLogic::Tower* tower);
		tinyxml2::XMLElement* addPoint(std::string name, std::string val1, std::string val2);
		tinyxml2::XMLElement* addPlayer(GameLogic::Player* player);
		GameLogic::Player* loadPlayer(tinyxml2::XMLNode* pRoot);
		std::string r, getText(tinyxml2::XMLElement* elem);
	public:
		XML() {}
		GameLogic::Tower* load();
		GameLogic::Game* loadSaveGame();
		 void save(GameLogic::Game *game);
	};
};