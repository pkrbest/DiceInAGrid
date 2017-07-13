#include "stdafx.h"
#include <iostream>
#include "Dice.h"
using namespace std;

// creates a dice with bottom = x
Dice::Dice(int x)
{
	bool lbIsEven(false);

	if (x > 6) x = 6;
	if (x < 1) x = 1;
	

	if (x == (x / 2) * 2) lbIsEven = true;

	mBottom = x;
	
	int a = operation(lbIsEven,x);
	AdjustValue(a);
	mTop = a;

	a = operation(lbIsEven, a);
	AdjustValue(a);
	mLeft = a;

	a = operation(lbIsEven, a);
	AdjustValue(a);
	if (a > 6) a = 1;
	mRight = a;

	a = operation(lbIsEven, a);
	AdjustValue(a);
	mFront = a;

	a = operation(lbIsEven, a);
	AdjustValue(a);
	mBack = a;
}


Dice::~Dice()
{
}

void Dice::Print()
{
	cout << "[ Bottom = "
		<< mBottom
		<< ", Top = "
		<< mTop
		<< ", Left = "
		<< mLeft
		<< ", Right = "
		<< mRight
		<< ", Front = "
		<< mFront
		<< ", Back = "
		<< mBack
		<< " ]\n";
}

int Dice::operation(bool lbIsEven, int x)
{
	return lbIsEven ? x - 1 : x + 1;
}

void Dice::AdjustValue(int& x)
{
	if (x > 6) x = 1;
	if (x < 1) x = 6;
}

int Dice::TurnBack()
{
	int prev_bottom = mBottom;
	mBottom = mBack;
	mBack = mTop;
	mTop = mFront;
	mFront = prev_bottom;

	return mBottom;
}

int Dice::TurnFront()
{
	int prev_bottom = mBottom;
	mBottom = mFront;
	mFront = mTop;
	mTop = mBack;
	mBack = prev_bottom;

	return mBottom;
}

int Dice::TurnLeft()
{
	int prev_bottom = mBottom;
	mBottom = mLeft;
	mLeft = mTop;
	mTop = mRight;
	mRight = prev_bottom;

	return mBottom;
}

int Dice::TurnRight()
{
	int prev_bottom = mBottom;
	mBottom = mRight;
	mRight = mTop;
	mTop = mLeft;
	mLeft = prev_bottom;

	return mBottom;

}

