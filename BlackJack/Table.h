#pragma once
#include <vector>
#include "Card.h"
#include "Player.h"
using namespace std;

class Table
{
public:
	Table();
	~Table();

	void populateDeck();
	void printDeck();
	void addPlayer(Player player);

private:
	vector<string>cardNames = { "2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace" };
	vector<int> values = { 2,3,4,5,6,7,8,9,10,11 };
	vector<Card> deck;
	vector<Player> players;

	void randomiseDeck();
};

