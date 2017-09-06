#pragma once
#include "Defines.h"

class Map
{
protected :
	vector<POSITION> triggerPos;	// 맵은 고정이므로 검색이 빠른 벡터 사용
	list<POSITION> enemyPos;		// 적은 유동적이므로 삽입삭제가 빠른 리스트 사용
public :
	Map();
	~Map();
};

