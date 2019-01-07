#pragma once
#include <vector>
#include "Stage.h"
#include "Player.h"
using namespace std;

namespace GameLogic {

	class Tower {
	private:
		vector<Stage*> stages;
		std::string beginStory;
		std::string endStory;
	public:
		Tower() {}
		void setStages(vector<Stage*> stages) { this->stages = stages; }
		vector<Stage*> getStages() { return stages; }
		Stage* getStage(int i) { return stages[i]; }
		void setBeginStory(std::string begin) { this->beginStory = begin; }
		std::string getBeginStory() { return beginStory; }
		void setEndStory(std::string end) { this->endStory = end; }
		std::string getEndStory() { return endStory; }
	};
}