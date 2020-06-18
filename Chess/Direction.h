#pragma once

class MyClass;

namespace Chess
{
	enum Direction
	{
		up = 0,
		rightUp = 1,
		right = 2,
		rightDown = 3,
		down = 4,
		leftDown = 5,
		left = 6,
		leftUp = 7,
		noDirection = 8,
	};

	Direction& operator++(Direction& direction, int number);
	Direction operator-(Direction& direction);
}
