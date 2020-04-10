#include "Queen.h"


bool Queen::IsDirectionFree(Direction direction, vector<Direction> BlockedDirectionsVector)
{
	for (int i = 0; i < BlockedDirectionsVector.size(); i++)
	{
		if (direction == BlockedDirectionsVector.at(i))
		{
			return false;
		}
	}
	return true;
}

void Queen::CheckPositionOnDirection(Position startingPosition,
	int i,
	std::vector<Direction>& blockedDirectionsVector,
	std::vector<Position>& possibleMovesVector,
	Direction direction,
	int horizontalOffset,
	int verticalOffset)
{
	Position movePosition =
		Position(startingPosition.horizontal + i * horizontalOffset,
			startingPosition.vertical + i * verticalOffset);
	if (IsDirectionFree(direction, blockedDirectionsVector) && this->IsMoveValid(movePosition))
	{
		possibleMovesVector.push_back(movePosition);
		if (this->chessBoardPtr->GetPiecePtr(movePosition))
		{
			blockedDirectionsVector.push_back(direction);
		}
	}
	else if (IsDirectionFree(direction, blockedDirectionsVector))
	{
		blockedDirectionsVector.push_back(direction);
	}
}

Queen::Queen(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
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