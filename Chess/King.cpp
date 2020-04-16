#include "King.h"

King::King(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
	this->type = king;
}

void King::CheckMove(Position startingPosition, Chess::Direction direction,
	vector<Position>& possibleMovesVector)
{
	Position movePosition = startingPosition + Position(direction);
	if (IsMoveValid(movePosition))
	{
		possibleMovesVector.push_back(movePosition);
	}
}

bool King::CheckOnDirection(Position startPosition, Chess::Direction direction, 
	PieceType expectingType)
{
	for (startPosition += Position(direction); 
		this->chessBoardPtr->InBorders(startPosition);
		startPosition += Position(direction))
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
	return IsPawnCheck(startingPosition) ||
		IsKnightCheck(startingPosition) ||
		IsLongRangeCheck(startingPosition);
}

bool King::IsLongRangeCheck(Position startPosition)
{
	if (CheckOnDirection(startPosition, Chess::up, rook))
	{
		return true;
	}
	if (CheckOnDirection(startPosition, Chess::rightUp, bishop))
	{
		return true;
	}
	if (CheckOnDirection(startPosition, Chess::right, rook))
	{
		return true;
	}
	if (CheckOnDirection(startPosition, Chess::rightDown, bishop))
	{
		return true;
	}
	if (CheckOnDirection(startPosition, Chess::down, rook))
	{
		return true;
	}
	if (CheckOnDirection(startPosition, Chess::leftDown, bishop))
	{
		return true;
	}
	if (CheckOnDirection(startPosition, Chess::left, rook))
	{
		return true;
	}
	if (CheckOnDirection(startPosition, Chess::leftUp, bishop))
	{
		return true;
	}
	return false;
}


bool King::IsCheckOnOffset(Position startingPosition, Position positionOffset, PieceType pieceType)
{
	Position piecePositon = startingPosition + positionOffset;
	Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(piecePositon);
	if (!this->chessBoardPtr->InBorders(piecePositon))
	{
		return false;
	}
	if (piecePtr == NULL)
	{
		return false;
	}
	else if (piecePtr->GetColor() != this->color && piecePtr->GetType() == pieceType)
	{
		return true;
	}
	return false;
}

bool King::IsKnightCheck(Position startingPosition)
{
	return IsCheckOnOffset(startingPosition, Position(1, 2), knight) || 
		IsCheckOnOffset(startingPosition, Position(2, 1), knight) ||
		IsCheckOnOffset(startingPosition, Position(2, -1), knight) ||
		IsCheckOnOffset(startingPosition, Position(1, -2), knight) ||
		IsCheckOnOffset(startingPosition, Position(-1, -2), knight) ||
		IsCheckOnOffset(startingPosition, Position(-2, -1), knight) ||
		IsCheckOnOffset(startingPosition, Position(-2, 1), knight) ||
		IsCheckOnOffset(startingPosition, Position(-1, 2), knight);
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
	CheckMove(startingPosition, Chess::up, possibleMovesVector);
	CheckMove(startingPosition, Chess::rightUp, possibleMovesVector);
	CheckMove(startingPosition, Chess::right, possibleMovesVector);
	CheckMove(startingPosition, Chess::rightDown, possibleMovesVector);
	CheckMove(startingPosition, Chess::down, possibleMovesVector);
	CheckMove(startingPosition, Chess::leftDown, possibleMovesVector);
	CheckMove(startingPosition, Chess::left, possibleMovesVector);
	CheckMove(startingPosition, Chess::leftUp, possibleMovesVector);
	return possibleMovesVector;
}
