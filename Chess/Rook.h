#pragma once
#include "LongRangePiece.h"

class Rook : public LongRangePiece
{
public:
    Rook(Color color, ChessBoard* chessBoardPtr, Game* game = nullptr);
};
