#pragma once
#include "Piece.h"
#include "Direction.cpp"

class Bishop : public Piece
{
public:
	Bishop(Color color, ChessBoard* chessBoardPtr);
	void CheckPositionOnDirection(Position startingPosition, 
		int i, 
		std::vector<Direction>& BlockedDirectionsVector, 
		std::vector<Position>& possibleMovesVector,
		Direction direction,
		int verticalOffset,
		int horizontalOffset);
	vector<Position> GetPossibleMoves(Position startingPosition);
private:
	bool IsDirectionFree(Direction direction, vector<Direction> BlockedDirectionsVector);
};

