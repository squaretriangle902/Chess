#include "Queen.h"

Queen::Queen(Color color, ChessBoard* chessBoardPtr) :
	LongRangePiece(color, chessBoardPtr)
{
	this->type = queen;
}

vector<Position> Queen::GetPossibleMoves(Position startingPosition)
{
	vector<Chess::Direction> BlockedDirectionsVector;
	vector<Position> possibleMovesVector;

	for (int i = 1; i < chessBoardPtr->GetSize(); i++)
	{
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::up);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::rightUp);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::right);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::rightDown);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::down);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::leftDown);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::left);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::leftUp);
	}

	return possibleMovesVector;
}