#pragma once
#include "SubsidiaryPiece.h"

class Knight : public SubsidiaryPiece
{
public:
    Knight(Color color, ChessBoard* chessBoardPtr, Game* game = nullptr);
private:
	vector<Position> GetPossibleMovesInternal(Position position, Chess::Direction pinDirection);
	void IsMovePossible(Position position, Position offset, vector<Position>& possibleMovesVector);
};
