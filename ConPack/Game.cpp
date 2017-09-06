#include "Game.h"
#include "Player.h"
#include "Stage1.h"

void Game::mainActive()
{
	FILE * fp = fopen("../data/mapObj.dat", "rt");
	static char temp[80];
	int cnt = 0;
	char * obj[30];
	
	POSITION pos(2, 1);
	Player player(pos);
	Stage1 map;

	while (1)
	{
		CONSOLE.Clear();

		BackGround();
		player.printPlayer();
		player.printScore();	
		
		map.PrintMap();

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
			player.Goleft(&pos);
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
			player.GoRight(&pos);
		if (GetAsyncKeyState(VK_UP) & 0x0001)
			player.GoUp(&pos);
		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
			player.GoDown(&pos);

		CONFLIP;
	}
}

Game::Game()
{
}


Game::~Game()
{
}
