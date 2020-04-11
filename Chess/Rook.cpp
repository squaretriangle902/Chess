#pragma once
#include "Rook.h"

Rook::Rook(Color color, ChessBoard* chessBoardPtr) : 
	LongRangePiece(color, chessBoardPtr)
{
}

vector<Position> Rook::GetPossibleMoves(Position startingPosition)
{
	vector<Direction::Direction> BlockedDirectionsVector;
	vector<Position> possibleMovesVector;

	for (int i = 1; i < chessBoardPtr->GetSize(); i++)
	{
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Direction::up, 0, 1);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Direction::right, 1, 0);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Direction::down, 0, -1);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Direction::left, -1, 0);
	}

	return possibleMovesVector;
}
