#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Color color, ChessBoard* chessBoardPtr);
	vector<Position> GetPossibleMoves(Position position);
private:
	void IsMovePossible(Position position, Position offset, vector<Position>& possibleMovesVector);
};
