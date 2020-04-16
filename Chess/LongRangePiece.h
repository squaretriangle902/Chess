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
		std::vector<Chess::Direction>& blockedDirectionsVector,
		std::vector<Position>& possibleMovesVector,
		Chess::Direction direction);
	bool IsDirectionFree(Chess::Direction direction, 
		vector<Chess::Direction> blockedDirectionsVector);
};

