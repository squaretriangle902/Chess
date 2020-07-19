#include "King.h"

King::King(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
	this->type = king;
}

vector<Position> King::GetPossibleMoves(Position position)
{
	return vector<Position>();
}
