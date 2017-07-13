#include "stdafx.h"
#include "Grid.h"
#include <iostream>
using namespace std;

int GlobalCounter = 0;

int PrabMin(int a, int b) 
{ 
	int res = a < b ? a : b;
	return res;
}

Grid::Grid(int GridSize, int DiceStart)
{
	mDice = new Dice(DiceStart);

	mSize = GridSize;

	mGrid = new bool*[GridSize];
	for (int i = 0; i < GridSize; ++i)
	{
		mGrid[i] = new bool[GridSize];
		for (int j = 0; j < GridSize; ++j)
		{
			mGrid[i][j] = false;
		}
	}

	mGrid[0][0] = true;

	mShortestDistance = -1;
	mCurrentShortestDistance = -1;
}


Grid::~Grid()
{
	for (int i = 0; i < mSize; ++i)
		delete[] mGrid[i];

	delete [] mGrid;
}

void Grid::PrintDice()
{
	mDice->Print();

	/*
	cout << "After Right Turn" << endl;
	mDice->TurnRight();
	mDice->Print();

	cout << "After Left Turn" << endl;
	mDice->TurnLeft();
	mDice->Print();

	cout << "After Front Turn" << endl;
	mDice->TurnFront();
	mDice->Print();

	cout << "After Back Turn" << endl;
	mDice->TurnBack();
	mDice->Print();
	*/
}


int Grid::ShortestDistance(int ii, int jj, int counter)
{
	int dist = mDice->CurrValue();
	mGrid[ii][jj] = true;
	//++counter;

	if ((ii + 1) == mSize && (jj + 1) == mSize)
	{
		mGrid[ii][jj] = false;
		return dist;
	}

	int lShortestDist(-1);
	if (((ii + 1) < mSize) && !mGrid[ii + 1][jj])
	{
		mDice->TurnRight();

#ifdef _DUMP
		cout << ++counter;
		cout << ". Right Turn. ";
		mDice->Print();
#endif

		int c = counter * 10;
		mCurrentShortestDistance += dist;
		lShortestDist = ShortestDistance(ii + 1, jj, c);
		mDice->TurnLeft();
	}

	if (((ii - 1) >= 0) && !mGrid[ii - 1][jj])
	{
		mDice->TurnLeft();
	
#ifdef _DUMP
		cout << ++counter;
		cout << ". Left Turn. ";
		mDice->Print();
#endif

		int c = counter * 10;
		int lSD = ShortestDistance(ii - 1, jj, c);
		lShortestDist = (lShortestDist < 0) ? lSD : PrabMin(lShortestDist, lSD);
		mDice->TurnRight();
	}

	if (((jj + 1) < mSize) && !mGrid[ii][jj + 1])
	{
		mDice->TurnFront();

#ifdef _DUMP
		cout << ++counter;
		cout << ". Front Turn. ";
		mDice->Print();
#endif

		int c = counter * 10;
		int lSD = ShortestDistance(ii, jj + 1, c);
		lShortestDist = (lShortestDist < 0) ? lSD : PrabMin(lShortestDist, lSD);
		mDice->TurnBack();
	}

	if (((jj - 1) >= 0) && !mGrid[ii][jj - 1])
	{
		mDice->TurnBack();

#ifdef _DUMP
		cout << ++counter;
		cout << ". Back Turn. ";
		mDice->Print();
#endif

		int c = counter * 10;
		int lSD = ShortestDistance(ii, jj - 1, c);
		lShortestDist = (lShortestDist < 0) ? lSD : PrabMin(lShortestDist, lSD);
		mDice->TurnFront();
	}

	lShortestDist = (lShortestDist < 0) ? dist : dist + lShortestDist;
	
	mGrid[ii][jj] = false;
	return lShortestDist;
}
