#pragma once
#include "LongRangePiece.h"

class Queen : public LongRangePiece
{
public:
	Queen(Color color, ChessBoard* chessBoardPtr);
};