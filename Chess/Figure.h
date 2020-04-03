#pragma once
#include "Position.h"

enum Color
{
	black = 0,
	white = 1,
};

class Figure
{
public:
	virtual Position* GetPossibleMoves(Position) = 0;
private:
	Color color;
};

