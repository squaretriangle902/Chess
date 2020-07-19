#pragma once
#include "SubsidiaryPiece.h"

SubsidiaryPiece::SubsidiaryPiece(Color color, ChessBoard* chessBoardPtr) : 
	Piece(color, chessBoardPtr)
{
}

vector<Position> SubsidiaryPiece::GetPossibleMoves(Position position)
{
	Chess::Direction pinDirection = Chess::noDirection;
	bool isPinned = this->IsPinned(position, pinDirection);
	vector<Position> checkingPiecesPositions;
	vector<Position> defendingMoves;
	vector<Position> possibleMovesVector = this->GetPossibleMoves(position, pinDirection);
	//possibleMovesVector = Intersection(possibleMovesVector, defendingMoves);
	return possibleMovesVector;
}

bool SubsidiaryPiece::IsPinned(Position piecePosition, Chess::Direction& direction)
{
	Position* kingPositionPtr = this->chessBoardPtr->GetKingPosition(this->color);
	if (kingPositionPtr == NULL)
	{
		return false;
	}
	TryGetDirectionFromPieceToKing(direction, piecePosition, *kingPositionPtr) &&
		IsDirectionFromPieceToKingClear(direction, piecePosition, *kingPositionPtr) &&
		IsPinningPiece(direction, piecePosition, PinningPieceType(direction));

}

bool SubsidiaryPiece::TryGetDirectionFromPieceToKing(Chess::Direction& direction,
	Position piecePosition, Position kingPosition)
{
	Position difference = kingPosition - piecePosition;
	difference.Reduce();
	return PositionToDirection(direction, difference);
}

bool SubsidiaryPiece::IsDirectionFromPieceToKingClear(Chess::Direction direction,
	Position piecePosition, Position kingPosition)
{
	for (Position currentPosition = piecePosition + Position(direction);
		currentPosition != kingPosition;
		currentPosition += Position(direction))
	{
		if (this->chessBoardPtr->GetPiecePtr(currentPosition) != NULL)
		{
			return false;
		}
	}
	return true;
}

bool SubsidiaryPiece::IsPinningPiece(Chess::Direction direction, Position piecePosition,
	PieceType pinningPieceType)
{
	for (Position currentPosition = piecePosition - Position(direction);
		this->chessBoardPtr->InBorders(currentPosition);
		currentPosition -= Position(direction))
	{
		Piece* currentPiecePtr = this->chessBoardPtr->GetPiecePtr(currentPosition);
		if (currentPiecePtr == NULL)
		{
			continue;
		}
		if (currentPiecePtr->GetColor() == this->color)
		{
			return false;
		}
		if (currentPiecePtr->GetType() == queen ||
			currentPiecePtr->GetType() == pinningPieceType)
		{
			return true;
		}
	}
	return false;
}

PieceType SubsidiaryPiece::PinningPieceType(Chess::Direction direction)
{
	if (direction == Chess::up ||
		direction == Chess::right ||
		direction == Chess::left ||
		direction == Chess::down)
	{
		return rook;
	}
	return bishop;
}