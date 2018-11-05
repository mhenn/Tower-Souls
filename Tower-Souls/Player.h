#pragma once
class Player {
private:
	int maxHealth;
	int health;
	int strength;
public:
	Player() :maxHealth(3), health(3), strength(1) {}
	Player(int nH, int nS) : maxHealth(3), health(nH), strength(nS) {}

	void setMax(int nM) { this->maxHealth = nM; }
	int getMax() { return this->maxHealth; }
	void setHealth(int nH) { this->health = nH; }
	int getHealth() { return this->health; }
	void setStrength(int nS) { this->strength = nS; }
	int getStrength() { return this->strength; }

	void incHealth() {
		if (this->health + 1 <= this->maxHealth)
			this->health += 1;
	}

	bool decHealth() {
		this->health -= 1;
		return this->health == 0;
	}
};