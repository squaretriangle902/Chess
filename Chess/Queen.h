#pragma once
#include "Piece.h"
#include "Direction.h"

class Queen : public Piece
{
public:
	Queen(Color color, ChessBoard* chessBoardPtr);
	vector<Position> GetPossibleMoves(Position startingPosition);
private:
	void CheckPositionOnDirection(Position startingPosition,
		int i,
		std::vector<Direction>& BlockedDirectionsVector,
		std::vector<Position>& possibleMovesVector,
		Direction direction,
		int verticalOffset,
		int horizontalOffset);
	bool IsDirectionFree(Direction direction, vector<Direction> BlockedDirectionsVector);
};