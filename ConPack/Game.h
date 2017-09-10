#pragma once

#include "Defines.h"

class Game
{
private :
	INT stage;
	INT slot;
	INT scores[3];
	INT slotInfo[3];
private :
	void Save(string Path, int isempty, int stage, int score1, int score2, int score3);
	void Load(string Path);
	int CheckSlot(string Path, int select);
	void MaxScoreSet(string Path);
public :
	void PrintClear();
	void PrintGameOver();
	void DefaultStage(int pos, int select);
	void ClearStage(int pos, int select);
	void StageSelectMenu(int select);
	void PrintSlot(int pos, int select);
	void PrintAllSlot(int select);
	void MainActive(bool NewOrLoad);
	void StageActive();
	void GameActive(int select);
public :
	Game();
	~Game();
};

