#include "LongRangePiece.h"

LongRangePiece::LongRangePiece(Color color, ChessBoard* chessBoardPtr) : 
	Piece(color, chessBoardPtr)
{
}

void LongRangePiece::CheckPositionOnDirection(Position startingPosition,
	int distance, 
	std::vector<Direction::Direction>& blockedDirectionsVector,
	std::vector<Position>& possibleMovesVector, 
	Direction::Direction direction,
	int horizontalOffset,
	int verticalOffset)//remove either offsets or direction
{
	Position movePosition =
		Position(startingPosition.horizontal + distance * horizontalOffset,
			startingPosition.vertical + distance * verticalOffset);
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

bool LongRangePiece::IsDirectionFree(Direction::Direction direction, 
	vector<Direction::Direction> blockedDirectionsVector)
{
	for (int i = 0; i < blockedDirectionsVector.size(); i++)
	{
		if (direction == blockedDirectionsVector.at(i))
		{
			return false;
		}
	}
	return true;
}