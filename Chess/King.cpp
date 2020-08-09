#include "King.h"

King::King(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
	this->type = king;
}

vector<Position> King::GetPossibleMovesInternal(Position position)
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
	if (this->IsMoveValid(movePosition) && 
		!this->chessBoardPtr->IsPositionUnderAttack(movePosition, this->color))
	{
		possibleMovesVector.push_back(movePosition);
	}
}
