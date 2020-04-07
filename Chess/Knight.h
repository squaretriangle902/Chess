#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Color color, ChessBoard* chessBoardPtr);
	vector<Position> GetPossibleMoves(Position position);
};

