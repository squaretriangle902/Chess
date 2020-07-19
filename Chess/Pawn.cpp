#pragma once
#include "Pawn.h"

Pawn::Pawn(Color color, ChessBoard* chessBoard) : SubsidiaryPiece(color, chessBoard)
{
	this->type = pawn;
}


vector<Position> Pawn::GetPossibleMoves(Position position, Chess::Direction pinDirection)
{
	vector<Position> possibleMovesVector;
	switch (this->color)
	{
	case white:
		return GetPossibleMoves(position, pinDirection, 
			Chess::up, Chess::leftUp, Chess::rightUp, 1);
		break;
	case black:
		return GetPossibleMoves(position, pinDirection,
			Chess::down, Chess::leftDown, Chess::rightDown,
			this->chessBoardPtr->GetSize() - 2);
		break;
	}
	return possibleMovesVector;
}

vector<Position> Pawn::GetPossibleMoves(Position position, Chess::Direction pinDirection,
	Chess::Direction moveDirection, Chess::Direction firstTakeDirection, 
	Chess::Direction secondTakeDirection, int longMoveHorizontal)
{
	vector<Position> possibleMovesVector;
	int moveDistance = 1;
	int longMoveDistance = 2;
	CheckMove(position, pinDirection, moveDirection, moveDistance, possibleMovesVector);
	if (!possibleMovesVector.empty() && position.horizontal == longMoveHorizontal)
	{
		CheckMove(position, pinDirection, moveDirection, longMoveDistance, possibleMovesVector);
	}
	CheckTaking(position, pinDirection, firstTakeDirection, possibleMovesVector);
	return possibleMovesVector;
}

void Pawn::CheckMove(Position startPosition, Chess::Direction pinDirection,
	Chess::Direction moveDirection, int distance, std::vector<Position>& possibleMovesVector)
{
	Position movePosition = startPosition + Position(moveDirection);
	if (this->chessBoardPtr->InBorders(movePosition) &&
		this->chessBoardPtr->GetPiecePtr(movePosition) == NULL &&
		(moveDirection == pinDirection || moveDirection == -pinDirection))
	{
		possibleMovesVector.push_back(movePosition);
	}
}

void Pawn::CheckTaking(Position startPosition, Chess::Direction pinDirection,
	Chess::Direction takeDirection, std::vector<Position>& possibleMovesVector)
{
	Position takingPosition = startPosition + Position(takeDirection);
	if (this->IsMoveValid(takingPosition) && this->chessBoardPtr->GetPiecePtr(takingPosition))
	{
		possibleMovesVector.push_back(takingPosition);
	}
}