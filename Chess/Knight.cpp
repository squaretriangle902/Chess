#pragma once
#include "Knight.h"

Knight::Knight(Color color, ChessBoard* chessBoardPtr) : 
	SubsidiaryPiece(color, chessBoardPtr)
{
	this->type = knight;
}

void Knight::IsMovePossible(Position startPosition, Position offset,
	std::vector<Position>& possibleMovesVector)
{
	Position movePosition = startPosition + offset;
	if (this->IsMoveValid(movePosition))
	{
		possibleMovesVector.push_back(movePosition);
	}
}

vector<Position> Knight::GetPossibleMovesInternal(Position position, 
	Chess::Direction pinDirection)
{
	vector<Position> possibleMovesVector(0);
	if (pinDirection != Chess::noDirection)
	{
		return possibleMovesVector;
	}
	IsMovePossible(position, Position(1, 2), possibleMovesVector);
	IsMovePossible(position, Position(2, 1), possibleMovesVector);
	IsMovePossible(position, Position(2, -1), possibleMovesVector);
	IsMovePossible(position, Position(1, -2), possibleMovesVector);
	IsMovePossible(position, Position(-1, -2), possibleMovesVector);
	IsMovePossible(position, Position(-2, -1), possibleMovesVector);
	IsMovePossible(position, Position(-2, 1), possibleMovesVector);
	IsMovePossible(position, Position(-1, 2), possibleMovesVector);
	return possibleMovesVector;
}