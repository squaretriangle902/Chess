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

bool Piece::IsPin(Position position)
{
	Position* kingPosition = this->chessBoardPtr->GetKingPosition(this->color);
	return false;
}

Chess::Direction Piece::FromPieceToKingDirection(Position piecePosition, 
	Position kingPosition)
{
	if (piecePosition.horizontal - kingPosition.horizontal ==
		piecePosition.vertical - kingPosition.vertical)
	{
		return Chess::rightUp;
	}
	return Chess::Direction();
}

void Piece::SetChessBoardPtr(ChessBoard* chessBoardPtr)
{
	this->chessBoardPtr = chessBoardPtr;
}