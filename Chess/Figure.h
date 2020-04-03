#pragma once
#include "Position.h"
#include "Color.cpp"
#include <vector>

using namespace std;

class Figure
{
public:
	virtual vector<Position> GetPossibleMoves(Position) = 0;
private:
	Color color;
};

