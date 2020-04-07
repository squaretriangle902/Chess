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