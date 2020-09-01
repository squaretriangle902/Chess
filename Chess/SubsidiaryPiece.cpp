#pragma once
#include "SubsidiaryPiece.h"

SubsidiaryPiece::SubsidiaryPiece(Color color, ChessBoard* chessBoardPtr) : 
	Piece(color, chessBoardPtr)
{
}

vector<Position> SubsidiaryPiece::GetPossibleMovesInternal(Position position)
{
	Chess::Direction pinDirection = this->chessBoardPtr->PinDirection(position);
	vector<Position> defendingMoves;
	bool isCheck = this->chessBoardPtr->IsCheck(this->color, defendingMoves);
	vector<Position> possibleMovesVector = this->GetPossibleMovesInternal(position, pinDirection);
	if (isCheck)
	{
		possibleMovesVector = Intersection(possibleMovesVector, defendingMoves);
	}
	return possibleMovesVector;
}
