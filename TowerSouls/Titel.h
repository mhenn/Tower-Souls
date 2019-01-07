#pragma once
#include "ViewUtils.h"

namespace GameView {
	class Titel {
	private:
		unsigned int spacer;
	public:
		Titel(int nSpacer) : spacer(nSpacer) {}		
		void draw();
	};
}