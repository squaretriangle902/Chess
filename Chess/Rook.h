#pragma once
#include "LongRangePiece.h"

class Rook : public LongRangePiece
{
public:
	Rook(Color color, ChessBoard* chessBoardPtr);
	vector<Position> GetPossibleMoves(Position startingPosition);
};
