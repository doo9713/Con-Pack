#include "Player.h"


void Player::printPlayer()
{
	CONSOLE.SetTextColor(YELLOW);
	CONPOS(pos.X, pos.Y) << player;
	CONSOLE.SetTextColor(WHITE);
}

void Player::printScore()
{
	CONPOS(35, 1) << "SCORE : " << score;
}

Player::Player(POSITION _pos)
	: Unit(_pos), player(PLAYER), score(0)
{
}

Player::~Player()
{
}
