#include "King.h"

King::King(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
	this->type = king;
}

void King::CheckMove(Position startingPosition, Chess::Direction direction,
	vector<Position>& possibleMovesVector)
{
	Position movePosition = startingPosition + Position(direction);
	if (IsMoveValid(movePosition) && this->GetCheckingPiecesPosition(movePosition).empty())
	{
		possibleMovesVector.push_back(movePosition);
	}
}

void King::IsCheckOnDirection(Position startPosition, Chess::Direction direction, 
	PieceType expectingType, vector<Position>& checkingPiecesPosition)
{
	for (Position currentPosition = startPosition + Position(direction);
		this->chessBoardPtr->InBorders(currentPosition);
		currentPosition += Position(direction))
	{
		Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(currentPosition);
		if (piecePtr == NULL || piecePtr->GetType() == king)
		{
			continue;
		}
		if (piecePtr->GetColor() != this->color &&
			(piecePtr->GetType() == queen || piecePtr->GetType() == expectingType))
		{
			checkingPiecesPosition.push_back(currentPosition);
		}
	}
	return;
}

vector<Position> King::GetCheckingPiecesPosition(Position kingPosition)
{
	vector<Position> checkingPiecesPosition;
	IsPawnCheck(kingPosition, checkingPiecesPosition);
	IsKnightCheck(kingPosition, checkingPiecesPosition);
	IsLongRangeCheck(kingPosition, checkingPiecesPosition);
	return checkingPiecesPosition;
}

vector<Position> King::GetDefendingMoves(Position kingPosition, 
	vector<Position> checkingPiecesPosition)
{
	if (checkingPiecesPosition.size() > 1)
	{
		return vector<Position>();
	}
	
}

void King::IsLongRangeCheck(Position startPosition, vector<Position>& checkingPiecesPosition)
{
	IsCheckOnDirection(startPosition, Chess::up, rook, checkingPiecesPosition);
	IsCheckOnDirection(startPosition, Chess::rightUp, bishop, checkingPiecesPosition);
	IsCheckOnDirection(startPosition, Chess::right, rook, checkingPiecesPosition);
	IsCheckOnDirection(startPosition, Chess::rightDown, bishop, checkingPiecesPosition);
	IsCheckOnDirection(startPosition, Chess::down, rook, checkingPiecesPosition);
	IsCheckOnDirection(startPosition, Chess::leftDown, bishop, checkingPiecesPosition);
	IsCheckOnDirection(startPosition, Chess::left, rook, checkingPiecesPosition);
    IsCheckOnDirection(startPosition, Chess::leftUp, bishop, checkingPiecesPosition);
}


void King::IsCheckOnOffset(Position startingPosition, Position positionOffset, 
	PieceType pieceType, vector<Position>& checkingPiecesPosition)
{
	Position piecePositon = startingPosition + positionOffset;
	Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(piecePositon);
	if (piecePtr != NULL && 
		piecePtr->GetColor() != this->color && 
		piecePtr->GetType() == pieceType)
	{
		checkingPiecesPosition.push_back(piecePositon);
	}
}

void King::IsKnightCheck(Position startingPosition, vector<Position>& checkingPiecesPosition)
{
	IsCheckOnOffset(startingPosition, Position(1, 2), knight, checkingPiecesPosition);
	IsCheckOnOffset(startingPosition, Position(2, 1), knight, checkingPiecesPosition);
	IsCheckOnOffset(startingPosition, Position(2, -1), knight, checkingPiecesPosition);
	IsCheckOnOffset(startingPosition, Position(1, -2), knight, checkingPiecesPosition);
	IsCheckOnOffset(startingPosition, Position(-1, -2), knight, checkingPiecesPosition);
	IsCheckOnOffset(startingPosition, Position(-2, -1), knight, checkingPiecesPosition);
	IsCheckOnOffset(startingPosition, Position(-2, 1), knight, checkingPiecesPosition);
    IsCheckOnOffset(startingPosition, Position(-1, 2), knight, checkingPiecesPosition);
}

void King::IsPawnCheck(Position startingPosition, vector<Position>& checkingPiecesPosition)
{
	switch (this->color)
	{
	case white:
		IsPawnCheck(startingPosition, Chess::leftUp, Chess::rightUp, 
			checkingPiecesPosition);
		break;
	case black:
		IsPawnCheck(startingPosition, Chess::leftDown, Chess::rightDown, 
			checkingPiecesPosition);
		break;
	}
}

void King::IsPawnCheck(Position startingPosition, Chess::Direction firstCheckDirection,
	Chess::Direction secondCheckDirection, vector<Position>& checkingPiecesPosition)
{
	IsCheckOnOffset(startingPosition, Position(firstCheckDirection), pawn, 
		checkingPiecesPosition);
	IsCheckOnOffset(startingPosition, Position(secondCheckDirection), pawn,
		checkingPiecesPosition);
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
