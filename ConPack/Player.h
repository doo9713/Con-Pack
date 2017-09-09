#pragma once
#include "Unit.h"

class Player : public Unit
{
private :
	char * player;
	INT score;
public :
	void printPlayer();
	void printScore();
	void eatCandy(list<INT> * candy);
public:
	Player(POSITION _pos);
	~Player();
};

