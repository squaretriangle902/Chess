#pragma once
#include "Piece.h"

Piece::Piece(Color color, ChessBoard* chessBoardPtr = nullptr, Game* game = nullptr)
{
	this->color = color;
	this->chessBoardPtr = chessBoardPtr;
	this->type = noType;
    this->game = game;
    this->moved = false;
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
    if (this->color == this->game->GetTurn())
	{
        vector<Position> tmp = this->GetPossibleMovesInternal(position);
        return tmp;
	}
    return vector<Position>();
}

void Piece::SetMoved(bool moved)
{
    this->moved = moved;
}

bool Piece::GetMoved()
{
    return this->moved;
}
