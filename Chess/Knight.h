#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Color color) : Piece(color)
	{
		this->jumps = true;
	}

	vector<Position> GetMoves(Position startingPosition)
	{
		vector<Position> positionsVector;
		positionsVector.push_back(
			Position(startingPosition.horizontal + 1, startingPosition.vertical + 2));
		positionsVector.push_back(
			Position(startingPosition.horizontal + 2, startingPosition.vertical + 1));
		positionsVector.push_back(
			Position(startingPosition.horizontal + 2, startingPosition.vertical - 1));
		positionsVector.push_back(
			Position(startingPosition.horizontal + 1, startingPosition.vertical - 2));
		positionsVector.push_back(
			Position(startingPosition.horizontal - 1, startingPosition.vertical - 2));
		positionsVector.push_back(
			Position(startingPosition.horizontal - 2, startingPosition.vertical - 1));
		positionsVector.push_back(
			Position(startingPosition.horizontal - 2, startingPosition.vertical + 1));
		positionsVector.push_back(
			Position(startingPosition.horizontal - 1, startingPosition.vertical + 2));
		return positionsVector;
	}
};

