#include "Common.h"

bool IncludedInVector(Position position, vector<Position> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector.at(i) == position)
		{
			return true;
		}
	}
	return false;
}

bool CompareVector(vector<Position> vector1, vector<Position> vector2)
{
	if (vector1.size() != vector2.size())
	{
		return false;
	}
	for (int i = 0; i < vector1.size(); i++)
	{
		if (!IncludedInVector(vector1.at(i), vector2))
		{
			return false;
		}
	}
	return true;
}

Chess::Direction GetDirection(Position position)
{
	for (Chess::Direction i = Chess::up; i <= Chess::leftUp; i++)
	{
		if (position == Position(i))
		{
			return i;
		}
	}
	return Chess::noDirection;
}

Chess::Direction GetDirection(Position firstPosition, Position secondPosition)
{
	Position difference = secondPosition - firstPosition;
	difference.Reduce();
	return GetDirection(difference);
}

vector<Position> Intersection(vector<Position> firstVector, 
	vector<Position> secondVector)
{
	vector<Position> result;
	for (int i = 0; i < firstVector.size(); i++)
	{
		if (!IncludedInVector(firstVector.at(i), secondVector))
		{
			result.push_back(firstVector.at(i));
		}
	}
	return result;
}