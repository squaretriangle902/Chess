#pragma once
#include "Position.h"

Position::Position(int horizontal, int vertical)
{
	this->horizontal = horizontal;
	this->vertical = vertical;
}

Position::Position()
{
	this->horizontal = 0;
	this->vertical = 0;
}

bool operator==(Position position1, Position position2)
{
	return position1.horizontal == position2.horizontal && 
		position1.vertical == position2.vertical;
}

Position operator+(Position position1, Position position2)
{
	return Position(position1.horizontal + position2.horizontal,
		position1.vertical += position2.vertical);
}

Position operator+=(Position position1, Position position2)
{
	return position1 + position2;
}
