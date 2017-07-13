// DiceInGrid.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Grid.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int GridSize = 10;
	int DiceStartsAt = 2;

	Grid myGrid(GridSize, DiceStartsAt);
	myGrid.PrintDice();

	int lShortestDist = myGrid.ShortestDistance();
	cout << "Shortest Distance = ";
	cout << lShortestDist << endl;

	cin.get();
	
	return 0;
}

