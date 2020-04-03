#pragma once
#include "Position.h"
#include "Color.cpp"
#include <vector>

using namespace std;

class Figure
{
public:
	virtual vector<Position> GetMoves(Position) = 0;
	Color GetColor()
	{
		return this->color;
	}
private:
	Color color;
};

