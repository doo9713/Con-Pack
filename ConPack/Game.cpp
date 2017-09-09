#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Stage1.h"

void Game::mainActive()
{
	FILE * fp = fopen("../data/mapObj.dat", "rt");
	static char temp[80];
	int cnt = 0;
	char * obj[30];
	
	POSITION posPlayer(2, 1), posEnemy(76,1);
	Player player(posPlayer);
	Enemy enemy(posEnemy);
	Stage1 map;

	while (1)
	{
		CONSOLE.Clear();

		//BackGround();
		map.PrintMap();
		player.printPlayer();	
		enemy.printEnemy();
		player.printScore();

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
			player.Goleft(&posPlayer, map.GetTriggerPos());
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
			player.GoRight(&posPlayer, map.GetTriggerPos());
		if (GetAsyncKeyState(VK_UP) & 0x0001)
			player.GoUp(&posPlayer, map.GetTriggerPos());
		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
			player.GoDown(&posPlayer, map.GetTriggerPos());

		player.eatCandy(map.GetCandyPos());
		enemy.EnemyMove(map.GetTriggerPos());

		CONFLIP;
	}
}

Game::Game()
{
}


Game::~Game()
{
}
