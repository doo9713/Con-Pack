#pragma once
#include "Defines.h"

class Map
{
protected :
	vector<INT> triggerPos[30];	// 맵은 고정이므로 검색이 빠른 벡터 사용
	list<INT> candyPos[30];
	list<POSITION> enemyPos;		// 적은 유동적이므로 삽입삭제가 빠른 리스트 사용
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

