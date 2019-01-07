#include "EventWindow.h"



void GameView::EventWindow::frame() {

	std::cout << std::setw(this->spacer) << "#" << std::setfill('#') << std::setw(this->size) << "#" << std::endl;
	std::cout << std::setfill(' ');
}

void GameView::EventWindow::content(std::string text) {
	int pad1 = (this->size - text.size()) / 2;
	int odd = 0;
	if (this->size + text.size() & 1)
		odd = 1;

	std::cout << std::setw(this->spacer) << "#";

	for (int i = 0; i < pad1; i++)
		std::cout << " ";
	std::cout << text;
	for (int i = 0; i < pad1 + odd; i++)
		if (i == pad1 + odd - 1)
			std::cout << "#";
		else
			std::cout << " ";

	std::cout << std::endl;
}



void GameView::EventWindow::draw() {

	std::vector<std::string> log = this->log->getEventlog();

	Utils::multEndl(4);	
	frame();
	content("");		
	
	for (int i = 0; i < 6; i++) {
		if (i < log.size())
			content(log[i]);		
		else
			content("");
	}
	
	content("");
	frame();
	Utils::multEndl(4);

}