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

void Piece::SetChessBoardPtr(ChessBoard* chessBoardPtr)
{
	this->chessBoardPtr = chessBoardPtr;
}

vector<Position> Piece::GetPossibleMoves(Position position)
{
	if (this->color == this->chessBoardPtr->GetTurn())
	{
        vector<Position> tmp = this->GetPossibleMovesInternal(position);
        return tmp;
	}
	return vector<Position>();
}
