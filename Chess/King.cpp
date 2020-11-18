#include "King.h"

King::King(Color color, ChessBoard* chessBoardPtr, Game* game) : Piece(color, chessBoardPtr, game)
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
    CheckCastling(position, possibleMovesVector);
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

bool King::CheckCastlingPosition(Position position)
{
    return this->chessBoardPtr->GetPiecePtr(position) == nullptr &&
            !this->chessBoardPtr->IsPositionUnderAttack(position, this->color);

}

bool King::CastlingIsPossible(Position kingPosition, Chess::Direction direction)
{
    return ConnectedWithRook(kingPosition, direction) && this->moved == false &&
            CastlingPositionsAreSafe(kingPosition, direction) &&
            !this->chessBoardPtr->IsPositionUnderAttack(kingPosition, this->color);
}

void King::CheckCastling(Position position, vector<Position> &possibleMovesVector)
{
    if (CastlingIsPossible(position, Chess::left))
    {
        possibleMovesVector.push_back(position + 2 * Position(Chess::left));
    }
    if (CastlingIsPossible(position, Chess::right))
    {
        possibleMovesVector.push_back(position + 2 * Position(Chess::right));
    }
}

bool King::ConnectedWithRook(Position position, Chess::Direction direction)
{
    Position i = position + direction;
    while(this->chessBoardPtr->GetPiecePtr(i) == nullptr && this->chessBoardPtr->InBorders(i))
    {
        i += direction;
    }
    Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(i);
    return this->chessBoardPtr->InBorders(i) && piecePtr->GetType() == rook && !piecePtr->GetMoved();
}

bool King::CastlingPositionsAreSafe(Position position, Chess::Direction direction)
{
    for (int i = 1; i <= 2; i++)
    {
        Position currentPosition = position + i * Position(direction);
        if (this->chessBoardPtr->IsPositionUnderAttack(currentPosition, this->color))
        {
            return false;
        }
    }
    return true;
}
