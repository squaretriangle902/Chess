#pragma once
#include "Bishop.h"

Bishop::Bishop(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
}

bool Bishop::IsDirectionFree(Direction direction, vector<Direction> BlockedDirectionsVector)
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

void Bishop::CheckPositionOnDirection(Position startingPosition, 
	int i, 
	std::vector<Direction>& blockedDirectionsVector, 
	std::vector<Position>& possibleMovesVector,
	Direction direction,
	int verticalOffset,
	int horizontalOffset)
{
	Position movePosition =
		Position(startingPosition.vertical + i*verticalOffset, 
			startingPosition.horizontal + i*horizontalOffset);
	if (IsDirectionFree(direction, blockedDirectionsVector) && this->IsMoveValid(movePosition))
	{
		possibleMovesVector.push_back(movePosition);
		if (this->chessBoardPtr->GetPiecePtr(movePosition))
		{
			blockedDirectionsVector.push_back(direction);
		}
	}
	else if(IsDirectionFree(direction, blockedDirectionsVector))
	{
		blockedDirectionsVector.push_back(direction);
	}
}

vector<Position> Bishop::GetPossibleMoves(Position startingPosition)
{
	vector<Direction> BlockedDirectionsVector;
	vector<Position> possibleMovesVector;

	for (int i = 1; i < chessBoardPtr->GetSize(); i++)
	{
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector, 
			possibleMovesVector, rightUp, 1, 1);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, rightDown, 1, -1);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, leftDown, -1, -1);
		CheckPositionOnDirection(startingPosition, i, BlockedDirectionsVector,
			possibleMovesVector, leftUp, -1, 1);
	}

	return possibleMovesVector;
}
