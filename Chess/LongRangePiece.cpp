#include "LongRangePiece.h"

LongRangePiece::LongRangePiece(Color color, ChessBoard* chessBoardPtr) : 
	Piece(color, chessBoardPtr)
{
}

void LongRangePiece::CheckPositionOnDirection(Position startPosition,
	int distance, 
	std::vector<Chess::Direction>& blockedDirectionsVector,
	std::vector<Position>& possibleMovesVector, 
	Chess::Direction direction)
{
	Position movePosition = startPosition + distance * Position(direction);
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

bool LongRangePiece::IsDirectionFree(Chess::Direction direction, 
	vector<Chess::Direction> blockedDirectionsVector)
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

void LongRangePiece::BlockAllExceptPinDirection(vector<Chess::Direction>& blockedDirectionsVector,
	Position position)
{
	Chess::Direction pinDirection;
	if (!this->IsPinned(position, pinDirection))
	{
		return;
	}
	for (Chess::Direction i = Chess::up; i <= Chess::leftUp; i++)
	{
		if (i != pinDirection && i != -pinDirection)
		{
			blockedDirectionsVector.push_back(i);
		}
	}
}
