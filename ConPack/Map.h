#pragma once
#include "Defines.h"

class Map
{
protected :
	vector<INT> triggerPos[30];	// ���� �����̹Ƿ� �˻��� ���� ���� ���
	list<INT> candyPos[30];
	list<POSITION> enemyPos;		// ���� �������̹Ƿ� ���Ի����� ���� ����Ʈ ���
public :
	vector<INT> * GetTriggerPos() { return triggerPos; }
	list<INT> * GetCandyPos() { return candyPos; }
public :
	bool CheckCandy();
	void PrintMap();
	void PrintCandy();
public :
	Map();
	~Map();
};

