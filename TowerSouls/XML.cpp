#include "XML.h"


//Save

std::string boolToText(bool b) {

	if (b)
		return "true";

	return "false";
}

void Utils::XML::add(tinyxml2::XMLElement * pParent, std::string name, std::string value) {

	char *cName = &name[0u];
	char *cValue = &value[0u];

	tinyxml2::XMLElement * pElem = xmlDoc.NewElement(cName);
	if (strlen(cValue) != 0)
		pElem->SetText(cValue);

	pParent->InsertEndChild(pElem);
}

tinyxml2::XMLElement* Utils::XML::addStory(std::string begin, std::string end) {

	tinyxml2::XMLElement * pStory = xmlDoc.NewElement("story");

	add(pStory, "begin", begin);
	add(pStory, "end", end);

	return pStory;
}

tinyxml2::XMLElement* Utils::XML::addItem(GameLogic::Item* item) {

	tinyxml2::XMLElement * pItem = xmlDoc.NewElement("item");
	std::string name = "";
	std::string strength = "";
	std::string health = "";


	if (item) {
		name = item->getName();
		strength = item->getStrength();
		health = item->getHealth();
	}

	add(pItem, "name", name);
	add(pItem, "health", health);
	add(pItem, "strength", strength);

	return pItem;
}

tinyxml2::XMLElement* Utils::XML::addMonster(GameLogic::Monster* monster) {

	tinyxml2::XMLElement * pMonster = xmlDoc.NewElement("monster");
	std::string name = "";
	std::string strength = "";
	std::string dropsItem = "";
	std::string type = "";

	if (monster) {
		name = monster->getName();
		strength = std::to_string(monster->getStrength());
		dropsItem = boolToText(monster->getItem() != nullptr);
	}

	add(pMonster, "name", name);
	add(pMonster, "strength", strength);
	add(pMonster, "dropsItem", dropsItem);
	pMonster->InsertEndChild(addItem(dropsItem.size() > 0 ? monster->getItem() : nullptr));

	return pMonster;
}


tinyxml2::XMLElement* Utils::XML::addRoom(GameLogic::Room* room) {

	tinyxml2::XMLElement * pRoom = xmlDoc.NewElement("room");
	add(pRoom, "north", boolToText(room->canPass(GameLogic::North)));
	add(pRoom, "east", boolToText(room->canPass(GameLogic::East)));
	add(pRoom, "south", boolToText(room->canPass(GameLogic::South)));
	add(pRoom, "west", boolToText(room->canPass(GameLogic::West)));
	add(pRoom, "fog", boolToText(room->isHidden()));
	add(pRoom, "start", boolToText(room->getStart()));

	GameLogic::Action* action = room->getEvent();
	std::string type = "";
	if (action)
		type = action->getType();

	add(pRoom, "containsMonster", boolToText(type == "monster"));
	add(pRoom, "containsItem", boolToText(type == "item"));
	add(pRoom, "containsHole", boolToText(type == "loch"));
	add(pRoom, "containsSaveSpot", boolToText(type == "save"));
	add(pRoom, "containsStairs", boolToText(type == "treppe"));

	pRoom->InsertEndChild(addMonster(type == "monster" ? dynamic_cast<GameLogic::Monster*>(action) : nullptr));
	pRoom->InsertEndChild(addItem(type == "item" ? dynamic_cast<GameLogic::Item*>(action) : nullptr));

	return pRoom;
}


tinyxml2::XMLElement* Utils::XML::addRow(std::vector<GameLogic::Room*> row) {

	tinyxml2::XMLElement * pRow = xmlDoc.NewElement("row");

	for (int i = 0; i < row.size(); i++)
		pRow->InsertEndChild(addRoom(row[i]));
	return pRow;
}

tinyxml2::XMLElement* Utils::XML::addStage(GameLogic::Stage* stage) {

	tinyxml2::XMLElement * pStage = xmlDoc.NewElement("stage");
	tinyxml2::XMLElement * pRooms = xmlDoc.NewElement("rooms");
	tinyxml2::XMLElement * pStory = xmlDoc.NewElement("story");
	std::string story = stage->getStory();
	pStory->SetText(&story[0u]);

	pStage->InsertFirstChild(pStory);



	for (int i = 0; i < stage->getHeight(); i++)
		pRooms->InsertEndChild(addRow(stage->getRow(i)));
	pStage->InsertEndChild(pRooms);

	return pStage;
}

tinyxml2::XMLElement* Utils::XML::addStages(vector<GameLogic::Stage*> stages) {

	tinyxml2::XMLElement * pStage = xmlDoc.NewElement("stages");
	for (int i = 0; i < stages.size(); i++)
		pStage->InsertEndChild(addStage(stages[i]));

	return pStage;
}


