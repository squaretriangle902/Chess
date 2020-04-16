#pragma once
#include "Rook.h"

Rook::Rook(Color color, ChessBoard* chessBoardPtr) : 
	LongRangePiece(color, chessBoardPtr)
{
	this->type = rook;
}

vector<Position> Rook::GetPossibleMoves(Position startingPosition)
{
	vector<Chess::Direction> BlockedDirectionsVector;
	vector<Position> possibleMovesVector;

	for (int i = 1; i < chessBoardPtr->GetSize(); i++)
	{
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::up, Position(0, 1));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::right, Position(1, 0));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::down, Position(0, -1));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::left, Position(-1, 0));
	}

	return possibleMovesVector;
}
