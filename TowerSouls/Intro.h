#pragma once
#include <iostream>
#include "ViewUtils.h"
#include <string>
namespace GameView {
	class Intro {
	private:
		std::string text;		
	public:
		Intro(std::string Text): text(Text) {}						
		void draw();
	};
}