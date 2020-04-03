#pragma once
#include "Figure.h"

class Knight : public Figure
{
	vector<Position> GetPossibleMoves(Position startingPosition)
	{
		vector<Position> positionVector;
		positionVector.push_back(
			Position(startingPosition.horizontal + 1, startingPosition.vertical + 2));
		positionVector.push_back(
			Position(startingPosition.horizontal + 2, startingPosition.vertical + 1));
		positionVector.push_back(
			Position(startingPosition.horizontal + 2, startingPosition.vertical - 1));
		positionVector.push_back(
			Position(startingPosition.horizontal + 1, startingPosition.vertical - 2));
		positionVector.push_back(
			Position(startingPosition.horizontal - 1, startingPosition.vertical - 2));
		positionVector.push_back(
			Position(startingPosition.horizontal - 2, startingPosition.vertical - 1));
		positionVector.push_back(
			Position(startingPosition.horizontal - 2, startingPosition.vertical + 1));
		positionVector.push_back(
			Position(startingPosition.horizontal - 1, startingPosition.vertical + 2));
		return positionVector;
	}
};

