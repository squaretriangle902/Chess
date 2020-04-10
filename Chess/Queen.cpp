#include "Queen.h"

Queen::Queen(Color color, ChessBoard* chessBoardPtr) :
	LongRangePiece(color, chessBoardPtr)
{
}

vector<Position> Queen::GetPossibleMoves(Position startingPosition)
{
	vector<Direction> BlockedDirectionsVector;
	vector<Position> possibleMovesVector;

	for (int i = 1; i < chessBoardPtr->GetSize(); i++)
	{
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, up, 0, 1);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, rightUp, 1, 1);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, right1, 1, 0);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, rightDown, 1, -1);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, down, 0, -1);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, leftDown, -1, -1);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, left1, -1, 0);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, leftUp, -1, 1);
	}

	return possibleMovesVector;
}