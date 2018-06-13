#pragma once
#include "suitEnum.h"
#include <string>

using namespace std;

class Card
{
public:
	int id;
	int value;
	suitEnum suit;
	string name;

	Card();
	Card(int id, int value, suitEnum suit, string name);
	~Card();
};

