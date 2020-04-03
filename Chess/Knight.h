#pragma once
#include "Figure.h"

class Knight : public Figure
{
	vector<Position> GetMoves(Position startingPosition)
	{
		vector<Position> pssiblePositionVector;
		pssiblePositionVector.push_back(
			Position(startingPosition.horizontal + 1, startingPosition.vertical + 2));
		pssiblePositionVector.push_back(
			Position(startingPosition.horizontal + 2, startingPosition.vertical + 1));
		pssiblePositionVector.push_back(
			Position(startingPosition.horizontal + 2, startingPosition.vertical - 1));
		pssiblePositionVector.push_back(
			Position(startingPosition.horizontal + 1, startingPosition.vertical - 2));
		pssiblePositionVector.push_back(
			Position(startingPosition.horizontal - 1, startingPosition.vertical - 2));
		pssiblePositionVector.push_back(
			Position(startingPosition.horizontal - 2, startingPosition.vertical - 1));
		pssiblePositionVector.push_back(
			Position(startingPosition.horizontal - 2, startingPosition.vertical + 1));
		pssiblePositionVector.push_back(
			Position(startingPosition.horizontal - 1, startingPosition.vertical + 2));
		return pssiblePositionVector;
	}
};

