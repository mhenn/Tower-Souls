#pragma once
#include "Item.h"

class Monster {
private:
	std::string name;
	int strength;
	bool dropsItem;
	Item *item;
public:
	Monster() : name("Monster"), strength(0), dropsItem(false), item(nullptr) {};
	Monster(std::string newName, int newStrength, bool drops, Item *droppedItem) :
		name(newName), strength(0), dropsItem(drops), item(droppedItem) {};
	void setName(std::string n) { this->name = n; }
	std::string getName() { return this->name; }
	void setStrength(int s) { this->strength = s; }
	int getStrength() { return this->strength; }
	void setDropsItem(bool d) { this->dropsItem = d; }
	bool getDropsItem() { return this->dropsItem; }
	void setItem(Item *i) { this->item = i; }
	Item* getItem() { return this->item; }
};