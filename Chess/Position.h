#pragma once

struct Position
{
	Position(int horizontal, int vertical);
	Position();
	friend bool operator == (Position position1, Position position2);

	int horizontal;
	int vertical;
};