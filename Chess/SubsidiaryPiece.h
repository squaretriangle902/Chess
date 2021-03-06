#pragma once
#include "Piece.h"
#include "Common.h"

class SubsidiaryPiece : public Piece
{
public: 
    SubsidiaryPiece(Color color = white, ChessBoard* chessBoardPtr = nullptr, Game* game = nullptr);
protected:
	vector<Position> GetPossibleMovesInternal(Position position);
	virtual vector<Position> GetPossibleMovesInternal(Position position, 
		Chess::Direction pinDirection) = 0;
};
