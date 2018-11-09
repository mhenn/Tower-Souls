#pragma once
#include <iostream>
#include "Monster.h"

class Room {


public:
	bool north, east, south, west, fog, start;
	bool containsPlayer, containsMonster, containsItem, containsHole, containsSaveSpot, containsStairs;
	Monster *monster;
	Item *item;
	std::string roomContent = " ";
	Room() :
		north(false), east(false), south(false), west(false), fog(true), start(false),
		containsPlayer(false), containsMonster(false), containsItem(false), containsHole(false),
		containsSaveSpot(false), containsStairs(false), monster(nullptr), item(nullptr) {}
	Room(bool n, bool e, bool s, bool w, bool f, bool sT, bool cP, bool cM, bool cI, bool cH, bool cSP, bool cS, Monster *m, Item *i) :
		north(n), east(e), south(s), west(w), fog(f), start(sT),
		containsPlayer(cP), containsMonster(cM), containsItem(cI), containsHole(cH),
		containsSaveSpot(cSP), containsStairs(cS), monster(m), item(i) {}

	void setNorth(bool n) { this->north = n; }
	bool getNorth() { return this->north; }
	void setSouth(bool s) { this->south = s; }
	bool getSouth() { return this->south; }
	void setWest(bool w) { this->west = w; }
	bool getWest() { return this->west; }
	void setEast(bool e) { this->east = e; }
	bool getEast() { return this->east; }
	void setFog(bool f) { this->fog = f; }
	bool getFog() { return this->fog; }
	void setStart(bool s) { this->start = s; }
	bool getStart() { return this->start; }
	void setContainsPlayer(bool p) { 
		this->containsPlayer = p; 
		if(p)
			setRoomContent("P"); 
	}
	bool getContainsPlayer() { return this->containsPlayer; }
	void setContainsMonster(bool m) { this->containsMonster = m; }
	bool getContainsMonster() { return this->containsMonster; }
	void setContainsItem(bool i) { this->containsItem = i; }
	bool getContainsItem() { return this->containsItem; }
	void setContainsHole(bool h) { this->containsHole = h; }
	bool getContainsHole() { return this->containsHole; }
	void setContainsSaveSpot(bool s) { this->containsSaveSpot = s; }
	bool getContainsSaveSpot() { return this->containsSaveSpot; }
	void setContainsStairs(bool s) { this->containsStairs = s; }
	bool getContainsStairs() { return this->containsStairs; }
	void setMonster(Monster *m) { this->monster = m; }
	Monster* getMonster() { return this->monster; }
	void setItem(Item *i) { this->item = i; }
	Item *getItem() { return this->item; }
	void setRoomContent(std::string content) { this->roomContent = content; }
	std::string getRoomContent() { return this->roomContent; }

	void operator =(Room* r) {
		north = r->getNorth();
		east = r->getEast();
		south = r->getSouth();
		west = r->getWest();
		fog = r->getFog();
		start = r->getStart();
		containsPlayer = r->getContainsPlayer();
		containsMonster = r->getContainsMonster();
		containsItem = r->getContainsItem();
		containsHole = r->getContainsHole();
		containsSaveSpot = r->getContainsSaveSpot();
		containsStairs = r->getContainsStairs();
		Monster *monster = r->getMonster();
		Item *item = r->getItem();
	}

	void setPlayerPosition() {
		this->containsPlayer = true;
		this->fog = false;
		this->roomContent = "P";
	}

	void triggerEvent() {

	}

	void removePlayer() {
		this->containsPlayer = true;
		this->roomContent = " ";
	}

	void drawTop() {
		std::cout << "---";
	}

	void drawMid() {
		if (!this->fog)
			std::cout << " " + this->roomContent + " ";
		else
			std::cout << "   ";
	}

	void drawBottom(bool bottom, Room *below) {
		if (bottom || !this->fog && !this->south || below && !below->fog && !below->getNorth())
			std::cout << "---";
		else 
			std::cout << "   ";		
	}

};