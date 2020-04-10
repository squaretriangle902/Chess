#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Color color, ChessBoard* chessBoardPtr);
	vector<Position> GetPossibleMoves(Position position);
private:
	void CheckStep(Position& position,
		int horizontalOffset, int verticalOffset,
		vector<Position>& possibleMovesVector);
};
