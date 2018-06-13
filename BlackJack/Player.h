#pragma once
#include <string>
#include <vector>
#include "Card.h"
using namespace std;

class Player
{
public:
	string name;
	double cash;
	int rank;

	Player();
	Player(string name);
	~Player();

	void addCard(Card card);
	int getScore();
	bool getIsInGame();

private:
	vector<Card> hand;
	bool isInGame;
	int score;
};

