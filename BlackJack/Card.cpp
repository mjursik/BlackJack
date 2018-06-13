#include "stdafx.h"
#include "Card.h"


Card::Card()
{
}

Card::Card(int id, int value, suitEnum suit, string name):
	id(id), value(value), suit(suit), name(name)
{
}


Card::~Card()
{
}
