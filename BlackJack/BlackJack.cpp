#include "stdafx.h"
#include "Table.h"
using namespace std;

int main()
{
	Table table;
	table.populateDeck();

	table.printDeck();

	system("pause");

    return 0;
}

