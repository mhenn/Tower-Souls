#pragma once
#include "Stage.h"

class Tower {
private:
	std::string beginStory;
	std::string endStory;
	std::vector<Stage*> tower;
	int currentStage = 0;
public:
	Tower() : beginStory(""), endStory("") {}

	void setBeginStory(std::string s) { this->beginStory = s; }
	std::string getBeginStory() { return this->beginStory; }
	void setEndStory(std::string s) { this->endStory = s; }
	std::string getEndStory() { return this->endStory; }
	Stage* operator[](int i) {
		return this->tower[i];
	}
	void setStageY(Stage* st) {
		this->tower.push_back(st);
	}
	void setCurrentStage(int newStageDepth) { this->currentStage = newStageDepth; }
	int getCurrentStage() { return this->currentStage; }
	Stage* getStage(int i) {
		return tower[i];
	}
};