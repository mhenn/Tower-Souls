#pragma once
#include <string>
class Item {
private:
	std::string name;
	int health;
	int strength;
public:
	Item() : name("item"), health(0), strength(0) {}
	Item(std::string newName, int newHealth, int newStrength) : name(newName), health(0), strength(0) {}
	void setName(std::string n) { this->name = n; }
	std::string getName() { return this->name; }
	void setHealth(int h) { this->health = h; }
	int getHealth() { return this->health; }
	void setStrength(int s) { this->strength = s; }
	int getStrength() { return this->strength; }
};