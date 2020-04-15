#pragma once
#include "Pawn.h"

Pawn::Pawn(Color color, ChessBoard* chessBoard) : Piece(color, chessBoard)
{
	this->type = pawn;
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
		CheckStep(position, 1, possibleMovesVector, movePushed);
		CheckJump(position, 2, possibleMovesVector, movePushed, 1);
		CheckTaking(position, 1, 1, possibleMovesVector);
		CheckTaking(position, -1, 1, possibleMovesVector);
		break;
	case black:
		movePushed = false;
		CheckStep(position, -1, possibleMovesVector, movePushed);
		CheckJump(position, -2, possibleMovesVector, movePushed, size - 2);
		CheckTaking(position, 1, -1, possibleMovesVector);
		CheckTaking(position, -1, -1, possibleMovesVector);
		break;
	}
	return possibleMovesVector;
}

void Pawn::CheckTaking(Position& position, 
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

void Pawn::CheckStep(Position position, int verticalOffset,
	std::vector<Position>& possibleMovesVector, bool& movePushed)
{
	Position movePosition = Position(position.horizontal, position.vertical + verticalOffset);
	if (IsMoveValid(movePosition) && this->chessBoardPtr->GetPiecePtr(movePosition) == NULL)
	{
		possibleMovesVector.push_back(movePosition);
		movePushed = true;
	}
}

void Pawn::CheckJump(Position position, int verticalOffset,
	std::vector<Position>& possibleMovesVector, bool movePushed, int necessaryVertical)
{
	Position movePosition = Position(position.horizontal, position.vertical + verticalOffset);
	if (IsMoveValid(movePosition) && this->chessBoardPtr->GetPiecePtr(movePosition) == NULL &&
		position.vertical == necessaryVertical && movePushed)
	{
		possibleMovesVector.push_back(movePosition);
	}
}