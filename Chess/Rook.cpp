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
			possibleMovesVector, Chess::up);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::right);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::down);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::left);
	}

	return possibleMovesVector;
}
