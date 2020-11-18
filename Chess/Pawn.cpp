#pragma once
#include "Pawn.h"

Pawn::Pawn(Color color, ChessBoard* chessBoard, Game* game) :
    SubsidiaryPiece(color, chessBoard, game)
{
    this->type = pawn;
}

vector<Position> Pawn::GetPossibleMovesInternal(Position position, Chess::Direction pinDirection)
{
	vector<Position> possibleMovesVector;
	switch (this->color)
	{
	case white:
		return GetPossibleMovesInternal(position, pinDirection, 
			Chess::up, Chess::leftUp, Chess::rightUp, 1);
		break;
	case black:
		return GetPossibleMovesInternal(position, pinDirection,
			Chess::down, Chess::leftDown, Chess::rightDown,
			this->chessBoardPtr->GetSize() - 2);
		break;
	}
	return possibleMovesVector;
}

vector<Position> Pawn::GetPossibleMovesInternal(Position position, Chess::Direction pinDirection,
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
	CheckTaking(position, pinDirection, secondTakeDirection, possibleMovesVector);
    CheckEnPassant(position, pinDirection, firstTakeDirection, Chess::left, possibleMovesVector);
    CheckEnPassant(position, pinDirection, secondTakeDirection, Chess::right, possibleMovesVector);
	return possibleMovesVector;
}

void Pawn::CheckMove(Position startPosition, Chess::Direction pinDirection,
	Chess::Direction moveDirection, int distance, std::vector<Position>& possibleMovesVector)
{
	Position movePosition = startPosition + distance * Position(moveDirection);
	if (this->chessBoardPtr->InBorders(movePosition) &&
		this->chessBoardPtr->GetPiecePtr(movePosition) == NULL &&
		(moveDirection == pinDirection || 
		moveDirection == -pinDirection || 
		pinDirection == Chess::noDirection))
	{
		possibleMovesVector.push_back(movePosition);
	}
}

void Pawn::CheckTaking(Position startPosition, Chess::Direction pinDirection,
	Chess::Direction takeDirection, std::vector<Position>& possibleMovesVector)
{
	Position takingPosition = startPosition + Position(takeDirection);
	if (this->IsMoveValid(takingPosition) && 
		this->chessBoardPtr->GetPiecePtr(takingPosition) &&
		(takeDirection == pinDirection ||
		takeDirection == -pinDirection ||
		pinDirection == Chess::noDirection))
	{
		possibleMovesVector.push_back(takingPosition);
    }
}

void Pawn::CheckEnPassant(Position position, Chess::Direction pinDirection, Chess::Direction enPassant,
                          Chess::Direction enemyPawnDirection, std::vector<Position> &possibleMovesVector)
{
    Position takingPosition = position + Position(enPassant);
    Position enemyPawnPosition = position + Position(enemyPawnDirection);
    Piece* enemyPawnPtr = this->chessBoardPtr->GetPiecePtr(enemyPawnPosition);
    Position* p = this->chessBoardPtr->GetEnPassantVulnerablePawnPosition();
    if (this->IsMoveValid(takingPosition) &&
        enemyPawnPtr != nullptr &&
        this->chessBoardPtr->GetEnPassantVulnerablePawnPosition() != nullptr &&
        enemyPawnPosition == *this->chessBoardPtr->GetEnPassantVulnerablePawnPosition() &&
        (enPassant == pinDirection ||
        enPassant == -pinDirection ||
        pinDirection == Chess::noDirection))
    {
        possibleMovesVector.push_back(takingPosition);
    }
}

