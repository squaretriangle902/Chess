#pragma once
#include "Pawn.h"

Pawn::Pawn(Color color, ChessBoard* chessBoard) : Piece(color, chessBoard)
{
	this->type = pawn;
}


vector<Position> Pawn::GetPossibleMoves(Position position)//TODO: make case one lined
{
	vector<Position> possibleMovesVector;
	switch (this->color)
	{
	case white:
		if (IsMovePossible(position, 1, possibleMovesVector))
		{
			CheckLongMove(position, 2, possibleMovesVector, 1);
		}
		CheckTaking(position, Position(1, 1), possibleMovesVector);
		CheckTaking(position, Position(-1, 1), possibleMovesVector);
		break;
	case black:
		if (IsMovePossible(position, -1, possibleMovesVector))
		{
			CheckLongMove(position, -2, possibleMovesVector, this->chessBoardPtr->GetSize() - 2);
		}
		CheckTaking(position, Position(1, -1), possibleMovesVector);
		CheckTaking(position, Position(-1, -1), possibleMovesVector);
		break;
	}
	return possibleMovesVector;
}

void Pawn::CheckTaking(Position startPosition, Position offset, 
	vector<Position>& possibleMovesVector)
{
	Position takingPosition = startPosition + offset;
	if (this->IsMoveValid(takingPosition) && this->chessBoardPtr->GetPiecePtr(takingPosition))
	{
		possibleMovesVector.push_back(takingPosition);
	}
}

bool Pawn::IsMovePossible(Position startPosition, int horizontalOffset,
	std::vector<Position>& possibleMovesVector)
{
	Position movePosition = startPosition + Position(0, horizontalOffset);
	if (this->chessBoardPtr->InBorders(movePosition) && 
		this->chessBoardPtr->GetPiecePtr(movePosition) == NULL)
	{
		possibleMovesVector.push_back(movePosition);
		return true;
	}
	return false;
}

void Pawn::CheckLongMove(Position startPosition, int horizontalOffset,
	std::vector<Position>& possibleMovesVector, int necessaryHorizontal)
{
	Position movePosition = startPosition + Position(0, horizontalOffset);
	if (startPosition.horizontal == necessaryHorizontal &&
		this->chessBoardPtr->GetPiecePtr(movePosition) == NULL)
	{
		possibleMovesVector.push_back(movePosition);
	}
}