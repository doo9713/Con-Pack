#include "Enemy.h"


void Enemy::printEnemy()
{
	CONSOLE.SetTextColor(LIGHTRED);
	CONPOS(pos.X, pos.Y) << enemy;
	CONSOLE.SetTextColor(WHITE);
}

int Enemy::ChangeDirection(list<INT> _canGo)
{
	vector<INT> v;
	for (auto iter : _canGo)
		v.push_back(iter);

	return v.at(Random(0, v.size() - 1));
}

void Enemy::EnemyMove(vector<INT> _trigger[])
{
	POSITION prevPos = pos;
	list<INT> canGo = { LEFT, RIGHT, UP, DOWN };
	int direction;

	/* ������ �� �ִ� ���� Ž�� */
	prevPos.X = pos.X - 2;
	if (CHECKOUTSIDE(prevPos.X, prevPos.Y) || checkTrigger(prevPos, _trigger[prevPos.Y]))
		canGo.remove(LEFT);
	prevPos.X = pos.X + 2;
	if (CHECKOUTSIDE(prevPos.X, prevPos.Y) || checkTrigger(prevPos, _trigger[prevPos.Y]))
		canGo.remove(RIGHT);
	prevPos.X = pos.X;
	prevPos.Y = pos.Y - 1;
	if (CHECKOUTSIDE(prevPos.X, prevPos.Y) || checkTrigger(prevPos, _trigger[prevPos.Y]))
		canGo.remove(UP);
	prevPos.Y = pos.Y + 1;
	if (CHECKOUTSIDE(prevPos.X, prevPos.Y) || checkTrigger(prevPos, _trigger[prevPos.Y]))
		canGo.remove(DOWN);

	/* �̹� ���� ���� �켱�������� �ְ� */
	if (canGo.size() > 1)
	{
		switch (nowDirection)
		{
		case LEFT:
			canGo.remove(RIGHT);
			break;
		case RIGHT:
			canGo.remove(LEFT);
			break;
		case UP :
			canGo.remove(DOWN);
			break;
		case DOWN :
			canGo.remove(UP);
			break;
		}
	}

	if (canGo.size() > 0)
		direction = ChangeDirection(canGo);	// ���� ����
	else
		direction = -1;

	/* ��ǥ ���� */
	switch (direction)
	{
	case LEFT :
		pos.X -= 2;
		nowDirection = LEFT;
		break;
	case RIGHT :
		pos.X += 2;
		nowDirection = RIGHT;
		break;
	case UP :
		pos.Y -= 1;
		nowDirection = UP;
		break;
	case DOWN :
		pos.Y += 1;
		nowDirection = DOWN;
		break;
	default:
		break;
	}
}

Enemy::Enemy(POSITION _pos)
	: Unit(_pos), enemy(ENEMY), nowDirection(-1)
{
}

Enemy::~Enemy()
{
}
