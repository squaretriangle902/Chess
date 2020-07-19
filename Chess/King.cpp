#include "King.h"

King::King(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
	this->type = king;
}

vector<Position> King::GetPossibleMoves(Position position)
{
	vector<Position> possibleMovesVector;
	for (Chess::Direction direction = Chess::up; direction != Chess::noDirection; direction++)
	{
		CheckMove(direction, possibleMovesVector);
	}
	return possibleMovesVector;
}

void King::CheckMove(Chess::Direction direction, vector<Position>& possibleMovesVector)
{
	Position position = Position(direction);
	if (!this->chessBoardPtr->IsPositionUnderAttack(position, this->color))
	{
		possibleMovesVector.push_back(position);
	}
}
