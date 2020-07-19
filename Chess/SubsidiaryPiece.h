#pragma once
#include "Piece.h"
#include "Common.h"

class SubsidiaryPiece : public Piece
{
public: 
	SubsidiaryPiece(Color color, ChessBoard* chessBoardPtr);
	vector<Position> GetPossibleMoves(Position position);
protected:
	virtual vector<Position> GetPossibleMoves(Position position, 
		Chess::Direction pinDirection) = 0;
};