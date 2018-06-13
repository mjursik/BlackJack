#include "stdafx.h"
#include "Table.h"
#include "Card.h"
#include "suitEnum.h"
#include <iostream>
#include<algorithm>
#include<time.h>

Table::Table()
{
}


Table::~Table()
{
}

void Table::populateDeck()
{
	int max = 10;
	int id = 0;
	for (size_t j = 0; j < cardNames.size(); j++)
	{
		string currentName = cardNames[j];
		int tempValue = 0;
		if (currentName == "Jack")
		{
			tempValue = 10;
		}
		else if (currentName == "Queen")
		{
			tempValue = 10;

		}
		else if (currentName == "King")
		{
			tempValue = 10;

		}
		else if (currentName == "Ace")
		{
			tempValue = 11;
		}
		else
		{
			tempValue = j < values.size() ? values[j] : max;
		}
		Card cardGivenHearts(id, tempValue, suitEnum::hearts, currentName);
		deck.push_back(cardGivenHearts);
		id++;

		Card cardGivenSpades(id, tempValue, suitEnum::spades, currentName);
		deck.push_back(cardGivenSpades);
		id++;

		Card cardGivenClubs(id, tempValue, suitEnum::clubs, currentName);
		deck.push_back(cardGivenClubs);
		id++;

		Card cardGivenDiamonds(id, tempValue, suitEnum::diamonds, currentName);
		deck.push_back(cardGivenDiamonds);
		id++;
	}

	randomiseDeck();
}

void Table::printDeck()
{
	for (size_t i = 0; i < deck.size(); i++)
	{
		cout << deck[i].id << " - " << deck[i].value << " - " << deck[i].suit << " - " << deck[i].name << endl;
	}
}

void Table::addPlayer(Player player)
{
	players.push_back(player);
}

void Table::randomiseDeck()
{
	srand(time(NULL));
	random_shuffle(deck.begin(), deck.end());
}
