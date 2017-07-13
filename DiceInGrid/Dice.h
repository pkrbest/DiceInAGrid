#pragma once
class Dice
{
public:
	Dice(int x);
	~Dice();
	void Print();

	int TurnRight();
	int TurnLeft();
	int TurnFront();
	int TurnBack();
	const int CurrValue() { return mBottom; }
private:
	int operation(bool lbIsEven, int x);
	void AdjustValue(int& a);
	int mBottom;
	int mTop;
	int mLeft;
	int mRight;
	int mFront;
	int mBack;
};

