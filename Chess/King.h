#pragma once
#include "Direction.h"
#include "Piece.h"
#include "Common.h"

class King : public Piece
{
public:
	King(Color color, ChessBoard* chessBoardPtr);
    vector<Position> GetPossibleMovesInternal(Position position);
private:
	void CheckMove(Position position, Chess::Direction direction, 
		vector<Position>& possibleMovesVector);
};

