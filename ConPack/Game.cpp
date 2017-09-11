#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"


void Game::PrintClear()
{
	char * title[14] =
	{
		"..######......###....##.....##.########.",
		".##....##....##.##...###...###.##.......",
		".##.........##...##..####.####.##.......",
		".##...####.##.....##.##.###.##.######...",
		".##....##..#########.##.....##.##.......",
		".##....##..##.....##.##.....##.##.......",
		"..######...##.....##.##.....##.########.",
		"..######..##.......########....###....########..",
		".##....##.##.......##.........##.##...##.....##.",
		".##.......##.......##........##...##..##.....##.",
		".##.......##.......######...##.....##.########..",
		".##.......##.......##.......#########.##...##...",
		".##....##.##.......##.......##.....##.##....##..",
		"..######..########.########.##.....##.##.....##.",
	};

	for (int i = 0; i < 14; ++i)
	{
		char temp[50];
		strcpy(temp, title[i]);
		if (i < 7)
			CONPOS(18, 5 + i);
		else
			CONPOS(15, 5 + i);
		for (int j = 0; j < 49; ++j) {
			if (temp[j] == '.')
				CONSOLE.SetTextColor(LIGHTSKYBLUE);
			else
				CONSOLE.SetTextColor(YELLOW);
			CONSOLE << temp[j];
		}
	}
	CONSOLE.SetTextColor(LIGHTGREEN);
	CONPOS(30, 22) << "PRESS ENTER KEY";
	CONSOLE.SetTextColor(WHITE);
}

void Game::PrintGameOver()
{
	char * title[14] =
	{
		"..######......###....##.....##.########.",
		".##....##....##.##...###...###.##.......",
		".##.........##...##..####.####.##.......",
		".##...####.##.....##.##.###.##.######...",
		".##....##..#########.##.....##.##.......",
		".##....##..##.....##.##.....##.##.......",
		"..######...##.....##.##.....##.########.",
		"..#######..##.....##.########.########..",
		".##.....##.##.....##.##.......##.....##.",
		".##.....##.##.....##.##.......##.....##.",
		".##.....##.##.....##.######...########..",
		".##.....##..##...##..##.......##...##...",
		".##.....##...##.##...##.......##....##..",
		"..#######.....###....########.##.....##."
	};

	for (int i = 0; i < 14; ++i)
	{
		char temp[50];
		strcpy(temp, title[i]);
		CONPOS(18, 5 + i);
		for (int j = 0; j < 49; ++j) {
			if (temp[j] == '.')
				CONSOLE.SetTextColor(LIGHTSKYBLUE);
			else
				CONSOLE.SetTextColor(YELLOW);
			CONSOLE << temp[j];
		}
	}
	CONSOLE.SetTextColor(LIGHTGREEN);
	CONPOS(30, 22) << "PRESS ENTER KEY";
	CONSOLE.SetTextColor(WHITE);
}

void Game::DefaultStage(int pos, int select)
{
	CONPOS(pos, 5) <<  "忙式式式式式忖";
	CONPOS(pos, 6) <<  "弛﹥﹛﹛﹛﹥弛";
	CONPOS(pos, 7) <<  "弛﹛﹥﹛﹥﹛弛";
	CONPOS(pos, 8) <<  "弛﹛﹛﹥﹛﹛弛";
	CONPOS(pos, 9) <<  "弛﹛﹥﹛﹥﹛弛";
	CONPOS(pos, 10) << "弛﹥﹛﹛﹛﹥弛";
	CONPOS(pos, 11) << "戌式式式式式戎";
	CONPOS(pos, 12) << "    STAGE " << select;
	CONPOS(pos, 13) << "  SCORE : 0";
}

void Game::ClearStage(int pos, int select)
{
	CONPOS(pos, 5) <<  "忙式式式式式忖";
	CONPOS(pos, 6) <<  "弛﹛﹛﹛﹛﹛弛";
	CONPOS(pos, 7) <<  "弛﹛﹛﹛﹛﹛弛";
	CONPOS(pos, 8) <<  "弛﹛﹛﹛﹛﹛弛";
	CONPOS(pos, 9) <<  "弛﹛﹛﹛﹛﹛弛";
	CONPOS(pos, 10) << "弛﹛﹛﹛﹛﹛弛";
	CONPOS(pos, 11) << "戌式式式式式戎";
	CONPOS(pos, 12) << "    STAGE " << select;
	CONPOS(pos, 13) << "  SCORE : " << scores[select - 1];
}

