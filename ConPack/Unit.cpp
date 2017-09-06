#include "Unit.h"


void Unit::Goleft(POSITION * _pos)
{
	double temp = _pos->X;
	_pos->X -= 2;
	if (CHECKOUTSIDE(_pos->X, _pos->Y))
		_pos->X = temp;
	pos.X = _pos->X;
	pos.Y = _pos->Y;
}

void Unit::GoRight(POSITION * _pos)
{
	double temp = _pos->X;
	_pos->X += 2;
	if (CHECKOUTSIDE(_pos->X, _pos->Y))
		_pos->X = temp;
	pos.X = _pos->X;
	pos.Y = _pos->Y;
}

void Unit::GoUp(POSITION * _pos)
{
	double temp = _pos->Y;
	_pos->Y -= 1;
	if (CHECKOUTSIDE(_pos->X, _pos->Y))
		_pos->Y = temp;
	pos.X = _pos->X;
	pos.Y = _pos->Y;
}

void Unit::GoDown(POSITION * _pos)
{
	double temp = _pos->Y;
	_pos->Y += 1;
	if (CHECKOUTSIDE(_pos->X, _pos->Y))
		_pos->Y = temp;
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
