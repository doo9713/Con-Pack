#pragma once
#include "Defines.h"

class Map
{
protected :
	vector<POSITION> triggerPos;	// ���� �����̹Ƿ� �˻��� ���� ���� ���
	list<POSITION> enemyPos;		// ���� �������̹Ƿ� ���Ի����� ���� ����Ʈ ���
public :
	Map();
	~Map();
};

