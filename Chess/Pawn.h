#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Color color, ChessBoard* chessBoard);
	vector<Position> GetPossibleMoves(Position position);
private:
	void IsMovePossible(Position position, int horizontalOffset,
		std::vector<Position>& possibleMovesVector, bool& movePushed);
	void CheckJump(Position position, int verticalOffset,
		std::vector<Position>& possibleMovesVector, bool movePushed, int necessaryVertical);
	void CheckTaking(Position& position, 
		int horizontalOffset, int verticalOffset, std::vector<Position>& possibleMovesVector);
};
