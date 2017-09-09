#include "Unit.h"
#include "Stage1.h"


bool Unit::checkTrigger(POSITION _pos, vector<INT> _trigger)
{
	for (auto iter : _trigger)
		if (_pos.X == iter)
			return true;
	return false;
}

void Unit::Goleft(POSITION * _pos, vector<INT> _trigger[])
{
	int temp = _pos->X;
	_pos->X -= 2;
	if (CHECKOUTSIDE(_pos->X, _pos->Y) || checkTrigger(*_pos , _trigger[_pos->Y]))
		_pos->X = temp;
	pos.X = _pos->X;
	pos.Y = _pos->Y;
}

void Unit::GoRight(POSITION * _pos, vector<INT> _trigger[])
{
	int temp = _pos->X;
	_pos->X += 2;
	if (CHECKOUTSIDE(_pos->X, _pos->Y) || checkTrigger(*_pos, _trigger[_pos->Y]))
		_pos->X = temp;
	pos.X = _pos->X;
	pos.Y = _pos->Y;
}

void Unit::GoUp(POSITION * _pos, vector<INT> _trigger[])
{
	int temp = _pos->Y;
	_pos->Y -= 1;
	if (CHECKOUTSIDE(_pos->X, _pos->Y) || checkTrigger(*_pos, _trigger[_pos->Y]))
		_pos->Y = temp;
	pos.X = _pos->X;
	pos.Y = _pos->Y;
}

void Unit::GoDown(POSITION * _pos, vector<INT> _trigger[])
{
	int temp = _pos->Y;
	_pos->Y += 1;
	if (CHECKOUTSIDE(_pos->X, _pos->Y) || checkTrigger(*_pos, _trigger[_pos->Y]))
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
