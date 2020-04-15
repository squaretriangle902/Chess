#include "King.h"

King::King(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
	this->type = king;
}

void King::CheckMove(Position& startingPosition, 
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
		IsMoveValid(startPosition);
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
