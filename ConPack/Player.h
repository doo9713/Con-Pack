#pragma once
#include "Unit.h"

class Player : public Unit
{
private :
	char * player;
	INT score;
public :
	INT getScore() { return score; }
public :
	void PrintPlayer();
	void PrintScore();
	void EatCandy(list<INT> * candy);
	bool TriggerEnemy(POSITION enemypos);
public:
	Player(POSITION _pos);
	~Player();
};

