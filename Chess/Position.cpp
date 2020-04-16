#pragma once
#include "Position.h"

Position::Position(int horizontal, int vertical)
{
	this->horizontal = horizontal;
	this->vertical = vertical;
}

Position::Position(Chess::Direction direction)
{
	switch (direction)
	{
	case Chess::up:
		this->horizontal = 0;
		this->vertical = 1;
		break;
	case Chess::rightUp:
		this->horizontal = 1;
		this->vertical = 1;
		break;
	case Chess::right:
		this->horizontal = 1;
		this->vertical = 0;
		break;
	case Chess::rightDown:
		this->horizontal = 1;
		this->vertical = -1;
		break;
	case Chess::down:
		this->horizontal = 0;
		this->vertical = -1;
		break;
	case Chess::leftDown:
		this->horizontal = -1;
		this->vertical = -1;
		break;
	case Chess::left:
		this->horizontal = -1;
		this->vertical = 0;
		break;
	case Chess::leftUp:
		this->horizontal = -1;
		this->vertical = 1;
		break;
	}
}

Position::Position(const Position& position)
{
	this->horizontal = position.horizontal;
	this->vertical = position.vertical;
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

void operator+=(Position& position1, Position position2)
{
	position1 = position1 + position2;
}

Position operator*(int coefficient, Position position)
{
	return Position(coefficient * position.horizontal, coefficient * position.vertical);
}
