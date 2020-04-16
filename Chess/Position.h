#pragma once
#include "Direction.h"

struct Position
{
	Position(int horizontal, int vertical);
	Position(Chess::Direction direction);
	Position(const Position& position);
	Position();
	friend bool operator == (Position position1, Position position2);
	friend Position operator + (Position position1, Position position2);
	friend void operator += (Position& position1, Position position2);
	friend Position operator * (int coefficient, Position position);

	int horizontal;
	int vertical;
};