#include "King.h"

King::King(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
	this->type = king;
}

vector<Position> King::GetPossibleMoves(Position position)
{
	vector<Position> possibleMovesVector;
	for (Chess::Direction direction = Chess::up; 
		direction != Chess::noDirection; direction++)
	{
		CheckMove(position, direction, possibleMovesVector);
	}
	return possibleMovesVector;
}

void King::CheckMove(Position kingPosition, Chess::Direction direction, 
	vector<Position>& possibleMovesVector)
{
	Position movePosition = kingPosition + Position(direction);
	if (!this->chessBoardPtr->IsPositionUnderAttack(kingPosition, this->color))
	{
		possibleMovesVector.push_back(kingPosition);
	}
}
