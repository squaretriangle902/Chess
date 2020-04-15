#pragma once
#include "Knight.h"

Knight::Knight(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
	this->type = knight;
}

void Knight::CheckStep(Position& position, 
	int horizontalOffset, int verticalOffset, 
	std::vector<Position>& possibleMovesVector)
{
	Position movePosition =
		Position(position.horizontal + horizontalOffset, position.vertical + verticalOffset);
	if (this->IsMoveValid(movePosition))
	{
		possibleMovesVector.push_back(movePosition);
	}
}

vector<Position> Knight::GetPossibleMoves(Position position)
{
	vector<Position> possibleMovesVector;
	CheckStep(position, 1, 2, possibleMovesVector);
	CheckStep(position, 2, 1, possibleMovesVector);
	CheckStep(position, 2, -1, possibleMovesVector);
	CheckStep(position, 1, -2, possibleMovesVector);
	CheckStep(position, -1, -2, possibleMovesVector);
	CheckStep(position, -2, -1, possibleMovesVector);
	CheckStep(position, -2, 1, possibleMovesVector);
	CheckStep(position, -1, 2, possibleMovesVector);
	return possibleMovesVector;
}

//vector<Position> GetMoves(Position startingPosition)
//{
//	vector<Position> positionsVector;
//	positionsVector.push_back(
//		Position(startingPosition.horizontal + 1, startingPosition.vertical + 2));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal + 2, startingPosition.vertical + 1));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal + 2, startingPosition.vertical - 1));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal + 1, startingPosition.vertical - 2));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal - 1, startingPosition.vertical - 2));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal - 2, startingPosition.vertical - 1));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal - 2, startingPosition.vertical + 1));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal - 1, startingPosition.vertical + 2));
//	return positionsVector;
//}