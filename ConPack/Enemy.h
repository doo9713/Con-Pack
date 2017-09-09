#pragma once
#include "Unit.h"

class Enemy : public Unit
{
private :
	char * enemy;
	int nowDirection;
public :
	void printEnemy();
	int ChangeDirection(list<INT> _canGo);
	void EnemyMove(vector<INT> _trigger[]);
public :
	Enemy(POSITION _pos);
	~Enemy();
};

