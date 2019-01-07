#pragma once

namespace GameLogic {
	class Point {
		private:
			unsigned int x;
			unsigned int y;
		public:
			Point() {}
			Point(unsigned int x, unsigned int y): x(x), y(y) {}
			unsigned int getX() { return this->x; } //getter
			unsigned int getY() { return this->y; } //getter
			bool operator ==(Point p) {
				return x == p.getX() && y == p.getY();
			}
	};
}