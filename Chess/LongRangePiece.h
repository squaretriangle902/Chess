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
		std::vector<Direction>& blockedDirectionsVector,
		std::vector<Position>& possibleMovesVector,
		Direction direction,
		int verticalOffset,
		int horizontalOffset);
	bool IsDirectionFree(Direction direction, vector<Direction> blockedDirectionsVector);
};