void Game::StageSelectMenu(int select)
{
	int pos[4] = { 0, 7, 32, 57 };
	for (int i = 1; i < 4; ++i)
	{
		if (i == select + 1)
			CONSOLE.SetTextColor(LIGHTGREEN);
		if (i <= stage)
			ClearStage(pos[i], i);
		else
			DefaultStage(pos[i], i);
		CONSOLE.SetTextColor(WHITE);
	}
}

void Game::PrintSlot(int pos, int select)
{
	CONPOS(pos, 5)  << "忙式式式式式忖";
	CONPOS(pos, 6)  << "弛﹛﹛﹛﹛﹛弛";
	CONPOS(pos, 7)  << "弛﹛﹛﹛﹛﹛弛";
	CONPOS(pos, 8)  << "弛﹛﹛﹛﹛﹛弛";
	CONPOS(pos, 9)  << "弛﹛﹛﹛﹛﹛弛";
	CONPOS(pos, 10) << "弛﹛﹛﹛﹛﹛弛";
	CONPOS(pos, 11) << "戌式式式式式戎";
	CONPOS(pos, 12) << "     SLOT " << select;

	char path[64];
	wsprintfA(path, "Slot%d.sav", select);
	if (!CheckSlot(path, select))
		CONPOS(pos+3, 13) << "EMPTY SLOT";
	else
		CONPOS(pos, 13) << "CURRENT STAGE : " << slotInfo[select - 1];
}

void Game::PrintAllSlot(int select)
{
	int pos[4] = { 0, 7, 32, 57 };
	for (int i = 1; i < 4; ++i)
	{
		if (i == select + 1)
			CONSOLE.SetTextColor(LIGHTGREEN);
		PrintSlot(pos[i], i);
		CONSOLE.SetTextColor(WHITE);
	}
}

void Game::MainActive(bool NewOrLoad)
{
	INT Select = 0;

	while (1)
	{
		CONSOLE.Clear();

		BackGround();
		PrintAllSlot(Select);

		if (Select == 3)
			CONSOLE.SetTextColor(LIGHTGREEN);
		CONPOS(32, 25) << "BACK TO MENU";
		CONSOLE.SetTextColor(WHITE);

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			Select += 1;
			if (Select >= 4)
				Select = 0;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			Select -= 1;
			if (Select < 0)
				Select = 3;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			if (Select == 3)
				return;
			char path[64];
			slot = Select + 1;
			wsprintfA(path, "Slot%d.sav", slot);
			if(NewOrLoad == LOADGAME && !CheckSlot(path, slot))
				continue;
			if (NewOrLoad == NEWGAME)
				Save(path, 1, 1, 0, 0, 0);
			if (NewOrLoad == LOADGAME)
				Load(path);
			StageActive();
			return;
		}

		CONFLIP;
	}
}

void Game::StageActive()
{
	INT Select = 0;

	while (1)
	{
		CONSOLE.Clear();

		BackGround();
		StageSelectMenu(Select);

		if (Select == 3)
			CONSOLE.SetTextColor(LIGHTGREEN);
		CONPOS(32, 25) << "BACK TO MENU";
		CONSOLE.SetTextColor(WHITE);

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			Select += 1;
			if (Select >= 4)
				Select = 0;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			Select -= 1;
			if (Select < 0)
				Select = 3;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			if (Select == 3)
				return;
			if (Select + 1 <= stage)
				GameActive(Select);
		}

		CONFLIP;
	}
}

