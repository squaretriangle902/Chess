#include "King.h"

King::King(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
	this->type = king;
}

void King::CheckMove(Position startingPosition, 
	int horizontalOffset, int verticalOffset, vector<Position>& possibleMovesVector)
{
	Position movePosition = Position(startingPosition.horizontal + horizontalOffset,
		startingPosition.vertical + verticalOffset);
	if (IsMoveValid(movePosition))
	{
		possibleMovesVector.push_back(movePosition);
	}
}

bool King::CheckOnDirection(Position& startPosition, bool endCondition, Position direction,
	PieceType expectingType)
{
	for (startPosition.horizontal += direction.horizontal,
		startPosition.vertical += direction.vertical;
		IsMoveValid(startPosition);// replace
		startPosition.horizontal += direction.horizontal, 
		startPosition.vertical += direction.vertical)
	{
		Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(startPosition);
		if (piecePtr == NULL)
		{
			continue;
		}
		if (piecePtr->GetColor() != this->color &&
			(piecePtr->GetType() == queen || piecePtr->GetType() == expectingType))
		{
			return true;
		}
		else
		{
			break;
		}
	}
	return false;
}

bool King::IsCheck(Position startingPosition)
{
	if (IsPawnCheck(startingPosition) || 
		IsKnightCheck(startingPosition) ||
		IsLongRangeCheck(startingPosition))
	{
		return true;
	}
	return false;
}

bool King::IsLongRangeCheck(Position startingPosition)
{
	int size = this->chessBoardPtr->GetSize();
	Position startPositionCopy = Position(startingPosition.horizontal,
		startingPosition.vertical);
	if (CheckOnDirection(startPositionCopy, startPositionCopy.vertical < size, Position(0, 1), rook))
	{
		return true;
	}
	startPositionCopy = Position(startingPosition.horizontal,
		startingPosition.vertical);
	if (CheckOnDirection(startPositionCopy, startPositionCopy.horizontal < size &&
		startPositionCopy.vertical < size, Position(1, 1), bishop))
	{
		return true;
	}
	startPositionCopy = Position(startingPosition.horizontal,
		startingPosition.vertical);
	if (CheckOnDirection(startPositionCopy, startPositionCopy.horizontal < size, Position(1, 0), rook))
	{
		return true;
	}
	startPositionCopy = Position(startingPosition.horizontal,
		startingPosition.vertical);
	if (CheckOnDirection(startPositionCopy, startPositionCopy.horizontal < size &&
		startPositionCopy.vertical > 0, Position(1, -1), bishop))
	{
		return true;
	}
	startPositionCopy = Position(startingPosition.horizontal,
		startingPosition.vertical);
	if (CheckOnDirection(startPositionCopy, startPositionCopy.vertical > 0, Position(0, -1), rook))
	{
		return true;
	}
	startPositionCopy = Position(startingPosition.horizontal,
		startingPosition.vertical);
	if (CheckOnDirection(startPositionCopy, startPositionCopy.horizontal > 0 &&
		startPositionCopy.vertical > 0, Position(-1, -1), bishop))
	{
		return true;
	}
	startPositionCopy = Position(startingPosition.horizontal,
		startingPosition.vertical);
	if (CheckOnDirection(startPositionCopy, startPositionCopy.horizontal > 0, Position(-1, 0), rook))
	{
		return true;
	}
	startPositionCopy = Position(startingPosition.horizontal,
		startingPosition.vertical);
	if (CheckOnDirection(startPositionCopy, startPositionCopy.horizontal > 0 &&
		startPositionCopy.vertical < size, Position(-1, 1), bishop))
	{
		return true;
	}
	return false;
}


bool King::IsCheckOnOffset(Position startingPosition, Position positionOffset, PieceType pieceType)
{
	Position piecePositon = Position(startingPosition.horizontal + positionOffset.horizontal,
		startingPosition.vertical + positionOffset.vertical);
	//IsMoveValid replace with inBorders
	if (!IsMoveValid(piecePositon))
	{
		return false;
	}
	if (this->chessBoardPtr->GetPiecePtr(piecePositon) == NULL)
	{
		return false;
	}
	else if (this->chessBoardPtr->GetPiecePtr(piecePositon)->GetColor() != this->color
		&& this->chessBoardPtr->GetPiecePtr(piecePositon)->GetType() == pieceType)
	{
		return true;
	}
	return false;
}

bool King::IsKnightCheck(Position startingPosition)
{
	if (IsCheckOnOffset(startingPosition, Position(1, 2), knight) ||
		IsCheckOnOffset(startingPosition, Position(2, 1), knight) ||
		IsCheckOnOffset(startingPosition, Position(2, -1), knight) ||
		IsCheckOnOffset(startingPosition, Position(1, -2), knight) ||
		IsCheckOnOffset(startingPosition, Position(-1, -2), knight) ||
		IsCheckOnOffset(startingPosition, Position(-2, -1), knight) ||
		IsCheckOnOffset(startingPosition, Position(-2, 1), knight) ||
		IsCheckOnOffset(startingPosition, Position(-1, 2), knight))
	{
		return true;
	}
	return false;
}

bool King::IsPawnCheck(Position startingPosition)
{
	int orientation = this->color == white ? 1 : -1;
	if (IsCheckOnOffset(startingPosition, Position(1, orientation), pawn) ||
		IsCheckOnOffset(startingPosition, Position(-1, orientation), pawn))
	{
		return true;
	}
	return false;
}

vector<Position> King::GetPossibleMoves(Position startingPosition)
{
	vector<Position> possibleMovesVector;
	CheckMove(startingPosition, 0, 1, possibleMovesVector);
	CheckMove(startingPosition, 1, 1, possibleMovesVector);
	CheckMove(startingPosition, 1, 0, possibleMovesVector);
	CheckMove(startingPosition, 1, -1, possibleMovesVector);
	CheckMove(startingPosition, 0, -1, possibleMovesVector);
	CheckMove(startingPosition, -1, -1, possibleMovesVector);
	CheckMove(startingPosition, -1, 0, possibleMovesVector);
	CheckMove(startingPosition, -1, 1, possibleMovesVector);
	return possibleMovesVector;
}
