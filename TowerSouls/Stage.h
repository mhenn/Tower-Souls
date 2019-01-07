#pragma once
#include "Room.h"
#include "Point.h"
#include <vector>

namespace GameLogic {
	extern class Room;
	extern class Point;

	class Stage {
		private:
			std::string story;
			std::vector<std::vector<Room*>> rooms;
			unsigned int length;
			unsigned int height;
			Point startPoint;
			Point endPoint;
	public:				
		public:			
			Stage(std::vector<std::vector<Room*>> rooms, Point start, Point end) :
			rooms(rooms), startPoint(start), endPoint(end){
				length = rooms[0].size();
				height = rooms.size();
			}
			Stage(std::vector<std::vector<Room*>> rooms, Point start) :
				rooms(rooms), startPoint(start) {
				length = rooms[0].size();
				height = rooms.size();
			}
			// übermittelt die Räume und gibt die Points der Anfang und End-Punkte auf welche dann per Pointer auf die Vectoren gezeigt wird.
			Stage(std::vector<std::vector<Room*>> rooms): rooms(rooms) {
				length = rooms[0].size();
				height = rooms.size();
			}
			std::string getStory() { return story; }
			void setStory(std::string story) { this->story = story; }
			Point getStart() { return this->startPoint; }
			Room* getRoom(unsigned int x, unsigned int y) { return rooms[y][x]; }
			Room* getRoom(Point position) { return rooms[position.getY()][position.getX()]; }
			unsigned int getLength() { return length; }
			unsigned int getHeight() { return height; }
			std::vector<Room*> getRow(int i) { return rooms[i]; }
	};
}