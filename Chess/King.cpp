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

bool King::IsCheckOnDirection(Position startPosition, Chess::Direction direction, 
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
	return IsCheckOnDirection(startPosition, Chess::up, rook) ||
		IsCheckOnDirection(startPosition, Chess::rightUp, bishop) ||
		IsCheckOnDirection(startPosition, Chess::right, rook) ||
		IsCheckOnDirection(startPosition, Chess::rightDown, bishop) ||
		IsCheckOnDirection(startPosition, Chess::down, rook) ||
		IsCheckOnDirection(startPosition, Chess::leftDown, bishop) ||
		IsCheckOnDirection(startPosition, Chess::left, rook) ||
		IsCheckOnDirection(startPosition, Chess::leftUp, bishop);
}


bool King::IsCheckOnOffset(Position startingPosition, Position positionOffset, PieceType pieceType)
{
	Position piecePositon = startingPosition + positionOffset;
	Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(piecePositon);
	return this->chessBoardPtr->InBorders(piecePositon) && piecePtr != NULL &&
		piecePtr->GetColor() != this->color && piecePtr->GetType() == pieceType;
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
	return IsCheckOnOffset(startingPosition, Position(1, orientation), pawn) ||
		IsCheckOnOffset(startingPosition, Position(-1, orientation), pawn);
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
