#include "Game.h"
#include "XML.h"

int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	Player *p = new Player();
	XML *x = new XML();
	Tower tower = x->load();
	Game *g = new Game(p, tower);
	g->play();
	
	return 0;
}