#pragma once
#include "Direction.h"
#include "Piece.h"
#include "Common.h"

class King : public Piece
{
public:
    King(Color color, ChessBoard* chessBoardPtr, Game* game = nullptr);
    vector<Position> GetPossibleMovesInternal(Position position);
private:
	void CheckMove(Position position, Chess::Direction direction, 
		vector<Position>& possibleMovesVector);
    bool CheckCastlingPosition(Position position);
    bool CastlingIsPossible(Position kingPosition, Chess::Direction direction);
    void CheckCastling(Position position, vector<Position>& possibleMovesVector);
    bool ConnectedWithRook(Position position, Chess::Direction);
    bool CastlingPositionsAreSafe(Position position, Chess::Direction);
};