void Game::GameActive(int select)
{
	bool isClear, isOver;

	POSITION posPlayer(2, 1);
	Player player(posPlayer);

	POSITION posEnemy1(76, 1);
	POSITION posEnemy2(76, 28);
	POSITION posEnemy3(2, 28);
	Enemy enemy1(posEnemy1);
	Enemy enemy2(posEnemy2);
	Enemy enemy3(posEnemy3);

	Map map;

	switch (select)
	{
	case 0 :
		enemy2.EnemyDisable();
	case 1:
		enemy3.EnemyDisable();
	}

	int flipConunt = 0;
	isClear = false;
	isOver = false;
	while (1)
	{
		CONSOLE.Clear();

		if (!isClear && !isOver)
		{
			map.PrintMap();
			player.PrintPlayer();

			switch (select)
			{
			case 2 :
				enemy3.PrintEnemy();
			case 1 :
				enemy2.PrintEnemy();
			case 0 :
				enemy1.PrintEnemy();
			}

			player.PrintScore();

			if (GetAsyncKeyState(VK_LEFT) & 0x0001)
				player.Goleft(&posPlayer, map.GetTriggerPos());
			if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
				player.GoRight(&posPlayer, map.GetTriggerPos());
			if (GetAsyncKeyState(VK_UP) & 0x0001)
				player.GoUp(&posPlayer, map.GetTriggerPos());
			if (GetAsyncKeyState(VK_DOWN) & 0x0001)
				player.GoDown(&posPlayer, map.GetTriggerPos());

			player.EatCandy(map.GetCandyPos());
			
			if(flipConunt % 2 == 0)
			switch (select)
			{
			case 2:
				enemy3.EnemyMove(map.GetTriggerPos());
			case 1:
				enemy2.EnemyMove(map.GetTriggerPos());
			case 0:
				enemy1.EnemyMove(map.GetTriggerPos());
			}

			isClear = map.CheckCandy();
			if (player.TriggerEnemy(enemy1.GetPosition()) 
				|| player.TriggerEnemy(enemy2.GetPosition()) 
				|| player.TriggerEnemy(enemy3.GetPosition()))
				isOver = true;
			else isOver = false;
		}

		if (isClear || isOver)
		{
			BackGround();

			if (isClear)
				PrintClear();
			if (isOver)
				PrintGameOver();

			if (GetAsyncKeyState(VK_RETURN) & 0x0001)
			{
				char path[64];
				scores[stage - 1] = player.getScore();
				wsprintfA(path, "Slot%d.sav", slot);
				if (isClear)
					++stage;
				MaxScoreSet(path);
				Save(path, 1, stage, scores[0], scores[1], scores[2]);
				return;
			}
		}

		++flipConunt;
		if (flipConunt == 10)
			flipConunt = 0;
		CONFLIP;
	}
}

void Game::Save(string Path, int isempty, int stage, int score1, int score2, int score3)
{
	Path = "./Data/Save/" + Path;
	WritePrivateProfileStringA("INFO", "isempty",
		IntToString(isempty).data(), Path.data());
	WritePrivateProfileStringA("INFO", "clear",
		IntToString(stage).data(), Path.data());
	WritePrivateProfileStringA("INFO", "score1",
		IntToString(score1).data(), Path.data());
	WritePrivateProfileStringA("INFO", "score2",
		IntToString(score2).data(), Path.data());
	WritePrivateProfileStringA("INFO", "score3",
		IntToString(score3).data(), Path.data());
}

void Game::Load(string Path)
{
	Path = "./Data/Save/" + Path;
	stage = ReadInt("INFO", "clear", Path);
	scores[0] = ReadInt("INFO", "score1", Path);
	scores[1] = ReadInt("INFO", "score2", Path);
	scores[2] = ReadInt("INFO", "score3", Path);
}

int Game::CheckSlot(string Path, int select)
{
	Path = "./Data/Save/" + Path;
	slotInfo[select - 1] = ReadInt("INFO", "clear", Path);
	return ReadInt("INFO", "isempty", Path);
}

void Game::MaxScoreSet(string Path)
{
	Path = "./Data/Save/" + Path;
	int temp;
	char key[16];
	for (int i = 0; i < 3; ++i) 
	{
		wsprintfA(key, "score%d", i + 1);
		temp = ReadInt("INFO", key, Path);
		if (scores[i] < temp)
			scores[i] = temp;
	}
}

Game::Game()
	:stage(1), slot(0)
{
	for (int i = 0; i < 3; ++i)
	{
		scores[i] = 0;
		slotInfo[i] = 0;
	}	
}


Game::~Game()
{
}
