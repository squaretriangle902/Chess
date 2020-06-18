#include "Direction.h"

Chess::Direction& Chess::operator++(Chess::Direction& direction, int number)
{
	switch (direction)
	{
	case Chess::up:
		direction = rightUp;
		break;
	case Chess::rightUp:
		direction = right;
		break;
	case Chess::right:
		direction = rightDown;
		break;
	case Chess::rightDown:
		direction = down;
		break;
	case Chess::down:
		direction = leftDown;
		break;
	case Chess::leftDown:
		direction = left;
		break;
	case Chess::left:
		direction = leftUp;
		break;
	case Chess::leftUp:
		direction = noDirection;
		break;
	}
	return direction;
}

Chess::Direction Chess::operator-(Direction& direction)
{
	switch (direction)
	{
	case Chess::up:
		return down;
		break;
	case Chess::rightUp:
		return leftDown;
		break;
	case Chess::right:
		return left;
		break;
	case Chess::rightDown:
		return leftUp;
		break;
	case Chess::down:
		return up;
		break;
	case Chess::leftDown:
		return rightUp;
		break;
	case Chess::left:
		return right;
		break;
	case Chess::leftUp:
		return rightDown;
		break;
	case Chess::noDirection:
		return noDirection;
		break;
	}
	return direction;
}
