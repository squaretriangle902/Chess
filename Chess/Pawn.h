#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Color color, ChessBoard* chessBoard);
	vector<Position> GetPossibleMoves(Position position);
private:
	bool IsMovePossible(Position position, int horizontalOffset,
		std::vector<Position>& possibleMovesVector);
	void CheckJump(Position position, int verticalOffset,
		std::vector<Position>& possibleMovesVector, int necessaryVertical);
	void CheckTaking(Position startPosition, Position offset, 
		std::vector<Position>& possibleMovesVector);
};
