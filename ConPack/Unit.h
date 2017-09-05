#pragma once
#include "Defines.h"

class Unit
{
protected :
	POSITION pos;
public :
	void Goleft(POSITION * _pos);
	void GoRight(POSITION * _pos);
	void GoUp(POSITION * _pos);
	void GoDown(POSITION * _pos);
public :
	Unit(POSITION _pos);
	~Unit();
};

