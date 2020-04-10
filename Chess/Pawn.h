#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Color color, ChessBoard* chessBoard);
	vector<Position> GetPossibleMoves(Position position);
private:
	void TryPushMove(Position position, int horizontalOffset,
		std::vector<Position>& possibleMovesVector, bool& movePushed);
	void TryPushJump(Position position, int verticalOffset,
		std::vector<Position>& possibleMovesVector, bool movePushed, int necessaryVertical);
	void TryPushTaking(Position& position, 
		int horizontalOffset, int verticalOffset, std::vector<Position>& possibleMovesVector);
};
