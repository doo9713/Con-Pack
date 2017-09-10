#pragma once
#include "Unit.h"

class Enemy : public Unit
{
private :
	char * enemy;
	int nowDirection;
public :
	void PrintEnemy();
	int ChangeDirection(list<INT> _canGo);
	void EnemyMove(vector<INT> _trigger[]);
	void EnemyDisable();
public :
	Enemy(POSITION _pos);
	~Enemy();
};

