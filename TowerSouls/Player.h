#pragma once
#include "Point.h"
#include "Stage.h"

namespace GameLogic {

	extern enum direction;

	class Player {
		private:
			unsigned int currentStage;
			Point room; //position in Stage
			Point start;
			unsigned int health;
			unsigned int maxhealth;
			unsigned int strength;
			bool gameOver = false;
			bool wonTheGame = false;
			bool saveAble = false;
			EventLog* log;
		public:
			// Benutzt den übergebenen Punkt als Position
			Player(Point roomPosition, EventLog* Log) : health(3), maxhealth(3), strength(1)
				, currentStage(0), room(roomPosition) , log(Log){}
			// Erstellt ein Point und benutzt diesen als aktuelle Position
			Player(unsigned int x, unsigned int y): health(3), maxhealth(3), strength(1)
				, currentStage(0), room(Point(x,y)) {}
			Player(EventLog* Log) : health(3), maxhealth(3), strength(1), currentStage(0), log(Log) {}			
			Player() : health(3), maxhealth(3), strength(1), currentStage(0) {}
			void setGameOver(bool GameOver) { gameOver = GameOver; }
			bool getGameOver() { return this->gameOver; }
			void setSaveAble(bool SaveAble) { saveAble = SaveAble; }
			bool getSaveAble() { return this->saveAble; }
			void setRoom(Point newRoom) { this->room = newRoom; }
			void setStart(Point Start) { this->start = Start; }
			Point getStart() { return this->start; }
			EventLog* getLog() { return this->log; }
			void setLog(EventLog* log) { this->log = log; }
			void incStage();
			void decStage();
			int getMaxHealth() { return maxhealth; }
			//return position in stage
			Point getRoom() { return this->room; }
			//return current Stage
			int getCurrentStage() { return this->currentStage; }
			// Erhöht die Gesundheit
			void incHealth(int amount = 1);
			// Verringert die Gesundheit
			void decHealth(int amount = 1);			
			// Erhöht die Maximale Gesundheit
			void incMaxHealth(int amount = 1) { maxhealth += amount; }
			// erhöht die Stärke
			void incStrength(int amount = 1) { strength += amount; }
			// checkt den Raum ob es möglich ist dort durch zu gehen wenn ja geht der Player
			bool move(direction d, Stage* currentStage);
			// wechselt in die nächste (eingang) /vorherige(Loch: direkt darunter) Etage
			void useStairs(int i = 1) { currentStage += i; }
			unsigned int getHealth() { return this->health; }
			unsigned int getStrength() { return this->strength; }	
			void setCurrentStage(int stage) { this->currentStage = stage; }
			void setHealth(int h) { this->health = h; }
			void setStrength(int s) { this->strength = s; }
			void setMaxHealth(int mh) { this->maxhealth = mh; }
			void setWon(bool won) { this->wonTheGame = won; }
			bool getWon() { return this->wonTheGame; }
	};
}
