#pragma once
#include "Position.h"
#include "Color.cpp"
#include <vector>

using namespace std;

class Piece
{
public:
	Piece(Color color)
	{
		this->color = color;
	}
	virtual vector<Position> GetMoves(Position) = 0;
	Color GetColor()
	{
		return this->color;
	}
protected:
	Color color;
	bool jumps;
};

