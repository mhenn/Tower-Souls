#pragma once
#include <iostream>
#include <string>
#include "ViewUtils.h"

namespace GameView {
	class Outro{
	private:
		std::string text;
	public:
		Outro(std::string Text) : text(Text) {}
		void draw();
	};
}