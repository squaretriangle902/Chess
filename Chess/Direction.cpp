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
		direction = up;
		break;
	}
	return direction;
}
