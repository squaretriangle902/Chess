#pragma once
#include "Bishop.h"

Bishop::Bishop(Color color, ChessBoard* chessBoardPtr) : 
	LongRangePiece(color, chessBoardPtr)
{
	this->type = bishop;
}

vector<Position> Bishop::GetPossibleMoves(Position startingPosition)
{
	vector<Chess::Direction> BlockedDirectionsVector;
	vector<Position> possibleMovesVector;
	for (int i = 1; i < chessBoardPtr->GetSize(); i++)
	{
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector, 
			possibleMovesVector, Chess::rightUp, Position(1, 1));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::rightDown, Position(1, -1));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::leftDown, Position(-1, -1));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::leftUp, Position(-1, 1));
	}
	return possibleMovesVector;
}
