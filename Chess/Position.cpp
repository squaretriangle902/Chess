#pragma once
#include "Position.h"

Position::Position(int vertical, int horizontal)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

Position::Position(Chess::Direction direction)
{
	switch (direction)
	{
	case Chess::up:
		this->vertical = 0;
		this->horizontal = 1;
		break;
	case Chess::rightUp:
		this->vertical = 1;
		this->horizontal = 1;
		break;
	case Chess::right:
		this->vertical = 1;
		this->horizontal = 0;
		break;
	case Chess::rightDown:
		this->vertical = 1;
		this->horizontal = -1;
		break;
	case Chess::down:
		this->vertical = 0;
		this->horizontal = -1;
		break;
	case Chess::leftDown:
		this->vertical = -1;
		this->horizontal = -1;
		break;
	case Chess::left:
		this->vertical = -1;
		this->horizontal = 0;
		break;
	case Chess::leftUp:
		this->vertical = -1;
		this->horizontal = 1;
		break;
	}
}

Position::Position(const Position& position)
{
	this->vertical = position.vertical;
	this->horizontal = position.horizontal;
}

Position::Position()
{
	this->vertical = 0;
	this->horizontal = 0;
}

void Position::Reduce()
{
	int gcd = GCD(this->vertical, this->horizontal);
	this->vertical = this->vertical / gcd;
	this->horizontal = this->horizontal / gcd;
}

bool operator==(Position position1, Position position2)
{
	return position1.horizontal == position2.horizontal &&
		position1.vertical == position2.vertical;
}

bool operator!=(Position position1, Position position2)
{
	return !(position1 == position2);
}

Position operator+(Position position1, Position position2)
{
	return Position(position1.vertical + position2.vertical,
		position1.horizontal + position2.horizontal);
}

Position operator-(Position position1, Position position2)
{
	return Position(position1.vertical - position2.vertical,
		position1.horizontal - position2.horizontal);
}

void operator+=(Position& position1, Position position2)
{
	position1 = position1 + position2;
}

void operator-=(Position& position1, Position position2)
{
	position1 = position1 - position2;
}

Position operator*(int coefficient, Position position)
{
	return Position(coefficient * position.horizontal, coefficient * position.vertical);
}
