#include "Unit.h"


void Unit::Goleft(POSITION * _pos)
{
	_pos->X -= 1;
	pos.X = _pos->X;
	pos.Y = _pos->Y;
}

void Unit::GoRight(POSITION * _pos)
{
	_pos->X += 1;
	pos.X = _pos->X;
	pos.Y = _pos->Y;
}

void Unit::GoUp(POSITION * _pos)
{
	_pos->Y -= 1;
	pos.X = _pos->X;
	pos.Y = _pos->Y;
}

void Unit::GoDown(POSITION * _pos)
{
	_pos->Y += 1;
	pos.X = _pos->X;
	pos.Y = _pos->Y;
}

Unit::Unit(POSITION _pos)
	:pos(_pos)
{
}

Unit::~Unit()
{
}
