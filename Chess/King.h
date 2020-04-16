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
	bool IsLongRangeCheck(Position startingPosition);
	bool IsCheckOnOffset(Position startingPosition, Position positionOffset, PieceType pieceType);
	bool IsKnightCheck(Position startingPosition);
	bool IsPawnCheck(Position startingPosition);
	void CheckMove(Position startingPosition, int horizontalOffset, int verticalOffset, std::vector<Position>& possibleMovesVector);
	bool CheckOnDirection(Position& startPosition, bool endCondition,
		Position direction, PieceType expectingType);
};

