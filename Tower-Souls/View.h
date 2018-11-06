#pragma once
#include "Map.h"
#include "AttributeBar.h"
#include "EventWindow.h"
class View {
private:	
	AttributeBar * bar;
	Map *map;	
	EventWindow *eventWin;
	std::string spacer = "                           ";
	std::string additionalSpacer = "                  ";

	void hideConsoleCursor()
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO     cursorInfo;
		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(out, &cursorInfo);
	}

public:
	View(std::vector<std::vector<Room*>> grid, Player *pL,int stage)  {
		this->map = new Map(grid);	
		this->bar = new AttributeBar(pL, stage, spacer );
		this->eventWin = new EventWindow(spacer + additionalSpacer);
	}

	void draw() {
		system("cls");
		hideConsoleCursor();
		bar->draw();		
		map->draw();
		eventWin->draw();
		std::cout << spacer  << "-n Neues Spiel   -l Spiel laden   -h Hilfe";
	}
};