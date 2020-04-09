#pragma once
#include "Rook.h"

Rook::Rook(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
}

vector<Position> Rook::GetPossibleMoves(Position startingPosition)
{
	vector<Direction> BlockedDirectionsVector;
	vector<Position> possibleMovesVector;

	for (int i = 1; i < chessBoardPtr->GetSize(); i++)
	{
		//CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
		//	possibleMovesVector, up, 0, 1);
		//CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
		//	possibleMovesVector, right, 1, 0);
		//CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
		//	possibleMovesVector, down, 0, -1);
		//CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
		//	possibleMovesVector, left, -1, 0);
	}

	return possibleMovesVector;
}

void Rook::CheckPositionOnDirection(Position startingPosition,
	int i,
	std::vector<Direction>& blockedDirectionsVector,
	std::vector<Position>& possibleMovesVector,
	Direction direction,
	int verticalOffset,
	int horizontalOffset)
{
	Position movePosition =
		Position(startingPosition.vertical + i * verticalOffset,
			startingPosition.horizontal + i * horizontalOffset);
	bool isEnemy;
	if (IsDirectionFree(direction, blockedDirectionsVector) && this->IsMoveValid(movePosition))
	{
		possibleMovesVector.push_back(movePosition);
		if (this->chessBoardPtr->GetPiecePtr(movePosition))
		{
			blockedDirectionsVector.push_back(direction);
		}
	}
	else if (IsDirectionFree(direction, blockedDirectionsVector))
	{
		blockedDirectionsVector.push_back(direction);
	}
}

bool Rook::IsDirectionFree(Direction direction, vector<Direction> BlockedDirectionsVector)
{
	for (int i = 0; i < BlockedDirectionsVector.size(); i++)
	{
		if (direction == BlockedDirectionsVector.at(i))
		{
			return false;
		}
	}
	return true;
}
