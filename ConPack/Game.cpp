#include "Game.h"
#include "Player.h"

void Game::mainActive()
{
	POSITION pos(10, 10);
	Player player(pos);

	// �㱸���� �޸������� �ؼ� ��������(strncpy??)
	// ���Ʒ��� �翷 �ӵ�����??
	while (1)
	{
		CONSOLE.Clear();

		BackGround();
		player.printPlayer();
		player.printScore();

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
