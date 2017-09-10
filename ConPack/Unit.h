#pragma once
#include "Defines.h"

class Unit
{
protected :
	POSITION pos;
public :
	void Goleft(POSITION * _pos, vector<INT> _trigger[]);
	void GoRight(POSITION * _pos, vector<INT> _trigger[]);
	void GoUp(POSITION * _pos, vector<INT> _trigger[]);
	void GoDown(POSITION * _pos, vector<INT> _trigger[]);
public :
	bool checkTrigger(POSITION _pos, vector<INT> _trigger);
	POSITION GetPosition() { return pos; }
public :
	Unit(POSITION _pos);
	~Unit();
};

