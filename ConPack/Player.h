#pragma once
#include "Unit.h"

#define PLAYER "��"
class Player : public Unit
{
private :
	char * player;
	INT score;
public :
	void printPlayer();
	void printScore();
public:
	Player(POSITION _pos);
	~Player();
};

