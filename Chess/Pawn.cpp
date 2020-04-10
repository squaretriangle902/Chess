#pragma once
#include "Pawn.h"

Pawn::Pawn(Color color, ChessBoard* chessBoard) : Piece(color, chessBoard)
{
}


vector<Position> Pawn::GetPossibleMoves(Position position)
{
	vector<Position> possibleMovesVector;
	int size = this->chessBoardPtr->GetSize();
	bool movePushed;
	switch (this->color)
	{
	case white:
		movePushed = false;
		TryPushMove(position, 1, possibleMovesVector, movePushed);
		TryPushJump(position, 2, possibleMovesVector, movePushed, 1);
		TryPushTaking(position, 1, 1, possibleMovesVector);
		TryPushTaking(position, -1, 1, possibleMovesVector);
		break;
	case black:
		movePushed = false;
		TryPushMove(position, -1, possibleMovesVector, movePushed);
		TryPushJump(position, -2, possibleMovesVector, movePushed, size - 2);
		TryPushTaking(position, 1, -1, possibleMovesVector);
		TryPushTaking(position, -1, -1, possibleMovesVector);
		break;
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
	std::vector<Position>& possibleMovesVector, bool& movePushed)
{
	Position movePosition = Position(position.horizontal, position.vertical + verticalOffset);
	if (IsMoveValid(movePosition) && this->chessBoardPtr->GetPiecePtr(movePosition) == NULL)
	{
		possibleMovesVector.push_back(movePosition);
		movePushed = true;
	}
}

void Pawn::TryPushJump(Position position, int verticalOffset,
	std::vector<Position>& possibleMovesVector, bool movePushed, int necessaryVertical)
{
	Position movePosition = Position(position.horizontal, position.vertical + verticalOffset);
	if (IsMoveValid(movePosition) && this->chessBoardPtr->GetPiecePtr(movePosition) == NULL &&
		position.vertical == necessaryVertical && movePushed)
	{
		possibleMovesVector.push_back(movePosition);
	}
}