#include "stdafx.h"
#include "Table.h"
#include "Card.h"
#include "suitEnum.h"
#include <iostream>
#include <algorithm>
#include <time.h>

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

void Table::play()
{
	while (true)
	{
		int playerNumbers;
		cout << "How many players will play? ";
		cin >> playerNumbers;
		if (cin.bad() || playerNumbers <= 0)
		{
			return;
		}

		for (size_t i = 0; i < playerNumbers; i++) // upis imena igraca i iznos njihovih novaca
		{
			string name;
			double cash;
			cout << "Please enter your desired name: ";
			cin >> name;

			players.push_back(Player(name)); // vracanje valuea u vector igraca
		}



		char choice;
		int houseValue = 0;

		for (size_t i = 0; i < players.size(); i++)
		{
			int brojac = 0;
			while (players[i].getScore() < 21)
			{
				cout << "Does the " << players[i].name << " wish to get a card?(y/n):  ";
				cin >> choice;

				if (choice == 'y')
				{
					players[i].addCard(deck.back());// stavlja zadnju kartu u ruku od igraca
					deck.pop_back();				  // mice tu kartu iz spila 
				}
				else if (choice == 'n')
				{
					break;
				}
			}
		}


		cout << "\n";
		cout << "\n";
		cout << "----------------------------" << endl;
		cout << "THE HOUSE PLAYS!" << endl;


		while (house.getScore() <= 21 && house.getScore() < 13)
		{
			
			house.addCard(deck.back());// stavlja zadnju kartu u ruku od kuce
			deck.pop_back();				// mice tu kartu iz spila 
		}

		for (size_t i = 0; i < players.size(); i++)
		{
			cout << players[i].name << " has : " << players[i].getScore() << " points." << endl;
		}

		cout << "The house has : " << house.getScore() << " points." << endl;
		/*
		if (playerValue > 21)
		{
		cout << "The player busted! Sorry!" << endl;
		}
		else if (houseValue > 21)
		{
		cout << "The house busted! You won!" << endl;
		}
		else if (abs(21 - playerValue) < (abs(21 - houseValue)))
		{
		cout << "The player won!" << endl;
		}
		else
		{
		cout << "The house won!" << endl;
		}
		*/
		return;
	}
}

void Table::randomiseDeck()
{
	srand(time(NULL));
	random_shuffle(deck.begin(), deck.end());
}
