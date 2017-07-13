#pragma once
#include "Dice.h"
class Grid
{
public:
	Grid(int GridSize, int DiceStart = 1);
	~Grid();
	void PrintDice();
	int ShortestDistance(int i = 0, int j = 0, int counter = 0);
private:
	Dice* mDice;
	bool** mGrid;
	int mSize;
	int mShortestDistance;
	int mCurrentShortestDistance;
};

