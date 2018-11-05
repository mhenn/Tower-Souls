#include <iostream>
#include <string>
#include <fstream>
#include "tinyxml2.h"
#include "Tower.h"

using namespace tinyxml2;


#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

int safeData()
{
	XMLDocument xmlDoc;

	XMLNode* pRoot = xmlDoc.NewElement("Root");
	xmlDoc.InsertFirstChild(pRoot);

	XMLElement* pElement = xmlDoc.NewElement("IntValue");
	pElement->SetText(10);
	pRoot->InsertEndChild(pElement);

	pElement = xmlDoc.NewElement("FloatValue");
	pElement->SetText(0.5f);
	pRoot->InsertEndChild(pElement);

	pElement = xmlDoc.NewElement("Date");
	pElement->SetAttribute("day", 26);
	pElement->SetAttribute("month", "April");
	pElement->SetAttribute("year", 2014);
	pElement->SetAttribute("dateFormat", "26/04/2014");
	pRoot->InsertEndChild(pElement);

	XMLError eResult = xmlDoc.SaveFile("SavedDate.xml");
	XMLCheckResult(eResult);
}

bool textToBool(std::string text) {
	return text == "false" ? false : true;
}

int textToInt(XMLElement * el) {
	int x = 0;
	el->QueryIntText(&x);
	return x;
}

Item* getItem(XMLNode *node) {
	Item *i = new Item();
	i->setHealth(textToInt(node->FirstChildElement("health")));
	i->setStrength(textToInt(node->FirstChildElement("strength")));
	i->setName(node->FirstChildElement("name")->GetText());
	return i;
}

Monster* getMonster(XMLNode *node) {
	return nullptr;
}

Stage* loadStage(XMLNode *stage) {

	XMLElement* rooms = stage->FirstChildElement("rooms");
	Stage *st = new Stage();

	XMLNode* room = rooms->FirstChildElement("room");


	for (int y = 0; y < 15; y++) {
		std::vector<Room*> row;
		for (int x = 0; x < 35; x++) {
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
				XMLNode* confMonster = room->FirstChildElement("monster");
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
		st->pushRow(row);
	}
	return st;
}


Tower load()
{
	XMLDocument xmlDoc;
	XMLError eResult = xmlDoc.LoadFile("Level1.xml");


	XMLNode* pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr)
	{
		std::cout << "Fehler1" << std::endl;
		//return ;
	}

	Tower tower;
	XMLElement* story = pRoot->FirstChildElement("story");
	XMLElement* stages = pRoot->FirstChildElement("stages");
	tower.setBeginStory(story->FirstChildElement("begin")->GetText());
	tower.setEndStory(story->FirstChildElement("end")->GetText());


	if (stages == nullptr)
	{
		std::cout << "Fehler3" << std::endl;
		//return ;
	}

	stages->FirstChildElement("stage");
	int stageHeight = 0;
	XMLNode* stage = stages->FirstChildElement("stage");
	while (stage) {

		tower.setStageY(loadStage(stage));
		stage = stage->NextSibling();
	}
	return tower;
}


int main()
{
	//writeShit();
	//readShit();
	//Tower t =
	Tower t = load();
	std::cout << "";
	//std::cout << "Räume geladen" << endl;

	system("PAUSE");

}