#pragma once

struct Position
{
	Position(int horizontal, int vertical);
	Position();
	friend bool operator == (Position position1, Position position2);
	friend Position operator + (Position position1, Position position2);
	friend Position operator += (Position position1, Position position2);
	friend Position operator * (int coefficient, Position position);

	int horizontal;
	int vertical;
};