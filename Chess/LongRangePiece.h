#pragma once
#include "Piece.h"
#include "Direction.h"

class LongRangePiece : public Piece
{
public:
	LongRangePiece(Color color, ChessBoard* chessBoardPtr);
protected:
	void CheckPositionOnDirection(Position startingPosition,
		int i,
		std::vector<Direction::Direction>& blockedDirectionsVector,
		std::vector<Position>& possibleMovesVector,
		Direction::Direction direction,
		int verticalOffset,
		int horizontalOffset);
	bool IsDirectionFree(Direction::Direction direction, 
		vector<Direction::Direction> blockedDirectionsVector);
};

