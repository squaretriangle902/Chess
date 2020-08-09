#pragma once
#include "Position.h"
#include "Color.h"
#include "PieceType.h"
#include "ChessBoard.h"
#include <vector>

using namespace std;

class ChessBoard;

class Piece
{
public:
	Piece(Color color, ChessBoard* chessBoardPtr);
    Color GetColor();
	PieceType GetType();
	bool IsMoveValid(Position position);
	void SetChessBoardPtr(ChessBoard* chessBoardPtr);
	vector<Position> GetPossibleMoves(Position);

protected:
	virtual vector<Position> GetPossibleMovesInternal(Position) = 0;
	PieceType type;
	Color color;
	ChessBoard* chessBoardPtr;
};