tinyxml2::XMLElement* Utils::XML::addTower(GameLogic::Tower* tower) {

	tinyxml2::XMLElement * pTower = xmlDoc.NewElement("tower");
	pTower->InsertFirstChild(addStory(tower->getBeginStory(), tower->getEndStory()));
	pTower->InsertEndChild(addStages(tower->getStages()));
	return pTower;
}

tinyxml2::XMLElement* Utils::XML::addPoint(std::string name, std::string val1, std::string val2) {

	char* cName = &name[0u];

	tinyxml2::XMLElement * pPoint = xmlDoc.NewElement(cName);
	add(pPoint, "x", val1);
	add(pPoint, "y", val2);

	return pPoint;
}

tinyxml2::XMLElement* Utils::XML::addPlayer(GameLogic::Player* player) {

	tinyxml2::XMLElement * pPlayer = xmlDoc.NewElement("player");
	add(pPlayer, "stage", std::to_string(player->getCurrentStage()));
	GameLogic::Point room = player->getRoom();
	pPlayer->InsertEndChild(addPoint("room", std::to_string(room.getX()), std::to_string(room.getY())));
	GameLogic::Point start = player->getStart();
	pPlayer->InsertEndChild(addPoint("start", std::to_string(start.getX()), std::to_string(start.getY())));
	add(pPlayer, "health", std::to_string(player->getHealth()));
	add(pPlayer, "maxHealth", std::to_string(player->getMaxHealth()));
	add(pPlayer, "strength", std::to_string(player->getStrength()));
	add(pPlayer, "saveable", "true");

	return pPlayer;
}

void Utils::XML::save(GameLogic::Game *game) {

	tinyxml2::XMLElement * pRoot = xmlDoc.NewElement("game");
	pRoot->InsertFirstChild(addPlayer(game->getCurrentPlayer()));
	pRoot->InsertEndChild(addTower(game->getTower()));
	xmlDoc.InsertFirstChild(pRoot);

	xmlDoc.SaveFile("SaveGame.xml");

}


//Save END

bool Utils::XML::textToBool(std::string text) {
	return text == "false" ? false : true;
}

int Utils::XML::textToInt(tinyxml2::XMLElement * el) {
	int x = 0;
	el->QueryIntText(&x);
	return x;
}

GameLogic::Item* Utils::XML::getItem(tinyxml2::XMLNode *node) {
	int iHealth = textToInt(node->FirstChildElement("health"));
	int iStrength = textToInt(node->FirstChildElement("strength"));
	std::string iName = node->FirstChildElement("name")->GetText();
	return new GameLogic::Item(iName, iHealth, iStrength);
}

GameLogic::Monster* Utils::XML::getMonster(tinyxml2::XMLNode *node) {
	GameLogic::Item* item = nullptr;
	tinyxml2::XMLNode* confMonster = node->FirstChildElement("monster");
	std::string name = confMonster->FirstChildElement("name")->GetText();
	int strength = textToInt(confMonster->FirstChildElement("strength"));
	if (textToBool(confMonster->FirstChildElement("dropsItem")->GetText())) {
		item = getItem(confMonster->FirstChildElement("item"));
	}
	return new GameLogic::Monster(name, strength, item);
}

std::string Utils::XML::getText(tinyxml2::XMLElement* elem) {
	try {
		if (elem && elem->GetText())
			r = elem->GetText();
	}
	catch (...) {}
	return r;
}

GameLogic::Stage* Utils::XML::loadStage(tinyxml2::XMLNode *stage) {

	tinyxml2::XMLElement* rooms = stage->FirstChildElement("rooms");
	tinyxml2::XMLElement* pStory = stage->FirstChildElement("story");
	tinyxml2::XMLNode* xmlRow = rooms->FirstChildElement("row");
	std::vector<std::vector<GameLogic::Room*>> stageV;
	std::string stageStory = getText(pStory);

	int y = 0;
	int x = 0;
	GameLogic::Point start;
	GameLogic::Point end;
	std::vector<GameLogic::Room*> row;
	while (xmlRow) {
		x = 0;

		tinyxml2::XMLNode* room = xmlRow->FirstChildElement("room");
		while (room) {

			bool north = textToBool(getText(room->FirstChildElement("north")));
			bool south = textToBool(getText(room->FirstChildElement("south")));
			bool east = textToBool(getText(room->FirstChildElement("east")));
			bool west = textToBool(getText(room->FirstChildElement("west")));
			bool hidden = textToBool(getText(room->FirstChildElement("fog")));
			GameLogic::Room *r = new GameLogic::Room(north, east, west, south, hidden);
			if (textToBool(getText(room->FirstChildElement("start")))) {
				start = GameLogic::Point(x, y);
				r->setAction(new GameLogic::Start(stageStory));

				r->setStart(true);
			}
			if (textToBool(getText(room->FirstChildElement("containsStairs"))))
				r->setAction(new GameLogic::Stairs());
			if (textToBool(getText(room->FirstChildElement("containsHole"))))
				r->setAction(new GameLogic::Hole());
			if (textToBool(getText(room->FirstChildElement("containsItem"))))
				r->setAction(getItem(room->FirstChildElement("item")));
			if (textToBool(getText(room->FirstChildElement("containsMonster"))))
				r->setAction(getMonster(room));
			if (textToBool(getText(room->FirstChildElement("containsSaveSpot"))))
				r->setAction(new GameLogic::SavePoint());
			room = room->NextSibling();
			row.push_back(r);
			x++;
		}
		y++;
		xmlRow = xmlRow->NextSibling();
		stageV.push_back(row);
		row.clear();
	}
	GameLogic::Stage* newStage = new GameLogic::Stage(stageV, start);
	newStage->setStory(stageStory);
	return newStage;
}


