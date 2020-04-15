#pragma once
#include "Direction.h"
#include "Piece.h"

class King : public Piece
{
public:
	King(Color color, ChessBoard* chessBoardPtr);
    vector<Position> GetPossibleMoves(Position startingPosition);
	bool IsCheck(Position startingPosition);
private:
	void CheckMove(Position& startingPosition, int horizontalOffset, int verticalOffset, std::vector<Position>& possibleMovesVector);
	bool CheckOnDirection(Position& startPosition, bool endCondition,
		Position direction, PieceType expectingType);
};

