#pragma once
#include "Direction.h"
#include "Piece.h"
#include "Common.h"

class King : public Piece
{
public:
	King(Color color, ChessBoard* chessBoardPtr);
    vector<Position> GetPossibleMoves(Position position);
private:
	void CheckMove(Chess::Direction direction, vector<Position>& possibleMovesVector);
};

