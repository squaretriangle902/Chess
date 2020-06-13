#pragma once
#include "Piece.h"

Piece::Piece(Color color, ChessBoard* chessBoardPtr = NULL)
{
	this->color = color;
	this->chessBoardPtr = chessBoardPtr;
	this->type = noType;
}

Color Piece::GetColor()
{
	return this->color;
}

PieceType Piece::GetType()
{
	return this->type;
}

bool Piece::IsMoveValid(Position position)
{
	if (!this->chessBoardPtr->InBorders(position))
	{
		return false;
	}
	Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(position);
	return piecePtr == NULL || piecePtr->color != this->color;

}

bool Piece::IsPinned(Position piecePosition)
{
	Position* kingPositionPtr = this->chessBoardPtr->GetKingPosition(this->color);
	if (kingPositionPtr == NULL)
	{
		return false;
	}
	Chess::Direction fromPieceToKingDirection;
	TryGetDirectionFromPieceToKing(fromPieceToKingDirection,
		piecePosition,
		*kingPositionPtr) &&
		IsDirectionFromPieceToKingClear(fromPieceToKingDirection,
			piecePosition,
			*kingPositionPtr) &&
		IsPinningPiece(fromPieceToKingDirection, 
			piecePosition, 
			PinningPieceType(fromPieceToKingDirection));

}

bool Piece::TryGetDirection(Chess::Direction& direction, Position position)
{
	for (Chess::Direction i = Chess::up; i < Chess::leftUp; i++)
	{
		if (position == Position(i))
		{
			direction = i;
			return true;
		}
	}
	return false;
}

bool Piece::TryGetDirectionFromPieceToKing(Chess::Direction& direction,
	Position piecePosition, Position kingPosition)
{
	Position difference = kingPosition - piecePosition;
	difference.Reduce();
	return TryGetDirection(direction, difference);
}

bool Piece::IsDirectionFromPieceToKingClear(Chess::Direction direction, 
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

bool Piece::IsPinningPiece(Chess::Direction direction, Position piecePosition,
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

PieceType Piece::PinningPieceType(Chess::Direction direction)
{
	if (direction == Chess::up ||
		direction == Chess::right ||
		direction == Chess::left || 
		direction == Chess::down)
	{
		return rook;
	}
	else
	{
		return bishop;
	}
}

void Piece::SetChessBoardPtr(ChessBoard* chessBoardPtr)
{
	this->chessBoardPtr = chessBoardPtr;
}