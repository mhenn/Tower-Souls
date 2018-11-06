#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "tinyxml2.h"
#include "Tower.h"


class XML {
private:
	bool textToBool(std::string text) {
		return text == "false" ? false : true;
	}

	int textToInt(tinyxml2::XMLElement * el) {
		int x = 0;
		el->QueryIntText(&x);
		return x;
	}

	Item* getItem(tinyxml2::XMLNode *node) {
		Item *i = new Item();
		i->setHealth(textToInt(node->FirstChildElement("health")));
		i->setStrength(textToInt(node->FirstChildElement("strength")));
		i->setName(node->FirstChildElement("name")->GetText());
		return i;
	}


	Stage* loadStage(tinyxml2::XMLNode *stage) {

		tinyxml2::XMLElement* rooms = stage->FirstChildElement("rooms");
		Stage *st = new Stage();

		tinyxml2::XMLNode* xmlRow = rooms->FirstChildElement("row");

		
		while (xmlRow) {
			std::vector<Room*> row;
			tinyxml2::XMLNode* room = xmlRow->FirstChildElement("room");
			while(room) {
				Room *r = new Room();
				r->setNorth(room->FirstChildElement("north")->GetText());
				r->setSouth(textToBool(room->FirstChildElement("south")->GetText()));
				r->setEast(textToBool(room->FirstChildElement("east")->GetText()));
				r->setWest(textToBool(room->FirstChildElement("west")->GetText()));
				r->setFog(textToBool(room->FirstChildElement("fog")->GetText()));
				r->setStart(textToBool(room->FirstChildElement("start")->GetText()));
				r->setContainsHole(textToBool(room->FirstChildElement("containsHole")->GetText()));
				r->setContainsItem(textToBool(room->FirstChildElement("containsItem")->GetText()));
				r->setContainsMonster(textToBool(room->FirstChildElement("containsMonster")->GetText()));
				r->setContainsPlayer(textToBool(room->FirstChildElement("containsPlayer")->GetText()));
				r->setContainsSaveSpot(textToBool(room->FirstChildElement("containsSaveSpot")->GetText()));
				r->setContainsStairs(textToBool(room->FirstChildElement("containsStairs")->GetText()));
				if (r->getContainsMonster()) {
					Monster *monster = new Monster();
					tinyxml2::XMLNode* confMonster = room->FirstChildElement("monster");
					monster->setName(confMonster->FirstChildElement("name")->GetText());
					monster->setStrength(textToInt(confMonster->FirstChildElement("strength")));
					monster->setDropsItem(textToBool(confMonster->FirstChildElement("dropsItem")->GetText()));
					if (monster->getDropsItem()) {
						monster->setItem(getItem(confMonster->FirstChildElement("item")));
					}
					r->setMonster(monster);

				}
				if (r->containsItem)
					r->setItem(getItem(room->FirstChildElement("item")));

				room = room->NextSibling();
				row.push_back(r);

			}
			xmlRow = xmlRow->NextSibling();
			st->pushRow(row);
		}
		return st;
	}

public:
	XML() {}

	Tower load()
	{
		tinyxml2::XMLDocument xmlDoc;
		tinyxml2::XMLError eResult = xmlDoc.LoadFile("Level1.xml");


		tinyxml2::XMLNode* pRoot = xmlDoc.FirstChild();
		if (pRoot == nullptr)
		{
			std::cout << "Fehler1" << std::endl;
			//return ;
		}

		Tower tower;
		tinyxml2::XMLElement* story = pRoot->FirstChildElement("story");
		tinyxml2::XMLElement* stages = pRoot->FirstChildElement("stages");
		tower.setBeginStory(story->FirstChildElement("begin")->GetText());
		tower.setEndStory(story->FirstChildElement("end")->GetText());


		if (stages == nullptr)
		{
			std::cout << "Fehler3" << std::endl;
			//return ;
		}

		stages->FirstChildElement("stage");
		int stageHeight = 0;
		tinyxml2::XMLNode* stage = stages->FirstChildElement("stage");
		while (stage) {

			tower.setStageY(loadStage(stage));
			stage = stage->NextSibling();
		}
		return tower;
	}
};