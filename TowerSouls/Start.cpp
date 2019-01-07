#include "Start.h"

void GameLogic::Start::run(GameLogic::Player* player, bool& remove) {

		std::string tmp = this->story;
		bool doIt = true;
		int start = 0;
		while (doIt) {
			if (tmp.size() > 100) {
				int end = tmp.find(" ", 100);
				std::string output = tmp.substr(0, end);
				tmp = tmp.substr(end);
				start = end + 1;				
				player->getLog()->addEvent(output);
			}
			else {
				player->getLog()->addEvent(tmp);
				doIt = false;
			}
		}
}