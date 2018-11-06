#include "Game.h"
#include "XML.h"

int main()
{

	//Stage *stage = new Stage(grid);
	Player *p = new Player();
	//std::vector<Stage*> st = { stage };
	XML *x = new XML();
	Tower tower = x->load();
	//Tower *t = new Tower();
	Game *g = new Game(p, tower);

	g->play();
	
	return 0;
}