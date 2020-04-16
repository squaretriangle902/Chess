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
			possibleMovesVector, Chess::up, Position(0, 1));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::rightUp, Position(1, 1));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::right, Position(1, 0));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::rightDown, Position(1, -1));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::down, Position(0, -1));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::leftDown, Position(-1, -1));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::left, Position(-1, 0));
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, Chess::leftUp, Position(-1, 1));
	}

	return possibleMovesVector;
}