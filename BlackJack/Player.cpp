#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	score = 0;
	isInGame = true;
}

Player::Player(string name):
	name(name)
{
	score = 0;
	isInGame = true;
}


Player::~Player()
{
}

void Player::addCard(Card card)
{
	score += card.value;
	hand.push_back(card);
}

int Player::getScore()
{
	return score;
}

bool Player::getIsInGame()
{
	return isInGame;
}
