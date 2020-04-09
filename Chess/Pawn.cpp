#pragma once
#include "Pawn.h"

Pawn::Pawn(Color color, ChessBoard* chessBoard) : Piece(color, chessBoard)
{
}

vector<Position> Pawn::GetPossibleMoves(Position position)
{
	vector<Position> possibleMovesVector;
	if (this->color == white)
	{
		TryPushMove(position, 1, possibleMovesVector);
		if (position.vertical == 1 && 
			this->IsMoveValid(Position(position.horizontal, position.vertical+1)))
		{
			TryPushMove(position, 2, possibleMovesVector);
		}
		TryPushTaking(position, 1, 1, possibleMovesVector);
		TryPushTaking(position, -1, 1, possibleMovesVector);
	}
	else if(this->color == black)
	{
		TryPushMove(position, -1, possibleMovesVector);
		if (position.vertical == 6 &&
			this->IsMoveValid(Position(position.horizontal, position.vertical + 1)))
		{
			TryPushMove(position, -2, possibleMovesVector);
		}
		TryPushTaking(position, 1, -1, possibleMovesVector);
		TryPushTaking(position, -1, -1, possibleMovesVector);
	}
	return possibleMovesVector;
}

void Pawn::TryPushTaking(Position& position, 
	int horizontalOffset, int verticalOffset, 
	vector<Position>& possibleMovesVector)
{
	Position takingPosition = Position(position.horizontal + horizontalOffset,
		position.vertical + verticalOffset);
	if (this->IsMoveValid(takingPosition) && this->chessBoardPtr->GetPiecePtr(takingPosition))
	{
		possibleMovesVector.push_back(takingPosition);
	}
}

void Pawn::TryPushMove(Position position, int verticalOffset,
	std::vector<Position>& possibleMovesVector)
{
	int size = this->chessBoardPtr->GetSize();
	bool inBorders = (position.vertical < size) && (position.vertical >= 0);
	Position movePosition =
		Position(position.horizontal, position.vertical + verticalOffset);
	if (movePosition.horizontal < this->chessBoardPtr->GetSize() && 
		!this->chessBoardPtr->GetPiecePtr(movePosition))
	{
		possibleMovesVector.push_back(movePosition);
	}
}