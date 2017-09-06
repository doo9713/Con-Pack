#include "Player.h"


void Player::printPlayer()
{
	CONSOLE.SetTextColor(YELLOW);
	CONPOS(pos.X, pos.Y) << player;
	CONSOLE.SetTextColor(WHITE);
}

void Player::printScore()
{
	CONPOS(32, 0) << "¦¨";
	CONPOS(32, 1) << "¦¢";
	CONPOS(32, 2) << "¦¦";
	for (int i = 1; i < 8; ++i)
		CONPOS(32 + i * 2, 2) << "¦¡";
	CONPOS(46, 0) << "¦¨";
	CONPOS(46, 1) << "¦¢";
	CONPOS(46, 2) << "¦¥";
	CONSOLE.SetTextColor(YELLOW);
	CONPOS(35, 1) << "SCORE : " << score;
	CONSOLE.SetTextColor(WHITE);
}

Player::Player(POSITION _pos)
	: Unit(_pos), player(PLAYER), score(0)
{
}

Player::~Player()
{
}
