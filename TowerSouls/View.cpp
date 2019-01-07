#pragma once
#include "View.h"


void GameView::View::hideConsoleCursor() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
	

void GameView::View::draw(GameView::draw d) {
	system("cls");
	hideConsoleCursor();

	switch (d) {
	case GameView::draw::Title:		
		this->title->draw();
		break;
	case GameView::draw::Begin:
		this->intro->draw();
		break;
	case GameView::draw::Help:
		HelpScreen().draw();
		break;
	case GameView::draw::StageSwitch:
		StageSwitchScreen().draw();
		break;
	case GameView::draw::Game:
		bar->draw();
		map->draw();
		eventWin->draw();
		for (int i = 0; i < 42; i++)
			std::cout << " ";
		std::cout << spacer << "-n Neues Spiel   -l Spiel laden   -h Hilfe";
		break;
	case GameView::draw::End:
		this->outro->draw();
		break;
	case GameView::draw::Death:
		DeathScreen().draw();
		break;
	}


	
}
