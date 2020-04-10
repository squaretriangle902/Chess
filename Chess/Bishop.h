#pragma once
#include "LongRangePiece.h"

class Bishop : public LongRangePiece
{
public:
	Bishop(Color color, ChessBoard* chessBoardPtr);
	vector<Position> GetPossibleMoves(Position startingPosition);
};