GameLogic::Player* Utils::XML::loadPlayer(tinyxml2::XMLNode* pRoot) {

	tinyxml2::XMLElement* pPlayer = pRoot->FirstChildElement("player");
	GameLogic::Player* player = new GameLogic::Player();
	player->setCurrentStage(textToInt(pPlayer->FirstChildElement("stage")));
	tinyxml2::XMLElement* pRoom = pPlayer->FirstChildElement("room");
	int roomX = textToInt(pRoom->FirstChildElement("x"));
	int roomY = textToInt(pRoom->FirstChildElement("y"));
	player->setRoom(GameLogic::Point(roomX, roomY));
	tinyxml2::XMLElement* pStart = pPlayer->FirstChildElement("start");
	int startX = textToInt(pStart->FirstChildElement("x"));
	int startY = textToInt(pStart->FirstChildElement("y"));
	player->setStart(GameLogic::Point(startX, startY));
	player->setHealth(textToInt(pPlayer->FirstChildElement("health")));
	player->setStrength(textToInt(pPlayer->FirstChildElement("strength")));
	player->setMaxHealth(textToInt(pPlayer->FirstChildElement("maxHealth")));
	player->setSaveAble(textToBool(pPlayer->FirstChildElement("saveable")->GetText()));
	return player;
}

GameLogic::Game* Utils::XML::loadSaveGame() {
	tinyxml2::XMLError eResult = xmlDoc.LoadFile("SaveGame.xml");
	tinyxml2::XMLNode* pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr)
	{
		std::cout << "Your SaveGame.xml is malformed" << std::endl;
		//return ;
	}

	GameLogic::Game* game = new GameLogic::Game();
	game->setPlayer(loadPlayer(pRoot));
	game->getCurrentPlayer()->setLog(game->getLog());

	GameLogic::Tower* tower = new GameLogic::Tower();

	tinyxml2::XMLElement* pTower = pRoot->FirstChildElement("tower");

	tinyxml2::XMLElement* story = pTower->FirstChildElement("story");
	tinyxml2::XMLElement* stages = pTower->FirstChildElement("stages");
	
	tower->setBeginStory(getText(story->FirstChildElement("begin")));
	tower->setEndStory(getText(story->FirstChildElement("end")));

	vector<GameLogic::Stage*> towV;
	stages->FirstChildElement("stage");
	int stageHeight = 0;
	tinyxml2::XMLNode* stage = stages->FirstChildElement("stage");
	while (stage) {

		towV.push_back(loadStage(stage));
		stage = stage->NextSibling();
	}
	tower->setStages(towV);
	game->setTower(tower);
	game->setPerspective(GameView::Game);
	return game;
}




GameLogic::Tower* Utils::XML::load() {
	tinyxml2::XMLError eResult = xmlDoc.LoadFile("Level.xml");

	tinyxml2::XMLNode* pRoot = xmlDoc.LastChild();
	if (pRoot == nullptr)
	{
		std::cout << "Your Level.xml is malformed" << std::endl;
		//return ;
	}

	GameLogic::Tower* tower = new GameLogic::Tower();
	tinyxml2::XMLElement* story = pRoot->FirstChildElement("story");
	tinyxml2::XMLElement* stages = pRoot->FirstChildElement("stages");	

	tower->setBeginStory(getText(story->FirstChildElement("begin")));
	tower->setEndStory(getText(story->FirstChildElement("end")));


	vector<GameLogic::Stage*> towV;
	stages->FirstChildElement("stage");
	int stageHeight = 0;
	tinyxml2::XMLNode* stage = stages->FirstChildElement("stage");
	while (stage) {
		towV.push_back(loadStage(stage));
		stage = stage->NextSibling();
	}
	tower->setStages(towV);
	return tower;
}




